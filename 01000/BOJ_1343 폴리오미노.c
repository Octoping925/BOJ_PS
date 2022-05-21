// https://www.acmicpc.net/problem/1343
#include <stdio.h>
#include <string.h>

char map[51];

int getLen(int start, int bound) {
    int idx = start;
    while(idx < bound && map[idx] == 'X') {
        ++idx;
    }
    return idx - start;
}

int main()
{
    scanf("%s", map);
    int len = strlen(map);
    
    for(int i = 0; i < len; ++i) {
        if(map[i] == 'X') {
            int xLen = getLen(i, len);
            if(xLen % 2 == 1) {
                printf("-1");
                return 0;
            }
            else if(xLen == 2) {
                map[i] = map[i+1] = 'B';
                i++;
            }
            else {
                map[i] = map[i+1] = map[i+2] = map[i+3] = 'A';
                i += 3;
            }
        }
    }
    
    printf("%s", map);
    return 0;
}
