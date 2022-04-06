// https://www.acmicpc.net/problem/15666
import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static int n, m;
    static List<Integer> list;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        ArrayList<Integer> arr = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; ++i) {
            arr.add(Integer.parseInt(st.nextToken()));
        }

        list = arr.stream().distinct().sorted().collect(Collectors.toList());
        back(new ArrayList<>(), 0);

    }

    static void back(ArrayList<Integer> barr, int idx) {
        if(barr.size() == m) {
            for(int i : barr) {
                System.out.printf("%d ", i);
            }
            System.out.println();
            return;
        }

        for(int i = idx; i < list.size(); ++i) {
            barr.add(list.get(i));
            back(barr, i);
            barr.remove(barr.size()-1);
        }
    }
}