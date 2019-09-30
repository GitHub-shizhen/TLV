#ifndef TLV_ENCODE_H
#define TVL_ENCODE_H

extern unsigned int *Transmit_data;
extern unsigned int DataLength;

void Transmit();
void Encode(const int Class, const int SubClass, const int Tag, const int HeadsLength,
	const int CodeLength, const unsigned char *Value);
#endif // !_TVL_ENCODE_H
