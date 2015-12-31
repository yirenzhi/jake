#!encoding=utf-8
# m=[]
# for x in range(100,1000):
# 	m.append(x/53+x%53)
 
# print "最大值为：",max(m)


def Test():
	list1=range(1,501)
	
	n=0
	while len(list1)>2:
		i=1
		m=len(list1)
		print "m=",m
		while 3*i-1<m:
			del list1[3*i-1-i+1-n]
			i+=1
		n=(m+n)%3
		print "n=",n
		print "len:",len(list1)
	if n==0 or n==1:
		del list1[0]
	elif n==2:
		del list1[1]
	print(list1)

def ageAcout():
	for x in range(1,63):
		for y in range(1,63):
			for z in range(1,63):
				if(x*y*z==2450 and x+y+z==64):
					print x,y,z

#ageAcout()
Test()