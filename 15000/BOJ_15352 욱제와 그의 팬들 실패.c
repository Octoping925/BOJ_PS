// https://www.acmicpc.net/problem/10814
#include <stdio.h>

int n, k;
int arr[1000010], xy[1000010][2];

int giveLeft(int x)
{
    int group = arr[x];
    int pos = xy[x][0];
    int cnt = 0;
    while(pos != -1 && arr[pos] == group) {
        ++cnt;
        pos = xy[pos][0];
    }
    return cnt;
}
int giveRight(int x)
{
    int group = arr[x];
    int pos = xy[x][1];
    int cnt = 0;
    while(pos != -1 && arr[pos] == group) {
        ++cnt;
        pos = xy[pos][1];
    }
    return cnt;
}

int main()
{
    scanf("%d %d", &k, &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
        xy[i][0] = i - 1;
        xy[i][1] = i + 1;
    }
    xy[1][0] = xy[n][1] = -1;

    int q, gift = 0;
    scanf("%d" ,&q);
    for(int i = 0; i < q; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if(a == 1) {
            arr[b] = 0;
            xy[xy[b][1]][0] = xy[b][0];
            xy[xy[b][0]][1] = xy[b][1];
        }
        else {
            gift++;
            gift += giveLeft(b);
            gift += giveRight(b);
        }
    }
    printf("%d", gift);
}