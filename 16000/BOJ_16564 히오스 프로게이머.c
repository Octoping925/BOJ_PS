// https://www.acmicpc.net/problem/16564
#include <stdio.h>

long long arrSum;
int arr[1000010];
int n, k;

long long calcPlusLev(int val) {
    long long plusLev = 0;
    for(int i = 0; i < n; ++i) {
        if(val > arr[i]) {
            plusLev += val - arr[i];
        }
    }
    return plusLev;
}

int main()
{
    scanf("%d %d", &n, &k);

    int minLev = 2000000000;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if(minLev > arr[i]) minLev = arr[i];
        arrSum += arr[i];
    }

    int left = minLev + k / n;
    int right = minLev + k;

    while(left < right)
    {
        int mid = (left + right) / 2;

        if(left == mid) {
            if(calcPlusLev(right) > k) right = left;
            else left = right;
            continue;
        }

        long long plusLev = calcPlusLev(mid);

        if(plusLev == k) {
            left = right = mid;
        }
        else if(plusLev > k) {
            right = mid - 1;
        }
        else { // plusLev < k
            left = mid;
        }
    }

    printf("%d", right);
    return 0;
}