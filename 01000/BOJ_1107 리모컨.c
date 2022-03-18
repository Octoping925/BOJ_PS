// https://www.acmicpc.net/problem/1107
// #include <stdio.h>

int num[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int n, m;

int concat(int x, int y) {
    return x * 10 + y;
}

int firstnum(int x) {
    if(x < 10) return x;
    return firstnum(x / 10);
}

int intlen(int x) {
    if(x < 10) return 1;
    return intlen(x / 10) + 1;
}

int main()
{
    scanf("%d\n%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int k;
        scanf("%d", &k);
        --num[k];
    }

    // 작은 수 찾기
    int smallNum;
    for(int i = 0; i <= ; ++i) {

    }

    // 큰 수 찾기
    int bigNum;

    // 비교
    
}