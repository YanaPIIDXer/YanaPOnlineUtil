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

// コンストラクタ
PacketSerializer::PacketSerializer(const RecvFunction &InRecvFunc, const SendFunction &InSendFunc)
	: RecvFunc(InRecvFunc)
	, SendFunc(InSendFunc)
{
}

// デストラクタ
PacketSerializer::~PacketSerializer()
{
}

// 受信した
void PacketSerializer::OnRecv(const char *pData, unsigned int Size)
{
	// バッファにデータをブチ込む。
	Buffer.resize(Buffer.size() + Size);
	unsigned int Begin = Buffer.size();
	for (unsigned int i = 0; i < Size; i++)
	{
		Buffer[Begin + i] = pData[i];
	}

	// ヘッダのシリアライズ
	MemoryStreamReader StreamReader(&Buffer[0], Buffer.size());
	PacketHeader Header;
	if (!Header.Serialize(&StreamReader)) { return; }

	unsigned int PacketSize = PacketHeader::HeaderSize + Header.GetSize();
	if (Buffer.size() < PacketSize) { return; }

	// 受信に成功していたらバッファから消去。
	for (unsigned int i = 0; i < PacketSize; i++)
	{
		Buffer.erase(Buffer.begin());
	}

	// 受信関数にパケットＩＤとストリームを投げる。
	RecvFunc(Header.GetPacketId(), &StreamReader);
}

// 送信.
void PacketSerializer::Send(CPacket *pPacket)
{
	// パケットサイズ計算
	MemorySizeCaliculator SizeCaliculator;
	SizeCaliculator.Serialize(pPacket);

	// シリアライズ本番
	MemoryStreamWriter StreamWriter(SizeCaliculator.GetSize() + PacketHeader::HeaderSize);

	// ヘッダ
	PacketHeader Header(pPacket->GetPacketId(), SizeCaliculator.GetSize());
	StreamWriter.Serialize(&Header);

	// パケット
	StreamWriter.Serialize(pPacket);

	// 送信
	SendFunc(StreamWriter.GetBuffer(), StreamWriter.GetSize());
}

}
}
