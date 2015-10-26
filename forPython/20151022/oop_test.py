#!/usr/bin/env python
# -*- coding: utf-8 -*-
import types
'a test class'

std1 = {'name': 'Michael','score':98}
std2 = {'name': 'Bob','score':88}

def print_score(std):
	print '%s:%s' %(std['name'],std['score'])

print_score(std1)
print_score(std2)

class Student(object):
	"""docstring for Student"""
	def __init__(self, name,score):
		self.name = name
		self.score = score
	def print_score(self):
		print '%s:%s' %(self.name,self.score)
	def get_grade(self):
		if self.score >= 90:
			return 'A'
		elif self.score >= 60:
			return 'B'
		else:
			return 'C'


stu1=Student('kk',99)
stu2=Student('mm',9)
stu1.print_score()
stu2.print_score()
print stu1.get_grade()
print stu2.get_grade

class People(object):
	def __init__(self,name):
		self.__name=name


bart= People('abc')
print bart
print People
bart.__name = 'Bart Simpson'
print bart.__name
bart.__name = 'Aart Simpson'
print bart.__name


#'''#
#私有变量在属性前加__，（两个_)
class Student1(object):
	"""docstring for Student1"""
	def __init__(self, name, score):
		super(Student1, self).__init__()
		self.__name = name
		self.__score = score
	def print_score(self):
		print ('name=%s score=%s')%(self.__name,self.__score)

#'''#

		
class Animal(object):
	def run(self):
		print 'Animal is running...'

class Dog(Animal):
	def run(self):
		print 'Dog is running...'

class Cat(Animal):
	def run(self):
		print 'Cat is running...'

class Tortoise(Animal):
	def run(self):
		print 'Tortoise is running slowly...'

dog=Dog()
dog.run()

cat=Cat()
cat.run()

def run_twice(animal):
	animal.run()
	animal.run()

tortoise=Tortoise()

run_twice(dog)
run_twice(cat)
run_twice(tortoise)

print type(123)

print type('abc')==types.StringType
print type(u'abc')==types.UnicodeType
print type([])==types.ListType
print type(str)==types.TypeType
#最后注意到有一种类型就叫TypeType，所有类型本身的类型就是TypeType

print isinstance('a',str)
print isinstance(u'a',unicode)
print isinstance('a',unicode)

print isinstance('a',(str,unicode))
print isinstance(u'a',(str,unicode))

print dir(stu1)

#仅仅把属性和方法列出来是不够的，配合getattr()、setattr()以及hasattr()，我们可以直接操作一个对象的状态：
class Myobject(object):
	def __init__(self):
		self.x=9
	def power(self):
		return self.x*self.x

obj = Myobject()
print hasattr(obj,'x')
print hasattr(obj,'y')
setattr(obj,'y',25)
print hasattr(obj,'y')
print getattr(obj,'y') 

