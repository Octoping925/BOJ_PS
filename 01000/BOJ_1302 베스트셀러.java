// https://www.acmicpc.net/problem/1302
import java.io.*;
import java.util.HashMap;

class Book {
    String context;
    int cnt;
    Book(String context, int cnt) {
        this.context = context;
        this.cnt = cnt;
    }

    boolean isBigger(Book b) {
        if(this.cnt != b.cnt) {
            return this.cnt > b.cnt;
        }
        return this.context.compareTo(b.context) < 0;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Book max = new Book("", 0);
        HashMap<String, Integer> hm = new HashMap<>();
        for(int i = 0; i < n; ++i) {
            String t = br.readLine();
            int cnt = hm.containsKey(t) ? hm.get(t) + 1 : 1;
            hm.put(t, cnt);
            if(new Book(t, cnt).isBigger(max)) {
                max.context = t;
                max.cnt = cnt;
            }
        }

        System.out.println(max.context);
    }
}