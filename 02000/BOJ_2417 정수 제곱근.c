// https://www.acmicpc.net/problem/2417
// #include <stdio.h>

int main()
{
    long long n;
    scanf("%lld", &n);

    long long l = 0, r = n;

    while(l < r)
    {
        long long mid = (l + r) / 2;

        if(mid * mid < n) {
            l = mid + 1;
        }
        else if(mid * mid == n) {
            l = r = mid;
        }
        else {
            r--;
        }
    }
    printf("%lld", l);
}        
        
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


