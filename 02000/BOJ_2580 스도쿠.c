// https://www.acmicpc.net/problem/2580
// #include <stdio.h>

int sudoku[10][10];
int garoCompleted[10];
int seroCompleted[10];
int squareComplted[10];

int solveGaro(int x)
{

}

int solveSero(int x)
{

}

int solveSquare(int x)
{

}




void solve()
{

}

int main()
{
    for(int i = 1; i < 10; ++i)
        for(int j = 1; j < 10; ++j)
            scanf("%d", &sudoku[i][j]);


    solve();

    for(int i = 1; i < 10; ++i) {
        for(int j = 1; j < 10; ++j)
            printf("%d ", sudoku[i][j]);
        printf("\n");
    }
}