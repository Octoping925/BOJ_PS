// https://www.acmicpc.net/problem/9012
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    char txt[51];
    while(n--) {
        scanf("%s", txt);
        
        int size = 0, chk = 1;
        for(int j = 0; j < strlen(txt); ++j) {
            if(txt[j] == '(') {
                size++;
            }
            else if(txt[j] == ')') {
                if(size == 0) {
                    chk = 0;
                    break;
                }
                size--;
            }
        }
        if(chk && size == 0) printf("YES\n");
        else printf("NO\n");
    }
}