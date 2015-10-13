# -*- coding: UTF-8 -*-
import requests
import os
import urllib2
import urllib
content=""
def req_test():
	url = "http://v.youku.com/v_show/id_XMTM1NzQyMjkwMA==.html?from=s1.8-1-1.2"
	response = requests.get(url)
	content = requests.get(url).content #string

def urllib2_test():
	url = "http://v.youku.com/v_show/id_XMTM1NzQyMjkwMA==.html?from=s1.8-1-1.2"
	response = urllib2.urlopen(url)
	global content 
	content = urllib2.urlopen(url).read()  #string

def head_test():
	url = "http://www.baidu.com/s"
	data = {
		'wd':'python全局变量'
	}
	data = urllib.urlencode(data) #编码工作，由dict转为string
	full_url = url+'?'+data#GET请求发送
	print full_url
	global content
	content = urllib2.urlopen(full_url).read()

def post_test():
	url = "http://www.douban.com/"
	data = {
		'form_email':'328478762@qq.com',
		'form_password':'a19931015'
	}
	data = urllib.urlencode(data) #编码工作，由dict转为string
	req = urllib2.Request(url=url,data=data)
	global content
	content = urllib2.urlopen(req).read()


if __name__ == '__main__':
	post_test()
	fp = open("test.txt",'w')
	fp.write(content)
	fp.close()