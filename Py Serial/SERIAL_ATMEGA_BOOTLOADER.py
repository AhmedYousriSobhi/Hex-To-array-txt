import serial
import serial.tools.list_ports
from TXT_FILE_HANDLER import *
#--------------------------------------------#
ser = serial.Serial()
#*******COM PORT FUNCTIONS********#        
def comConfig():
    print(50*'-',"\n\t",ser.port, "C O N F I G  B O A R D\n")
    while True:
        cmd= input("\nPY_DEBUG: COMMAND LIST:\
                    \n\tCHANGE_COM : TO CHANGE COM PORT.\
                    \n\tCHANGE_BAUD : TO CHANGE BAUDRATE.\
                    \n\tRETURN : TO RETURN TO MAIN MENUE.\
                    \n\nYOUR COMMAND IS : ")
        if cmd == "CHANGE_COM":
            ser.port = input("PY_DEBUG: ENTER COM NUMBER : ")
        elif cmd == "CHANGE_BAUD":
            ser.baudrate = int(input("PY_DEBUG: ENTER BAUDRATE : "))
        elif cmd == "RETURN":
            break;
        else:
            print("PY_DEBUG: UNDEFINED COMMAND!!")
#--------------------------------------------#
#*******USART FUNCTIONS********#
def waitForDataRecieve():
    print("PY_DEBUG: WAITING TO RECIEVE DATA")
    while ser.in_waiting == 0:
       pass
def read_string():
    waitForDataRecieve()
    while ser.in_waiting !=0:
        print(ser.read_until())
        
def read_byte():
    waitForDataRecieve()
    print(ser.read())
#--------------------------------------------#            
#*******BOOTLOADER FUNCTIONS********#
def BLD_CMD_LIST():
    print("PY_DEBUG: BLD COMMANDS LIST CMD IS SENT")
    ser.write('A'.encode('ascii'))
    read_string()

def BLD_CMD_FLASH():
    print("PY_DEBUG: BLD FLASH APP CODE CMD IS SENT")
    ser.write('F'.encode('ascii'))
    read_string()
    print("PY_DEBUG: BOOTLOADER IS OUT OF COMMUNICATION")
    read_string()
    
def BLD_CMD_UPLOAD():
    print("PY_DEBUG: BLD UPLOAD NEW COMMAND IS SENT")
    ser.write('U'.encode('ascii'))
    read_string()
    i = 0
    app_code = TXT_FILE_READ()
    BytesInPage = 128
    CODE_SIZE = len(app_code)
    NumOfPage = CODE_SIZE // BytesInPage
    print("PY_DEBUG: CODE SIZE = ",CODE_SIZE," , Num of Page = ", NumOfPage)
    ser.write(str(NumOfPage).encode('ascii'))
    while i<CODE_SIZE:
        ser.write(app_code[i])
        #read_string()
        print(i)
        i=i+1
    read_string()
    
def comBoard():
    print(50*'-',"\n\t",ser.port, "S E R I A L  B O A R D\n")
    print("PY_DEBUG: RESET THE MCU")
    read_string()
    while True:
        
        cmdB = input("\nPY_DEBUG: COMMAND LIST:\
                      \n\tBLD_LIST : TO SEE BLD LIST COMMAND.\
                      \n\tBLD_FLASH : TO FLASH APP CODE FROM BLD COMMAND.\
                      \n\tBLD_UPLOAD : TO UPLOAD NEW APP CODE BYTES TO BLD.\
                      \n\tRETURN : TO RETURN TO MAIN MENUE.\
                      \n\nYOUR COMMAND IS: ")
        if cmdB == "BLD_LIST":
            BLD_CMD_LIST()
        elif cmdB == "BLD_FLASH":
            BLD_CMD_FLASH()
        elif cmdB == "BLD_UPLOAD":
            BLD_CMD_UPLOAD()
        elif cmdB == "RETURN":
            break

          
#--------------------------------------------#
#*********PORT CONFIGURATION**************#
# if this the main py file to run ,
# so if another program run , it will not run the code inside this if.          
if __name__ == '__main__':
    ports = serial.tools.list_ports.comports()
    print("PY_DEBUG: LIST OF CONNECTED COM PORTS :")
    for port, desc, hwid in sorted(ports):
            print("{}: {} [{}]".format(port, desc, hwid))
            
    keyword_com = 'COM'

    while True:
        ser.port = input("PY_DEBUG: ENTER COM NUMBER : ")
        if keyword_com in ser.port :
            break;

    ser.baudrate = int(input("PY_DEBUG: ENTER BAUDRATE : "))
    ser.close()
    print("PY_DEBUG : SERIAL PORT :\n", ser)
    #Get Command From User.
    cmd = '0'
    while(1):
        print(50*'-','\n\t\tM A I N  M E N U E\n')
        cmd= input("\nPY_DEBUG: COMMAND LIST:\
                    \n\tOPEN_PORT : TO OPEN COM PORT SELECTED.\
                    \n\tCLOSE_PORT : TO CLOSE COM PORT.\
                    \n\tCONFIG_COM : TO CHANGE COM PORT.\
                    \n\tCMD : TO SEND MANUAL COMMAND.\
                    \n\nYOUR COMMAND IS : ")
        if cmd == "OPEN_PORT" :
            ser.open()
            print("PY_DEBUG: COM PORT IS OPENED? ", ser.is_open)
            comBoard()
        elif cmd == "CLOSE_PORT":
            ser.close()
            print("PY_DEBUG: COM PORT IS CLOSED? ", not ser.is_open)
        elif cmd == "CONFIG_COM":
            print("PY_DEBUG: ENTERING CONFIGURATION COM BOARD.")
            comConfig()
        elif cmd == "CMD":
            co = input("ENTER COMMAND: ")
            ser.write(bytearray.fromhex(co))
            read_string()
        else:
            print("PY_DEBUG: UNDEFINED COMMAND.")
