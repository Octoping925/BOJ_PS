// https://school.programmers.co.kr/learn/courses/30/lessons/42862
import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        Set<Integer> losts = new HashSet<>();
        Set<Integer> reserves = new HashSet<>();
        
        for (int i : lost) losts.add(i);
        for (int i : reserve) reserves.add(i);
        
        for (int i = 1; i <= n; ++i) {
            if (!losts.contains(i)) {
                answer++;
                continue;
            }
            
            if (reserves.contains(i)) {
                answer++;
                losts.remove(i);
                reserves.remove(i);
                continue;
            }
            
            if (reserves.contains(i - 1)) {
                answer++;
                reserves.remove(i - 1);
                losts.remove(i);
                continue;
            }
            
            if (reserves.contains(i + 1) && !losts.contains(i + 1)) {
                answer++;
                reserves.remove(i + 1);
                losts.remove(i);
                continue;
            }
        }
        
        return answer;
    }
}