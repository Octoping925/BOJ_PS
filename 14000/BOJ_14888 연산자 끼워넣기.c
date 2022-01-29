// https://www.acmicpc.net/problem/14888
#include <stdio.h>

char op[4] = {'+', '-', '*', '/'};
int nums[12], operators[5];
int opcnt[5];
char arr[12];

int n, max=-2147345468, min=2147345468;

void recursive(int depth)
{
    if(depth == n-1) {
        int sum = nums[0];
        for(int i = 0; i < n-1; ++i)
        {
            switch(arr[i])
            {
                case '+':
                    sum += nums[i+1];
                    break;
                case '-':
                    sum -= nums[i+1];
                    break;
                case '*':
                    sum *= nums[i+1];
                    break;
                case '/':
                    sum /= nums[i+1];
                    break;
            }
        }
        if(sum > max) max = sum;
        if(sum < min) min = sum;
        return;
    }
    else
    {
        for(int i = 0; i < 4; ++i)
        {
            if(opcnt[i] < operators[i]) {
                arr[depth] = op[i];
                ++opcnt[i];
                recursive(depth + 1);
                --opcnt[i];
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i)
        scanf("%d", &nums[i]);
    for(int i = 0; i < 4; ++i)
        scanf("%d", &operators[i]);
    
    recursive(0);
    printf("%d\n%d", max, min);
}