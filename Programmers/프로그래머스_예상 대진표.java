// https://programmers.co.kr/learn/courses/30/lessons/12985
class Solution
{
    public int solution(int n, int a, int b)
    {
        int totalRound = 0;
        while((1 << ++totalRound) != n);
        return getAnswer(totalRound, a, b, 1, n);
    }

    public int getAnswer(int n, int a, int b, float left, float right) {
        float mid = (left + right) / 2;
        if(a <= mid && b <= mid) return getAnswer(n-1, a, b, left, mid);
        else if(a >= mid && b >= mid) return getAnswer(n-1, a, b, mid, right);
        else return n;
    }
}