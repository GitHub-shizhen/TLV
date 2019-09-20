#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "TLV_ConstStatement.h"
#include "TLV_Encode.h"

using namespace std;
unsigned int TLV_Encode::vectorLength = 0;
std::vector<unsigned int> TLV_Encode::Transmit_data = { 0 };

TLV_Encode::TLV_Encode() {}
TLV_Encode::~TLV_Encode() {}

void TLV_Encode::ResetVector()
{
	Transmit_data.clear();
}

void TLV_Encode::Encode(const int Class, const int SubClass, const int Tag, const int Length, const unsigned char *Value)
{
	static unsigned int InsertIndex = 0;

	switch (Class)
	{
	case MIXTURE_PRIVATECLASS:
		Transmit_data.push_back(MIXTURE_PRIVATECLASS);
		break;
	case SINGLE_PRIVATECLASS:
		Transmit_data.push_back(SINGLE_PRIVATECLASS);
		break;
	case 0x00:
//		Transmit_data.insert(Transmit_data.begin() + InsertIndex , vectorLength - InsertIndex);
		Transmit_data.insert(Transmit_data.begin() + InsertIndex, 6 + Length);
		InsertIndex = 0;
	default:
		break;
	}

	switch (SubClass)
	{
	case MAP:
		Transmit_data.push_back(MAP);
		break;
	case SENSOR:
		Transmit_data.push_back(SENSOR);
		break;
	default:
		break;
	}

	switch (Tag)
	{
	case MAPLATITIUDE:
		Transmit_data.push_back(MAPLATITIUDE);
		break;
	case MAPLONGITUDE:
		Transmit_data.push_back(MAPLONGITUDE);
		break;
	case SENSOR_UPPERLIMIT:
		Transmit_data.push_back(SENSOR_UPPERLIMIT);
		break;
	case SENSOR_LOWERLIMIT:
		Transmit_data.push_back(SENSOR_LOWERLIMIT);
		break;
	case 0x00:
		if (0x00 != Class)
		{
			InsertIndex = Transmit_data.size();
		}
	default:
		break;
	}

/*
if (0x00 == Length && 0x00 != Class)
	{
		InsertIndex = Transmit_data.size();		
	}
*/
	
	if(0x00 != Length && 0x00 != Class)
	{
		Transmit_data.push_back(Length);
		for (int i = 0; i < Length; i++)
		{
			Transmit_data.push_back(*(Value + i));
		}
		
	}
	vectorLength = Transmit_data.size();

}

void TLV_Encode::Transmit(const unsigned int Length)
{
	cout << "Encode data is: " << endl;
	SendData = new unsigned int[Length];
	for (int i = 0; i < Length; i++)
	{
		*(SendData + i) = Transmit_data.at(i);
		cout << hex << *(SendData + i) << " ";
	}
	cout << endl;
	DataLength = Length;
}


unsigned int * TLV_Encode::GetSendData()
{
	return SendData;
}



unsigned int TLV_Encode::GetDataLength()
{
	return DataLength;
}

void TLV_Encode::ReadyTransmit()
{
	TLV_Encode::Transmit(vectorLength);
}

