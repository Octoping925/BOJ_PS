// https://www.acmicpc.net/problem/1918
import java.io.*;
import java.util.*;

public class Main {
    static Stack<String> alphaStack = new Stack<>();
    static Stack<Character> expStack = new Stack<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution(br.readLine()));
    }

    public static String solution(String txt) {
        for(char i : txt.toCharArray())
        {
            if(i == '+' || i == '-') {
                while(!expStack.isEmpty() && expStack.peek() != '(') {
                    calc();
                }
                expStack.push(i);
            }
            else if(i == '*' || i == '/') {
                expStack.push(i);
            }
            else if(i == '(') {
                expStack.push(i);
            }
            else if(i == ')') {
                while(expStack.peek() != '(') {
                    calc();
                }
                expStack.pop();
                if(!expStack.isEmpty() && (expStack.peek() == '*' || expStack.peek() == '/'))
                    calc();
            }
            else {
                alphaStack.push(Character.toString(i));
                if(!expStack.isEmpty() && (expStack.peek() == '*' || expStack.peek() == '/')) {
                    calc();
                }
            }
        }

        while(!expStack.isEmpty()) calc();
        return alphaStack.peek();
    }

    public static void calc() {
        String y = alphaStack.pop();
        String x = alphaStack.pop();
        char exp = expStack.pop();
        alphaStack.push(x + y + exp);
    }
}