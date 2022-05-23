// https://www.acmicpc.net/problem/3409
import java.io.*;
import java.util.*;

public class Main
{
    static String[][] arr;
    static String T;
    static String P;

    static int[] explored;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcaseCnt = Integer.parseInt(br.readLine());

        for(int tc = 0; tc < testcaseCnt; ++tc) {
            int K = Integer.parseInt(br.readLine());

            ArrayList<String> varNames = new ArrayList<>(K);
            arr = new String[K][3];

            for(int i = 0; i < K; ++i) {
                String[] tmp = br.readLine().split(" = ");
                varNames.add(tmp[0]);

                if(tmp[1].contains("+")) {
                    String[] tmp2 = tmp[1].split(" \\+ ");
                    arr[i][1] = tmp2[0];
                    arr[i][2] = tmp2[1];
                }
                else arr[i][0] = tmp[1];
            }


            // 트리 연결 구조 2차원 배열 만들기
            for(int i = 0; i < K; ++i) {
                if(arr[i][0] == null) {
                    arr[i][1] = Integer.toString(varNames.indexOf(arr[i][1]));
                    arr[i][2] = Integer.toString(varNames.indexOf(arr[i][2]));
                }
            }


            // 트리 탐색하며 P 구하기
            T = br.readLine();
            P = br.readLine();

            explored = new int[K];
            Arrays.fill(explored, 0);

            int result = recursive(varNames.indexOf(T), 0);

            System.out.println(result == P.length() ? "YES" : "NO");
        }
    }

    public static int recursive(int nowNode, int readCnt)
    {
        if(readCnt == P.length() || explored[nowNode] == 1)
            return readCnt;

        explored[nowNode] = 1;
        String WORD = arr[nowNode][0];

        if(WORD != null) {
            int nowReadCnt = 0;

            for(char c : WORD.toCharArray()) {
                if(readCnt + nowReadCnt == P.length())
                    return readCnt + nowReadCnt;

                if(P.charAt(readCnt + nowReadCnt) == c) {
                    ++nowReadCnt;
                    Arrays.fill(explored, 0);
                }
            }

            return readCnt + nowReadCnt;
        }

        int left = recursive(Integer.parseInt(arr[nowNode][1]), readCnt);
        int right = recursive(Integer.parseInt(arr[nowNode][2]), left);
        return right;
    }
}
