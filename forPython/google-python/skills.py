#! /usr/bin/env python
# -*- encoding=utf-8 -*-

#1. 字典推导(Dictionary comprehensions)和集合推导(Set comprehensions)
some_list=[1,2,3,4,5]
another_list=[x+1 for x in some_list]
print another_list

list1=[1, 2, 3, 4, 5, 2, 5, 1, 4, 8]
set1={x for x in list1 if x%2==0}
print set1

d={x:x%2==0 for x in range(1,11)}
print d


#2.计数时使用Counter计数对象。Python的collections类库里有个内置的dict类的子类，是专门来干这种事情的：
from collections import Counter 
c=Counter('hello world')
print c


#3. 漂亮的打印出JSON   为了能让JSON数据表现的更友好，我们可以使用indent参数来输出漂亮的JSON。当在控制台交互式编程或做日志时，这尤其有用：

import json
data={"status": "OK", "count": 2, "results": [{"age": 27, "name": "Oz", "lactose_intolerant": True}, {"age": 29, "name": "Joe", "lactose_intolerant": False}]}
print(json.dumps(data))
print(json.dumps(data,indent=2))


#4. 创建一次性的、快速的小型web服务




