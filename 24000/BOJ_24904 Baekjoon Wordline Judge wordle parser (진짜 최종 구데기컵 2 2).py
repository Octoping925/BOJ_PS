f = open("C:\\Users\myc13\\Documents\\BOJ_PS\\BOJ_PS\\24000\\BOJ_24904 Baekjoon Wordline Judge wordlist (진짜 최종 구데기컵 2 2).txt", 'r')

line = ""
while True:
    line = f.readline().split()[0]
    if len(line) == 5:
        if line[2] == 'A' and line[3] == 'S' and line[0] != 'S' and line[1] != 'S' and line[2] != 'S' and line[4] != 'S' and line[0] != 'A' and line[1] != 'A' and line[3] != 'A' and line[4] != 'A' and 'G' not in line and 'R' not in line and 'N' not in line and 'D' not in line and 'T' not in line and 'C' not in line and 'O' not in line:
            print(line)