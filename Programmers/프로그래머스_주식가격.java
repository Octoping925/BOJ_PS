// https://programmers.co.kr/learn/courses/30/lessons/42584
import java.util.*;

class Jusik {
    int price;
    int seq;
    Jusik(int p, int s) {
        price = p;
        seq = s;
    }
}

class Solution {
    Stack<Jusik> stack = new Stack<>();

    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        
        for(int i = 0; i < prices.length; ++i) {
            if(stack.empty()) stack.add(new Jusik(prices[i], i));
            else {
                while(!stack.empty() && stack.peek().price > prices[i]) {
                    answer[stack.peek().seq] = i - stack.peek().seq;
                    stack.pop();
                }
                stack.add(new Jusik(prices[i], i));
            }
        }

        while(!stack.empty()) {
            Jusik j = stack.peek();
            answer[j.seq] = prices.length -1 - j.seq;
            stack.pop();
        }
        return answer;
    }
}