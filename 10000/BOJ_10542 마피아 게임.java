// https://www.acmicpc.net/problem/10542
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 3];

        ArrayList<Integer>[] graph = new ArrayList[n + 3];
        for(int i = 1; i <= n; ++i) {
            graph[i] = new ArrayList<Integer>();
        }

        for(int i = 1; i <= n; ++i) {
            arr[i] = Integer.parseInt(br.readLine());
            graph[arr[i]].add(i);
        }

        // for(int i = 1; i <= n; ++i)
        // {
        //     for(int j : graph[i]) {
        //         System.out.print(j);
        //         System.out.print(' ');
        //     }
        //     System.out.println();
        // }
        int[] mafia = new int[n + 3];
        for(int i = 1; i <= n; ++i) {
            if(graph[i].isEmpty()) {
                mafia[i] = 1; // 한번도 안 지목당한 사람은 무조건 마피아여도 됨
                mafia[arr[i]] = -1; // 마피아가 지목한 사람은 마피아가 아님
            }
        }
        
        for(int i = 1; i <= n; ++i)
            System.out.println(mafia[i]);


        return;
    }
}
