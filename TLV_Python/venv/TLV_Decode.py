import ConstStatement

class TLV_Decode:


    def result(self, Message):
        num = 0
        for i in range(0, len(Message)):
            if (ConstStatement.MAP == Message[i - 1]):
                Message.remove(Message[0])
#                print(Message)
                self.MapDecode(Message)
            if (ConstStatement.SENSOR == Message[i - 1]):
                Message.remove(Message[0])
                self.SensorDecode(Message)

    def MapDecode(self, Message):
#        for i in range(0, len(Message)):
#        print("Execute MapDecode")
        if (ConstStatement.MAPLONGITUDE == Message[0]):
            print("MapLatitude is:", end=" ")
#            print("Message Length: %X"%Message[1])
            for j in range(Message[1]):
                print(chr(Message[2 + j]), end="")
            print()

        elif (ConstStatement.MAPLATITIUDE == Message[0]):
            print("MapLongitude is:", end=" ")
            for j in range(Message[1]):
                print(chr(Message[2 + j]), end="")
            print()


    def Decode(self, Message, Length):
        Data = []
        i = 0
        """
        for i in range(Length):
            Data.append(Message[i])
           
            if (i < (Length - 2)):
                if (ConstStatement.SINGLE_PRIVATECLASS == Message[i + 1]):
                    Data.remove(Data[0])
                    self.result(Data)
                    Data.clear()
                if (ConstStatement.MIXTURE_PRIVATECLASS == Message[i + 1]):
                    Data.remove(Data[0])
                    self.result(Data)
                    Data.clear()
        if (ConstStatement.SINGLE_PRIVATECLASS == Data[0]):
            Data.remove(Data[0])
            self.result(Data)
            Data.clear()
        elif (ConstStatement.MIXTURE_PRIVATECLASS == Data[0]):
            Data.remove(Data[0])
            self.result(Data)
            Data.clear()
        """
        print("Length is: %d"%Length)
        while (i < Length):
            print('HEAD is: %X'%Message[i])
            if (ConstStatement.SINGLE_PRIVATECLASS == Message[i]):
                if (ConstStatement.MAP == Message[1 + i]):
                    Data.append(Message[2 + i])
                    Data.append(Message[3 + i])
                    for i in range(Message[3 + i]):
                        Data.append(Message[4 + i])
                    self.MapDecode(Data)
                    print(Data)
                    print("Message[3 + i] is: %d"%Message[3 + i])
                    i = 4 + Message[3 + i]
                    Data.clear()
            print("i is: %d"%i)
#        for i in Message:

