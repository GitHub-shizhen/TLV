/*
 Visual Studio 2017 对C语言居然有无法设置宏定义的Bug， 没办法只能曲线救国，所以文件后缀只能使用cpp。但
 所有代码均是c的语句
*/
#ifndef TLV_CONSTSTATEMENT_H
#define TLV_CONSTSTATEMENT_H

constexpr auto MIXTURE_PRIVATECLASS = 0xFF;               
constexpr auto SINGLE_PRIVATECLASS = 0xDF;	
constexpr auto MAP = 0x81;
constexpr auto SENSOR = 0x70;

enum CodeType
{
	MAPLONGITUDE = 0x01,
	MAPLATITIUDE,
	SENSOR_UPPERLIMIT,
	SENSOR_LOWERLIMIT,
};

#endif // !TLV_CONSTSTATEMENT_H
