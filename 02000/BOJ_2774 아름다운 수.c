// https://www.acmicpc.net/problem/2774
#include <stdio.h>

int n, num;
int cnt[10];

int main() {
    scanf("%d", &n);

    while(n--) {
        scanf("%d", &num);
        while (num > 0) {
            cnt[num % 10]++;
            num /= 10;
        }

        int answer = 0;
        for (int i = 0; i < 10; ++i) {
            if(cnt[i]) answer++;
            cnt[i] = 0;
        }

        printf("%d\n", answer);
    }
}