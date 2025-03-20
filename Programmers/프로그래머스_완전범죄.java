// https://school.programmers.co.kr/learn/courses/30/lessons/389480
import java.util.*;

class Solution {
    int MAX = 1000000000;
    int nowMax = -1;
    
    public int solution(int[][] info, int n, int m) {
        Arrays.sort(info, (x, y) -> y[0] - x[0]);
        int result = dfs(info, 0, n, m);
        
        return result != MAX ? n - result : -1;
    }
    
    private int dfs(int[][] info, int idx, int n, int m) {
        if (n <= 0 || m <= 0) return MAX;
        if (nowMax > n) return MAX;
        
        if (idx == info.length) {
            nowMax = Math.max(n, nowMax);
            return n;
        }
        
        int minB = dfs(info, idx + 1, n, m - info[idx][1]);
        int minA = dfs(info, idx + 1, n - info[idx][0], m);
        
        if (minA != MAX && minB != MAX) {
            return Math.max(minA, minB);
        }
        
        return Math.min(minA, minB);
    }
}