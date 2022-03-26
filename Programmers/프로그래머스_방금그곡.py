def getMusicTime(txt):
    musicStart = (int(txt.split(':')[0]) * 60 + int(txt.split(',')[0].split(':')[1]))
    musicEnd = (int(txt.split(',')[1].split(':')[0]) * 60 + int(txt.split(',')[1].split(':')[1]))
    return musicEnd - musicStart

def getMusicName(txt):
    return txt.split(',')[2]

def getMusicInfo(txt):
    return txt.split(',')[-1]

def makeReplace(txt):
    return txt.replace('C#', 'c').replace('D#', 'd').replace('F#')
    

def cutmusic(txt):
    musicTime = getMusicTime(txt)
    musicInfo = getMusicInfo(txt)
    musicPlayed = ""
    
    i = 0
    while True:
        if i >= musicTime:
            break
            
        musicPlayed += musicInfo[i % len(musicInfo)]
        
        if musicInfo[(i + 1) % len(musicInfo)] == '#':
            musicPlayed += musicInfo[(i + 1) % len(musicInfo)]
            i += 1
            musicTime += 1
        i += 1
        
    return musicPlayed
    

def solution(m, musicinfos):
    musicPlayed = []
    musicCorrect = []
    
    
    for txt in musicinfos:
        musicPlayed.append(cutmusic(txt))
        
        if cutmusic(txt).find(m) != -1 and cutmusic(txt).find(m + "#") == -1:
            musicCorrect.append(txt)
        
        
    
    maxTime = -1
    maxName = ""
    for music in musicCorrect:
        if getMusicTime(music) > maxTime:
            maxName = getMusicName(music)
            maxTime = getMusicTime(music)
    
    if maxTime == -1:
        return "(None)"
    return maxName