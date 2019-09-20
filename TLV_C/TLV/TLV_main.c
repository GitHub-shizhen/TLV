#include <stdio.h>
#include "TLV_ConstStatement.h"
#include "TLV_Encode.h"
#include "TLV_Decode.h"


int main(void)
{
	char SendMapCoordinate;
	unsigned char Value[15] = "";
	unsigned int Length = 0;
	printf("***********************************************************************************\n");
	printf("**********           TLV Encode / Decode Demo                            **********\n");
	printf("**********                                          Author : LUO         **********\n");
	printf("***********************************************************************************\n\n");
	printf("Transmit Map Coordinate ? (Please input y or n)");
	SendMapCoordinate = getchar();
	if ('y' == SendMapCoordinate )
	{
		printf("Please input Longitude: \n");
		scanf("Longitude := %s", Value);
		for (int i = 0; i < 15; i++)
		{
			if (0x00 == Value[i])
			{
				Length = i;
				break;
			}
		}		
		Encode(Single_PrivateClass, Map, MapLongitude, 3, Length, Value);
		memset(Value, '\0', 15);
		
		printf("Please input Latitude: \n");
		scanf("Latitude := %s", Value);
		for (int i = 0; i < 15; i++)
		{
			if (0x00 == Value[i])
			{
				Length = i;
				break;
			}
		}
		Encode(Single_PrivateClass, Map, MapLatitude, 3, Length, Value);
		memset(Value, '\0', 15);
	}
//	ReadyTransmit();

//	printf("Encode Now!!!!!!!!!!!!!!!!!!!!!!!!");
//	Decode(SendData, DataLength);
	
}