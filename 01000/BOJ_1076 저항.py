# https://www.acmicpc.net/problem/1076
resistance = {'black':0, 'brown':1, 'red':2, 
    'orange':3, 'yellow':4, 'green':5, 
    'blue':6, 'violet':7, 
    'grey':8, 'white':9}


i1=resistance[input()]
i2=resistance[input()]
i3=resistance[input()]

print((i1*10+i2)*(10**i3))