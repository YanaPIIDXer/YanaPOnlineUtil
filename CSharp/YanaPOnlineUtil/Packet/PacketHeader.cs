using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using YanaPOnlineUtil.Stream;

namespace YanaPOnlineUtil.Packet
{
	/// <summary>
	/// パケットヘッダ
	/// </summary>
	public class PacketHeader : ISerializable
	{
		/// <summary>
		/// ヘッダサイズ
		/// </summary>
		public static readonly uint HeaderSize = 2;

		/// <summary>
		/// パケットＩＤ
		/// </summary>
		public byte PacketId { get; private set; }

		/// <summary>
		/// パケットサイズ
		/// </summary>
		public byte Size { get; private set; }

		/// <summary>
		/// コンストラクタ
		/// </summary>
		public PacketHeader()
		{
			PacketId = 0;
			Size = 0;
		}

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InPacketId">パケットＩＤ</param>
		/// <param name="InSize">パケットサイズ</param>
		public PacketHeader(byte InPacketId, byte InSize)
		{
			PacketId = InPacketId;
			Size = InSize;
		}

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Stream">ストリーム</param>
		/// <returns>成功したらtrueを返す</returns>
		public bool Serialize(IMemoryStream Stream)
		{
			byte Data = 0;
			if(!Stream.Serialize(ref Data)) { return false; }
			PacketId = Data;

			if(!Stream.Serialize(ref Data)) { return false; }
			Size = Data;

			return true;
		}
	}
}
