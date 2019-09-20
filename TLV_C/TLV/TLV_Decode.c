#include <stdio.h>
#include "TLV_ConstStatement.h"



unsigned int MapDecode(const unsigned int *Data)
{
	
	if (MapLatitude == *Data)
	{
		printf("MapLatitude is: ");
		for (int i = 0; i < *(Data + 1); i++)
		{
			printf("%s", *(Data + 2 + i));
		}
		printf("\n");
	}
	if (MapLongitude == *Data)
	{
		printf("MapLongitude is: ");
		for (int i = 0; i < *(Data + 1); i++)
		{
			printf("%s", *(Data + 2 + i));
		}
		printf("\n");
	}
	return (*(Data + 1) + 4);
}

int result(int numTag, const unsigned int *Data)
{
	int num = 0;
	if (3 == numTag)
	{
		if (Map == *Data)
		{
			num = MapDecode(Data + 1);
		}
	}
	return num;   
}


void Decode(const unsigned int *Data, const unsigned int Length)
{
	int count = 0;
	for (int i = 0; i < Length; )
	{

		switch (*Data)
		{
			case Mixture_PrivateClass:
				if (*(Data + 1) > 0x80)
				{
					count = result(3, ( Data + 1 ));
					count = 4;
				}
				else
				{
					count = result(2, (Data + 1));
					count = 3;
				}
				break;
			case Single_PrivateClass:
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


