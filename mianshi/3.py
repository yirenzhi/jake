def startgame():
#接受输入数据
    l1=[]
    while(1):
        b=input()
        l1.append(b)
        if(b=="0"):
            break

#计算结果
    min= 1
    max=10
    for a in l1:
        if(a=="0"):
            return
        elif(a.isdigit()):
            num=int(a)
        elif(a=="too low"):
            min=num
        elif(a=="too high"):
            max=num
        elif(a=="correct"):
            if(num>min and num<max):
                print("maybe")
            else:
                print("yes")

startgame()