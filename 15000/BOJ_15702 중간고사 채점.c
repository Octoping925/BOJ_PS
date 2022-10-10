// https://www.acmicpc.net/problem/15702
#include <stdio.h>

int score[100];

int min(int x, int y) { return x < y ? x : y; }

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &score[i]);
    }

    int maxStudent = 100001;
    int maxScore = -1;

    for(int i = 0; i < m; ++i) {
        int student, studentScore = 0;
        scanf("%d", &student);
        for(int j = 0; j < n; ++j) {
            char k;
            scanf(" %c", &k);

            if(k == 'O') {
                studentScore += score[j];
            }
        }

        if(studentScore > maxScore) {
            maxStudent = student;
            maxScore = studentScore;
        }
        else if(studentScore == maxScore) {
            maxStudent = min(maxStudent, student);
        }
    }

    printf("%d %d", maxStudent, maxScore);
    return 0;
}