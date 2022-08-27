// https://www.acmicpc.net/problem/14002
#include <stdio.h>

int arr[1000001], lis[1000001], history[1000001], realLis[1000001];
int topIdx = -1, n;

int binarySearch(int left, int right, int num) {
    int mid = (left + right) / 2;
    if(lis[mid] == num) return mid;

    if(lis[mid] < num) {
        if(lis[mid + 1] > num) return mid + 1;
        return binarySearch(mid + 1, right, num);
    }
    else {
        if(lis[mid - 1] < num) return mid;
        return binarySearch(left, mid - 1, num);
    }
}

int lowerBound(int num) {
    return binarySearch(0, topIdx, num);
}

void addLast(int num, int i) {
    lis[++topIdx] = num;
    history[i] = topIdx;
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    addLast(arr[0], 0);

    for(int i = 1; i < n; ++i) {
        if(arr[i] > lis[topIdx]) {
            addLast(arr[i], i);
        }
        else {
            int idx = lowerBound(arr[i]);
            lis[idx] = arr[i];
            history[i] = idx;
        }
    }

    printf("%d\n", topIdx + 1);


    int len = topIdx;
    for(int i = n - 1; i >= 0; --i) {
        if(history[i] == len) {
            realLis[topIdx - len] = arr[i];
            len--;
        }
    }

    for(int i = topIdx; i >= 0; --i) {
        printf("%d ", realLis[i]);
    }
}