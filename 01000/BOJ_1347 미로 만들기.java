// https://www.acmicpc.net/problem/1347
import java.io.*;
import java.util.*;

class Human
{
    // dir 0 = 아래, 1 = 왼쪽, 2 = 위, 3 = 오른쪽
    int direction;
    public int x, y;

    Human() {
        direction = 0;
        x = 100;
        y = 100;
    }

    void turnLeft() {
        direction = (3 + direction) % 4;
    }
    void turnRight() {
        direction = (direction + 1) % 4;
    }
    void goForward() {
        if(direction == 0) x++;
        else if(direction == 1) y--;
        else if(direction == 2) x--;
        else y++;
    }
}

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        String note = br.readLine();

        int map[][] = new int[200][200];
        Human hj = new Human();

        int leftEnd = 100;
        int rightEnd = 100;
        int upEnd = 100;
        int downEnd = 100;
        map[100][100] = 1;
        
        for(char i : note.toCharArray()) {
            if(i == 'L') hj.turnLeft();
            else if(i == 'R') hj.turnRight();
            else if(i == 'F') {
                hj.goForward();
                map[hj.x][hj.y] = 1;

                if(hj.y < leftEnd)
                    leftEnd = hj.y;
                if(hj.x < upEnd)
                    upEnd = hj.x;
                if(hj.y > rightEnd)
                    rightEnd = hj.y;
                if(hj.x > downEnd)
                    downEnd = hj.x;
            }
        }

        for(int i = upEnd; i <= downEnd; ++i) {
            for(int j = leftEnd; j <= rightEnd; ++j) {
                if(map[i][j] == 1) System.out.print('.');
                else System.out.print('#');
            }
            System.out.println();
        }
        
        return;
    }
}
