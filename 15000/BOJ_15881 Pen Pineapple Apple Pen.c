// https://www.acmicpc.net/problem/15881
#include <stdio.h>

int cnt, sw;

int main()
{
    int n;
    scanf("%d", &n);

    while(n--) {
        char k;
        scanf(" %c", &k);

        switch(k) {
            case 'p':
                if(sw == 3) {
                    cnt++;
                    sw = 0;
                }
                else {
                    sw = 1;
                }
                break;
            case 'P':
                sw = sw == 1 ? 2 : 0;
                break;
            case 'A':
                sw = sw == 2 ? 3 : 0;
        }
    }

    printf("%d", cnt);
}