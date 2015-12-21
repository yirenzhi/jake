

def temperature(c):
    f = c*9/5+32
    return(str(f) + "*F")

print(temperature(20))

#1.初级难度设计一个重量转换器，输入以"g"为单位的数字后转换为"kg"的结果
def gtokg(c):
    return (str(c/1000)+"kg")
print(gtokg(500))

#2.中级难度，设计一个求直角三角形斜边长的函数
def xiebian (a, b):
    return "The right triangle third side's length is "+str((a*a+b*b)**(1/2))
print(xiebian(3, 4))


#位置参数，关键词参数
def trapezoid_area1(base_up,base_down,height):
    return 1/2*(base_up+base_down)*height

print (trapezoid_area1(1,2,3))
print (trapezoid_area1(base_up=1,base_down=2,height=3))
#print (trapezoid_area1(base_up=1, base_down=2, 3))#为何我这样不对
print(trapezoid_area1(1, 2, height=3))

print('   *', '  * *', ' ***', '   |')
print('   *', '  * *', ' * * *', '   |', sep='\n')

#默认参数
def trapezoid_area2(base_up,base_down,height=3):
    return 1/2*(base_up+base_down)*height

print(trapezoid_area2(1, 2))

def text_create(name, msg):

    file_path = "./"+name+".txt"
    fp = open(file_path, "w")
    fp.write(msg)
    fp.close()
    print("Done")

def text_filter(word, censored_word='lame', changed_word='Awesome'):
    return word.replace(censored_word, changed_word)

def censored_text_create(name,msg):
    clean_msg=text_filter(msg)
    text_create(name, clean_msg)

#text_create("abc", "hello world")
censored_text_create('kkk', 'lame!lame!lame!')

