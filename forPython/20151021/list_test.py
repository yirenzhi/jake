#!encoding=utf-8
classmates=['Michael','Bob','Tracy']
print classmates
print len(classmates)
print classmates[0] 
print classmates[-1]
classmates.append('Adam')
print classmates
classmates.insert(1,'Jack')
print classmates
classmates.pop()
print classmates
classmates.pop(1)
print classmates
classmates[1]='Sarah'
print classmates


#-------tuple---------
'''
另一种有序列表叫元组：tuple。tuple和list非常类似，但是tuple一旦初始化就不能修改，比如同样是列出同学的名字：

>>> classmates = ('Michael', 'Bob', 'Tracy')
现在，classmates这个tuple不能变了，它也没有append()，insert()这样的方法。其他获取元素的方法和list是一样的，你可以正常地使用classmates[0]，classmates[-1]，但不能赋值成另外的元素。

不可变的tuple有什么意义？因为tuple不可变，所以代码更安全。如果可能，能用tuple代替list就尽量用tuple。

'''

tupleclass=('Michael','Bob','Tracy')

'''
所以，只有1个元素的tuple定义时必须加一个逗号,，来消除歧义：

>>> t = (1,)
>>> t
(1,)

'''

t=('A','B',['x','y'])
print t 
t[2][0]='X'
t[2][1]='Y'
print t
#此时的不变指的是指向的值不变，也就是指针不变

