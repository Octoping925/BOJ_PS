// https://www.acmicpc.net/problem/12014
#include <stdio.h>

int arr[100000], lis[100000];
int topIdx = -1;

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
    int testcase;
    scanf("%d", &testcase);

    for(int tc = 1; tc <= testcase; ++tc) {
        int n, k;
        scanf("%d %d", &n, &k);
        topIdx = -1;

        for(int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
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

        printf("Case #%d\n", tc);
        printf("%d\n", topIdx + 1 >= k);
    }
}