// https://www.acmicpc.net/problem/9913
#include <stdio.h>

int freq[1001];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        freq[k]++;
    }

    int maxFreqidx = 1;
    for(int i = 2; i <= 1000; ++i) {
        if(freq[i] > freq[maxFreqidx]) {
            maxFreqidx = i;
        }
    }

    printf("%d", freq[maxFreqidx]);
    return 0;
}