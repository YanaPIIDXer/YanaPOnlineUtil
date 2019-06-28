#include "Packet/PacketHeader.h"

namespace YanaPOnlineUtil
{
namespace Packet
{

const unsigned int PacketHeader::HeaderSize = 2;

// �R���X�g���N�^
PacketHeader::PacketHeader()
	: PacketId(0)
	, Size(0)
{
}

// �R���X�g���N�^
PacketHeader::PacketHeader(unsigned char InPacketId, unsigned char InSize)
	: PacketId(InPacketId)
	, Size(InSize)
{
}

// �V���A���C�Y
bool PacketHeader::Serialize(Stream::IMemoryStream *pStream)
{
	if (!pStream->Serialize(&PacketId)) { return false; }
	if (!pStream->Serialize(&Size)) { return false; }

	return true;
}

}
}
