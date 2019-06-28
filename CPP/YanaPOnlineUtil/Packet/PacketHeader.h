#ifndef __PACKETHEADER_H__
#define __PACKETHEADER_H__

#include "Serializable/Serializable.h"
#include "Packet.h"

namespace YanaPOnlineUtil
{
namespace Packet
{

/**
 * @class PacketHeader
 * @brief パケットヘッダ
 */
class PacketHeader : public ISerializable
{

public:

	/**
	 * @brief コンストラクタ
	 */
	PacketHeader();
	
	/**
	 * @brief コンストラクタ
	 * @param[in] InPacketId パケットＩＤ
	 * @param[in] InSize サイズ
	 */
	PacketHeader(unsigned char InPacketId, unsigned char InSize);
	
	/**
	 * @brief デストラクタ
	 */
	virtual ~PacketHeader() {}

	/**
	 * @fn unsigned char GetPacketId() const
	 * @brief パケットＩＤ取得
	 * @return パケットＩＤ
	 */
	unsigned char GetPacketId() const { return PacketId; }

	/**
	 * @fn unsigned char GetSize() const
	 * @brief サイズ取得
	 * @return サイズ
	 */
	unsigned char GetSize() const { return Size; }

	/**
	 * @fn virtual bool Serialize(Util::Stream::IMemoryStream *pStream) override
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Serialize(Stream::IMemoryStream *pStream) override;

	//! ヘッダサイズ
	static const unsigned int HeaderSize;

private:

	// パケットＩＤ
	unsigned char PacketId;

	// サイズ
	unsigned char Size;

};

}
}

#endif		// #ifndef __PACKETHEADER_H__
