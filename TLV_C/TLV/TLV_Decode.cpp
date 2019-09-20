#include <stdio.h>
#include "TLV_ConstStatement.h"



unsigned int MapDecode(const unsigned int *Data)
{

	if (MAPLATITIUDE == *Data)
	{
		printf("MapLatitude is: ");
		for (int i = 0; i < *(Data + 1); i++)
		{
			printf("%c", *(Data + 2 + i));
		}
		printf("\n");
	}
	if (MAPLONGITUDE == *Data)
	{
		printf("MapLongitude is: ");
		for (int i = 0; i < *(Data + 1); i++)
		{
			printf("%c", *(Data + 2 + i));
		}
		printf("\n");
	}
	return *(Data + 1);
}

unsigned int SensorDecode(const unsigned int *Data)
{
		if (SENSOR_UPPERLIMIT == *(Data + 2))
		{
			printf("SensorUpperlimit is: ");
			for (int i = 0; i < *(Data + 3); i++)
			{
				printf("%c", *(Data + 4 + i));
			}
			printf("\n");

		}
		int point = 4 + *(Data + 3);
		if (SENSOR_LOWERLIMIT == *(Data + point + 1))
		{
			printf("SensorLowerlimit is: ");
			for (int i = 0; i < *(Data + point + 2); i++)
			{
				printf("%c", *(Data + point + 3 + i));
			}
			printf("\n");

		}
		return *Data;
}

int result(int numTag, const unsigned int *Data)
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
	
}


void Decode(const unsigned int *Data, const unsigned int Length)
{
	int count = 0;
	for (int i = 0; i < Length; )
	{

		switch (*Data)
		{
		case MIXTURE_PRIVATECLASS:
			if (*(Data + 1) > 0x80)
			{
				count = result(3, (Data + 1));
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