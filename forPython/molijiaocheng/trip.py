from bs4 import BeautifulSoup
import requests

url='https://cn.tripadvisor.com/Attractions-g60763-Activities-New_York_City_New_York.html'
wb_data=requests.get(url)
#print(wb_data.text)
soup = BeautifulSoup(wb_data.text,'lxml')
#title =soup.select('#ATTR_ENTRY_105127 > div.property_title > a')
titles=soup.select('div.property_title')
imgs=soup.select('img[width="160"]')
spans=soup.select('div.p13n_reasoning_v2')
#print(titles,imgs,spans)
for title,img,span in zip(titles,imgs,spans):
	data={
	'title':title.get_text(),
	'img':img.get('src'),
	#'span':span.get_text(),
	'span':list(span.stripped_strings),

	}
	print(data)
