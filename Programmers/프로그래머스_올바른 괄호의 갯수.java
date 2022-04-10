// https://programmers.co.kr/learn/courses/30/lessons/12929
class Solution {
    public int solution(int n) {
        int answer = 0;
        answer = par(n, 0, 0);
        return answer;
    }
    
    int par(int n, int left, int right) {
        int result = 0;
        if(n == left && n == right) return 1;
        if(left == right) result += par(n, left+1, right);
        else if(left == n) result += par(n, left, right+1);
        else {
            result += par(n, left+1, right);
            result += par(n, left, right+1);
        }
        return result;
    }
}