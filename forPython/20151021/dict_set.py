#!encoding=utf-8
#python中{}表示字典dict    []表示列表list  ()表示元组tuple 所指向的内容不可更改

d={'Michael':95,'Bob':75,'Tracy':85}
print d['Michael']
print d.get('Michael',-1)
print d.get('Tom',-1)

print d
d.pop('Bob')
print d


'''
set和dict类似，也是一组key的集合，但不存储value。由于key不能重复，所以，在set中，没有重复的key。

要创建一个set，需要提供一个list作为输入集合：
'''

s=set([1,2,3])
print s
#重复元素回被删除
m=set([1,1,2,2,3,3])
print m
m.add(4)
print m
m.remove(4)
print m


#set可以看成数学意义上的无序和无重复元素的集合，因此，两个set可以做数学意义上的交集、并集等操作：


s1=set([1,2,3])
s2=set([2,3,4])
print s1&s2 
print s1|s2 


x=(1,2,3)
m.add(x)
print m


