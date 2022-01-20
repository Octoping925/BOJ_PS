// https://www.acmicpc.net/problem/3409

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int testcaseCnt;
    scanf("%d", &testcaseCnt);

    for(int xx = 0; xx < testcaseCnt; ++xx)
    {
        int K;
        scanf("%d", &K);

        string *vars = new string[K + 1];
        string exp[510][2]; // 2차원 배열은 new로 선언하기 너무 귀찮다
        int *uncompleted = new int[K + 1];

        for(int i = 0; i < K; ++i)
        {
            string txt;
            scanf("%s", &txt);


        }
        

    }
}