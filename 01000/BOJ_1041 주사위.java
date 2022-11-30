import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        long n = Long.parseLong(br.readLine());

        long[] nums = Arrays.stream(br.readLine().split(" "))
                .mapToLong(Long::parseLong).toArray();

        if(n == 1) {
            System.out.println(Arrays.stream(nums).sum() - Arrays.stream(nums).max().orElseThrow());
            return;
        }

        System.out.println(
                ((n-2)*(n-2) + (n-1)*(n-2)*4L) * oneMinNum(nums)
                + ((n-2) * 4L + (n-1) * 4L) * twoMinNum(nums)
                + 4L * threeMinNum(nums));
    }

    private static long oneMinNum(long[] nums) {
        return Arrays.stream(nums).min().orElseThrow();
    }

    private static long twoMinNum(long[] nums) {
        long [] twoLenSums = {
                nums[0] + nums[1], // ab
                nums[0] + nums[2], // ac
                nums[0] + nums[3], // ad
                nums[0] + nums[4], // ae
                nums[1] + nums[2], // bc
                nums[1] + nums[3], // bd
                nums[1] + nums[5], // bf
                nums[2] + nums[4], // ce
                nums[2] + nums[5], // cf
                nums[3] + nums[4], // de
                nums[3] + nums[5], // df
                nums[4] + nums[5] // ef
        };

        return oneMinNum(twoLenSums);
    }

    private static long threeMinNum(long[] nums) {
        long[] threeLenSums = {
                nums[0] + nums[1] + nums[2], // abc
                nums[0] + nums[1] + nums[3], // abd
                nums[0] + nums[2] + nums[4], // ace
                nums[0] + nums[3] + nums[4], // ade
                nums[1] + nums[2] + nums[5], // bcf
                nums[1] + nums[3] + nums[5], // bdf
                nums[2] + nums[4] + nums[5], // cef
                nums[3] + nums[4] + nums[5] // def
        };

        return oneMinNum(threeLenSums);
    }
}

// (n-2)^2 + (n-2)*(n-1)*4 = 최소숫자
// (n-2) * 4 + (n-1) * 4 = 두 면 합 최소
// 4 = 세 면 합 최소