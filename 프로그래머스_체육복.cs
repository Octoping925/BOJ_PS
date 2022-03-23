// https://programmers.co.kr/learn/courses/30/lessons/42862
using System;

public class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int[] havingArr = new int[n+2];  // 없으면 -1, 갖고 있으면 0, 여분있으면 1
        
        foreach(int i in lost) {
            havingArr[i]--;
        }
        foreach(int i in reserve) {
            havingArr[i]++;
        }
        
        int answer = 0;
        for(int i = 1; i <= n; ++i) {
            if(havingArr[i] >= 0) answer++;
            else {
                if(havingArr[i - 1] == 1) {
                    havingArr[i - 1]--;
                    havingArr[i]++;
                    answer++;
                }
                else if(havingArr[i + 1] == 1) {
                    havingArr[i + 1]--;
                    havingArr[i]++;
                    answer++;
                }
            }
        }
        
        return answer;
    }
}