#include "MemorySizeCaliculator.h"
#include <string.h>

namespace YanaPOnlineUtil
{
namespace Stream
{

// コンストラクタ
MemorySizeCaliculator::MemorySizeCaliculator()
	: Size(0)
{
}

// intのシリアライズ
bool MemorySizeCaliculator::Serialize(int *pData)
{
	Size += sizeof(int);
	return true;
}

// unsigned intのシリアライズ
bool MemorySizeCaliculator::Serialize(unsigned int *pData)
{
	Size += sizeof(unsigned int);
	return true;
}

// shortのシリアライズ
bool MemorySizeCaliculator::Serialize(short *pData)
{
	Size += sizeof(short);
	return true;
}

// unsigned shortのシリアライズ
bool MemorySizeCaliculator::Serialize(unsigned short *pData)
{
	Size += sizeof(unsigned short);
	return true;
}

// charのシリアライズ
bool MemorySizeCaliculator::Serialize(char *pData)
{
	Size += sizeof(char);
	return true;
}

// unsigned charのシリアライズ
bool MemorySizeCaliculator::Serialize(unsigned char *pData)
{
	Size += sizeof(unsigned char);
	return true;
}

// floatのシリアライズ
bool MemorySizeCaliculator::Serialize(float *pData)
{
	Size += sizeof(float);
	return true;
}

// 文字列のシリアライズ
bool MemorySizeCaliculator::Serialize(std::string *pData)
{
	Size += sizeof(unsigned int);	// 文字列長.
	Size += pData->length();		// 文字数.
	return true;
}

}
}
