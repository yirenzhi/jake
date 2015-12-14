import urllib.request
'''
f=urllib.request.urlopen('http://www.baidu.com/')
print(f.read(300).decode('utf-8'))

req=urllib.request.Request(url='http://localhost/test.cgi',data=b'This data is passed to stdin of the CGI')
m=urllib.request.urlopen(req)
print(m.read().decode('utf-8'))
'''

DATA = b'some data'
req2=urllib.request.Request(url='http://www.baidu.com/',data=DATA,method='PUT')
c=urllib.request.urlopen(req2)
print (c.status)
print (c.reason)