// https://www.acmicpc.net/problem/9290
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= n; ++tc) {
            char[][] map = new char[3][3];
            map[0] = br.readLine().toCharArray();
            map[1] = br.readLine().toCharArray();
            map[2] = br.readLine().toCharArray();
            char nk = br.readLine().charAt(0);

            System.out.printf("Case %d:\n", tc);
            if(leftupdegakChk(nk, map)) {
                map[2][0] = map[1][1] = map[0][2] = nk;
            }
            else if(leftdowndegakChk(nk, map)) {
                map[0][0] = map[1][1] = map[2][2] = nk;
            }
            else {
                for(int x = 0; x < 3; ++x) {
                    if(rowChk(x, nk, map)) {
                        map[0][x] = map[1][x] = map[2][x] = nk;
                        break;
                    }
                    if(colChk(x, nk, map)) {
                        map[x][0] = map[x][1] = map[x][2] = nk;
                        break;
                    }
                }
            }

            for(int i = 0; i < 3; ++i) {
                System.out.println(map[i]);
            }
        }
    }

    static boolean leftupdegakChk(char nk, char[][] map) {
        int cnt = 0;
        for(int i = 0; i < 3; ++i) {
            if(map[i][2-i] == nk) ++cnt;
            else if(map[i][2-i] != '-') return false;
        }
        return cnt == 2;
    }
    static boolean leftdowndegakChk(char nk, char[][] map) {
        int cnt = 0;
        for(int i = 0; i < 3; ++i) {
            if(map[i][i] == nk) ++cnt;
            else if(map[i][i] != '-') return false;
        }
        return cnt == 2;
    }
    static boolean rowChk(int rowNum, char nk, char[][] map) {
        int cnt = 0;
        for(int i = 0; i < 3; ++i) {
            if(map[i][rowNum] == nk) ++cnt;
            else if(map[i][rowNum] != '-') return false;
        }
        return cnt == 2;
    }
    static boolean colChk(int colNum, char nk, char[][] map) {
        int cnt = 0;
        for(int i = 0; i < 3; ++i) {
            if(map[colNum][i] == nk) ++cnt;
            else if(map[colNum][i] != '-') return false;
        }
        return cnt == 2;
    }
}