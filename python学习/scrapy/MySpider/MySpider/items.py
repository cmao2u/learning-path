import scrapy

class MySpiderItem(scrapy.Item):
    song_name = scrapy.Field()  # 歌曲名
    singer = scrapy.Field()     # 歌手
    album = scrapy.Field()      # 专辑
    song_id = scrapy.Field()    # 歌曲ID
    download_url = scrapy.Field()  # 下载链接
    file_path = scrapy.Field()  # 本地保存路径