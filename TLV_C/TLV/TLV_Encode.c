#include <stdio.h>
#include <string.h>
#include "TLV_ConstStatement.h"
#include "TLV_Encode.h"

static unsigned int *Transmit_data;
static unsigned int vectorLength = 0;
unsigned int DataLength = 0;
unsigned int *SendData;

void Transmit(const unsigned int Length)
{
	printf("Encode data is: ");
    SendData = new unsigned int[Length];
	for (int i = 0; i < Length; i++)
	{
		*(SendData + i) = Transmit_data.at(i);
		printf("%X ", *(SendData + i));
	}
	printf("\n");
	DataLength = Length;
}

void ReadyTransmit()
{
	Transmit(vectorLength);
}

void Encode(const int Class, const int SubClass, const int Tag, const int HeadsLength, 
	const int CodeLength, const unsigned char *Value)
{
	Transmit_data =(unsigned int *) calloc((HeadsLength + CodeLength), sizeof(int));
/*	if ( Mixture_PrivateClass == Class )
	{
		Transmit_data.push_back(Mixture_PrivateClass);
	}
	else
	{
		Transmit_data.push_back(Single_PrivateClass);
		if (Map == SubClass)
		{
			Transmit_data.push_back(Map);
		}
	}
	if (MapLatitude == Tag)
	{
		Transmit_data.push_back(MapLatitude);
	}
	if (MapLongitude == Tag)
	{
		Transmit_data.push_back(MapLongitude);
	}
	Transmit_data.push_back(Length);
	for (int i = 0; i < Length; i++)
	{
		Transmit_data.push_back(*(Value + i));
	}
	vectorLength = Transmit_data.size();
	*/
	printf("Length is: %d", sizeof(Transmit_data));
}
