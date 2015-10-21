#！encoding=utf-8
print('I\'m\"OK\"')
print("I\'m\"OK\"")
print r'\\\\\\\\'#当\为单数时有问题！！
print '''line1
line2
line3'''
print 10/3
print 10.0/3
print 10%3
print '中文'
print len(u'中文')
print len(u'中文'.encode('utf-8'))
print 'Hi,%s,you have $%d.'%('Michael',100000)