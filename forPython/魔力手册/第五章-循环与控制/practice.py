#1.设计一个这样的函数，在桌面新建十个文件并以数字命名
def create_file():
    for i in range(1, 11):
        filename='/home/zhoud/Desktop/' + str(i) + ".txt"
        fp = open(filename, "w")
        fp.close()
    print("Done")

#create_file()

def count_money(amount, rate, time):
    print("amount is "+str(amount))
    lilv = rate+1
    money = amount
    for i in range(1, time+1):
        money *= lilv
        print("year {}:  ${}".format(i,money))

count_money(100, 0.05, 8)