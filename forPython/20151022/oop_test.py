#!/usr/bin/env python
# -*- coding: utf-8 -*-

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


stu1=Student('kk',99)
stu2=Student('mm',9)
stu1.print_score()
stu2.print_score()

class People(object):
	pass


bart= People()
print bart
print People
bart.name = 'Bart Simpson'
print bart.name

		

