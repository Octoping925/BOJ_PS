// https://www.acmicpc.net/problem/1063
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>

int main()
{
    char X1, X2;
    int kingX, kingY, dolX, dolY, n;
    scanf("%c%d %c%d %d", &X1, &kingY, &X2, &dolY, &n);
    kingX = X1 - 'A' + 1;
    dolX = X2 - 'A' + 1;

    for(int i = 0; i < n; ++i)
    {
        std::string order = "";
        std::cin >> order;
        //printf("\n%c%d %c%d", kingX+'A'-1, kingY, dolX+'A'-1, dolY);
        //printf("\n%d%d %d%d", kingX, kingY, dolX, dolY);
        if(order.compare("R") == 0) { // x++
            if(kingX == 8) continue;
    
            if(kingX + 1 == dolX) {
                if(dolX == 8) continue;
                ++dolX;
            }
            ++kingX;
        }
        else if(order.compare("L") == 0) { // x--
            if(kingX == 1) continue;
            
            if(kingX - 1 == dolX) {
                if(dolX == 1) continue;
                --dolX;
            }
            --kingX;
        }
        else if(order.compare("B") == 0) { // y--
            if(kingY == 1) continue;
            
            if(kingY - 1 == dolY) {
                if(dolY == 1) continue;
                --dolY;
            }
            --kingY;
        }
        else if(order.compare("T") == 0) { // y++
            if(kingY == 8) continue;
            
            if(kingY + 1 == dolY) {
                if(dolY == 8) continue;
                ++dolY;
            }
            ++kingY;
        }
        else if(order.compare("RT") == 0) { // x++ y++
            if(kingX == 8 || kingY == 8) continue;
    
            if(kingX + 1 == dolX && kingY + 1 == dolY) {
                if(dolX == 8 || dolY == 8) continue;
                ++dolX;
                ++dolY;
            }
            ++kingX;
            ++kingY;
        }
        else if(order.compare("LT") == 0) { // x-- y++
            if(kingX == 1 || kingY == 8) continue;
    
            if(kingX - 1 == dolX && kingY + 1 == dolY) {
                if(dolX == 1 || dolY == 8) continue;
                --dolX;
                ++dolY;
            }
            --kingX;
            ++kingY;
        }
        else if(order.compare("RB") == 0) { // x++ y--
            if(kingX == 8 || kingY == 1) continue;
    
            if(kingX + 1 == dolX && kingY - 1 == dolY) {
                if(dolX == 8 || dolY == 1) continue;
                ++dolX;
                --dolY;
            }
            ++kingX;
            --kingY;
        }
        else { // if(order.compare("LB") == 0)  // x-- y--
            if(kingX == 1 || kingY == 1) continue;
    
            if(kingX - 1 == dolX && kingY - 1 == dolY) {
                if(dolX == 1 || dolY == 1) continue;
                --dolX;
                --dolY;
            }
            --kingX;
            --kingY;
        }
    }

    printf("%c%d\n%c%d", kingX+'A'-1, kingY, dolX+'A'-1, dolY);
}