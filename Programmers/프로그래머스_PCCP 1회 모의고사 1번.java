// https://school.programmers.co.kr/learn/courses/20847/lessons/255900
import java.util.*;

class Solution {
    String[] letters = "abcdefghijklmnopqrstuvwxyz".split("");
    Map<String, Status> map = new HashMap<>();
    
    public String solution(String input_string) {
        init();
        
        String[] inputLetters = input_string.split("");
        
        for(int i = 0; i < inputLetters.length; ++i) {
            String letter = inputLetters[i];
            if(map.get(letter) == Status.NO_SHOW) {
                map.put(letter, Status.SHOW);
            }
            else if(map.get(letter) == Status.SHOW) {
                if(!inputLetters[i - 1].equals(letter)) {
                    map.put(letter, Status.DETACHED);
                }
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for(String letter : letters) {
            if(map.get(letter) == Status.DETACHED)
                sb.append(letter);
        }
        
        if(sb.length() > 0) return sb.toString();
        return "N";
    }
    
    private void init() {
        for(String letter : letters) {
            map.put(letter, Status.NO_SHOW);
        }
    }
}

enum Status {
    NO_SHOW,
    SHOW,
    DETACHED;
}