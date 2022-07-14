// https://www.acmicpc.net/problem/10807
#include <stdio.h>
int arr[100];
int n, k, cnt;
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;++i) scanf("%d",&arr[i]);
    scanf("%d", &k);
    for(int i=0;i<n;++i) if(arr[i]==k) ++cnt;
    printf("%d", cnt);
    return 0;
}