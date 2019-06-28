using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using YanaPOnlineUtil.Stream;

namespace YanaPOnlineUtil.Packet
{
	/// <summary>
	/// パケットシリアライズクラス
	/// </summary>
	public class PacketSerializer
	{
		/// <summary>
		/// 受信イベント
		/// </summary>
		private Action<uint, IMemoryStream> RecvEvent;

		/// <summary>
		/// 送信イベント
		/// </summary>
		private Action<byte[]> SendEvent;

		/// <summary>
		/// バッファ
		/// </summary>
		private List<byte> Buffer = new List<byte>();

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InRecvEvent">受信イベント</param>
		/// <param name="InSendEvent">送信イベント</param>
		public PacketSerializer(Action<uint, IMemoryStream> InRecvEvent, Action<byte[]> InSendEvent)
		{
			RecvEvent = InRecvEvent;
			SendEvent = InSendEvent;
		}

		/// <summary>
		/// 受信した
		/// </summary>
		/// <param name="Data">データ</param>
		public void OnRecv(byte[] Data)
		{
			Buffer.AddRange(Data);

			PacketHeader Header = new PacketHeader();
			MemoryStreamReader StreamReader = new MemoryStreamReader(Buffer.ToArray());

			if (!Header.Serialize(StreamReader)) { return; }

			int PacketSize = (int)PacketHeader.HeaderSize + Header.Size;
			if(Buffer.Count < PacketSize) { return; }

			Buffer.RemoveRange(0, PacketSize);

			RecvEvent(Header.PacketId, StreamReader);
		}

		/// <summary>
		/// 送信
		/// </summary>
		/// <param name="SendPacket">送信するパケット</param>
		public void Send(Packet SendPacket)
		{
			MemorySizeCaliculator SizeCaliculator = new MemorySizeCaliculator();
			SizeCaliculator.Serialize(SendPacket);

			MemoryStreamWriter StreamWriter = new MemoryStreamWriter();
			PacketHeader Header = new PacketHeader(SendPacket.PacketId, (byte)SizeCaliculator.Size);

			StreamWriter.Serialize(Header);
			StreamWriter.Serialize(SendPacket);

			SendEvent(StreamWriter.Buffer.ToArray());
		}
	}
}
