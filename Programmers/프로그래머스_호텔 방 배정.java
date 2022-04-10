// https://programmers.co.kr/learn/courses/30/lessons/64063
import java.util.*;

class Solution {
    static HashMap<Long, Long> hm = new HashMap<>();

    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];

        for(int i = 0; i < room_number.length; ++i) {
            if(!hm.containsKey(room_number[i])) {
                answer[i] = room_number[i];
                hm.put(room_number[i], room_number[i]);
            }
            else {
                long g = recursive(hm.get(room_number[i]) + 1);

                hm.put(room_number[i], g);
                hm.put(g, g);
                answer[i] = g;
            }
        }

        return answer;
    }

    long recursive(long x) {
        long result = x;
        if(hm.containsKey(x)) {
            result = recursive(hm.get(x) + 1);
            hm.put(x, result);
        }
        return result;
    }
}