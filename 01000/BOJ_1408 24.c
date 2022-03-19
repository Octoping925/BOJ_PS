// https://www.acmicpc.net/problem/1408
#include <stdio.h>

int printtwo(int h, int m, int d) {
    if(h < 10) printf("0");
    printf("%d:", h);
    if(m < 10) printf("0");
    printf("%d:", m);
    if(d < 10) printf("0");
    printf("%d", d);
    
}

int main()
{
    int hh, mm, dd;
    int hh2, mm2, dd2;

    scanf("%d:%d:%d", &hh, &mm, &dd);
    scanf("%d:%d:%d", &hh2, &mm2, &dd2);

    int t = (hh2 * 3600 + mm2 * 60 + dd2) - (hh * 3600 + mm * 60 + dd);
    if(t < 0) t += 3600 * 24;
    
    int h = t / 3600;
    int m = t % 3600 / 60;
    int d = t % 60;
    
    printtwo(h, m, d);
}