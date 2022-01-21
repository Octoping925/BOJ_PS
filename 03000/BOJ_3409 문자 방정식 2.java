// https://www.acmicpc.net/problem/3409
import java.io.*;
import java.util.*;


public class main
{
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
					value[i][0] = "0";
					value[i][1] = tmp2[0];
					value[i][2] = tmp2[1];
				}
				else value[i][0] = tmp[1];
		    }

			// System.out.println('\n');
			
			// for(int i = 0; i < K; ++i)
			// 	System.out.println(value[i][0] + " " + value[i][1] + " " + value[i][2]);


			// 트리 연결 구조 구하는 2차원 배열 만들기
			String[][] arr = new String[K][3];

			for(int i = 0; i < K; ++i)
			{
				if(value[i][0] == "0") {
					arr[i][1] = Integer.toString(varNames.indexOf(value[i][1]));
					arr[i][2] = Integer.toString(varNames.indexOf(value[i][2]));
				}
				else {
					arr[i][0] = value[i][0];
				}
			}

			// System.out.println('\n');
			// for(int i = 0; i < K; ++i)
			// 	System.out.println(arr[i][0] + " " + arr[i][1] + " " + arr[i][2]);
			

			// 트리 탐색하며 P 구하기
			String T = br.readLine();
			String P = br.readLine();

			int l = recursive(varNames.indexOf(T), 0);
			if(l == P.length())
			{
				
			}
		}
	}
}
