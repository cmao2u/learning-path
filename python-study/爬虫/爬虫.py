
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
# # # quote()明文转密文
# # # unquote()密文转明文
# print(quote("不要老是骚扰我，你们没有自己的事要做吗？"))
# print(unquote("%E4%BD%A0%E5%A5%BD"))
# import requests
# url="https://www.baidu.com/s?"
# headers={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36"}
# name=input("请输入关键字")
# kw={'wd': name}
# res=requests.get(url,headers=headers,params=kw)
# print(res.request.headers)
# import requests
# url=("https://p5.music.126.net/obj/wonDlsKUwrLClGjCm8Kx/76315544841/03ca/3273/523c/b868c1e818d0a417144babb7e9dbdee5.jpg?imageView&quality=89")
# headers={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36"}
# res=requests.get(url,headers=headers)
# # print(res.content)
# with open("网易云test01.jpg","wb") as f:
#     f.write(res.content)
# url=("https://m804.music.126.net/20251109121013/336ebeadb55da2088bd1b59da6cad795/jdyyaac/obj/w5rDlsOJwrLDjj7CmsOj/28481673308/98f5/a5a1/d78a/94120424909f3fbe6c3d3aa5f091c350.m4a?vuutv=GUKKs21BCZ+JWnc1K5W7+TOT2Wf/Dwtv6B2Q8zqoU3Otzl862IC/lzU6dC18Yo7RnZxoLgQ3Z3N/4YKG8S/HJZifYovTd3yNo8NdEB8AbqQ=&authSecret=0000019a66b7cfd316470a3b1e26f146&cdntag=bWFyaz1vc193ZWIscXVhbGl0eV9leGhpZ2g")
# headers={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36"}
# res=requests.get(url,headers=headers)
# with open("网易云test02.mp3","wb")as g:
#     g.write(res.content)

