#include "PacketSerializer.h"
#include "PacketHeader.h"
#include "Stream/MemoryStreamReader.h"
#include "Stream/MemorySizeCaliculator.h"
#include "Stream/MemoryStreamWriter.h"

using namespace YanaPOnlineUtil::Stream;

namespace YanaPOnlineUtil
{
namespace Packet
{

// �R���X�g���N�^
PacketSerializer::PacketSerializer(const RecvFunction &InRecvFunc, const SendFunction &InSendFunc)
	: RecvFunc(InRecvFunc)
	, SendFunc(InSendFunc)
{
}

// �f�X�g���N�^
PacketSerializer::~PacketSerializer()
{
}

// ��M����
void PacketSerializer::OnRecv(const char *pData, unsigned int Size)
{
	// �o�b�t�@�Ƀf�[�^���u�`���ށB
	Buffer.resize(Buffer.size() + Size);
	unsigned int Begin = Buffer.size();
	for (unsigned int i = 0; i < Size; i++)
	{
		Buffer[Begin + i] = pData[i];
	}

	// �w�b�_�̃V���A���C�Y
	MemoryStreamReader StreamReader(&Buffer[0], Buffer.size());
	PacketHeader Header;
	if (!Header.Serialize(&StreamReader)) { return; }

	unsigned int PacketSize = PacketHeader::HeaderSize + Header.GetSize();
	if (Buffer.size() < PacketSize) { return; }

	// ��M�ɐ������Ă�����o�b�t�@��������B
	for (unsigned int i = 0; i < PacketSize; i++)
	{
		Buffer.erase(Buffer.begin());
	}

	// ��M�֐��Ƀp�P�b�g�h�c�ƃX�g���[���𓊂���B
	RecvFunc(Header.GetPacketId(), &StreamReader);
}

// ���M.
void PacketSerializer::Send(CPacket *pPacket)
{
	// �p�P�b�g�T�C�Y�v�Z
	MemorySizeCaliculator SizeCaliculator;
	SizeCaliculator.Serialize(pPacket);

	// �V���A���C�Y�{��
	MemoryStreamWriter StreamWriter(SizeCaliculator.GetSize() + PacketHeader::HeaderSize);

	// �w�b�_
	PacketHeader Header(pPacket->GetPacketId(), SizeCaliculator.GetSize());
	StreamWriter.Serialize(&Header);

	// �p�P�b�g
	StreamWriter.Serialize(pPacket);

	// ���M
	SendFunc(StreamWriter.GetBuffer(), StreamWriter.GetSize());
}

}
}
