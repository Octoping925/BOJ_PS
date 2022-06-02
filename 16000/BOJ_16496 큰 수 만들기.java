// https://www.acmicpc.net/problem/16496
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        boolean allZero = true;
        String[] arr = new String[n];
        for(int i = 0; i < n; ++i) {
            arr[i] = st.nextToken();
            allZero = allZero && arr[i].equals("0");
        }

        if(allZero) {
            System.out.println(0);
            return;
        }

        Arrays.sort(arr, (x, y) -> {
            int shortLen = Math.min(x.length(), y.length());

            for(int i = 0; i < shortLen; ++i) {
                if(x.charAt(i) != y.charAt(i)) {
                    return y.charAt(i) - x.charAt(i);
                }
            }

            return (y+x).compareTo(x+y);
        });

        System.out.println(String.join("", arr));
    }
}