// https://www.acmicpc.net/problem/1072
#include <stdio.h>

int calcWinRate(int win, int total) {
    return win * (long long) 100 / total;
}

int solution(int win, int total) {
    if (total == win) return -1;

    int prevWinRate = calcWinRate(win, total);
    if (prevWinRate == 99) return -1;

    int left = 1;
    int right = total;

    while (left < right) {
        int mid = (left + right) / 2;
        int winRate = calcWinRate(win + mid, total + mid);

        if (winRate == prevWinRate) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    printf("%d", solution(y, x));
    return 0;
}
