// https://www.acmicpc.net/problem/1550
#include <stdio.h>
#include <string.h>
char arr[6];
int main()
{
    scanf("%s", arr);
    int len = strlen(arr);
    
    int pow = 1;
    int answer = 0;
    while(len--){
        if('A' <= arr[len] && arr[len] <= 'F')
            answer += (arr[len] - 'A' + 10) * pow;
        else
            answer += (arr[len] - '0') * pow;
        pow = pow << 4;
    }
    printf("%d",answer);
    
}