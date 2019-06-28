using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using YanaPOnlineUtil.Stream;

namespace YanaPOnlineUtil.Packet
{
	/// <summary>
	/// パケットクラス
	/// </summary>
	public abstract class Packet : ISerializable
	{
		/// <summary>
		/// パケットＩＤ
		/// </summary>
		public abstract byte PacketId { get; }

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Stream">ストリーム</param>
		/// <returns>成功したらtrueを返す</returns>
		public abstract bool Serialize(IMemoryStream Stream);
	}
}