# import requests
# url="https://vodkgeyttp8.vod.126.net/cloudmusic/59a4/core/5017/9782a4cfeb09ed1a42449bcac3dd4b80.mp4?wsSecret=aeaab9d2a1192dab02e6eb321a3089c8&wsTime=1762842346"
# headers={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36"}
# res=requests.get(url,headers=headers)
# with open("解解.mp4","wb") as f:
#     f.write(res.content)
# ###request爬取百度————————失败————————呜呜呜QAQ你等着百度——————————早晚把你带走——————嘿嘿
# import requests
# import time
# import random
# word=input("请输入名称")
# page=int(input("请输入要保存的页数"))
# session=requests.Session()
# url="https://tieba.baidu.com/f"
# headers={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
#          "Referer":f"https://tieba.baidu.com/f?kw={word}",
#          "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8",
#          "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8",
#          "Accept-Encoding": "gzip, deflate, br",
#          "Connection": "keep-alive",
#          "Upgrade-Insecure-Requests": "1",
#          "Cookie":"""BIDUPSID=E669D4D2464551080C36D873F32CC9FB; PSTM=1749645938; BAIDUID=E669D4D2464551088A2C08D1C9B4E54F:FG=1; BAIDUID_BFESS=E669D4D2464551088A2C08D1C9B4E54F:FG=1; H_WISE_SIDS=60271_62325_63141_63242_63354_63403_63442_63457_63503_63499_63541_63567_63563_63583_63579; H_PS_PSSID=60271_62325_63141_63724_63729_63705_63275_63810_63820_63837_63881_63909_63933_63952_63948_63957_64005_64010_64015_64027_64037; MCITY=-224%3A; BAIDU_WISE_UID=wapp_1757388733706_942; ZFY=I:BZig1lhFxFlMw0o88QZ:Ap2LjmZxA:B6EyFs0lgb:AMt8:C; arialoadData=false; TIEBA_SID=H4sIAAAAAAAAA9MFAPiz3ZcBAAAA; BAIDU_SSP_lcr=https://cn.bing.com/; Hm_lvt_292b2e1608b0823c1cb6beef7243ef34=1762852189,1762852894,1762930323,1762932863; HMACCOUNT=8D150DB52B11D62F; USER_JUMP=-1; st_key_id=17; RT="z=1&dm=baidu.com&si=93902470-cbe9-40f8-9648-ddfa8f21b4a6&ss=mhvnhihq&sl=c&tt=6wr&bcn=https%3A%2F%2Ffclog.baidu.com%2Flog%2Fweirwood%3Ftype%3Dperf&ld=18jtm&ul=19hv6&hd=19hv9"; video_bubble0=1; ppfuid=FOCoIC3q5fKa8fgJnwzbE67EJ49BGJeplOzf+4l4EOvDuu2RXBRv6R3A1AZMa49I27C0gDDLrJyxcIIeAeEhD8JYsoLTpBiaCXhLqvzbzmvy3SeAW17tKgNq/Xx+RgOdb8TWCFe62MVrDTY6lMf2GrfqL8c87KLF2qFER3obJGnsqkZri/4OJbm7r4CyJIowGEimjy3MrXEpSuItnI4KD7cPaJi+EtbDcJgnQk/tNlI4n1pPf9rvqnYNm2WK8+4sy85/Lw0UoEI6HZjB4I95xEqKBeQ139A9EY4xNc1PkePGgLbz7OSojK1zRbqBESR5Pdk2R9IA3lxxOVzA+Iw1TWLSgWjlFVG9Xmh1+20oPSbrzvDjYtVPmZ+9/6evcXmhcO1Y58MgLozKnaQIaLfWRMWxg8jAkEPs+b09272wkCcMJmBV3DqpyTuzDwSUDbMyyfzO9u0S9v0HHkJ/i4zKsdnTNS/pLMWceus0e757/UNkQhA4BJH1ZqCtXJJ8GJaKAAv3LCf1Y7/fHL3PTSf9vid/u2VLX4h1nBtx8EF07eCMhWVv+2qjbPV7ZhXk3reaWRFEeso3s/Kc9n/UXtUfNU1sHiCdbrCW5yYsuSM9SPGDZsl7FhTAKw7qIu38vFZiq+DRc8Vbf7jOiN9xPe0lOdZHUhGHZ82rL5jTCsILwcRVCndrarbwmu7G154MpYiKmTXZkqV7Alo4QZzicdyMbWvwvmR2/m//YVTM8qeZWgDSHjDmtehgLWM45zARbPujeqU0T92Gmgs89l2htrSKIXcjKdgQvu5YtJbjqELHHJqkB6QrTePrqfOOtPobsFTAzXqh1iYbjxr7b/BFa7Frm5dImdyxYIjA1uSy2hfTFv/d3cnXH4nh+maaicAPllDg7JjsxZAfQoVAycJHizlQ5d34k8SzMID0x3kxnXwHfxXvz6DS3RnKydYTBUIWPYKJrsJOWe5xtyW4Ih3AFBypKPNZxCGhdRLPMuw9uS6j8+B9ZxeHR1YbuoydGhgWuSXpmicvCOZ5ilmUBt/wdqpvyAWuAFbMc1TpNbxQZiCF6/b1+SIlGdqadGFIFR1MMwbooKDbFUOPsQE72/a0kEWC2KhuPKLM9/6dZ00isWP1M71YVK+GcriYXdSGsdTLua2Z4rsiMpSciOy0GtH0BDIaHROBNUIGus13vk3BD9zddjzj9ZJseUlzwEV+bscicwIjSCwQvM4e3xnzVzlld+zvYN0q7Yw+xx5u95PSoz+nO88s9TqjpS2CuGXeoK3JV0ZszUm/I4svUtnuwoAeyS5LWqphVNhJG/707P2GcCYlcR4=; BDUSS=XV4TDZUVGtmMmw2R1FIVFlKLU84S3hOVy02aG13MjVFeGFsMHNuYTg1UFJ4VHRwSVFBQUFBJCQAAAAAAQAAAAEAAABIF9QjsNaw1mxpbmhvbWUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAANE4FGnROBRpe; BDUSS_BFESS=XV4TDZUVGtmMmw2R1FIVFlKLU84S3hOVy02aG13MjVFeGFsMHNuYTg1UFJ4VHRwSVFBQUFBJCQAAAAAAQAAAAEAAABIF9QjsNaw1mxpbmhvbWUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAANE4FGnROBRpe; STOKEN=39151e3b4dff6557bd4b52be6bc142bf99734573643562bcd8d91e7acb4a5930; Hm_lpvt_292b2e1608b0823c1cb6beef7243ef34=1762932948; 4896069448_FRSVideoUploadTip=1; video_bubble4896069448=1; XFI=35a63840-bf9a-11f0-b3bc-5b26f772a2b1; BA_HECTOR=0g84a48485ag2480aka4al0g20058n1kh8e6l24; ariaappid=c890648bf4dd00d05eb9751dd0548c30; ariauseGraymode=false; ab_sr=1.0.1_MDU0ODI2YzU1OTI0ZTBhNGQyNjNiMDFkM2U1NThkYzZjZjkxMmUyYmFiYjJlNGVjNzVkZThmMDk4ZjE2OTZmMTU5ZTMzYWM5Njg2ZDZjNTI4MzQ4YmY0MzQyODczMTcxMTJlYjVlNDc3ZDYwMmY5MjIzMjQzOWQ3MzdiNzRlMDcxYjAxOWE3YTIzYTMyOGMwMTdhYzM4NWI5YzFhMmE0YmRkZDNlZWMzMjJkZmE3NzZhN2Y5NTVkMDhjYjZkM2Nm; st_data=583b14ed23c3646d6ba91b3a514bd8d99aa351ac087adf190e6730f977ac2d42b2edff1cf1f39c9f7c4a4e77e1617de92c0d41fabda0881e21f98e683c8c85ae605556bd3cbb77eaae29f9e61048785c4d7f72128f64b62a7f580f6c27c50c28749caabe1a7eedbab7f60f81ca797c2200d23333e2f092738fbe72ea4921cf4486bc51ac4c35c30f5e8dcaba495bc431; st_sign=672fc740; XFCS=118524E0FF8341248A738486E157E4267FEE89195CA57DE6B28CB7B9B7D6894A; XFT=BxKPQVnNHFZQju6Q1QRgKP7rTodWjHvOr2cs7QEoS48="""}
# session.headers.update(headers)
# cookies_str = """BIDUPSID=E669D4D2464551080C36D873F32CC9FB; PSTM=1749645938; BAIDUID=E669D4D2464551088A2C08D1C9B4E54F:FG=1; BAIDUID_BFESS=E669D4D2464551088A2C08D1C9B4E54F:FG=1; H_WISE_SIDS=60271_62325_63141_63242_63354_63403_63442_63457_63503_63499_63541_63567_63563_63583_63579; H_PS_PSSID=60271_62325_63141_63724_63729_63705_63275_63810_63820_63837_63881_63909_63933_63952_63948_63957_64005_64010_64015_64027_64037; MCITY=-224%3A; BAIDU_WISE_UID=wapp_1757388733706_942; ZFY=I:BZig1lhFxFlMw0o88QZ:Ap2LjmZxA:B6EyFs0lgb:AMt8:C; arialoadData=false; TIEBA_SID=H4sIAAAAAAAAA9MFAPiz3ZcBAAAA; BAIDU_SSP_lcr=https://cn.bing.com/; Hm_lvt_292b2e1608b0823c1cb6beef7243ef34=1762852189,1762852894,1762930323,1762932863; HMACCOUNT=8D150DB52B11D62F; USER_JUMP=-1; st_key_id=17; RT="z=1&dm=baidu.com&si=93902470-cbe9-40f8-9648-ddfa8f21b4a6&ss=mhvnhihq&sl=c&tt=6wr&bcn=https%3A%2F%2Ffclog.baidu.com%2Flog%2Fweirwood%3Ftype%3Dperf&ld=18jtm&ul=19hv6&hd=19hv9"; video_bubble0=1; ppfuid=FOCoIC3q5fKa8fgJnwzbE67EJ49BGJeplOzf+4l4EOvDuu2RXBRv6R3A1AZMa49I27C0gDDLrJyxcIIeAeEhD8JYsoLTpBiaCXhLqvzbzmvy3SeAW17tKgNq/Xx+RgOdb8TWCFe62MVrDTY6lMf2GrfqL8c87KLF2qFER3obJGnsqkZri/4OJbm7r4CyJIowGEimjy3MrXEpSuItnI4KD7cPaJi+EtbDcJgnQk/tNlI4n1pPf9rvqnYNm2WK8+4sy85/Lw0UoEI6HZjB4I95xEqKBeQ139A9EY4xNc1PkePGgLbz7OSojK1zRbqBESR5Pdk2R9IA3lxxOVzA+Iw1TWLSgWjlFVG9Xmh1+20oPSbrzvDjYtVPmZ+9/6evcXmhcO1Y58MgLozKnaQIaLfWRMWxg8jAkEPs+b09272wkCcMJmBV3DqpyTuzDwSUDbMyyfzO9u0S9v0HHkJ/i4zKsdnTNS/pLMWceus0e757/UNkQhA4BJH1ZqCtXJJ8GJaKAAv3LCf1Y7/fHL3PTSf9vid/u2VLX4h1nBtx8EF07eCMhWVv+2qjbPV7ZhXk3reaWRFEeso3s/Kc9n/UXtUfNU1sHiCdbrCW5yYsuSM9SPGDZsl7FhTAKw7qIu38vFZiq+DRc8Vbf7jOiN9xPe0lOdZHUhGHZ82rL5jTCsILwcRVCndrarbwmu7G154MpYiKmTXZkqV7Alo4QZzicdyMbWvwvmR2/m//YVTM8qeZWgDSHjDmtehgLWM45zARbPujeqU0T92Gmgs89l2htrSKIXcjKdgQvu5YtJbjqELHHJqkB6QrTePrqfOOtPobsFTAzXqh1iYbjxr7b/BFa7Frm5dImdyxYIjA1uSy2hfTFv/d3cnXH4nh+maaicAPllDg7JjsxZAfQoVAycJHizlQ5d34k8SzMID0x3kxnXwHfxXvz6DS3RnKydYTBUIWPYKJrsJOWe5xtyW4Ih3AFBypKPNZxCGhdRLPMuw9uS6j8+B9ZxeHR1YbuoydGhgWuSXpmicvCOZ5ilmUBt/wdqpvyAWuAFbMc1TpNbxQZiCF6/b1+SIlGdqadGFIFR1MMwbooKDbFUOPsQE72/a0kEWC2KhuPKLM9/6dZ00isWP1M71YVK+GcriYXdSGsdTLua2Z4rsiMpSciOy0GtH0BDIaHROBNUIGus13vk3BD9zddjzj9ZJseUlzwEV+bscicwIjSCwQvM4e3xnzVzlld+zvYN0q7Yw+xx5u95PSoz+nO88s9TqjpS2CuGXeoK3JV0ZszUm/I4svUtnuwoAeyS5LWqphVNhJG/707P2GcCYlcR4=; BDUSS=XV4TDZUVGtmMmw2R1FIVFlKLU84S3hOVy02aG13MjVFeGFsMHNuYTg1UFJ4VHRwSVFBQUFBJCQAAAAAAQAAAAEAAABIF9QjsNaw1mxpbmhvbWUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAANE4FGnROBRpe; BDUSS_BFESS=XV4TDZUVGtmMmw2R1FIVFlKLU84S3hOVy02aG13MjVFeGFsMHNuYTg1UFJ4VHRwSVFBQUFBJCQAAAAAAQAAAAEAAABIF9QjsNaw1mxpbmhvbWUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAANE4FGnROBRpe; STOKEN=39151e3b4dff6557bd4b52be6bc142bf99734573643562bcd8d91e7acb4a5930; Hm_lpvt_292b2e1608b0823c1cb6beef7243ef34=1762932948; 4896069448_FRSVideoUploadTip=1; video_bubble4896069448=1; XFI=35a63840-bf9a-11f0-b3bc-5b26f772a2b1; BA_HECTOR=0g84a48485ag2480aka4al0g20058n1kh8e6l24; ariaappid=c890648bf4dd00d05eb9751dd0548c30; ariauseGraymode=false; ab_sr=1.0.1_MDU0ODI2YzU1OTI0ZTBhNGQyNjNiMDFkM2U1NThkYzZjZjkxMmUyYmFiYjJlNGVjNzVkZThmMDk4ZjE2OTZmMTU5ZTMzYWM5Njg2ZDZjNTI4MzQ4YmY0MzQyODczMTcxMTJlYjVlNDc3ZDYwMmY5MjIzMjQzOWQ3MzdiNzRlMDcxYjAxOWE3YTIzYTMyOGMwMTdhYzM4NWI5YzFhMmE0YmRkZDNlZWMzMjJkZmE3NzZhN2Y5NTVkMDhjYjZkM2Nm; st_data=583b14ed23c3646d6ba91b3a514bd8d99aa351ac087adf190e6730f977ac2d42b2edff1cf1f39c9f7c4a4e77e1617de92c0d41fabda0881e21f98e683c8c85ae605556bd3cbb77eaae29f9e61048785c4d7f72128f64b62a7f580f6c27c50c28749caabe1a7eedbab7f60f81ca797c2200d23333e2f092738fbe72ea4921cf4486bc51ac4c35c30f5e8dcaba495bc431; st_sign=672fc740; XFCS=118524E0FF8341248A738486E157E4267FEE89195CA57DE6B28CB7B9B7D6894A; XFT=BxKPQVnNHFZQju6Q1QRgKP7rTodWjHvOr2cs7QEoS48="""
# cookies_dict = dict([l.split('=', 1) for l in cookies_str.split('; ')])
# session.cookies.update(cookies_dict)
# for i in range(page):
#     params = {
#         'kw':word,'ie':'utf-8','pn':i*50
#     }
#     try:
#         res = session.get(url=url, headers=headers, params=params,timeout=(5,30))
#         if res.status_code==200:
#             with open(f"{word}{i + 1}.html", "wb") as f:
#                 f.write(res.content)
#                 print(f"{i+1}页保存成功")
#         else:
#             print(f"{i+1}页保存失败，状态码{res.status_code}")
#     except Exception as e:
#         print(f"第{i+1}页爬取错误:{e}")
#     time.sleep(random.uniform(2,5))






