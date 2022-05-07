// https://www.acmicpc.net/problem/1270
#include <stdio.h>
#include <algorithm>

int n;
long arr[100010];

int main()
{
    scanf("%d", &n);
    while(n--) {
        int k;
        scanf("%d", &k);
        for(int i = 0; i < k; ++i) {
            scanf("%ld", &arr[i]);
        }
        std::sort(arr, arr+k);
        if(k == 1) {
            printf("%ld\n", arr[0]);
            continue;
        }

        int sw = 0;
        long num = arr[0], count = 1;
        for(int i = 1; i < k; ++i) {
            if(num == arr[i]) count++;
            else {
                num = arr[i];
                count = 1;
            }
            if(count > k/2) {
                printf("%ld\n", num);
                sw = 1;
                break;
            }
        }
        if(!sw) {
           printf("SYJKGW\n");
        }
    }
}