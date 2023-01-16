// https://www.acmicpc.net/problem/1105
#include <stdio.h>

int isExist8(int x) {
    while(x > 0) {
        int mod = x % 10;
        if(mod == 8) {
            return 1;
        }
        x /= 10;
    }
    return 0;
}

int xArr[11], yArr[11];
int xLen, yLen;

void toArray(int num, int* arr, int* len) {
    int length = 0;
    while(num > 0) {
        arr[length++] = num % 10;
        num /= 10;
    }

    *len = length;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    if(!isExist8(x) || !isExist8(y)) {
        printf("0");
        return 0;
    }

    toArray(x, xArr, &xLen);
    toArray(y, yArr, &yLen);

    if(xLen != yLen) {
        printf("0");
        return 0;
    }

    int cnt = 0;
    for(int i = xLen - 1; i >= 0; --i) {
        if(xArr[i] == 8 && yArr[i] == 8) {
            cnt++;
        }
        else if(xArr[i] == yArr[i]) {
            continue;
        }
        else {
            break;
        }
    }

    printf("%d", cnt);
    return 0;
}