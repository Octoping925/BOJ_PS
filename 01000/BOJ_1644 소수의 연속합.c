// https://www.acmicpc.net/problem/1644
#include <stdio.h>

int prime[4000010] = {0, 0, 1, 1,};
int arr[2000010];
int n, chk;

int min(int x, int y) {
    return x < y ? x : y;
}

void erathos(int n) {
    for(int i = 2; i <= n; ++i) {
        if(prime[i]) {
            for(int j = i+i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i <= n; ++i)
        prime[i] = 1;

    erathos(n);

    int len = 0;
    for(int i = 2; i <= n; ++i) {
        if(prime[i]) arr[++len] = i;
    }

    int p1 = 1;
    int p2 = 1;
    int sum = arr[1];
    int caseCnt = 0;

    while(p1 <= len) {
        if(sum < n) {
            if(p2 == len) {
                break;
            }
            p2++;
            sum += arr[p2];
        }
        else if(sum > n){
            if(p1 == p2) {
                p2++;
                sum += arr[p2];
            }
            else {
                sum -= arr[p1];
                p1++;
            }
        }
        else {
            ++caseCnt;
            if(p1 == len && p2 == len) {
                break;
            }
            if(p1 == p2) {
                p2++;
                sum += arr[p2];
            }
            else {
                sum -= arr[p1];
                p1++;
            }
        }
    }

    printf("%d", caseCnt);
    return 0;
}