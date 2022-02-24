// https://www.acmicpc.net/problem/4195
import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
		int testcaseCnt = Integer.parseInt(br.readLine());
		
		for(int xxx = 0; xxx < testcaseCnt; ++xxx)
		{
		    int n = Integer.parseInt(br.readLine());
		    
			HashMap<String, Integer> friendIdx = new HashMap<>();
		    int tree[][] = new int[n * 2 + 1][2];
		    
            int cnt = 0;
		    for(int i = 0; i < n; ++i)
		    {
                st = new StringTokenizer(br.readLine(), " ");
		        String x = st.nextToken();
                String y = st.nextToken();
                
                if(!friendIdx.containsKey(x)) {
                    friendIdx.put(x, cnt);
                    tree[cnt][0] = cnt;
                    tree[cnt][1] = 1;
                    ++cnt;
                }
                if(!friendIdx.containsKey(y)) {
                    friendIdx.put(y, cnt);
                    tree[cnt][0] = cnt;
                    tree[cnt][1] = 1;
                    ++cnt;
                }
                
                union(friendIdx.get(x), friendIdx.get(y), tree);
                System.out.println(tree[find(friendIdx.get(x), tree)][1]);
		    }
		}

		return;
	}

	public static void union(int x, int y, int[][] tree)
	{
		x = find(x, tree);
        y = find(y, tree);
        if(x == y) return;
        tree[y][0] = x;
        tree[x][1] += tree[y][1];
	}

	public static int find(int x, int[][] tree)
	{
		if(tree[x][0] == x) return x;
        return tree[x][0] = find(tree[x][0], tree);
	}
}