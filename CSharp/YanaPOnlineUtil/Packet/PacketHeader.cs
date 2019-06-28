using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YanaPOnlineUtil.Packet
{
	/// <summary>
	/// パケットヘッダ
	/// </summary>
	public class PacketHeader
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
	}
}
