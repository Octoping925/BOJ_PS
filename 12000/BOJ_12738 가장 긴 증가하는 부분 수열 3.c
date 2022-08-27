// https://www.acmicpc.net/problem/12738
#include <stdio.h>

int arr[1000001], lis[1000001];
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

void addLast(int num) {
    lis[++topIdx] = num;
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        arr[i] += 1000000000;
    }

    addLast(arr[0]);

    for(int i = 1; i < n; ++i) {
        if(arr[i] > lis[topIdx]) {
            addLast(arr[i]);
        }
        else {
            lis[lowerBound(arr[i])] = arr[i];
        }
    }

    printf("%d", topIdx + 1);
}