// https://www.acmicpc.net/problem/2150
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

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        connections = new LinkedList[n+1];
        connectionsReverse = new LinkedList[n+1];
        visitChk = new boolean[n+1];
        visitRevChk = new boolean[n+1];

        for(int i = 1; i <= n; ++i) {
            connections[i] = new LinkedList<>();
            connectionsReverse[i] = new LinkedList<>();
        }

        for(int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            connections[x].add(y);
            connectionsReverse[y].add(x);
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

        for (LinkedList<Integer> scc : sccList) {
            Collections.sort(scc);
        }

        Collections.sort(sccList, Comparator.comparing(x -> x.get(0)));

        System.out.println(sccList.size());

        for(LinkedList<Integer> scc : sccList) {
            for(int i : scc) {
                System.out.printf("%d ", i);
            }
            System.out.println(-1);
        }
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