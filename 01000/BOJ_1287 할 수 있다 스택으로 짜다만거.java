// https://www.acmicpc.net/problem/1287
import java.io.*;
import java.util.*;

public class Main
{
    static Stack<Integer> number;
    static Stack<Character> exp;

    static int points[];
    static int n, m, v;

    static String makePostfix(String txt)
    {
        char t[] = txt.toCharArray();
        StringBuilder sb = new StringBuilder();
        Stack<Character> oper = new Stack<>();

        for(char c : t)
        {
            if('0' <= c && c <= '9') {
                sb.append(c);
                sb.append(" ");
            }
            else if(c == '(') oper.add(c);
            else if(c == '+' || c == '-') {
                while(!oper.isEmpty() && (oper.peek() == '*' || oper.peek() == '/')) {
                    sb.append(oper.pop());
                    sb.append(" ");
                }
                oper.add(c);
            }
            else if(c == '*' || c == '/') oper.add(c);
            else if(c == ')') {
                while(true) {
                    char k = oper.pop();
                    if(k == '(') break;
                    sb.append(k);
                    sb.append(" ");
                }
            }
        }
        while(!oper.isEmpty()) {
            if(oper.peek() == '(') return "Error";
            sb.append(oper.pop());
            sb.append(" ");
        }
        return sb.toString();
    }
    
    

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String txt = br.readLine();
        try {
            String postfix = makePostfix(txt);
            if(postfix == "Error") throw new Exception();
            System.out.println(postfix);
        }
        catch(Exception e) {
            System.out.println("ROCK");
        }
        
        


        return;
    }
}
