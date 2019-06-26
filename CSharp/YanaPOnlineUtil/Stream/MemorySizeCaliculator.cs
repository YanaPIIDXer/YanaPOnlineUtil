using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YanaPOnlineUtil.Stream
{
	/// <summary>
	/// メモリサイズ計算
	/// </summary>
	public class MemorySizeCaliculator : IMemoryStream
	{

		/// <summary>
		/// サイズ
		/// </summary>
		public int Size { get; private set; }

		/// <summary>
		/// コンストラクタ
		/// </summary>
		public MemorySizeCaliculator()
		{
			Size = 0;
		}

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Serialize(ref int Data)
		{
			Size += sizeof(int);
			return true;
		}

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Serialize(ref uint Data)
		{
			Size += sizeof(uint);
			return true;
		}

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Serialize(ref short Data)
		{
			Size += sizeof(short);
			return true;
		}

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Serialize(ref ushort Data)
		{
			Size += sizeof(ushort);
			return true;
		}

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Serialize(ref char Data)
		{
			Size += 1;
			return true;
		}

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す。</returns>
		public bool Serialize(ref byte Data)
		{
			Size += 1;
			return true;
		}
		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す</returns>

		public bool Serialize(ref string Data)
		{
			// 文字列長
			Size += sizeof(uint);

			// 文字列
			Size += Data.Length;
			return true;
		}

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す</returns>
		public bool Serialize(char[] Data)
		{
			Size += Data.Length;
			return true;
		}
	}
}
