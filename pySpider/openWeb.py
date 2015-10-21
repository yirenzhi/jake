#coding=utf-8
import webbrowser as web
import time
import sys
url='www.baidu.com'
while True:
	try:
		time.sleep(3)
		web.open(url)
	except KeyboardInterrupt:
		sys.exit('\nProcess aborted')
