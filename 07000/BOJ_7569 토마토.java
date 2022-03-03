// https://www.acmicpc.net/problem/7569
import java.io.*;
import java.util.*;

public class Main
{
    static int arr[][][];
    static Queue<Pair> q;
    static int n, m, h;
    static int raw = 0, answer = 0;

    static void bfs()
    {
        while(!q.isEmpty())
        {
            int len = q.size();

            for(int i = 0; i < len; ++i)
            {
                Pair now = q.poll();
                int x = now.x, y = now.y, z = now.z;

                if(x > 1 && arr[x - 1][y][z] == 0) {
                    q.add(new Pair(x - 1, y, z));
                    arr[x - 1][y][z] = 1;
                    --raw;
                }
                if(x < n && arr[x + 1][y][z] == 0) {
                    q.add(new Pair(x + 1, y, z));
                    arr[x + 1][y][z] = 1;
                    --raw;
                }
                if(y > 1 && arr[x][y - 1][z] == 0) {
                    q.add(new Pair(x, y - 1, z));
                    arr[x][y - 1][z] = 1;
                    --raw;
                }
                if(y < m && arr[x][y + 1][z] == 0) {
                    q.add(new Pair(x, y + 1, z));
                    arr[x][y + 1][z] = 1;
                    --raw;
                }
                if(z > 1 && arr[x][y][z - 1] == 0) {
                    q.add(new Pair(x, y, z - 1));
                    arr[x][y][z - 1] = 1;
                    --raw;
                }
                if(z < h && arr[x][y][z + 1] == 0) {
                    q.add(new Pair(x, y, z + 1));
                    arr[x][y][z + 1] = 1;
                    --raw;
                }
            }
            ++answer;
        }

        if(raw > 0) System.out.println(-1);
        else System.out.println(answer - 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        q = new LinkedList<>();

        st = new StringTokenizer(br.readLine(), " ");
        
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());

        arr = new int[n + 1][m + 1][h + 1];
        
        
        for(int k = 1; k <= h; ++k)
        {
            for(int i = 1; i <= n; ++i)
            {
                st = new StringTokenizer(br.readLine(), " ");
                for(int j = 1; j <= m; ++j)
                {
                    arr[i][j][k] = Integer.parseInt(st.nextToken());
                    if(arr[i][j][k] == 0) raw++;
                    else if(arr[i][j][k] == 1) q.add(new Pair(i, j, k));
                }
            }
        }
        
        if(raw == 0) {
            System.out.println(0);
            return;
        }

        bfs();
        return;
    }

    static class Pair{
        public int x, y, z;
        public Pair(int xx, int yy, int zz) { 
            x = xx;
            y = yy;
            z = zz;
        }   
    }
}
