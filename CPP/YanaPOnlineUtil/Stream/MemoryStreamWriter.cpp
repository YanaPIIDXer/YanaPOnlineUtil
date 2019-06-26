#include "MemoryStreamWriter.h"
#include <memory.h>
#include <string.h>
#include "EndianConverter.h"

namespace YanaPOnlineUtil
{
namespace Stream
{

// �R���X�g���N�^
MemoryStreamWriter::MemoryStreamWriter(unsigned int InBufferSize)
	: pBuffer(nullptr)
	, BufferSize(InBufferSize)
	, CurrentPosition(0)
	, bIsError(false)
{
	pBuffer = new char[BufferSize];
}

// �f�X�g���N�^
MemoryStreamWriter::~MemoryStreamWriter()
{
	delete[] pBuffer;
}

// int�̃V���A���C�Y
bool MemoryStreamWriter::Serialize(int *pData)
{
	int Data = EndianConverter::Convert(*pData);
	return Write(&Data, sizeof(int));
}

// unsigned int�̃V���A���C�Y
bool MemoryStreamWriter::Serialize(unsigned int *pData)
{
	unsigned int Data = EndianConverter::Convert(*pData);
	return Write(&Data, sizeof(unsigned int));
}

// short�̃V���A���C�Y
bool MemoryStreamWriter::Serialize(short *pData)
{
	short Data = EndianConverter::Convert(*pData);
	return Write(&Data, sizeof(short));
}

// unsigned short�̃V���A���C�Y
bool MemoryStreamWriter::Serialize(unsigned short *pData)
{
	unsigned short Data = EndianConverter::Convert(*pData);
	return Write(&Data, sizeof(unsigned short));
}

// char�̃V���A���C�Y
bool MemoryStreamWriter::Serialize(char *pData)
{
	return Write(pData, sizeof(char));
}

// unsigned char�̃V���A���C�Y
bool MemoryStreamWriter::Serialize(unsigned char *pData)
{
	return Write(pData, sizeof(unsigned char));
}

// float�̃V���A���C�Y
bool MemoryStreamWriter::Serialize(float *pData)
{
	float Data = EndianConverter::Convert(*pData);
	return Write(&Data, sizeof(float));
}

// ������̃V���A���C�Y
bool MemoryStreamWriter::Serialize(std::string *pData)
{
	// ������.
	unsigned int Length = pData->length();
	if (!Serialize(&Length)) { return false; }

	// ������.
	return Write(pData->c_str(), Length);
}


// ��������
bool MemoryStreamWriter::Write(const void *pData, unsigned int Size)
{
	if (CurrentPosition + Size > BufferSize)
	{
		// �o�b�t�@�T�C�Y���I�[�o�[������G���[
		bIsError = true;
		return false;
	}

	memcpy((pBuffer + CurrentPosition), pData, Size);
	CurrentPosition += Size;
	return true;
}

}
}
