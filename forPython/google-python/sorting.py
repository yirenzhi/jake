#! /usr/bin/env python
# -*- encoding=utf-8 -*-
a=[6,4,8,9,3]
#sorted 返回列表不改变自身，sort无返回值，改变自身
print sorted(a)
print a
print a.sort()
print a

strs=['aa','bb','zz','CC']
print sorted(strs)
print sorted(strs,reverse=True)


strs1=['aaaa','aaa','a','aa']
print sorted(strs1,key=len)


print sorted(strs,key=str.lower)


strs2=['bd','jn','ci','wo']
def fu1(s):
	return s[-1]
print sorted(strs2,key=fu1)
print sorted(strs2,key=(lambda x: x[-1]))


nums=[1,2,3,4]
squares=[a*a for a in nums]
print squares

#upper()大写，lower()小写
str3=['HEllo','world','nihao']
str4=[x.lower()+'!!!' for x in str3]
print str4