// https://www.acmicpc.net/problem/13706
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String n = br.readLine();

        BigInteger l = BigInteger.ONE;
        BigInteger r = new BigInteger(n);
        BigInteger find = new BigInteger(n);
        
        
        while(l.compareTo(r) == -1) // l < r
        {
            BigInteger mid = (l.add(r)).divide(BigInteger.valueOf(2)); // (l + r) / 2
            BigInteger midmid = mid.multiply(mid);
            if(midmid.compareTo(find) == -1) { // mid*mid < find
                l = mid.add(BigInteger.ONE);
            }
            else if(midmid.compareTo(find) == 1){ // mid*mid > find
                r = mid.subtract(BigInteger.ONE);
            }
            else {
                break;
            }
        }
        System.out.println((l.add(r)).divide(BigInteger.valueOf(2)));
        return;
    }
}


