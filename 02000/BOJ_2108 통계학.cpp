// https://www.acmicpc.net/problem/2108
#include <iostream>
#include <algorithm>

using namespace std;

int arr[500010];
int chebin[8010];

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr+n);

    for(int i = 0; i < n; ++i) chebin[arr[i] + 4000]++;
    
    int mx = 0, tmp = 1;
    for(int i = 0; i <= 8010; ++i) {
        if(chebin[i] > chebin[mx]) {
            mx = i;
            tmp = 1;
        }
        else if(chebin[i] == chebin[mx]) tmp++;
    }

    if(tmp > 1) {
        int t = 0;
        for(int i = 0; i <= 8010; ++i)
        {
            if(chebin[mx] == chebin[i]) t++;
            if(t == 2) {
                mx = i;
                break;
            }
        }
    }
    

    if(sum >= 0) printf("%d\n", ((double)sum / n) - ((int)sum / n) < 0.5 ? ((int)sum / n) : ((int)sum / n) + 1); // 산술평균
    else printf("%d\n", ((int)sum / n) - ((double)sum / n) < 0.5 ? ((int)sum / n) : ((int)sum / n)-1); // 산술평균
    printf("%d\n", arr[n / 2]); // 중앙값
    printf("%d\n", mx-4000); // 최빈값
    printf("%d\n", arr[n - 1] - arr[0]); // 범위
}