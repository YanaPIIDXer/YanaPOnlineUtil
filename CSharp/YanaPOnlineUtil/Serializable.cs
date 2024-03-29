﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using YanaPOnlineUtil.Stream;

namespace YanaPOnlineUtil
{
	/// <summary>
	/// シリアライズ可能オブジェクトインタフェース
	/// </summary>
    public interface ISerializable
    {
		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Stream">メモリストリーム</param>
		/// <returns>成功したらtrueを返す</returns>
		bool Serialize(IMemoryStream Stream);
    }
}
