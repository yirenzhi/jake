#!encoding=utf-8
import math
#调用函数

print abs(100)
print abs(-20)
print abs(12.34)

print cmp(1,2)
print cmp(2,1)
print cmp (3,3)

print int('123')
print int(12.34)
print float('12.34')
print str(1.23)
print unicode(100)
print bool(1)
print bool('')

a=abs
print a(-2)


#定义函数
def my_abs(x):
	if x>=0:
		return x
	if x<0:
		return -x

print my_abs(-9)

'''
如果想定义一个什么事也不做的空函数，可以用pass语句：

def nop():
    pass
pass语句什么都不做，那有什么用？实际上pass可以用来作为占位符，比如现在还没想好怎么写函数的代码，就可以先放一个pass，让代码能运行起来。
if age >= 18:
    pass
'''
age=15
if age>=18:
	pass

'''
当传入了不恰当的参数时，内置函数abs会检查出参数错误，而我们定义的my_abs没有参数检查，所以，这个函数定义不够完善。

让我们修改一下my_abs的定义，对参数类型做检查，只允许整数和浮点数类型的参数。数据类型检查可以用内置函数isinstance实现：

'''
print my_abs('A')
def my_abs_new(x):
	if not isinstance(x,(int,float)):
		raise TypeError('bad type')
	if x>=0:
		return x
	if x<0:
		return -x
#print my_abs_new('A')	参数类型错误

#返回多个值
def move(x,y,step,angle=0):
	nx = x + step * math.cos(angle)
	ny = y + step * math.sin(angle)
	return nx,ny

x,y = move(10,10,10,math.pi/6)
#其实是返回了一个tuple
r=move(10,10,10,math.pi/6)
print x,y
print r

#默认参数
def power(x):
	return x*x

print power(5)

#x^n
def power(x,n=2):
	s=1 
	while(n>0):
		s=s*x
		n=n-1
	return s 

print power(5,3)
print power(5)

def enroll(name,gender,age=6,city='Beijing'):
	print 'name', name
	print 'gender', gender
	print 'age',age
	print 'city',city

print enroll('zhoud',9)
print enroll('zhoud',9,city='anhui')


#定义可变参数和定义list或tuple参数相比，仅仅在参数前面加了一个*号。在函数内部，参数numbers接收到的是一个tuple，
#因此，函数代码完全不变。但是，调用该函数时，可以传入任意个参数，包括0个参数：
def calc(number):
	sum=0
	for x in number:
		sum=sum+x
	return sum 
print calc([1,2,3,4,5])

def calc_new(*number):
	sum=0
	for x in number:
		sum=sum+x
	return sum 
print calc_new(1,2,3,4,5,6)

nums=[1,2,3]
print calc_new(*nums)

#关键字参数传入dict
def person(name,age,**kw):
	print name,age,kw

person('zhoud',23)
person('zhoud',23,gender='M',job='Engineer')


'''
在Python中定义函数，可以用必选参数、默认参数、可变参数和关键字参数，这4种参数都可以一起使用，
或者只用其中某些，但是请注意，参数定义的顺序必须是：必选参数、默认参数、可变参数和关键字参数。
'''
def func(a,b,c=0,*d,**kw):
	print 'a=',a,'b=',b,'c=',c,'d=',d,'kw=',kw

func(1,2)
func(1,2,3)
func(1,2,3,4,5)

#amazing
a=(1,2,3,4)
b={'x':99}
func(*a,**b)

#递归函数
def fact(n):
	if n==1:
		return 1
	else:
		return n*fact(n-1)

print fact(5)




