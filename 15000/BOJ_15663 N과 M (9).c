// https://www.acmicpc.net/problem/15663
#include <stdio.h>

int n, m, len;
int freq[10010];
int arr[9];
int barr[9];

void back(int depth, int idx) {
    if(depth == m) {
        for(int i = 0; i < m; ++i) {
            printf("%d ", barr[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 0; i < len; ++i) {
        if(freq[arr[i]] > 0) {
            barr[depth] = arr[i];
            freq[arr[i]]--;
            back(depth + 1, i);
            freq[arr[i]]++;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        freq[k]++;
    }

    for(int i = 0; i < 10010; ++i) {
        if(freq[i]) {
            arr[len++] = i;
        }
    }

    back(0, -1);
}