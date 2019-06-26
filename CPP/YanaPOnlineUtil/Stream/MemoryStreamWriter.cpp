#include "MemoryStreamWriter.h"
#include <memory.h>
#include <string.h>
#include "EndianConverter.h"

namespace YanaPOnlineUtil
{
namespace Stream
{

// コンストラクタ
MemoryStreamWriter::MemoryStreamWriter(unsigned int InBufferSize)
	: pBuffer(nullptr)
	, BufferSize(InBufferSize)
	, CurrentPosition(0)
	, bIsError(false)
{
	pBuffer = new char[BufferSize];
}

// デストラクタ
MemoryStreamWriter::~MemoryStreamWriter()
{
	delete[] pBuffer;
}

// intのシリアライズ
bool MemoryStreamWriter::Serialize(int *pData)
{
	int Data = EndianConverter::Convert(*pData);
	return Write(&Data, sizeof(int));
}

// unsigned intのシリアライズ
bool MemoryStreamWriter::Serialize(unsigned int *pData)
{
	unsigned int Data = EndianConverter::Convert(*pData);
	return Write(&Data, sizeof(unsigned int));
}

// shortのシリアライズ
bool MemoryStreamWriter::Serialize(short *pData)
{
	short Data = EndianConverter::Convert(*pData);
	return Write(&Data, sizeof(short));
}

// unsigned shortのシリアライズ
bool MemoryStreamWriter::Serialize(unsigned short *pData)
{
	unsigned short Data = EndianConverter::Convert(*pData);
	return Write(&Data, sizeof(unsigned short));
}

// charのシリアライズ
bool MemoryStreamWriter::Serialize(char *pData)
{
	return Write(pData, sizeof(char));
}

// unsigned charのシリアライズ
bool MemoryStreamWriter::Serialize(unsigned char *pData)
{
	return Write(pData, sizeof(unsigned char));
}

// floatのシリアライズ
bool MemoryStreamWriter::Serialize(float *pData)
{
	float Data = EndianConverter::Convert(*pData);
	return Write(&Data, sizeof(float));
}

// 文字列のシリアライズ
bool MemoryStreamWriter::Serialize(std::string *pData)
{
	// 文字列長.
	unsigned int Length = pData->length();
	if (!Serialize(&Length)) { return false; }

	// 文字列.
	return Write(pData->c_str(), Length);
}


// 書き込み
bool MemoryStreamWriter::Write(const void *pData, unsigned int Size)
{
	if (CurrentPosition + Size > BufferSize)
	{
		// バッファサイズをオーバーしたらエラー
		bIsError = true;
		return false;
	}

	memcpy((pBuffer + CurrentPosition), pData, Size);
	CurrentPosition += Size;
	return true;
}

}
}
