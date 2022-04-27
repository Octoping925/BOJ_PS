// https://www.acmicpc.net/problem/10546
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        ArrayList<String> participants = new ArrayList<>();
        ArrayList<String> completes = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            participants.add(br.readLine());
        }
        for(int i = 0; i < n - 1; ++i) {
            completes.add(br.readLine());
        }

        Collections.sort(participants);
        Collections.sort(completes);
        completes.add("");

        for(int i = 0; i < n; ++i) {
            String p = participants.get(i);
            String c = completes.get(i);
            if(!p.equals(c)) {
                System.out.println(p);
                break;
            }
        }
    }
}
