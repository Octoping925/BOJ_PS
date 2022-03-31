// https://www.acmicpc.net/problem/1918
import java.io.*;
import java.util.*;

public class Main {
    static Stack<String> alphaStack;
    static Stack<Character> expStack;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        String p = br.readLine();

        while(true) {
            String p = randomMake();//br.readLine();
//            String p= "A-((B)+C)/D";
            System.out.println(p);
            System.out.println(mine(p));
            System.out.println(convert(p.toCharArray())+"\n");
            if(!mine(p).equals(convert(p.toCharArray()))) {
                return;
            }
        }
    }

    public static String randomMake() {
        Random r = new Random();
        StringBuilder sb = new StringBuilder();
        char[] exp = {'+', '-', '*', '/'};

        int len = r.nextInt() % 3 + 5;
        int parcnt = 0;
        int wordtmp = 0;
        while(len-->0) {
            int percent = r.nextInt(100);
            if(percent < 20) {
                int pl = r.nextInt(4);
                parcnt+=pl;
                while(pl-->0) sb.append('(');
            }
            sb.append((char)('A'+(wordtmp++ % 26)));
            if(percent < 70 && parcnt > 0 && ('A'<=sb.charAt(sb.length()-1) && sb.charAt(sb.length()-1) <= 'Z')) {
                sb.append(')');
                parcnt--;
            }

            sb.append(exp[r.nextInt(4)]);
        }
        sb.append((char)('A'+r.nextInt(20)));
        while(parcnt-->0) sb.append(')');
        return sb.toString();
    }




    public static String mine(String txt) {
        alphaStack = new Stack<>();
        expStack = new Stack<>();
        for(char i : txt.toCharArray())
        {
//            System.out.println(i);
            if(i == '+' || i == '-') {
                while(!expStack.isEmpty() && expStack.peek() != '(') {
                    calc();
                }
                expStack.push(i);
            }
            else if(i == '*' || i == '/') {
                expStack.push(i);
            }
            else if(i == '(') expStack.push(i);
            else if(i == ')') {
                if(expStack.peek() == '(') {
                    expStack.pop();
                    if(!expStack.isEmpty() && (expStack.peek() == '*' || expStack.peek() == '/')) calc();
                }
                else {
                    while(expStack.peek() != '(') {
                        calc();
                    }
                    expStack.pop();
                    if(!expStack.isEmpty() && (expStack.peek() == '*' || expStack.peek() == '/')) calc();
                }
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


    private static String convert(char[] str){
        char[] stk =new char[str.length];
        char top;
        int peek=-1;
        String res="";
        for(char c:str){
            switch(c){
                case '+': case '-': case '*': case '/':
                    while(peek>=0&&prec(c)<=prec(stk[peek])) res+=stk[peek--];
                    stk[++peek]=c;
                    break;
                case '(': stk[++peek]=c; break;
                case ')':
                    top=stk[peek--];
                    while(top!='('){
                        res+=top;
                        top=stk[peek--];
                    }
                    break;
                default: res+=c; break;
            }
        }
        while(peek>=0) res+=stk[peek--];
        return res;
    }
    private static int prec(char c){
        switch(c){
            case '(': case ')': return 0;
            case '+': case '-': return 1;
            case '*': case '/': return 2;
        }
        return -1;
    }
}

/*
A+B*C-D/E

ABC*+ D E
-
/
숫자뽑았을 때 *나 / 있으면 같이 pop,
봅았을 때 +나 -면 그 이전 애들 pop하고 push
) 나오는 순간 (가 나올때까지 pop 하면서 마구 흡입

 */