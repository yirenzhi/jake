#!/usr/bin/env python
# -*- coding: utf-8 -*-

from scrapy.selector import Selector
from scrapy.spider import CrawlSpider, Rule
from scrapy.linkextractors import LinkExtractor
# from Scrapy.items import Company
from Scrapy.Scrapy.items import Company

class JuziSpider(CrawlSpider):
    name = "juzi"                           #爬虫的名字，用来启动爬虫
    host = 'http://itjuzi.com'
    allowed_domains = ["itjuzi.com"]        #允许抓取的域名前缀
    start_urls = (
        'http://www.itjuzi.com/company',    #起始url，从这个url开始抓取，逐层跟进
    )
    #抓取程序会自动解析当前网页里符合以下规则的url，并自动跟进抓取，follow表示是否跟进，
    # callback表示抓取回来，做如何处理

    rules = (
        Rule(LinkExtractor(allow=('/company/\d+',)), callable='parse_company', follow=True),
        Rule(LinkExtractor(allow=('/company\?page=\d+',)), follow=True),
    )

    #以下是对抓取回来的内容做html解析，scrapy提供了selector，可以基于xpath提取相关数据
    #具体xpath语法比较琐碎，可以自行查阅相关资料
    def parse_company(self, response):
        d = {
            u'网址': 'url', u'公司': 'name', u'时间': 'setup_time', u'地点': 'location', u'状态': 'status',
            u'阶段': 'stage', u'行业': 'business', u'子行业': 'sub_business', u'简介': 'info'
        }
        # 创建对象选择器，用于从response(服务器端的响应，返回的数据)中提取数据
        selector = Selector(response)
        company = Company()
        # split是切割字符串,strip是去除字符串两端的空格，回车符
        index = response.url.split('/')[-1].strip()
        company['index'] = index

        '''
        实例
        以下实例展示了join()的使用方法：

        #!/usr/bin/python

        str = "-";
        seq = ("a", "b", "c"); # 字符串序列
        print str.join( seq );

        以上实例输出结果如下：

        a-b-c
        '''
        for i in range(10):
            path = "//[ul@class='detail-info']/li[" + str(i + 1) + "]"
            # selector 提供了 xpath 函数，通过xpath语法，可以提取html中的数据
            txt =
    # def parse(self, response):
    #     pass

