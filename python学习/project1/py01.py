
#从0开始学习，
# 前面可能写的很烂，
# 但我相信会越来越好！！！
# print("hello world")
# #python严格控制缩进
# print("hello world","hello everyone",sep='|',end='|')
# print("hello sir",end='|')
# ma=2+3j
# ma2=4+5j
# print(ma+ma2,sep='|',end='|')

# #5.1占位符
# name="cmao2"
# age=18
# print("名字:%s，年龄:%6d"%(name,age))
# b=2.34532
# print("%f"%b)
# print("%.3f"%b)
# 格式化
# name="cmao2"
# age=18
# print(f"我的名字{name},我的年龄{age}")

#
# a=5
# b=2
# print(a/b)
# print(a//b)
# print(a**b)
# sum=0
# for i in range(101):
#     sum+=i
# print(sum)
# i=1
# while(i<=5):
#     if(i==3):
#         print(f"小明在第{i}个苹果里吃到一条虫子,不吃了")
#         i+=1
#     print(f"小明在吃第{i}个苹果")
#     i=i+1
# a1="橙猫猫"
# b=a1.encode('utf-8')
# print(b)
# print("cmao2\n"*5)
# print('c' in'cmao2')
# name='cmao2'
# print(name[1])
# print(name[-2])
# print(name[0:3])
# name="RIVER"
# print(name.index("V",2))
# print(name.find("v"))
# print(name.count("V"))
# print(name.startswith("R"))
# print(name.split("V"))
# list=[1,"r","cmao2",3.424]
# print(list[0:3])
# print(list[:])
# list.append("four")
# list.extend([1,2,3])
# print(list)
# list[1]="SOUL"
# print(list)
# print('SOUL' not in list)
# while True:
#     name=input("请输入用户名：")
#     name_list=["Cmao2","ikun","Lin"]
#     if name in name_list:
#         print(f"该昵称{name}已存在!")
#     else:
#         name_list.append(name)
#         print(name_list)
#         break
# del name_list[0]
# print(name_list)
# list_A=["f","w","h","w","s"]
# print(list_A)
# list_A.remove("w")
# print(list_A)
# list_A.remove("h")
# print(list_A)
# list_A.sort()
# list_A.reverse()
# print(list_A)
# tuple_A=(1,5,3,7,1,1,8)
# print(tuple_A)
# print(len(tuple_A))
# print(tuple_A.count(1))
# 深浅拷贝
# import copy
# list_A=[1,5,2,6]
# list_B=list_A
# print(list_A)
# print(list_B)
# list_A.append(78)
# print(list_A)
# print(list_B)
# list_C=copy.copy(list_A)
# print(list_C)
# list_D=[1,2,[9,3,56],2,5]
# list_E=copy.deepcopy(list_D)
# print(list_D)
# print(list_E)
# list_D[2].append(7)
# print(list_D)
# print(list_E)
#函数
# def func1():
#     print("济州之旅顺利鸭！")
# def func2():
#     print("hello Cmao2")
#     func1()
# func2()
# def func3():
#     return 20
# print(func3())
# def add(a,b):
#     return a+b
# print(add(1,2))
# def func5(a=8):
#     return a+8
# print(func5())
# print(func5(18))
# def fund(*args):
#     return sum(args)
# print(fund(1,2,3))
# print(fund(1,7,3,8))
# def func8(**kwargs):
#     print(kwargs)
#     print(type(kwargs))
# func8(name="Cmao2",age=18)
# def study():
#     print("晚上在学习")
#     def course():
#         print("在学python")
#     course()
#     return
# study()
# def study():
#     global name
#     name="晚上在学习"
# study()
# print(name)
# def outer():
#     a=10
#     def inner1():
#         nonlocal a
#         a=20
#         def inner2():
#             nonlocal a
#             a=30
#             print("inner2值为",a)
#         inner2()
#         print("inner1值为",a)
#     inner1()
#     print("outer值为",a)
# outer()
# add=lambda x,y:x+y
# print(add(1,4))
# fund =lambda **kwargs:kwargs
# print(fund(name="Cmao2",age=18))
# import builtins
# print(dir(builtins))
# print(sum({1.2,2.2}))
# list_A=[1,3,2]
# def multiply(a):
#     return a*5
# mp=map(multiply,list_A)
# print(list(mp))
# for i in mp:
#     print(i)
# from functools import reduce
# list_A=[1,3,2,6]
# def func1(a,b):
#     return a+2*b
# result=reduce(func1,list_A)
# print(result)
# try:
#     print(1)
# except Exception as e:
#     print(e)
#     print("出现了异常")
# else:
#     print("没有异常")
# finally:
#     print("啦啦啦")
# def login():
#     password=input("请输入密码:")
#     if len(password) >= 8:
#         print("输入成功")
#     else:
#         raise Exception("密码长度不足")
# try:
#     login()
# except Exception as e:
#     print(e)
# import test01/'.
# test01.yyy()
# def func1(n):
#     if n==1:
#         return 1
#     return n+func1(n-1)
# def fb(n):
#     if n<=1:
#         return n
#     return fb(n-1)+fb(n-2)
# print(func1(100))
# print(fb(255))
# def outer(m):
#     n=10
#     def inner():
#         print(n+m)
#     return inner
# print(outer(30)())
# def send():
#     print("发送信息")
# def transfer():
#     print("转账")
# def outer(fn):
#     def inner():
#         fn()
#     return inner
# print(outer(send)())
# print(outer(transfer)())
# def  outer(fn):
#     def inner():
#         print(f"[日志]---{fn.__name__}")
#         fn()
#         print(f"[日志]---{fn.__name__}")
#     return inner
# @outer
# def send():
#     print .

