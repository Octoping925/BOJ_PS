// D번
// 고른 애보다 오른쪽 아래만 가면 된다. ESM순서대로.

//DFS
// 시간복잡도? 3000

// S만 탐색하면서, 왼쪽위의 E의 개수와 오른쪽 아래의 M의 개수를 기록.
// 그 후 S를 돌면서 E*M을 sum에 더함


// 900만 좌표 중 500만개가 S라 치자.
// 그러면 500만개의 S가 900만 좌표를 순회함 = ㅋㅋ 씨발

// #include <stdio.h>

char arr[3010][3010];

int main()
{
    int n, m;
    scanf("%d %d\n", &n, &m);

    for(int i = 0; i < n; ++i)
        scanf("%s", arr+i);
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}