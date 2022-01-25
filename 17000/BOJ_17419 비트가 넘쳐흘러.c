//K = K-(K&((~K)+1))

// 5
// 10110   -> 3

#include <stdio.h>

char tmp[1000001];
int arr[1000001];
int arr2[1000001];

void normalize()
{

}

int main()
{
    int n;
    scanf("%d\n", &n);
    scanf("%s", arr);

    for(int i = 0; i < n; ++i) {
        arr[i] -= '0';
    }
}
