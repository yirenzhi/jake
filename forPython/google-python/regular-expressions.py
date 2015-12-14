#! /usr/bin/env python
# -*- encoding=utf-8 -*-
import re
#正则表达式
'''
match = re.search(pat, str)
The re.search() method takes a regular expression pattern and a string and searches for that 
pattern within the string.If the search is successful, search() returns a match object or None otherwise. 
Therefore, the search is usually  immediately followed by an if-statement to test if the search succeeded, 
as shown in the following example which  searches for the pattern 'word:' followed by a 3 letter word (details below):
'''

str1='an example word:cat!!'
match =re.search(r'word:\w\w\w',str1)
if match:
	print 'found',match.group()
else:
	print 'did not find'


## Search for pattern 'iii' in string 'piiig'.
## All of the pattern must match, but it may appear anywhere.
## On success, match.group() is matched text

match1=re.search(r'iii','piiig')
print match1.group()
match2=re.search(r'igs','piiig')
print match2

## . = any char but \n
## .是任意字符除了\n
match3=re.search(r'..g','piiig')

print match3.group()

## \d = digit char, \w = word char
## \d是数字字符，\w是字母字符

match5=re.search(r'\d\d\d','p123g')
print match5.group()

match6=re.search(r'\w\w\w','@@abcd!!')
print match6.group()

#\s*匹配任意格空格

##Square brackets can be used to indicate a set of chars, so [abc] matches 'a' or 'b' or 'c'. 
##中括号匹配里面其中一个，[abc]匹配'a','b'或者'c'

#小括号可以用来匹配文本的部分内容，然后会保存在group中
str2='purple alice-b@google.com monkey dishwasher'
match6=re.search(r'([\w.-]+)@([\w.-]+)',str2)
print match6.group()
print match6.group(1)
print match6.group(2)


'''
findall

findall() is probably the single most powerful function in the re module. 
Above we used re.search() to find the first match for a pattern. findall() 
finds *all* the matches and returns them as a list of strings, with each string 
representing one match.
re.search()是查找第一个匹配的字符，findall()查找所有的匹配项,并返回列表
'''
str3='purple alice-b@google.com, blah monkey bob@abc.com blah dishwasher'
emails=re.findall(r'[\w.-]+@[\w.-]+',str3)
for m in emails:
	print m
print emails

#findall and Groups

tuples = re.findall(r'([\w.-]+)@([\w.-]+)',str3)
print tuples
