// https://www.acmicpc.net/problem/3029
#include <stdio.h>

typedef struct time {
    int hour;
    int minute;
    int second;
} Time;

Time subtractTime(Time x, Time y) {
    int xx = x.hour * 3600 + x.minute * 60 + x.second;
    int yy = y.hour * 3600 + y.minute * 60 + y.second;

    xx -= yy;
    if(xx <= 0) xx += 3600 * 24;

    Time result;
    result.hour = xx / 3600;
    result.minute = (xx % 3600) / 60;
    result.second = xx % 60;
    return result;
}

void printTime(Time x) {
    if(x.hour < 10) printf("0");
    printf("%d:", x.hour);
    if(x.minute < 10) printf("0");
    printf("%d:", x.minute);
    if(x.second < 10) printf("0");
    printf("%d", x.second);
}

int main()
{
    Time start, end;

    scanf("%d:%d:%d", &start.hour, &start.minute, &start.second);
    scanf("%d:%d:%d", &end.hour, &end.minute, &end.second);

    printTime(subtractTime(end, start));
    return 0;
}