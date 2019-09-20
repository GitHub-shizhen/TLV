#include <stdio.h>
#include <iostream>
#include "TLV_ConstStatement.h"
#include "TLV_Encode.h"
#include "TLV_Decode.h"

void SendMap(void)
{
	unsigned char Value[10] = "";
	unsigned int Length = 0;
	printf("Please input Longitude:\nLongitude := ");
	scanf("%s", Value);
	for (int i = 0; i < 10; i++)
	{
		if (0x00 == Value[i])
		{
			Length = i;
			break;
		}
	}
	Encode(SINGLE_PRIVATECLASS, MAP, MAPLONGITUDE, 4, Length, Value);
	memset(Value, '\0', 10);


	printf("Please input Latitude:\nLatitude := ");
	scanf("%s", Value);
	for (int i = 0; i < 10; i++)
	{
		if (0x00 == Value[i])
		{
			Length = i;
			break;
		}
	}
	Encode(SINGLE_PRIVATECLASS, MAP, MAPLATITIUDE, 4, Length, Value);
	memset(Value, '\0', 10);
}

void SendSensor(void)
{
	unsigned char Value[10] = "";
	unsigned int Length = 0;
	static unsigned int DataTotalLength = 0;
	Encode(MIXTURE_PRIVATECLASS, SENSOR, 0x00, 3, 0x00, 0x00);								//发送混合私有类的编码头
	printf("Please input Sensor Upper Limit:\nUpper Limit := ");
	scanf("%s", Value);
	for (int i = 0; i < 10; i++)
	{
		if (0x00 == Value[i])
		{
			Length = i;
			break;
		}
	}
	DataTotalLength = Length;
	Encode(SINGLE_PRIVATECLASS, 0x00, SENSOR_UPPERLIMIT, 3, Length, Value);
	memset(Value, '\0', 10);


	printf("Please input Sensor Lower Limit:\nLower Limit := ");
	scanf("%s", Value);
	for (int i = 0; i < 10; i++)
	{
		if (0x00 == Value[i])
		{
			Length = i;
			break;
		}
	}
//	printf("Length is:%d", Length);
	DataTotalLength += Length;
	Encode(SINGLE_PRIVATECLASS, 0x00, SENSOR_LOWERLIMIT, 3, Length, Value);
	memset(Value, '\0', 10);
	Encode(0x00, 0x00, 0x00, 0x00, DataTotalLength, 0x00);                                //发送完成混合私有类编码的标志
	DataTotalLength = 0;
}

int main(void)
{
	char SendPermission = 'n';
	
	printf("***********************************************************************************\n");
	printf("**********           TLV Encode / Decode Demo                            **********\n");
	printf("**********                                          Edition : C          **********\n");
	printf("**********                                          Author : LUO         **********\n");
	printf("***********************************************************************************\n\n");

    printf("Transmit Map Coordinate ? (Please input y or n)\n");
	scanf("%c", &SendPermission);
	if ('y' == SendPermission)
	{
		SendMap();
		SendPermission = 'n';
	}

	printf("Transmit Sensor Coordinate ? (Please input y or n)\n");
	if (13 == getchar());                                                      //不加这句，上面的输入回车会被下面的scanf识别，无法正常输入
	scanf("%c", &SendPermission);
	if ('y' == SendPermission)
	{
		SendSensor();
		SendPermission = 'n';
	}
	
	Transmit();                                                               //子编码完成后统一发送编码集合

	printf("Encode Now!!!!!!!!!!!!!!!!!!!!!!!!\n");
	Decode(Transmit_data, DataLength);

}