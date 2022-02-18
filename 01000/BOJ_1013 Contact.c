// https://www.acmicpc.net/problem/1013
// #include <stdio.h>
// #include <string.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; ++testcase)
    {
        char arr[210];
        scanf("%s", arr);
        int len = strlen(arr);

        int sw = 0, i;
        for(i = 0; i < len; ++i) // (100+1+ | 01)+
        {
            if(sw == 0 && arr[i] == '0') {
                if(arr[i + 1] == '1') {  //01 건너뛰기
                    sw = 0;
                    i += 1;
                }
                else {//10011001
                        printf("NO1%d\n",i);
                        break;
                }
            }
            else {
                if(sw == 0 && arr[i] == '1') // 10+ 부분
                {
                    sw = 1;
                    int cnt = 0;
                    while(i < len && arr[i + 1] == '0') ++i, ++cnt;
                    if(cnt == 0) break;
                }
                else if(sw == 1 && arr[i] == '1') // 10+1+ 부분
                {
                    if(i == len - 1) sw = 0;
                    if(arr[i + 1] == '1') continue;
                    else if(arr[i + 2] == '1') {
                        i+=2;
                        sw = 0;
                    }
                    else {
                        while(i < len && arr[i + 1] == '1') ++i;
                        // if(arr[i] == '0') --i;
                    }
                }
                // else if(sw == 2 && arr[i] == '0') {
                    
                //     sw = 0;
                //     i--;
                // }

            }
        }
        if(i == len) {
            if(sw == 1) printf("NO3\n");
            else printf("YES\n");
        }
    }
}