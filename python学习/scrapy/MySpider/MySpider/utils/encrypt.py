import random
import base64
import json
import binascii
from Cryptodome.Cipher import AES

class WangYiYunEncrypt:
    def __init__(self):
        self.pub_key = "010001"
        self.modulus = "00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b3ece0462db0a22b8e7"
        self.nonce = b"0CoJUm6Qyw8W8jud"

    def create_secret_key(self, size):
        return bytes(''.join(random.sample('1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ', size)), 'utf-8')

    def aes_encrypt(self, text, key):
        pad = 16 - len(text) % 16
        text = text + pad * chr(pad)
        encryptor = AES.new(key, AES.MODE_CBC, b'0102030405060708')
        return base64.b64encode(encryptor.encrypt(text.encode('utf-8')))

    def rsa_encrypt(self, text):
        text = text[::-1]
        text_hex = binascii.hexlify(text.encode()).decode()
        rs = pow(int(text_hex, 16), int(self.pub_key, 16), int(self.modulus, 16))
        return format(rs, 'x').zfill(256)

    def encrypt(self, data):
        text = json.dumps(data)
        secret_key = self.create_secret_key(16)
        params = self.aes_encrypt(text, self.nonce).decode('utf-8')
        params = self.aes_encrypt(params, secret_key).decode('utf-8')
        enc_sec_key = self.rsa_encrypt(secret_key.decode('utf-8'))
        return {'params': params, 'encSecKey': enc_sec_key}