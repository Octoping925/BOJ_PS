// https://www.acmicpc.net/problem/10871
#include <stdio.h>
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    
    for(int i=0; i<n; ++i)
    {
        int t;
        scanf("%d", &t);
        if(t<k) printf("%d ", t);
    }
    return 0;
}