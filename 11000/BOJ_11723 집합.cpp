// https://www.acmicpc.net/problem/11723
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int bitmask = 0;

    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int k;
        string txt;

        cin >> txt;

        if(txt.compare("add") == 0) {
            cin >> k;
            bitmask |= (1 << k);
        }
        else if(txt.compare("remove") == 0) {
            cin >> k;
            bitmask &= ~(1 << k);
        }
        else if(txt.compare("check") == 0) {
            cin >> k;
            cout << ((bitmask & (1 << k)) != 0) << "\n";
        }
        else if(txt.compare("toggle") == 0) {
            cin >> k;
            if(bitmask & (1 << k)) bitmask &= ~(1 << k);
            else bitmask |= (1 << k);
        }
        else if(txt.compare("all") == 0) bitmask = (1 << 21) - 1;
        else if(txt.compare("empty") == 0) bitmask = 0;
    }
}