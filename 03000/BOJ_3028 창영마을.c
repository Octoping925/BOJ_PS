// https://www.acmicpc.net/problem/3028
#include <stdio.h>
#include <string.h>

char roll[51];

void rollA(int* pos) {
    if(*pos == 3) return;
    *pos = *pos == 1 ? 2 : 1;
}
void rollB(int* pos) {
    if(*pos == 1) return;
    *pos = *pos == 2 ? 3 : 2;
}
void rollC(int* pos) {
    if(*pos == 2) return;
    *pos = *pos == 1 ? 3 : 1;
}


int main()
{
    gets(roll);
    int len = strlen(roll);
    int pos = 1;

    for(int i = 0; i < len; ++i) {
        switch(roll[i]) {
            case 'A':
                rollA(&pos);
                break;
            case 'B':
                rollB(&pos);
                break;
            case 'C':
                rollC(&pos);
                break;
        }
    }
    printf("%d", pos);
}