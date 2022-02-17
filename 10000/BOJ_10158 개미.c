// https://www.acmicpc.net/problem/10158
#include <stdio.h>

int min(int x, int y, int z) {
    if(x < y) {
        if(x < z) return x;
        if(y < z) return y;
        return z;
    }
    if(y < z) return y;
    return z;
}

int w, h, p, k, t;
int memorizeUP[40010][2];
int memorizeRIGHT[40010][2];

int main()
{
    scanf("%d %d", &w, &h);
    scanf("%d %d", &p, &k);
    scanf("%d", &t);

    int x = p, y = k, sw = 0;
    int dir = 0, cnt = t;
    while(cnt > 0)
    {
        int len;
        switch(dir)
        {
            case 0:
                len = min(w-x, h-y, cnt);
                x += len;
                y += len;
                cnt -= len;
                if(x == w) {
                    if(memorizeRIGHT[y][0] == 0) {
                        memorizeRIGHT[y][0] = cnt;
                        memorizeRIGHT[y][1] = dir;
                        dir = 3;
                    }
                    else if(memorizeRIGHT[y][1] == dir && cnt != 0 && sw == 0) {
                        int cycle = memorizeRIGHT[y][0] - cnt;
                        cnt = t % cycle;
                        x = p, y = k, dir = 0;
                        memorizeRIGHT[y][0] = 0;
                        sw = 1;
                    }
                    else dir = 3;
                }
                else if(y == h) {
                    if(memorizeUP[x][0] == 0) {
                        memorizeUP[x][0] = cnt;
                        memorizeUP[x][1] = dir;
                        dir = 1;
                    }
                    else if(memorizeUP[x][1] == dir && cnt != 0 && sw == 0) {
                        int cycle = memorizeUP[x][0] - cnt;
                        cnt = t % cycle;
                        x = p, y = k, dir = 0;
                        memorizeUP[x][0] = 0;
                        sw = 1;
                    }
                    else dir = 1;
                }
                break;
            case 1:
                len = min(w-x, y, cnt);
                x += len;
                y -= len;
                cnt -= len;
                if(x == w) dir = 2;
                else if(y == 0) dir = 0;
                break;
            case 2:
                len = min(x, y, cnt);
                x -= len;
                y -= len;
                cnt -= len;
                if(x == 0) dir = 1;
                else if(y == 0) dir = 3;
                break;
            case 3:
                len = min(x, h-y, cnt);
                x -= len;
                y += len;
                cnt -= len;
                if(x == 0) dir = 0;
                else if(y == h) dir = 2;
                break;
        }
    }
    printf("%d %d", x, y);
}