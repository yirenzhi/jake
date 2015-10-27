#! /usr/bin/env python
# -*- coding:utf-8 -*-

from types import MethodType
class Student(object):
	pass

s = Student()
s.name = 'Michael'
print s.name

def set_age(self,age):
	self.age=age
#给实例绑定一个方法
s.set_age = MethodType(set_age,s,Student)
s.set_age(25)
print s.age

#对class绑定方法
def set_score(self,score):
	self.score=score

Student.set_score=MethodType(set_score,None,Student)
s2=Student()
s2.set_score(99)
print s2.score

#使用slot可以限制class的属性
class People(object):
	__slots__=('name','age')

p1=People()
p1.name='a'
#p1.abc='kk'


class Flower(object):
	def get_score(self):
		return self._score
	def set_score(self,value):
		if not isinstance(value,int):
			raise ValueError('score must be an integer!')
		if value<0 or value>100:
			raise ValueError('score must between 0~100')
		self._score=value

f1=Flower()
f1.set_score(60)
print f1.get_score()
#f1.set_score(200)

'''
@property的实现比较复杂，我们先考察如何使用。把一个getter方法变成属性，只需要加上@property就可以了，此时，
@property本身又创建了另一个装饰器@score.setter，负责把一个setter方法变成属性赋值，于是，我们就拥有一个可控的属性操作
'''
class Plant(object):
	@property
	def score(self):
	    return self._score

	@score.setter#负责把一个setter方法变成属性赋值，于是，我们就拥有一个可控的属性操作
	def score(self,value):
		if not isinstance(value,int):
			raise ValueError('score must be an integer!')
		if value<0 or value>100:
			raise ValueError('score must between 0~100')
		self._score=value

p1=Plant()
p1.score=88
print p1.score
#把方法直接变成属性，对实例进行操作时可以直接使用类似直接调属性其实是调用方法，既保证了安全性，同时保持了调用的方便真是精彩！！！


#多重继承
class Animal(object):
	pass

class Mammal(object):
	pass

class Bird(object):
	pass

class Dog(Mammal):
	pass

class Bat(Mammal):
	pass

class Parrot(Bird):
	pass

class Ostrich(Bird):
	pass

class Runnable(object):
	def run(self):
		print 'Running...'

class Flyable(object):
	def fly(self):
		print 'Fly...'

class Dog(Mammal,Runnable):
	pass

class Bat(Mammal,Flyable):
	pass

print dir(Bat)
#定制类
#__str__
class File(object):
	def __init__(self,name):
		self.name=name
	def __str__(self):
		return 'File object (name:%s)'%self.name
print Bat()
print File("abc")

#__repr__()是为调试服务的

'''
_iter__

如果一个类想被用于for ... in循环，类似list或tuple那样，就必须实现一个__iter__()方法，
该方法返回一个迭代对象，然后，Python的for循环就会不断调用该迭代对象的next()方法拿到循环的下一个值，
直到遇到StopIteration错误时退出循环。
我们以斐波那契数列为例，写一个Fib类，可以作用于for循环：
'''
class Fib(object):
	def __init__(self):
		self.a,self.b=0,1#初始化两个计数器
	def __iter__(self):
		return self  #实例本身就是迭代对象，故返回自己
	def next(self):
		self.a,self.b=self.b,self.a+self.b 
		if self.a>10000:
			raise StopIteration()
		return self.a 

for n in Fib():
	if n<100:
		print n

		
#__getitem__()像list那样按照下标取出元素
class Fib(object):
	def __getitem__(self,n):
		a,b=1,1 
		for x in range(n):
			a,b=b,a+b 
		return a 

f=Fib()

print f[10]

class Fib(object):
	def __getitem__(self,n):
		if isinstance(n,int):
			a,b=1,1 
			for x in range(n):
				a,b=b,a+b 
			return a 
		if isinstance(n,slice):#输入的参数是切片
			start = n.start
			stop =n.stop
			a,b=1,1 
			L=[]
			for x in range(stop):
				if x>=start:
					L.append(a)
				a,b=b,a+b 
			return L


f=Fib()
print f[5:7]

#__getattr__  可以用来动态返回属性或函数

class Mm(object):
	def __init__(self):
		self.name='Maichael'
	def __getattr__(self,attr):
		if attr=='score':
			return 99
		elif attr=='age':
			return lambda:25
		raise AttributeError('\'Mm\'object has no attribute \'%s\'' % attr)

m1=Mm()
print m1.name
print m1.score
print m1.age()
#print m1.b

class Chain(object):
	def __init__(self,path=''):
		self._path = path
	def __getattr__(self,path):
		return Chain('%s/%s'%(self._path,path))
	def __str__(self):
		return self._path

print Chain().status.user.timeline.list


#__call__()函数可以将实例化作函数

class Kklt(object):
	def __init__(self,name):
		self.name = name 
	def __call__(self):
		print ('My name is %s.'%self.name)

k1 = Kklt('kklt')
k1()

#callable判断对象是否能被调用callable()
print callable(k1)
print callable([1,2,3])

















