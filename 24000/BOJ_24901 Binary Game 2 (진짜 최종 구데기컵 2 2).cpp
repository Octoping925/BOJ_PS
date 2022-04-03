#include <iostream>
#include <stack>
using namespace std;

void print(int x) {
    stack<int> st;
    while(x > 0) {
        st.push(x % 2);
        x /= 2;
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i <= n; ++i)
        print(i);
}