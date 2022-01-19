# https://www.acmicpc.net/problem/20000
import io
import zipfile
import urllib
import urllib.request

fileName = "challenge" + input() + ".out"

downloadLink = "https://upload.acmicpc.net/a921f42a-9e94-4fa7-a7bc-58608c92a1cf/"

req = urllib.request.urlopen(downloadLink)
content = req.read()
zip = zipfile.ZipFile(io.BytesIO(content))

print(zip.read(fileName).decode('utf-8'))

#ㅋㅋ 이게 안되네