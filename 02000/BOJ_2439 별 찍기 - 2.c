// https://www.acmicpc.net/problem/2439
#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        for(int j=n-1; j>i; --j) printf(" ");
        for(int j=0; j<=i; ++j) printf("*");
        printf("\n");
    }
    return 0;
}