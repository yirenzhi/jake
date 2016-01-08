# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

# import scrapy
#
#
# class ScrapyItem(scrapy.Item):
#     # define the fields for your item here like:
#     # name = scrapy.Field()
#     pass


from scrapy import Item, Field
#定义实体类，继承自scrapy的Item类,index,url,name...是类变量，
用来存放一个字段信息

class Company(Item):
    index = Field()
    url = Field()
    name = Field()
    setup_time = Field()
    location = Field()
    status = Field()
    stage = Field()
    business = Field()
    sub_business = Field()
    info = Field()
    invest_demand = Field()
    invest_status = Field()






