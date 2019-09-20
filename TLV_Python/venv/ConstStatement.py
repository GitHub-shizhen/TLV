class _const:
    class ConstError(TypeError):pass
    def __setattr__(self, name, value):
        if name in self.__dict__:
            raise self.ConstError("Can not rebind const (%s)"%name)
        self.__dict__[name]=value

import sys
from enum import Enum
sys.modules[__name__]=_const()

const = _const
const.MIXTURE_PRIVATECLASS = 0xFF
const.SINGLE_PRIVATECLASS = 0xDF
const.MAP = 0x81
const.SENSOR = 0x70

const.MAPLONGITUDE = 0x01
const.MAPLATITIUDE = 0x02
const.SENSORUPPERLIMIT = 0x03
const.SENSORLOWERLIMIT = 0x04
#TLV = Enum('TLV',('MAPLONGITUDE', 'MAPLATITIUDE', 'SENSOR_UPPERLIMIT', 'SENSOR_LOWERLIMIT'))