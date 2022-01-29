// https://www.acmicpc.net/problem/2580
// #include <stdio.h>

int sudoku[10][10];
int garoCompleted[10];
int seroCompleted[10];
int squareComplted[10];

int chkGaro(int x)
{
    for(int i = 1; i < 10; ++i)
        if(sudoku[x][i] == 0) {
            garoCompleted[x] = 0;
            return 0;
        }
}
int chkSero(int x)
{
    for(int i = 1; i < 10; ++i)
    if(sudoku[i][x] == 0) {
        seroCompleted[x] = 0;
        return 0;
    }
}
int chkSquare(int x, int y)
{
    
}

int solveGaro(int x)
{

}

int solveSero(int x)
{

}

int solveSquare(int x, int y)
{

}


void init()
{
    for(int i = 1; i < 10; ++i) {
        chkGaro(i);
        chkSero(i);
    }
}

void solve()
{
    while(1)
    {

    }
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