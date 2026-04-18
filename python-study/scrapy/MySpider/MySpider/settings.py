BOT_NAME = "MySpider"
SPIDER_MODULES = ["MySpider.spiders"]
NEWSPIDER_MODULE = "MySpider.spiders"
ROBOTSTXT_OBEY = False

# 请求头
DEFAULT_REQUEST_HEADERS = {
    'Accept': 'application/json, text/plain, */*',
    'Accept-Language': 'zh-CN,zh;q=0.9',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36',
    'Referer': 'https://music.163.com/'
}

# 开启下载管道
ITEM_PIPELINES = {
    'MySpider.pipelines.MySpiderPipeline': 300,
}

# 歌曲保存路径（改成你想保存的文件夹）
FILES_STORE = 'D:/网易云下载'

# 反爬配置
DOWNLOAD_DELAY = 1
CONCURRENT_REQUESTS = 4
LOG_LEVEL = 'WARNING'

# 禁用压缩中间件
DOWNLOADER_MIDDLEWARES = {
    'scrapy.downloadermiddlewares.httpcompression.HttpCompressionMiddleware': None,
}