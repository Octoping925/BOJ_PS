# https://programmers.co.kr/learn/courses/30/lessons/17683

def getMusicTime(txt):
    musicStart = (int(txt.split(':')[0]) * 60 + int(txt.split(',')[0].split(':')[1]))
    musicEnd = (int(txt.split(',')[1].split(':')[0]) * 60 + int(txt.split(',')[1].split(':')[1]))
    return musicEnd - musicStart

def getMusicName(txt):
    return txt.split(',')[2]

def getMusicInfo(txt):
    return txt.split(',')[-1]

def makeReplace(txt):
    return txt.replace('C#', 'c').replace('D#', 'd').replace('F#', 'f').replace('G#', 'g').replace('A#', 'a')
    

def cutmusic(txt):
    musicTime = getMusicTime(txt)
    musicInfo = makeReplace(getMusicInfo(txt))
    musicPlayed = ""
    
    for i in range(musicTime):
        musicPlayed += musicInfo[i % len(musicInfo)]
        
    return musicPlayed
    

def solution(m, musicinfos):
    musicPlayed = []
    musicCorrect = []
    
    for txt in musicinfos:
        musicPlayed.append(cutmusic(txt))
        
        if cutmusic(txt).find(makeReplace(m)) != -1:
            musicCorrect.append(txt)
        
    if len(musicCorrect) == 0:
        return "(None)"
    
    maxTime = -1
    maxName = ""
    for music in musicCorrect:
        if getMusicTime(music) > maxTime:
            maxName = getMusicName(music)
            maxTime = getMusicTime(music)
    
    return maxName