# https://www.acmicpc.net/problem/1287
import re
try:
    txt = input()
    r = re.split('[-|+|*|/]', re.sub('[(|)]', '', txt))
    if '' in r:
        raise Exception()
    if "()" in txt:
        raise Exception()
    print(eval(txt.replace('/', '//')))
except:
     print("ROCK")