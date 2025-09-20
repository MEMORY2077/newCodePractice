import base64
import binascii

# 要解码的字符串
encoded_str = "55+33+42+70+63+6d+6c+30+65+33+63+7a+62+47+4d+77+5a+47+56+66+4d+6c+39+7a+63+44+46+79+4d+58+52+48+4e+47+30+7a+58+7a+49+77+4d+6a+55+68+66+51+3d+3d"

# 替换"+"为标准Base64的"/"，并去除多余的"+"号
processed_str = encoded_str.replace("+", "").replace("55", "U").replace("33", "3").replace("42", "B").replace("70", "p").replace("63", "c").replace("6d", "m").replace("6c", "l").replace("30", "0").replace("65", "e").replace("7a", "z").replace("62", "b").replace("47", "G").replace("4d", "M").replace("77", "w").replace("5a", "Z").replace("56", "V").replace("66", "f").replace("39", "9").replace("44", "D").replace("46", "F").replace("79", "y").replace("58", "X").replace("52", "R").replace("48", "H").replace("4e", "N").replace("49", "I").replace("6a", "j").replace("55", "U").replace("68", "h").replace("51", "Q").replace("3d", "=")

try:
    # 进行Base64解码
    decoded_bytes = base64.b64decode(processed_str)
    decoded_str = decoded_bytes.decode('utf-8')
    print("解码结果：", decoded_str)
except binascii.Error as e:
    print("解码错误：", e)