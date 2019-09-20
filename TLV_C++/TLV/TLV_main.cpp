#include "pch.h"
#include <iostream>
#include "TLV_ConstStatement.h"
#include "TLV_Encode.h"
#include "TLV_Decode.h"

using namespace std;
TLV_Encode TLVEncode;
TLV_Decode TLVDecode;

void SendMap(void)
{
	unsigned char Value[10] = "";
	unsigned int Length = 0;
	cout << "Please input Longitude: \nLongitude := ";
	cin >> Value;
	for (int i = 0; i < 10; i++)
	{
		if (0x00 == Value[i])
		{
			Length = i;
			break;
		}
	}	
	TLVEncode.Encode(SINGLE_PRIVATECLASS, MAP, MAPLONGITUDE, Length, Value);
	memset(Value, '\0', 10);


	cout << "Please input Latitude: \nLatitude := ";
	cin >> Value;
	for (int i = 0; i < 10; i++)
	{
		if (0x00 == Value[i])
		{
			Length = i;
			break;
		}
	}
	TLVEncode.Encode(SINGLE_PRIVATECLASS, MAP, MAPLATITIUDE, Length, Value);
	memset(Value, '\0', 10);
}

void SendSensor(void)
{
	unsigned char Value[10] = "";
	unsigned int Length = 0;
	static unsigned int DataTotalLength = 0;
	TLVEncode.Encode(MIXTURE_PRIVATECLASS, SENSOR, 0x00, 0x00, 0x00);								//发送混合私有类的编码头
	cout<<"Please input Sensor Upper Limit:\nUpper Limit := ";
	cin >> Value;
	for (int i = 0; i < 10; i++)
	{
		if (0x00 == Value[i])
		{
			Length = i;
			break;
		}
	}
	DataTotalLength = Length;
	TLVEncode.Encode(SINGLE_PRIVATECLASS, 0x00, SENSOR_UPPERLIMIT, Length, Value);
	memset(Value, '\0', 10);


	cout<<"Please input Sensor Lower Limit:\nLower Limit := ";
	cin >> Value;
	for (int i = 0; i < 10; i++)
	{
		if (0x00 == Value[i])
		{
			Length = i;
			break;
		}
	}
	DataTotalLength += Length;
	TLVEncode.Encode(SINGLE_PRIVATECLASS, 0x00, SENSOR_LOWERLIMIT, Length, Value);
	memset(Value, '\0', 10);
	TLVEncode.Encode(0x00, 0x00, 0x00, DataTotalLength, 0x00);                                //发送完成混合私有类编码的标志
//	TLVEncode.Encode(0x00, 0x00, 0x00, 0x00, 0x00);
	DataTotalLength = 0;
}

int main(void)
{
	char SendPermission = 'n';	
	TLVEncode.ResetVector();
	cout << "***********************************************************************************" << endl;
	cout << "**********           TLV Encode / Decode Demo                            **********" << endl;
	cout << "**********                                          Edition : C++        **********" << endl;
	cout << "**********                                          Author : LUO         **********" << endl;
	cout << "***********************************************************************************" << endl;
	cout << "\n" << endl;
	cout << "Transmit Map Coordinate ? (Please input y or n)" << endl;
	cin >> SendPermission;
	if ('y' == SendPermission )
	{
		SendMap();
		SendPermission = 'n';	
	}

	cout << "Transmit Sensor Value Range ? (Please input y or n)" << endl;
	cin >> SendPermission;
	if ('y' == SendPermission)
	{
		SendSensor();
		SendPermission = 'n';
	}
	TLVEncode.ReadyTransmit();

	cout << "Encode Now!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	TLVDecode.Decode(TLVEncode.GetSendData(), TLVEncode.GetDataLength());
	
}