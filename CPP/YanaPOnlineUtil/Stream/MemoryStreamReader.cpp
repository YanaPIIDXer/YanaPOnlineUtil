#include "MemoryStreamReader.h"
#include "EndianConverter.h"
#include <memory.h>

namespace YanaPOnlineUtil
{
namespace Stream
{

// �R���X�g���N�^
MemoryStreamReader::MemoryStreamReader(const char *pInBuffer, unsigned int InBufferSize)
	: pBuffer(nullptr)
	, BufferSize(InBufferSize)
	, CurrentPosition(0)
	, bIsError(false)
{
	pBuffer = new char[BufferSize];
	memcpy(pBuffer, pInBuffer, BufferSize);
}

// �f�X�g���N�^
MemoryStreamReader::~MemoryStreamReader()
{
	delete[] pBuffer;
}

// int�̃V���A���C�Y
bool MemoryStreamReader::Serialize(int *pData)
{
	if (!Read(pData, sizeof(int))) { return false; }
	*pData = EndianConverter::Convert(*pData);
	return true;
}

// unsigned int�̃V���A���C�Y
bool MemoryStreamReader::Serialize(unsigned int *pData)
{
	if (!Read(pData, sizeof(unsigned int))) { return false; }
	*pData = EndianConverter::Convert(*pData);
	return true;
}

// short�̃V���A���C�Y
bool MemoryStreamReader::Serialize(short *pData)
{
	if (!Read(pData, sizeof(short))) { return false; }
	*pData = EndianConverter::Convert(*pData);
	return true;
}

// unsigned short�̃V���A���C�Y
bool MemoryStreamReader::Serialize(unsigned short *pData)
{
	if (!Read(pData, sizeof(unsigned short))) { return false; }
	*pData = EndianConverter::Convert(*pData);
	return true;
}

// char�̃V���A���C�Y
bool MemoryStreamReader::Serialize(char *pData)
{
	return Read(pData, sizeof(char));
}

// unsigned char�̃V���A���C�Y
bool MemoryStreamReader::Serialize(unsigned char *pData)
{
	return Read(pData, sizeof(unsigned char));
}

// float�̃V���A���C�Y
bool MemoryStreamReader::Serialize(float *pData)
{
	if (!Read(pData, sizeof(float))) { return false; }
	*pData = EndianConverter::Convert(*pData);
	return true;
}

// ������̃V���A���C�Y
bool MemoryStreamReader::Serialize(std::string *pData)
{
	// ������.
	unsigned int Length = 0;
	if (!Serialize(&Length)) { return false; }

	// ������.
	char *pStr = new char[Length + 1];
	memset(pStr, 0, Length + 1);
	if (!Read(pStr, Length)) { return false; }

	*pData = pStr;
	return true;
}


// �ǂݍ���
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
