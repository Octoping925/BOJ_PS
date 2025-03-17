// https://school.programmers.co.kr/learn/courses/30/lessons/389479
class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;

        int[] servers = new int[24];

        for (int i = 0; i < 24; ++i) {
            int player = players[i];

            int serverCnt = 0;
            for (int j = Math.max(i - k + 1, 0); j < i; ++j) {
                serverCnt += servers[j];
            }

            int maxAffordable = (serverCnt + 1) * m;

            if (player >= maxAffordable) {
                int exceed = player - maxAffordable + 1;
                int needMore = (int) Math.ceil((double) exceed / m);

                servers[i] = needMore;
                answer += servers[i];
            }
        }

        return answer;
    }
}
