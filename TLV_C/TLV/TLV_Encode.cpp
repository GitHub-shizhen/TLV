#include <stdio.h>
#include <string.h>
#include <iostream>
#include "TLV_ConstStatement.h"
#include "TLV_Encode.h"

unsigned int *Transmit_data;
static unsigned int vectorLength = 0;
static unsigned int index = 0;
unsigned int DataLength = 0;

void Transmit()
{
	printf("Encode data is: ");
	for (int i = 0; i < vectorLength; i++)
	{
		printf("%X ", *(Transmit_data + i));		
	}
	printf("\n");
	DataLength = vectorLength;

//    free(Transmit_data);
}

/*
  HeadsLength 包括Class，SubClass，Tag和CodeLength的长度
  */
void Encode(const int Class, const int SubClass, const int Tag, const int HeadsLength,
	const int CodeLength, const unsigned char *Value)
{	
	static unsigned int InsertIndex = 0;
/*
 追加子编码单元，为统一发送编码集合做准备
*/
	if (0x00 != Class)
	{
		vectorLength += HeadsLength + CodeLength;
		if (0 == vectorLength)
		{
			Transmit_data = (unsigned int *)malloc(sizeof(unsigned int)*vectorLength);
			if (!Transmit_data)
			{
				printf("Not Enough Memory!\n");
				free(Transmit_data);
				exit(0);
			}
		}
		else
		{
			Transmit_data = (unsigned int *)realloc(Transmit_data, sizeof(unsigned int)*vectorLength);
			if (!Transmit_data)
			{
				printf("Not Enough Memory!\n");
				free(Transmit_data);
				exit(0);
			}
		}
	}


/*
 当混合私有类编码完成后，更新总的数据长度值
*/
	if (!Class)
	{
		*(Transmit_data + InsertIndex) = 6 + CodeLength;
		InsertIndex = 0;
	}



	for (; index < vectorLength; index++)
	{
		switch (Class)
		{
		case MIXTURE_PRIVATECLASS :
			*(Transmit_data + index) = MIXTURE_PRIVATECLASS;
			index++;
			break;
		case SINGLE_PRIVATECLASS :
			*(Transmit_data + index) = SINGLE_PRIVATECLASS;			
			index++;
			break;
		default:
			break;
		}
		
		switch (SubClass)
		{
		case MAP :
			*(Transmit_data + index) = MAP;
			index++;
			break;
		case SENSOR:
			*(Transmit_data + index) = SENSOR;
			index++;			
			break;
		default:
			break;
		}
		
		switch (Tag)
		{
		case MAPLATITIUDE:
			*(Transmit_data + index) = MAPLATITIUDE;
			index++;
			break;
		case MAPLONGITUDE:
			*(Transmit_data + index) = MAPLONGITUDE;
			index++;
			break;
		case SENSOR_UPPERLIMIT:
			*(Transmit_data + index) = SENSOR_UPPERLIMIT;
			index++;
			break;
		case SENSOR_LOWERLIMIT:
			*(Transmit_data + index) = SENSOR_LOWERLIMIT;
			index++;
			break;
		case 0x00 :
			if (0x00 != Class)
			{
				InsertIndex = index;
				index += 1;
			}
			break;
		default:
			break;
		}
		
		if (0x00 != CodeLength && 0x00 != Class)
		{
			*(Transmit_data + index) = CodeLength;
			index++;
			for (int i = 0; i < CodeLength; i++)
			{
				*(Transmit_data + index + i) = *(Value + i);
			}
			index += CodeLength;
		}		
	}
	index--;
	
}