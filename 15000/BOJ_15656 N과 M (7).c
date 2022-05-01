// https://www.acmicpc.net/problem/15656
#include <stdio.h>

void sort(int *arr, int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(arr[i] < arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int arr[9], barr[9];
int n, m;

void back(int depth) {
    if(depth == m) {
        for(int i = 0; i < depth; ++i)
            printf("%d ", barr[i]);

        printf("\n");
        return;
    }
    for(int i = 0; i < n; ++i) {
        barr[depth] = arr[i];
        back(depth + 1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    sort(arr, n);
    back(0);
    return 0;
}