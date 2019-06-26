using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YanaPOnlineUtil.Stream
{
	/// <summary>
	/// メモリストリームインタフェース
	/// </summary>
	public interface IMemoryStream
	{
		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す</returns>
		bool Serialize(ref int Data);

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す</returns>
		bool Serialize(ref uint Data);

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す</returns>
		bool Serialize(ref short Data);

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す</returns>
		bool Serialize(ref ushort Data);

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す</returns>
		bool Serialize(ref char Data);

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す</returns>
		bool Serialize(ref byte Data);

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す</returns>
		bool Serialize(ref string Data);

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Data">データ</param>
		/// <returns>成功したらtrueを返す</returns>
		bool Serialize(char[] Data);
	}
}
