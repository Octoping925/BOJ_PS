// https://www.acmicpc.net/problem/14467
#include <stdio.h>

int status[11] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
    {
        int cow, st;
        scanf("%d %d", &cow, &st);

        switch(status[cow])
        {
        case -1:
            status[cow] = st;
            break;

        case 0:
            if(st == 1) ++cnt;
            status[cow] = st;
            break;

        case 1:
            if(st == 0) ++cnt;
            status[cow] = st;
            break;
        }
    }
    printf("%d", cnt);
}