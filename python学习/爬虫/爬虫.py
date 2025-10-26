import requests
# 基本使用
# # import requests
# # #找到目标url
# # url='http://www.baidu.com'
# # #发送请求
# # response=requests.get(url)
# # #打印响应
# # print(response.content.decode('utf= 8'))
url=('https://ts1.tc.mm.bing.net/th/id/R-C.987f582c510be58755c4933cda68d525?rik=C0D21hJDYvXosw&riu=http%3a%2f%2fimg.pconline.com.cn%2fimages%2fupload%2fupc%2ftx%2fwallpaper%2f1305%2f16%2fc4%2f20990657_1368686545122.jpg&ehk=netN2qzcCVS4ALUQfDOwxAwFcy41oxC%2b0xTFvOYy5ds%3d&risl=&pid=ImgRaw&r=0')
response=requests.get(url)
# print(response.content)
with open('1.jpg','wb') as f:
    f.write(response.content)