# send()
# def decorator_B(func):
#     def wrapper_B(name):
#         print("[日志]--装饰前")
#         func(name)
#     return wrapper_B
# def decorator_A(func):3
#     def wrapper_A(name):
#         print(f"{name}是装饰器中的")
#         func(name)
#     return wrapper_A
# @decorator_B
# @decorator_A
# def func1(a):
#     print("嘻嘻是被装饰函数中的")
# func1('哈哈')
# class Person:
#     name="Cmao2"
#     def speak(self):
#         print("Hello!")
# P1=Person()
# P1.speak()
# print(P1.name)
# P1.name="KK"
# print(P1.name)
# class Person:
#     def __init__(self,name,age,sex):
#         self.name=name
#         self.age=age
#         self.sex=sex
#     def __del__(self):
#         print("嘻嘻")
#     def play(self):
#         print("Cmao2在玩")
#     def show(self):
#         print(f"名字是{self.name},年龄是{self.age},性别是{self.sex}")
# P1=Person("Cmao2",18,'male')
# P1.show()
# P1.play()
# class Person:
#     def __init__(self, name, age):
#         self.name = name
#         self.age = age
#     def __play(self):
#         print("这是私有部分")
# P1=Person('Cmao2',18)
# P1._Person__play()
# class Person:
#     def __init__(self, name, age):
#         self.name = name
#         self.age = age
#     def _eat(self):
#         print(f"{self.name}在吃饭")
#     def _play(self):
#         print(f"{self.age}的{self.name}在玩")
# class Girl(Person):
#     pass
# girl_A=Girl("Annie",18)
# print(girl_A._eat())
# print(girl_A._play())
# class Father:
#     def __init__(self):
#         print("支持")
# class Mother:
#     def __init__(self):
#         print("陪伴")
# class Child(Mother,Father):
#     pass
# Cmao2=Child() 
# class Animal:
#     def __init__(self):
#         pass
class singleton(object):
    _instance=None
    def __new__(cls,*args,**kwargs):
        if cls._instance is None:
            cls._instance=super().__new__(cls)
        return cls._instance
A=singleton()
B=singleton()
print(A is B)





















































































#     def shout(self):
#         print("小动物在叫")
# class Dog(Animal):
#     def shout(self):
#         print("小狗汪汪汪")
# class Cat(Animal):
#     def shout(self):
#         print("小猫喵喵喵")
# cat1=Cat()
# dog1=Dog()
# def test01(object):
#     object.shout()
# test01(cat1)
# test01(dog1)
# class Biscuit:
#     @staticmethod
#     def sweet(name):
#         print(f"{name}是甜的")
# B1=Biscuit()
# B1.sweet("曲奇饼干")
# class Cookie:
#     @classmethod
#     def sweet(cls):
#         print(f"{cls.__name__}是甜的")
# cookie=Cookie()
# cookie.sweet()
class Person:
    def __init__(self):
        print("这是init")
    # def __new__(self,*args,**kwargs):
    #     print("这是new")
person1=Person()















