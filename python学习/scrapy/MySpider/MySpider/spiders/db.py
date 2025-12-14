import scrapy
import json
from MySpider.items import MySpiderItem
from MySpider.utils.encrypt import WangYiYunEncrypt

class DbSpider(scrapy.Spider):
    name = "db"
    allowed_domains = ["music.163.com"]

    def __init__(self):
        self.encrypt = WangYiYunEncrypt()
        self.playlist_id = "7411335088"  # 你的歌单ID，不用改
        # 替换成你自己的网易云登录Cookie（必须改！）
        self.cookie = "JSESSIONID-WYYY=VmcomooY2csnc1R3Gg3K68JHHl%2Fmf9Md%2BcFrlK19NZcud5n4krBz7s2fjgWfn8EykjR5WPCHO%5CoCfHF%2Fs4rCW14yR%2Bw%2Fp8Ex21ORt2EKKAJaDW%2BtrAIPIHG%2BFnNg7BVGNCJrH%5C9a3n9s5HXM0E66iOJcNpDh%2Bxhp067OkerzgGFzy4dz%3A1765614324442; _iuqxldmzr_=32; _ntes_nnid=16898ef61f382854804ca7c3a85b4141,1765612524462; _ntes_nuid=16898ef61f382854804ca7c3a85b4141; NMTID=00OgTJkq6O1FpU1E0oriNIpTUEatX4AAAGbFrURFw; WEVNSM=1.0.0; WNMCID=cufkcx.1765612526226.01.0; WM_NI=BOeEFA%2FrrfDXiXYt8Sa0PgzPlH%2Bzc9pQso4enpAA3wlhiZ0AG%2B7S4jGMcNw4%2Fop2eOCo%2FlLMLG%2FmexoBEF18IorjJwEtruU8PiQSLpgQc6DVvod5VJNZGlFdvrNZUrPhbkg%3D; WM_NIKE=9ca17ae2e6ffcda170e2e6ee8bb57d9cf5b7b4dc4fa59e8ea6d84a928f8f87cb72a9bdc08ef0708cb2a9b2bb2af0fea7c3b92a8291aba6c54bedaebe87c754ab889795bb59a3f0a088f95cb098e59be233b48fbd90b76faeb08fa2b27db0b8a7bbb34b85f5f9b4b7628593adaff640edb1c0d3e84581b1e18dcf479099e18ee874ad9e8ba7b4348bb1be8bc97d87acbe96d83494b79fb4cf7ca58fadd7c75eb6b1acd6d5428e86898dc570b6ae82bbd87a94b8ae8ce637e2a3; WM_TID=u0yZ3Zpu%2B%2BVFQAUQQUaXjlN5mmdTylRt; sDeviceId=YD-%2FIpKolEQyQdFEhQUFUeSykIpyjcXuf67; ntes_utid=tid._.hEvdIwGAjEdBAhQRUBbSngZ5n3IH%252FA50._.0; __snaker__id=9IikpQMXzuuO8pJC; gdxidpyhxdE=%2FSAyNMMkWWAQY3%5CRoqHWmXmcvvYbRV5i1b9Vxj%2FXI%5CxK3JTKUDqkcRuYfOeGxsvjBp%2FKpmkmV%5ClNykPYdL7q1cOuSGXryb3Ywb%2BfNt%2Fcg64iMUgDnZR1R%5CuMgnRtk86wy%5CdwlqEgSM4%2BNbpt%5CkZjKw3Y%5CybOgjZVOV6RitnGNJ2%2BsjVY%3A1765613446485; MUSIC_U=0008092116AE9D55B829E12A1FC1ACB1E87F7344801152C9EFB877558C2E59718AFEB2B6F1BB1974BAD8E9113A6F5631E6A519B682422E6A0A1953B2C9A3A5B9A098CBF204EC9F8642F88342591C081FFA3605EB79B5208009B01EA5DE1BC029A0BB45157E6E155FD78FD0167A2D4E86511FFA9909E226F7DFCDE640B6FB1C3D4244BFB9F1C3769C5849E2A1DB41A018B3BE02B9679AE5D1AA40BE752A9962F68D7172F12549B52927F169747CCC84B79A7B99B74A374C1AB4D11C03CFBEFA90F88AB679DDBB180419626FBBAB1CF8E08C1B729DD962726B1EEB93E83221BB0A372683F4B1093261EF12A2478C152F65A8C4C31A72B9D3C5BD4E84650DE3BC33B0E2C9D30C0669C68DD08C9D3C361602F31072C28B3D1EA8FAA0147CA1A6832B0DD1EBDEEED9DE6CABA6BEF6B77C38ABF4521643847A660380C7CBE87B426D0E8D32C0E513B730131932EC9A2BECB54FDE279DD57EDDF1D81B6521063205AE3E31DD94D3AFA59702B6353915F63E629C488AAE9EE7BBA41B9917BA372180AE97DB2ED9A6028FC825E0A8AE0A7B3AEF04B7; __csrf=9c6849261ba0300c5ca4c4ea1321821a; ntes_kaola_ad=1"

    def start_requests(self):
        # 歌单API请求
        api_url = "https://music.163.com/weapi/v3/playlist/detail"
        data = {
            "id": self.playlist_id,
            "n": 1000,
            "s": 8
        }
        encrypt_data = self.encrypt.encrypt(data)
        yield scrapy.FormRequest(
            url=api_url,
            formdata=encrypt_data,
            headers={
                'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36',
                'Referer': 'https://music.163.com/',
                'Cookie': self.cookie
            },
            callback=self.parse_playlist
        )

    def parse_playlist(self, response):
        data = json.loads(response.text)
        if data.get("code") == 200 and data.get("playlist"):
            songs = data["playlist"]["tracks"]
            for song in songs:
                if not song:
                    continue
                item = MySpiderItem()
                item['song_id'] = song['id']
                item['song_name'] = song['name']
                item['singer'] = ','.join([artist['name'] for artist in song['ar']])
                item['album'] = song['al']['name']
                yield self.get_song_url_request(item)
        else:
            self.logger.error(f"获取歌单失败：{data.get('msg', 'Cookie无效/未登录')}")

    def get_song_url_request(self, item):
        api_url = 'https://music.163.com/weapi/song/enhance/player/url/v1'
        data = {
            'ids': [item['song_id']],
            'level': 'standard',
            'br': 320000
        }
        encrypt_data = self.encrypt.encrypt(data)
        return scrapy.FormRequest(
            url=api_url,
            formdata=encrypt_data,
            meta={'item': item},
            callback=self.parse_song_url
        )

    def parse_song_url(self, response):
        item = response.meta['item']
        data = json.loads(response.text)
        if data['code'] == 200 and data['data'] and data['data'][0]['url']:
            item['download_url'] = data['data'][0]['url']
            item['file_path'] = f"{item['singer']}/{item['album']}/{item['song_name']}.mp3"
            yield item
        else:
            self.logger.warning(f"歌曲《{item['song_name']}》无下载权限")