#!encoding=utf-8
import os
#切片
l=['a','b','c','d']
print l[0:3]
print l[-2:-1]

m=range(100)
print m[:10]
print m[-10:]

#前十个数，没两个取一个
print m[:10:2]
#所有数，每5个取一个
print m[::5]


#迭代即for循环

d={'a':1,'b':2,'c':3}
for key in d:
	print key

for ch in 'ABC':
	print ch

for x,y in [(1,2),(3,4),(5,6)]:
	print x,y

#裂表生成式
print range(1,11)
print [x*x for x in range(1,11)]
print [x*x for x in range(1,11) if x%2==0]
print [m+n for m in "ABC" for n in "DEF"]
print [d for d in os.listdir('.')]
L=['Hello','World','IBM','Apple']
print [s.lower() for s in L]



