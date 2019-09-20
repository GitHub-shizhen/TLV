// TLV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "TLV_ConstStatement.h"
#include "TLV_Decode.h"

using namespace std;

TLV_Decode::TLV_Decode()
{

}

TLV_Decode::~TLV_Decode()
{

}

unsigned int TLV_Decode::MapDecode(const unsigned int *Data)
{
	
	if (MAPLATITIUDE == *Data)
	{
		cout << "MapLatitude is: ";
		for (int i = 0; i < *(Data + 1); i++)
		{
			cout << (char)*(Data + 2 + i);
		}
		cout << endl;
	}
	if (MAPLONGITUDE == *Data)
	{
		cout << "MapLongitude is: ";
		for (int i = 0; i < *(Data + 1); i++)
		{
			cout << (char)*(Data + 2 + i);
		}
		cout << endl;
	}
	return *(Data + 1);
}

unsigned int TLV_Decode::SensorDecode(const unsigned int *Data)
{
	if (SENSOR_UPPERLIMIT == *(Data + 2))
	{
		cout << "SensorUpperlimit is: ";
		for (int i = 0; i < *(Data + 3); i++)
		{
			cout << (char)*(Data + 4 + i);
		}
		cout << endl;
	}
	int point = 4 + *(Data + 3);
	if (SENSOR_LOWERLIMIT == *(Data + point + 1))
	{
		cout << "SensorLowerlimit is: ";
		for (int i = 0; i < *(Data + point + 2); i++)
		{
			cout << (char)*(Data + point + 3 + i);
		}
		cout << endl;
	}
	return *Data;
}

int TLV_Decode::result(int numTag, const unsigned int *Data)
{
	int num = 0;
	if (3 == numTag)
	{
		if (MAP == *Data)
		{
			num = MapDecode(Data + 1);
		}
		return (num + 4);
	}
	if (2 == numTag)
	{
		if (SENSOR == *Data)
		{
			num = SensorDecode(Data + 1);
		}
		return (num + 3);
	}
	return num;   
}


void TLV_Decode::Decode(const unsigned int *Data, const unsigned int Length)
{
	int count = 0;
	for (int i = 0; i < Length; )
	{

		switch (*Data)
		{
			case MIXTURE_PRIVATECLASS:
				if (*(Data + 1) > 0x80)
				{
					count = result(3, ( Data + 1 ));
				}
				else
				{
					count = result(2, (Data + 1));
				}
				break;
			case SINGLE_PRIVATECLASS:
				if (*(Data + 1) > 0x80)
				{					
					count = result(3, (Data + 1));
				}
				else
				{
					count = result(2, (Data + 1));
				}
				break; 
			default:
				break;
		}
		Data += count;
		i += count;
	}
}


