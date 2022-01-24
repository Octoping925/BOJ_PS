# https://www.acmicpc.net/problem/1076

# arr = ["black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"]

# for _ in range(3):
#     idx = arr.index(input())

#     if _ < 2:
#         print(idx, end='')
#     else:
#         print('0' * idx)


resistance = {'black':[0, 1], 'brown':[1,10], 'red':[2,100], 
    'orange':[3,1000], 'yellow':[4, 10000], 'green':[5, 100000], 
    'blue':[6, 1000000], 'violet':[7, 100000000], 
    'grey':[8, 100000000], 'white':[9, 1000000000]}


result = ''
for i in range(3):
    getColor = str(input())
    if i==0 or i==1:
        result += str(resistance[getColor][0])
    else: 
        result = str(resistance[getColor][1] * int(result))

print(int(result))