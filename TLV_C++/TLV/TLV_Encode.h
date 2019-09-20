#ifndef TLV_ENCODE_H
#define TVL_ENCODE_H
#include <iostream>
#include <vector>

class TLV_Encode
{
public:
	
	TLV_Encode();
	~TLV_Encode();

	void Encode(const int Class, const int SubClass, const int Tag, const int Length, const unsigned char *Value);
	void Transmit(const unsigned int Length);
	void ResetVector();

	unsigned int * GetSendData();

	unsigned int GetDataLength();

	void ReadyTransmit();
	
private:
	unsigned int *SendData;
	unsigned int DataLength = 0;
	static std::vector<unsigned int> Transmit_data;
	static unsigned int vectorLength;
};

#endif // !_TVL_ENCODE_H

