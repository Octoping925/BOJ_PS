// https://www.acmicpc.net/problem/5525
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        String txt = br.readLine();

        String pn = "I";
        for(int i = 0; i < n; ++i) pn += "OI";

        for(int i = 0; i< m; ++i)
        {
            if(pn.equals(txt.substring(i, i+2*n+1)))
            {
               System.out.println(i); 
            }
        }
    }
    
}
