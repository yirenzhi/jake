import string
path = './Walden1.txt'

'''
with open(path,'r') as text:
    words = text.read().split()
    print(words)
    for word in words:
        print('{}-{} times'.format(word,words.count(word)))
'''

#增加了预处理，有些单词被处理了几遍，开头大写的单词被单独处理了，一些带标点的单词被单独统计了
'''
string.punctuation表示所有的标点符号，strip()表示从两边删除参数里的字符，默认为空格
'''
with open(path, 'r') as text:
    words = [raw_word.strip(string.punctuation).lower() for raw_word in text.read().split()]
    words_index = set(words)
    counts_dict = {index:words.count(index) for index in words_index}
print('------')
for word in sorted(counts_dict, key=lambda x: counts_dict[x], reverse=True):
    print('{}-{} times'.format(word, counts_dict[word]))
