// https://www.acmicpc.net/problem/16719
#include <stdio.h>
#include <string.h>

char originalTxt[101];
int visited[101];
int len;

void printTXT() {
    for(int i = 0; i < len; ++i) {
        if(visited[i]) printf("%c", originalTxt[i]);
    }
    printf("\n");
}

void back(int left, int right) {
    if(left > right) return;

    if(left == right) {
        visited[left] = 1;
        printTXT();
        return;
    }

    int min = left;
    for(int i = left; i <= right; ++i) {
        if(originalTxt[i] < originalTxt[min]) {
            min = i;
        }
    }

    visited[min] = 1;
    printTXT();

    back(min + 1, right);
    back(left, min - 1);
}

int main() {
    scanf("%s", originalTxt);
    len = strlen(originalTxt);
    back(0, len-1);
    return 0;
}