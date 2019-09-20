#ifndef TLV_DECODE_H
#define TLV_DECODE_H


class TLV_Decode
{
public:
	TLV_Decode();
	~TLV_Decode();

	void Decode(const unsigned int *Data, const unsigned int Length);
	int result(int numTag, const unsigned int *Data);
	unsigned int MapDecode(const unsigned int *Data);
	unsigned int SensorDecode(const unsigned int *Data);
private:

};

#endif // !TLV_DECODE_H

