from bs4 import BeautifulSoup
import requests

url='https://cn.tripadvisor.com/Attractions-g60763-Activities-New_York_City_New_York.html'
wb_data=requests.get(url)
#print(wb_data.text)
soup = BeautifulSoup(wb_data.text,'lxml')
#title =
print(soup)