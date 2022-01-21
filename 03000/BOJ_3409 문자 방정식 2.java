// https://www.acmicpc.net/problem/3409
import java.io.*;
import java.util.*;

public class Main
{
	static String[][] arr;
	static String T;
	static String P;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcaseCnt = Integer.parseInt(br.readLine());
		
		for(int xxx = 0; xxx < testcaseCnt; ++xxx)
		{
		    int K = Integer.parseInt(br.readLine());
		    
			ArrayList<String> varNames = new ArrayList<String>(K);
		    String[][] value = new String[K][3];
		    
		    for(int i = 0; i < K; ++i)
		    {
		        String txt = br.readLine();
		        String[] tmp = txt.split(" = ");
		        varNames.add(tmp[0]);
		        
		        if(tmp[1].indexOf('+') != -1)
				{
					String[] tmp2 = tmp[1].split(" \\+ ");
					value[i][1] = tmp2[0];
					value[i][2] = tmp2[1];
				}
				else value[i][0] = tmp[1];
		    }

			// System.out.println('\n');
			
			// for(int i = 0; i < K; ++i)
			// 	System.out.println(value[i][0] + " " + value[i][1] + " " + value[i][2]);


			// 트리 연결 구조 2차원 배열 만들기
			arr = new String[K][3];

			for(int i = 0; i < K; ++i)
			{
				if(value[i][0] == null) {
					arr[i][1] = Integer.toString(varNames.indexOf(value[i][1]));
					arr[i][2] = Integer.toString(varNames.indexOf(value[i][2]));
				}
				else {
					arr[i][0] = value[i][0];
				}
			}

// 			System.out.println('\n');
// 			for(int i = 0; i < K; ++i)
// 				System.out.println(arr[i][0] + " " + arr[i][1] + " " + arr[i][2]);


			// 트리 탐색하며 P 구하기
			T = br.readLine();
			P = br.readLine();

			int l = recursive(varNames.indexOf(T), 0);

			System.out.println(l == P.length() ? "YES" : "NO");
		}

		return;
	}

	public static int recursive(int nowNode, int readCnt)
	{
		if(readCnt == P.length())
			return readCnt;

		String WORD = arr[nowNode][0];

		if(WORD != null)
		{
			int nowReadCnt = 0;

			for(int i = 0; i < WORD.length(); ++i)
			{
				if(readCnt + nowReadCnt == P.length())
					return readCnt + nowReadCnt;
				
				if(P.charAt(readCnt + nowReadCnt) == WORD.charAt(i))
					++nowReadCnt;
			}

			return readCnt + nowReadCnt;
		}

		int left = recursive(Integer.parseInt(arr[nowNode][1]), readCnt);
		int right = recursive(Integer.parseInt(arr[nowNode][2]), left);
		return right;
	}
}

