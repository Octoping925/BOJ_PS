// https://www.acmicpc.net/problem/1439
#include <stdio.h>
#include <string.h>

char arr[1000010];
int cluster[2];
int arr_len;

int min(int x, int y) {
    return x < y ? x : y;
}

int main()
{
    scanf("%s", arr);
    arr_len = strlen(arr);

    char cur = arr[0];
    cluster[cur-'0']++;

    for(int i = 1; i < arr_len; ++i) {
        if(arr[i] != cur) {
            cluster[arr[i] - '0']++;
        }
        cur = arr[i];
    }

    printf("%d", min(cluster[0], cluster[1]));
    return 0;
}