// https://www.acmicpc.net/problem/1316
#include <stdio.h>
#include <string.h>

char txt[101];

int main()
{
    int n, sum;
    scanf("%d", &n);
    sum = n;
    
    for(int i = 0; i < n; ++i)
    {
        scanf("%s", txt);
        int alpha[30] = { 0, };
        
        for(int j = 0; j < strlen(txt); ++j)
        {
            if(!alpha[txt[j] - 'a']) ++alpha[txt[j] - 'a'];
            else if(txt[j - 1] == txt[j]) ++alpha[txt[j] - 'a'];
            else {
                sum--;
                break;
            }
        }
    }
    printf("%d", sum);
}