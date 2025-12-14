import os
import json
import base64
import random
import string
import requests
from Crypto.Cipher import AES
from bs4 import BeautifulSoup

# ===================== 基础配置 =====================
PLAYLIST_ID = "741335088"     # ← 换成你的歌单 ID
SAVE_DIR = "downloads"

HEADERS = {
    "User-Agent": "Mozilla/5.0",
    "Referer": "https://music.163.com/",
}

session = requests.Session()
session.headers.update(HEADERS)

# ===================== 工具函数 =====================
def safe_filename(name):
    return "".join(c for c in name if c not in r'\/:*?"<>|')

def random_key(length=16):
    return "".join(random.choice(string.ascii_letters + string.digits) for _ in range(length))

# ===================== weapi 加密 =====================
def weapi(data):
    modulus = (
        "00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7"
        "b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280"
        "104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932"
        "575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b"
        "3ece0462db0a22b8e7"
    )
    pubkey = "010001"
    nonce = "0CoJUm6Qyw8W8jud"
    sec_key = random_key(16)

    def aes_encrypt(text, key):
        pad = 16 - len(text) % 16
        text = text + chr(pad) * pad
        return base64.b64encode(
            AES.new(key.encode(), AES.MODE_CBC, b"0102030405060708")
            .encrypt(text.encode())
        ).decode()

    def rsa_encrypt(text):
        text = text[::-1]
        rs = pow(int(text.encode().hex(), 16), int(pubkey, 16), int(modulus, 16))
        return format(rs, "x").zfill(256)

    enc_text = aes_encrypt(json.dumps(data), nonce)
    enc_text = aes_encrypt(enc_text, sec_key)
    enc_sec_key = rsa_encrypt(sec_key)

    return {
        "params": enc_text,
        "encSecKey": enc_sec_key
    }

# ===================== 歌单解析（HTML，最稳） =====================
def get_playlist_songs(playlist_id):
    url = "https://music.163.com/api/playlist/detail"
    params = {
        "id": playlist_id,
        "n": 1000,
        "s": 8
    }

    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64)",
        "Referer": "https://music.163.com/",
        "Accept": "*/*"
    }

    r = requests.get(url, params=params, headers=headers)
    r.raise_for_status()

    js = r.json()

    if "result" not in js or "tracks" not in js["result"]:
        print("[!] 接口被风控或歌单不可访问")
        return []

    ids = [song["id"] for song in js["result"]["tracks"]]

    print(f"[+] 歌单解析到 {len(ids)} 首歌")
    return ids

# ===================== 歌曲详情 =====================
def get_song_detail(song_ids):
    url = "https://music.163.com/weapi/v3/song/detail"
    data = {
        "c": json.dumps([{"id": i} for i in song_ids]),
        "ids": json.dumps(song_ids),
        "csrf_token": ""
    }
    r = session.post(url, data=weapi(data))
    r.raise_for_status()
    return r.json()["songs"]

# ===================== 获取播放链接 =====================
def get_song_url(song_id):
    url = "https://music.163.com/weapi/song/enhance/player/url"
    data = {
        "ids": json.dumps([song_id]),
        "br": 128000,
        "csrf_token": ""
    }
    r = session.post(url, data=weapi(data))
    r.raise_for_status()
    return r.json()["data"][0]["url"]

# ===================== 下载 =====================
def download_song(name, url):
    if not url:
        print(f"[!] 无法下载：{name}")
        return

    os.makedirs(SAVE_DIR, exist_ok=True)
    path = os.path.join(SAVE_DIR, f"{safe_filename(name)}.mp3")

    with session.get(url, stream=True) as r:
        with open(path, "wb") as f:
            for chunk in r.iter_content(1024):
                if chunk:
                    f.write(chunk)

    print(f"[✓] 已下载：{name}")

# ===================== 主流程 =====================
def main():
    song_ids = get_playlist_songs(PLAYLIST_ID)
    print(song_ids[:5])
    if not song_ids:
        print("[!] 歌单为空，终止")
        return

    songs = get_song_detail(song_ids)

    for s in songs:
        name = f"{s['name']} - {s['ar'][0]['name']}"
        print(f"[*] 下载中：{name}")
        url = get_song_url(s["id"])
        download_song(name, url)

    print("\n🎉 全部完成")

if __name__ == "__main__":
    main()
