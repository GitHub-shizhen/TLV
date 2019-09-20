import ConstStatement

class TLV_Encode():
    Data = []
    InsertIndex = 0
    vectorLength = 0
#    InsertIndex

    def Encode(self, Class, SubClass, Tag, Length, Value):
        if(ConstStatement.MIXTURE_PRIVATECLASS == Class):
            self.Data.append(ConstStatement.MIXTURE_PRIVATECLASS)
        elif (ConstStatement.SINGLE_PRIVATECLASS == Class):
            self.Data.append(ConstStatement.SINGLE_PRIVATECLASS)
        elif (0x00 == Class):
            self.Data.insert(self.InsertIndex, 6 + Length)
            self.InsertIndex = 0

        if(ConstStatement.MAP == SubClass):
            self.Data.append(ConstStatement.MAP)
        elif(ConstStatement.SENSOR == SubClass):
            self.Data.append(ConstStatement.SENSOR)

        if(ConstStatement.MAPLATITIUDE == Tag):
            self.Data.append(ConstStatement.MAPLATITIUDE)
        elif(ConstStatement.MAPLONGITUDE == Tag):
            self.Data.append(ConstStatement.MAPLONGITUDE)
        elif(ConstStatement.SENSORUPPERLIMIT == Tag):
            self.Data.append(ConstStatement.SENSORUPPERLIMIT)
        elif(ConstStatement.SENSORLOWERLIMIT == Tag):
            self.Data.append(ConstStatement.SENSORLOWERLIMIT)
        elif(0x00 == Tag):
            if(0x00 != Class):
                self.InsertIndex = len(self.Data)

        if(0x00 != Length and 0x00 != Class):
            self.Data.append(Length)
            for i in Value:
#                print('%X'%ord(i))
                self.Data.append(ord(i))
#                print("Value`s content is : %X"%int(i))
        self.vectorLength = len(self.Data)

    def Transmit(self):
        print("Encode data is: ")
        for i in self.Data:
            print('%X'% i,end=" ")
        print()


