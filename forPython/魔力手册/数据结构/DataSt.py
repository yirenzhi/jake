
#list
Weekday = ['Monday','Tuesday','Wednesday','Thursday','Friday']
print(Weekday[0])

all_in_list = [
	1,
	1.0,
	'a word',
	print(1),
	True,
	[1,2],
	(1,2),
	{'key':'value'}
]

#列表的增删改查
#增
fruit = ['pineapple','pear']
fruit.insert(1,'grape')
print(fruit)

fruit[0:0] = ['Orange']
print(fruit)

#删
fruit.remove('pear')
print(fruit)

fruit[0] = 'Grapefruit'
print(fruit)

del fruit[0:2]
print(fruit)

#Dictionary

dicty = {'A':'a','B':'b'}
print(dicty)
dicty['C']='c'
print(dicty)

dicty.update({'E':'e','F':'f'})
print(dicty)

del dicty['A']
