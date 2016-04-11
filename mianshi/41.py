'''

'''

#'''
with open('data.txt','r') as f1:
    l1=[int(a)for a in f1.read().split()]
l1.sort()
with open('result.txt','w') as f2:
    f2.write(" ".join( str(a) for a in l1))

#'''