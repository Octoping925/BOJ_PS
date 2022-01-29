// https://www.acmicpc.net/problem/2580
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sudoku[10][10];
int unsolved[82][2];

int garo[10][10], sero[10][10], square[10][10][10];
int blank = 0;

// int check(int x, int y, int num)
// {
//     for(int i = 1; i <= 9; ++i){
//         if(sudoku[x][i] == num) return 0;
//         if(sudoku[i][y] == num) return 0;
//     }
//     int tmpX = (x-1)/3*3+1, tmpY = (y-1)/3*3+1;
//     for(int i = tmpX; i <= tmpX+2; ++i)
//         for(int j = tmpY; j <= tmpY+2; ++j)
//             if(sudoku[i][j] == num) return 0;

//     return 1;
// }


void solve(int cnt)
{
    while(cnt < blank)
    {
        for(int i = cnt; i < blank; ++i)
        {
            int ux = unsolved[i][0], uy = unsolved[i][1];
            
            if(sudoku[ux][uy] == 0)
            {
                for(int k = 1; k <= 9; ++k)
                {
                    if(garo[ux][k] == 0 && sero[uy][k] == 0 && square[(ux-1)/3*3+1][(uy-1)/3*3+1][k] == 0) {
                        garo[ux][k] = sero[uy][k] = square[(ux-1)/3*3+1][(uy-1)/3*3+1][k] = 1;
                        sudoku[ux][uy] = k;
                        solve(cnt + 1);
                        garo[ux][k] = sero[uy][k] = square[(ux-1)/3*3+1][(uy-1)/3*3+1][k] = 0;
                        sudoku[ux][ux] = 0;
                    }
                }
            }
            assert(1==1);
        }
    }

    for(int i = 1; i < 10; ++i) {
        for(int j = 1; j < 10; ++j)
            printf("%d ", sudoku[i][j]);
        printf("\n");
    }
    exit(0);
}

int main()
{
    for(int i = 1; i < 10; ++i) {
        for(int j = 1; j < 10; ++j) {
            scanf("%d", &sudoku[i][j]);
            unsolved[blank][0] = i;
            unsolved[blank][1] = j;
            garo[i][num] = 1;
            sero[j][num] = 1;
            square[(i-1)/3*3+1][(j-1)/3*3+1][num] = 1;
            if(sudoku[i][j] == 0) ++blank;
        }
    }


    solve(0);
}