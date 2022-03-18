// https://www.acmicpc.net/problem/16466
#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[1000000];

int main()
{
    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    sort(arr, arr+n);
    int answer = 1;
    for(int i : arr)
        if(answer == i) ++answer;

    cout << answer;
}