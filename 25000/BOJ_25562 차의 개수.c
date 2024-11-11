// https://www.acmicpc.net/problem/25562
#include <stdio.h>

int nums[1500];
int cards[30];

int isAble(int cnt, int k) {
    for (int i = 0; i < cnt; ++i) {
        if (nums[k - cards[i]]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", n * (n - 1) / 2);

    int cnt = 0;
    int k = 1;
    while (cnt < n) {
        if (isAble(cnt, k)) {
            for (int i = 0; i < cnt; ++i) {
                nums[k - cards[i]] = 1;
            }

            cards[cnt++] = k;
            printf("%d ", k);
        }

        k++;
    }
    printf("\n");

    printf("%d\n", n - 1);
    for (int i = n; i <= n * n; i += n) {
        printf("%d ", i);
    }
}

/**
 * 최대값 =
 * 최대값 개수 = n(n-1)/2
 * 1 2 4 8 13 19
 * 시작부터 그냥 나온 차가 없는 숫자들로 뽑기 시작하자
 *
 *
 * 최소값 = n의 배수로 짝 짝 뽑으면 됨.
 * 예: 5개 뽑아.  5 10 15 20 25 = 5 10 15 20 해서 n-1개 나옴.
*/
