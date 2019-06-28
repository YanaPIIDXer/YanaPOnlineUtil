#include "MemoryStreamReader.h"
#include "EndianConverter.h"
#include <memory.h>

namespace YanaPOnlineUtil
{
namespace Stream
{

// コンストラクタ
MemoryStreamReader::MemoryStreamReader(const char *pInBuffer, unsigned int InBufferSize)
	: pBuffer(nullptr)
	, BufferSize(InBufferSize)
	, CurrentPosition(0)
	, bIsError(false)
{
	pBuffer = new char[BufferSize];
	memcpy(pBuffer, pInBuffer, BufferSize);
}

// デストラクタ
MemoryStreamReader::~MemoryStreamReader()
{
	delete[] pBuffer;
}

// intのシリアライズ
bool MemoryStreamReader::Serialize(int *pData)
{
	if (!Read(pData, sizeof(int))) { return false; }
	*pData = EndianConverter::Convert(*pData);
	return true;
}

// unsigned intのシリアライズ
bool MemoryStreamReader::Serialize(unsigned int *pData)
{
	if (!Read(pData, sizeof(unsigned int))) { return false; }
	*pData = EndianConverter::Convert(*pData);
	return true;
}

// shortのシリアライズ
bool MemoryStreamReader::Serialize(short *pData)
{
	if (!Read(pData, sizeof(short))) { return false; }
	*pData = EndianConverter::Convert(*pData);
	return true;
}

// unsigned shortのシリアライズ
bool MemoryStreamReader::Serialize(unsigned short *pData)
{
	if (!Read(pData, sizeof(unsigned short))) { return false; }
	*pData = EndianConverter::Convert(*pData);
	return true;
}

// charのシリアライズ
bool MemoryStreamReader::Serialize(char *pData)
{
	return Read(pData, sizeof(char));
}

// unsigned charのシリアライズ
bool MemoryStreamReader::Serialize(unsigned char *pData)
{
	return Read(pData, sizeof(unsigned char));
}

// floatのシリアライズ
bool MemoryStreamReader::Serialize(float *pData)
{
	if (!Read(pData, sizeof(float))) { return false; }
	*pData = EndianConverter::Convert(*pData);
	return true;
}

// 文字列のシリアライズ
bool MemoryStreamReader::Serialize(std::string *pData)
{
	// 文字列長.
	unsigned int Length = 0;
	if (!Serialize(&Length)) { return false; }

	// 文字列.
	char *pStr = new char[Length + 1];
	memset(pStr, 0, Length + 1);
	if (!Read(pStr, Length)) { return false; }

	*pData = pStr;
	return true;
}


// 読み込み
bool MemoryStreamReader::Read(void *pData, unsigned int Size)
{
	if (bIsError) { return false; }
	
	if (CurrentPosition + Size > BufferSize)
	{
		bIsError = true;
		return false;
	}

	memcpy(pData, (pBuffer + CurrentPosition), Size);
	CurrentPosition += Size;
	return true;
}

}
}
