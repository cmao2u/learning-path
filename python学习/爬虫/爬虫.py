
# 基本使用
# # import requests
# # #找到目标url
# # url='http://www.baidu.com'
# # #发送请求
# # response=requests.get(url)
# # #打印响应
# # print(response.content.decode('utf= 8'))爬文本
# url=('https://ts1.tc.mm.bing.net/th/id/R-C.987f582c510be58755c4933cda68d525?rik=C0D21hJDYvXosw&riu=http%3a%2f%2fimg.pconline.com.cn%2fimages%2fupload%2fupc%2ftx%2fwallpaper%2f1305%2f16%2fc4%2f20990657_1368686545122.jpg&ehk=netN2qzcCVS4ALUQfDOwxAwFcy41oxC%2b0xTFvOYy5ds%3d&risl=&pid=ImgRaw&r=0')
# response=requests.get(url)
# # print(response.content)
# with open('1.jpg','wb') as f:
#     f.write(response.content)
# import requests
# url='https://ss2.bdstatic.com/70cFvXSh_Q1YnxGkpoWK1HF6hhy/it/u=1659552792,3869332496&fm=253&gp=0.jpg'
# response =requests.get(url)
# #print(response.content)#爬图片
# print(response.request.headers)
# print(response.headers)
# with open('2.jpg','wb') as g:
#      g.write(response.content)
# UAlist=["Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36"
#         "Mozilla/5.0 (iPhone; CPU iPhone OS 18_5 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/18.5 Mobile/15E148 Safari/604.1"
# #         ]构建UA池
# from urllib.parse import quote,unquote
# # quote()明文转密文
# # unquote()密文转明文
# print(quote("你好"))
# print(unquote("%E4%BD%A0%E5%A5%BD"))
# import requests
# url="https://www.baidu.com/s?"
# headers={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36"}
# name=input("请输入关键字")
# kw={'wd': name}
# res=requests.get(url,headers=headers,params=kw)
# print(res.request.headers)
import requests
# url=("https://p5.music.126.net/obj/wonDlsKUwrLClGjCm8Kx/76315544841/03ca/3273/523c/b868c1e818d0a417144babb7e9dbdee5.jpg?imageView&quality=89")
# headers={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36"}
# res=requests.get(url,headers=headers)
# # print(res.content)
# with open("网易云test01.jpg","wb") as f:
#     f.write(res.content)
url=("https://m804.music.126.net/20251109121013/336ebeadb55da2088bd1b59da6cad795/jdyyaac/obj/w5rDlsOJwrLDjj7CmsOj/28481673308/98f5/a5a1/d78a/94120424909f3fbe6c3d3aa5f091c350.m4a?vuutv=GUKKs21BCZ+JWnc1K5W7+TOT2Wf/Dwtv6B2Q8zqoU3Otzl862IC/lzU6dC18Yo7RnZxoLgQ3Z3N/4YKG8S/HJZifYovTd3yNo8NdEB8AbqQ=&authSecret=0000019a66b7cfd316470a3b1e26f146&cdntag=bWFyaz1vc193ZWIscXVhbGl0eV9leGhpZ2g")
headers={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36"}
res=requests.get(url,headers=headers)
with open("网易云test02.mp3","wb")as g:
    g.write(res.content)






