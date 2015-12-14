#! /usr/bin/env python
# -*- encoding=utf-8 -*-
dict1 = {}
dict1['a'] = 'alpha'
dict1['g'] = 'gamma'
dict1['o'] = 'omega'
print dict1

print dict1['a']

print dict1.keys()
print dict1.values()

#输出时，字符的调用
dict2={}
dict2['word']='garfield'
dict2['count']=88
print 'I am %(count)d years old,my name is %(word)s.'%dict2