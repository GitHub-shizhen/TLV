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




