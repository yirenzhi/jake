#!encoding=utf-8
age=20
if age >= 18:
	print 'your age is',age
	print 'adult'

age=3
if age>=18:
	print 'your age is',age
	print 'adult'
else:
	print 'your age is',age
	print 'teenager'

age=3
if age>=18:
	print 'your age is',age
	print 'adult'
elif age>=6:
	print 'your age is',age
	print 'teenager'
else:
	print 'your age is',age
	print 'kid'

print 1==True



#Python的循环有两种，一种是for...in循环，依次把list或tuple中的每个元素迭代出来，看例子：
print '-----------loop------------'
names=['Michael','Bob','Tracy']
for name in names:
	print name

sum=0
for x in (1,2,3,4,5,6,7,8,9,10):
	sum=sum+x
print sum

#如果要计算1-100的整数之和，从1写到100有点困难，幸好Python提供一个range()函数，
#可以生成一个整数序列，比如range(5)生成的序列是从0开始小于5的整数：

print range(5)

sum=0
for x in range(101):
	sum=sum+x
print sum

#第二种循环是while循环，只要条件满足，就不断循环，条件不满足时退出循环。
#比如我们要计算100以内所有奇数之和，可以用while循环实现：
sum=0
n=1
while (n<=99):
	sum=sum+n
	n=n+2
print sum

birth=input('birth')
print birth
if birth<2000:
	print '00前'
else:
	print '00后'



