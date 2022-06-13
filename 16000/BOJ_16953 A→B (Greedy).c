// https://www.acmicpc.net/problem/16953
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int cnt = 1;
    while(n < m) {
        if(m > 10 && m % 10 == 1) {
            m /= 10;
            ++cnt;
        }
        else if(m % 2 == 0) {
            m /= 2;
            ++cnt;
        }
        else break;
    }
    
    printf("%d", n == m ? cnt : -1);
    return 0;
}

// 만약 m이 1로 끝날 경우, 그건 x10 + 1해서 만들어진 값일 수 밖에 없다.
// 만약 m이 짝수일 경우, 그건 x2 해서 만들어진 값일 수밖에 없다.

// 반대로 연산해나간다면 답을 구할 수 있다.