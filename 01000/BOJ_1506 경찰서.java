// https://www.acmicpc.net/problem/1506
import java.io.*;
import java.util.*;

public class Main {

    static int[] price;
    static LinkedList<LinkedList<Integer>> sccList = new LinkedList<>();
    static LinkedList<Integer> scc;
    static LinkedList<Integer> stack = new LinkedList<>();
    static LinkedList<Integer>[] connections;
    static LinkedList<Integer>[] connectionsReverse;
    static boolean[] visitChk;
    static boolean[] visitRevChk;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        price = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        connections = new LinkedList[n+1];
        connectionsReverse = new LinkedList[n+1];
        visitChk = new boolean[n+1];
        visitRevChk = new boolean[n+1];

        for(int i = 1; i <= n; ++i) {
            connections[i] = new LinkedList<>();
            connectionsReverse[i] = new LinkedList<>();
        }

        for(int i = 1; i <= n; ++i) {
            char[] str = br.readLine().toCharArray();

            for(int j = 0; j < n; ++j) {
                if(str[j] == '1') {
                    connections[i].add(j + 1);
                    connectionsReverse[j + 1].add(i);
                }
            }
        }

        for(int i = 1; i <= n; ++i) {
            if(!visitChk[i]) {
                dfs(i);

                visitRevChk = new boolean[n+1];
                while(!stack.isEmpty()) {
                    int top = stack.pollLast();
                    if(visitRevChk[top]) continue;

                    scc = new LinkedList<>();
                    dfsReverse(top);
                    sccList.add(scc);
                }
            }
        }
        
        int answer = 0;
        for(LinkedList<Integer> scc : sccList) {
            int min = price[scc.get(0) - 1];
            for(int i : scc) {
                if(price[i -1] < min) min = price[i - 1];
            }

            answer += min;
        }

        System.out.println(answer);
    }

    static void dfs(int pos) {
        LinkedList<Integer> set = connections[pos];
        visitChk[pos] = true;

        for(int i : set) {
            if(!visitChk[i]) {
                dfs(i);
            }
        }
        stack.add(pos);
    }

    static void dfsReverse(int pos) {
        LinkedList<Integer> set = connectionsReverse[pos];
        visitRevChk[pos] = true;
        scc.add(pos);

        for(int i : set) {
            if(!visitRevChk[i] && visitChk[i]) {
                visitRevChk[i] = true;
                dfsReverse(i);
            }
        }
    }
}