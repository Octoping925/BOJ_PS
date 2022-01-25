// https://www.acmicpc.net/problem/9012
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string txt;
    for(int i = 0 ; i < n; ++i)
    {
        cin >> txt;
        
        stack<char> par;
        bool chk = true;
        for(char j : txt)
        {
            if(j == '(')
                par.push(j);
            else if(j == ')')
            {
                if(par.empty()) {
                    chk = false;
                    break;
                }
                par.pop();
            }
        }
        if(chk && par.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}