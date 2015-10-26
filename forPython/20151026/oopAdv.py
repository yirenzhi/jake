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
