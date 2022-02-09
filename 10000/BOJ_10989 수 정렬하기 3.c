// https://www.acmicpc.net/problem/10989
// #include <stdio.h>

int counting[10010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        int k;
        scanf("%d", &k);
        counting[k]++;
    }

    for(int i = 1; i <= n; ++i) {
        while(counting[i] > 0) {
            printf("%d\n", i);
            counting[i]--;
        }
    }

    return 0;
}