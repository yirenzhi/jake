#!/usr/bin/env python
# -*- coding: utf-8 -*-

'a test module'

__author__ = 'zhoud'

'''
第1行和第2行是标准注释，第1行注释可以让这个hello.py文件直接在Unix/Linux/Mac上运行，第2行注释表示.py文件本身使用标准UTF-8编码；

第4行是一个字符串，表示模块的文档注释，任何模块代码的第一个字符串都被视为模块的文档注释；

第6行使用__author__变量把作者写进去，这样当你公开源代码后别人就可以瞻仰你的大名；
'''
import Image
import sys

def test():
	print __doc__   #文档注释
	args = sys.argv
	if len(args)==1:
		print 'hello world'
	elif len(args)==2:
		print 'hello %s' % args[1]
	else:
		print 'Too many argument'


#'''
try:
    import cStringIO as StringIO
except ImportError: # 导入失败会捕获到ImportError
    import StringIO
#'''

def _private_1(name):
	return 'Hello,%s' % name

def _private_2(name):
	return 'Hi,%s' % name

def greeting(name):
	if len(name)>3:
		return _private_1(name)
	else:
		return _private_2(name)
'''
我们在模块里公开greeting()函数，而把内部逻辑用private函数隐藏起来了，这样，
调用greeting()函数不用关心内部的private函数细节，这也是一种非常有用的代码封装和抽象的方法，即：

'''

def image_test():
	im=Image.open('test1.jpg')
	print im.format,im.size,im.mode
#	im.thumbnail((1200,800))
#	im.save('new1.png','PNG')
	print sys.path

if __name__ == '__main__':
	image_test()
