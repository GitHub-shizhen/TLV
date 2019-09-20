from TLV_Encode import TLV_Encode
from TLV_Decode import TLV_Decode
import ConstStatement as Macro

DataTotalLength = 0

def SendMap():
#    Length = 0
    print("Please input Longitude: ")
    Value = input("Longitude := ")
    EncodeClass.Encode(Macro.SINGLE_PRIVATECLASS, Macro.MAP, Macro.MAPLONGITUDE,
                       len(Value), Value)
    print("Please input Latitude: ")
    Value1 = input("Latitude := ")
    EncodeClass.Encode(Macro.SINGLE_PRIVATECLASS, Macro.MAP, Macro.MAPLATITIUDE,
                       len(Value1), Value1)

def SendSensor():
    EncodeClass.Encode(Macro.MIXTURE_PRIVATECLASS, Macro.SENSOR, 0x00, 0x00, 0x00)
    print("Please input Sensor Upper Limit: ")
    Value = input("Upper Limit: ")
    DataTotalLength = len(Value);
    EncodeClass.Encode(Macro.SINGLE_PRIVATECLASS, 0x00, Macro.SENSORUPPERLIMIT,
                       len(Value), Value)
    print("Please input Sensor Lower Limit: ")
    Value1 = input("Lower Limit: ")
    DataTotalLength += len(Value1)
    EncodeClass.Encode(Macro.SINGLE_PRIVATECLASS, 0x00, Macro.SENSORLOWERLIMIT,
                       len(Value1), Value1)
    EncodeClass.Encode(0x00, 0x00, 0x00, DataTotalLength, 0x00)

if  __name__ == "__main__" :
    SendPermission = "n"
    EncodeClass = TLV_Encode()
    DecodeClass = TLV_Decode()
    print("***********************************************************************************")
    print("**********           TLV Encode / Decode Demo                            **********")
    print("**********                                          Edition : Python     **********")
    print("**********                                          Author : LUO         **********")
    print("***********************************************************************************")
    SendPermission = input("Transmit Map Coordinate ? (Please input y or n)\n")
    if  'y' == SendPermission :
        SendMap()
        SendPermission = 'n'
    """
    SendPermission = input("Transmit Sensor Value Range ? (Please input y or n)\n")
    if 'y' == SendPermission:
        SendSensor()
        SendPermission = 'n'
    """
    EncodeClass.Transmit()

    DecodeClass.Decode(EncodeClass.Data, EncodeClass.vectorLength)
