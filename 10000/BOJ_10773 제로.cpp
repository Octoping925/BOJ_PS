// https://www.acmicpc.net/problem/10773
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    stack<int> stack;
    for(int i = 0 ; i < n; ++i)
    {
        int k;
        cin >> k;
        
        if(k == 0)
            stack.pop();
        else
            stack.push(k);
    }
    
    int sum = 0;
    while(!stack.empty())
    {
        sum += stack.top();
        stack.pop();
    }
    
    cout << sum;
}