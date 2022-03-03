// https://www.acmicpc.net/problem/18870
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        ArrayList<Integer> arr = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for(int i = 0; i < n; ++i) {
            arr.add(Integer.parseInt(st.nextToken()));
        }

        ArrayList<Integer> arr2 = (ArrayList<Integer>)arr.clone();
        Collections.sort(arr);

        HashMap<Integer, Integer> sortedArr = new HashMap<>();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(!sortedArr.containsKey(arr.get(i)))
                sortedArr.put(arr.get(i), cnt++);
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for(int i : arr2) {
            bw.write(Integer.toString(sortedArr.get(i)) + ' ');
        }
        bw.flush();
    }
}
