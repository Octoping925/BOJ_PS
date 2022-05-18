// https://www.acmicpc.net/problem/16139
#include <stdio.h>
#include <string.h>

int arr[200010][26];
char txt[200010];
int main()
{
    scanf("%s", txt);
    int len = strlen(txt);

    for(int i = 1; i <= len; ++i) {
        for(int j = 0; j < 26; ++j) {
            arr[i][j] = arr[i - 1][j];
            if(j == txt[i-1] - 'a') {
                arr[i][j]++;
            }
        }
    }

    int n;
    scanf("%d", &n);

    while(n--) {
        char x;
        int start, end;
        scanf(" %c %d %d", &x, &start, &end);

        printf("%d\n", arr[end + 1][x-'a'] - arr[start][x-'a']);
    }
}
