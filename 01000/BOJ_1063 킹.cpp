// https://www.acmicpc.net/problem/1063
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Stone {
public:
    char X;
    int Y;
    
    bool canGoL() { return X != 'A'; }
    bool canGoR() { return X != 'H'; }
    bool canGoB() { return Y != 1; }
    bool canGoT() { return Y != 8; }
    void goL() { X--; }
    void goR() { X++; }
    void goB() { Y--; }
    void goT() { Y++; }
    void goLB() { goL(), goB(); }
    void goLT() { goL(), goT(); }
    void goRB() { goR(), goB(); }
    void goRT() { goR(), goT(); }

    bool operator == (const Stone& s) {
        return X == s.X && Y == s.Y;
    }
};

int main()
{
    int n;
    Stone king, dol;
    scanf("%c%d %c%d %d", &king.X, &king.Y, &dol.X, &dol.Y, &n);

    for(int i = 0; i < n; ++i)
    {
        string order;
        cin >> order;
        if(order.compare("R") == 0) { // x++
            if(!king.canGoR()) continue;
            king.goR();

            if(king == dol) {
                if(dol.canGoR()) dol.goR();
                else king.goL();
            }
        }
        else if(order.compare("L") == 0) { // x--
            if(!king.canGoL()) continue;
            king.goL();

            if(king == dol) {
                if(dol.canGoL()) dol.goL();
                else king.goR();
            }
        }
        else if(order.compare("B") == 0) { // y--
            if(!king.canGoB()) continue;
            king.goB();

            if(king == dol) {
                if(dol.canGoB()) dol.goB();
                else king.goT();
            } 
            
        }
        else if(order.compare("T") == 0) { // y++
            if(!king.canGoT()) continue;
            king.goT();

            if(king == dol) {
                if(dol.canGoT()) dol.goT();
                else king.goB();
            }
            
        }
        else if(order.compare("RT") == 0) { // x++ y++
            if(!king.canGoR() || !king.canGoT()) continue;
            king.goRT();
    
            if(king == dol) {
                if(dol.canGoR() && dol.canGoT()) dol.goRT();
                else king.goLB();
            }
        }
        else if(order.compare("LT") == 0) { // x-- y++
            if(!king.canGoL() || !king.canGoT()) continue;
            king.goLT();

            if(king == dol) {
                if(dol.canGoL() && dol.canGoT()) dol.goLT();
                else king.goRB();
            }
        }
        else if(order.compare("RB") == 0) { // x++ y--
            if(!king.canGoR() || !king.canGoB()) continue;
            king.goRB();

            if(king == dol) {
                if(dol.canGoR() && dol.canGoB()) dol.goRB();
                else king.goLT();
            }
        }
        else { // if(order.compare("LB") == 0)  // x-- y--
            if(!king.canGoL() || !king.canGoB()) continue;
            king.goLB();
    
            if(king == dol) {
                if(dol.canGoL() && dol.canGoB()) dol.goLB();
                else king.goRT();
            }
        }
    }

    printf("%c%d\n%c%d", king.X, king.Y, dol.X, dol.Y);
}