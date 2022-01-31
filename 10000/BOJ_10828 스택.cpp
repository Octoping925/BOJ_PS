// https://www.acmicpc.net/problem/10828
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string txt;
    stack<int> stack;
    
    for(int i = 0; i < n; ++i)
    {
        cin >> txt;
        
        if(txt.compare("push") == 0) {
            int k;
            cin >> k;
            stack.push(k);
        }
        else if(txt.compare("pop") == 0) {
            if(stack.empty() == 1)
                cout << "-1" << endl;
            else {
                cout << stack.top() << endl;
                stack.pop();
            }
        }
        else if(txt.compare("size") == 0) {
            cout << stack.size() << endl;
        }
        else if(txt.compare("empty") == 0) {
            if(stack.empty() == 1)
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
        else if(txt.compare("top") == 0) {
            if(stack.empty() == 1)
                cout << "-1" << endl;
            else
                cout << stack.top() << endl;
                
        }
    }

    return 0;
}
