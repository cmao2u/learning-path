from scrapy.pipelines.files import FilesPipeline
from scrapy.http import Request

class MySpiderPipeline(FilesPipeline):
    def get_media_requests(self, item, info):
        yield Request(
            url=item['download_url'],
            meta={'file_path': item['file_path']}
        )

    def file_path(self, request, response=None, info=None, *, item=None):
        return request.meta['file_path']

    def item_completed(self, results, item, info):
        for ok, res in results:
            if ok:
                self.logger.info(f"✅ 成功下载：{item['file_path']}")
            else:
                self.logger.error(f"❌ 下载失败：{item['song_name']}")
        return item