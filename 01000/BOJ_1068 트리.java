// https://www.acmicpc.net/problem/1068
import java.io.*;
import java.util.*;

class Node {
    int parent;
    Set<Integer> childs = new HashSet<>();
    boolean isDelete = false;

    public Node(int parent) {
        this.parent = parent;
    }
}

public class Main
{
    static Node[] nodeArr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        nodeArr = new Node[n];

        for(int i = 0; i < n; ++i) {
            nodeArr[i] = new Node(-1);
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; ++i) {
            int parent = Integer.parseInt(st.nextToken());
            nodeArr[i].parent = parent;
            if(parent != -1) {
                nodeArr[parent].childs.add(i);
            }
        }

        dfs(Integer.parseInt(br.readLine()));

        System.out.println(Arrays.stream(nodeArr)
            .filter(node -> !node.isDelete && node.childs.isEmpty())
            .count());
    }

    static void dfs(int idx) {
        Node node = nodeArr[idx];
        node.isDelete = true;
        if(node.parent != -1 && !nodeArr[node.parent].isDelete) {
            nodeArr[node.parent].childs.remove(idx);
        }

        node.childs.forEach(Main::dfs);
    }
}