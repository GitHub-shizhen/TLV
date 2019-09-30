/*
 Visual Studio 2017 对C语言居然有无法设置宏定义的Bug， 没办法只能曲线救国，所以文件后缀只能使用cpp。但
 所有代码均是c的语句
*/
#ifndef TLV_CONSTSTATEMENT_H
#define TLV_CONSTSTATEMENT_H

#define	MIXTURE_PRIVATECLASS		0xFF
#define SINGLE_PRIVATECLASS		0xDF
#define	MAP				0x81
#define	SENSOR				0x70
/*
static const int MIXTURE_PRIVATECLASS = 0xFF;               
static const int SINGLE_PRIVATECLASS = 0xDF;	
static const int MAP = 0x81;
static const int SENSOR = 0x70;
*/

enum CodeType
{
	MAPLONGITUDE = 0x01,
	MAPLATITIUDE,
	SENSOR_UPPERLIMIT,
	SENSOR_LOWERLIMIT,
};

#endif // !TLV_CONSTSTATEMENT_H
