// https://programmers.co.kr/learn/courses/30/lessons/42578
import java.util.*;
import java.util.Map.Entry;

class Solution {
    public int solution(String[][] clothes) {
        HashMap<String,Integer> hm = new HashMap<>();
        for (String[] clothe : clothes) {
            if (hm.containsKey(clothe[1])) {
                hm.put(clothe[1], hm.get(clothe[1]) + 1);
            } else {
                hm.put(clothe[1], 1);
            }
        }

        int answer = 1;
        for (Entry<String, Integer> entrySet : hm.entrySet()) {
            answer *= entrySet.getValue() + 1;
        }

        return answer - 1;
    }
}