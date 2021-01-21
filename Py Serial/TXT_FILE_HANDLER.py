def TXT_FILE_READ():
    while True:
        file_name = input("PY_DEBUG: ENTER TXT FILE NAME LIKE 'text.txt' : ")
        if ".txt" in file_name:
            break
    text = open(file_name)
    # Creating void array:
    app_code_list=[]
    #BytesInPage=128
    index = 1
    counter = 0
    while True:
        temp = text.read(index)
        if( temp.isnumeric()): #to collect hex
            text.read(index)
            temp=text.read(index)
            temp+=text.read(index)
            app_code_list.append(temp)
        elif (temp == ';'):
            break
    #print(app_code)
    for i in range(0,len(app_code_list)):
        app_code_list[i] = (bytearray.fromhex(app_code_list[i]))
    
    print(app_code_list)    
    #print(type(app_code_list[0]))
    #CODE_SIZE = len(app_code_list)
    #print("CODE SIZE = ",CODE_SIZE," , Num of Page = ", NumOfPage)
    print("PY_DEBUG: CLOSING FILE.")
    print(text.close())
    return app_code_list

