#!encoding=utf-8
m=[]
for x in range(100,1000):
	m.append(x/53+x%53)
 
print "最大值为：",max(m)