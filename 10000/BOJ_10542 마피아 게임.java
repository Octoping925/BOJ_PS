// https://www.acmicpc.net/problem/10542
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int uncertained = n;
        int[] arr = new int[n + 3];
        int[] mafia = new int[n + 3];

        ArrayList<Integer>[] graph = new ArrayList[n + 3];
        for(int i = 1; i <= n; ++i) {
            graph[i] = new ArrayList<Integer>();
        }

        for(int i = 1; i <= n; ++i) {
            arr[i] = Integer.parseInt(br.readLine());
            graph[arr[i]].add(i);
        }

        // 한번도 안 지목당한 사람은 마피아
        // 마피아가 지목한 사람은 무조건 시민
        for(int i = 1; i <= n; ++i) {
            if(graph[i].isEmpty()) {
                mafia[i] = 1;
                uncertained--;
                
                if(mafia[arr[i]] == 0) {
                    mafia[arr[i]] = -1;
                    uncertained--;
                }
                
            }
        }
        
        // 마피아를 지목한 사람은 무조건 시민
        for(int i = 1; i <= n; ++i) {
            if(mafia[arr[i]] == 1) {
                mafia[i] = -1;
                uncertained--;
            }
        }
        
        System.out.println("uncertained = " + Integer.toString(uncertained));
        for(int i = 1; i <= n; ++i)
            System.out.println(mafia[i]);


        return;
    }
}


/*

모든 사람을 마피아로 간주
그 후 1이 3을 뽑았을 경우 1과 3을 분리


*/