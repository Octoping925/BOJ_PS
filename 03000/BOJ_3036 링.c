// https://www.acmicpc.net/problem/3036
#include <stdio.h>

void abbreviation(int first, int k) {
    int min = first < k ? first : k;
    for(int i = 2; i <= min; ++i) {
        if(first % i == 0 && k % i == 0) {
            first /= i;
            k /= i;
            i--;
        }
    }

    printf("%d/%d\n", first, k);
}

int main()
{
    int n;
    scanf("%d", &n);

    int first;
    scanf("%d", &first);

    while(--n) {
        int k;
        scanf("%d", &k);
        abbreviation(first, k);
    }
}