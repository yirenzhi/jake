#! /usr/bin/env python
# -*- encoding:utf-8 -*-
import commands
print map(lambda x:x*x,[y for y in range(10)])

lst=[-1,1,-2,2]
lst1=list()
for i in range(len(lst)):
	if lst[i] > 0:
		lst1.append(lst[i])

print lst1

print filter(lambda x:x<0,lst)

def add(x,y):
	return x+y
print add('三角形的树','北极')


'''
使用迭代器的循环可以避开索引，但有时候我们还是需要索引来进行一些操作的。这时候内建函数enumerate就派上用场咯，它能在iter函数的结果前加上索引，以元组返回，用起来就像这样：
1
2
	
for idx, ele in enumerate(lst):
    print idx, ele
'''

for idx,ele in enumerate(range(1,6)):
	print idx,ele


def make_incrementor (n): 
	return lambda x:x+n
f=make_incrementor(10)
g=make_incrementor(20)
print f(5), g(5)

print make_incrementor(50)(60)

foo=[2,18,9,22,17,24,8,12,27]
print map(lambda x:x*2+10 ,foo)		#重复调用
print filter(lambda x:x%3==0,foo)	#重复掉用并判断返回值
print reduce(lambda x,y:x+y,foo)  #累加

#素数
num = range(2,50)
for i in range(2,8):
	num=filter(lambda x:x==i or x%i, num)
	print num
print num
num=range(2,50)

print map(lambda word:len(word),'It is raining cats and dogs'.split())

print map(lambda line:line.split()[2],commands.getoutput('mount -v').splitlines())