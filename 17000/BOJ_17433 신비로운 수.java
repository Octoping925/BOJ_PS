// https://www.acmicpc.net/problem/17433
import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        while (n-- > 0) {
            findSpecialNumber();
        }
    }

    private static void findSpecialNumber() throws IOException {
        int size = Integer.parseInt(br.readLine());
        List<Integer> numbers = getNumbers(size);
        List<Integer> distinctAndSortedNumbers = distinctAndSort(numbers);

        boolean isAllSame = distinctAndSortedNumbers.size() == 1;
        if (isAllSame) {
            System.out.println("INFINITY");
            return;
        }

        List<Integer> subtractedNumbers = getSubtractedNumbers(distinctAndSortedNumbers);

        System.out.println(gcd(subtractedNumbers));
    }

    private static List<Integer> getNumbers(int size) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        List<Integer> arr = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            arr.add(Integer.parseInt(st.nextToken()));
        }
        return arr;
    }

    private static List<Integer> distinctAndSort(List<Integer> numbers) {
        return numbers.stream()
                .distinct()
                .sorted()
                .collect(Collectors.toList());
    }

    private static List<Integer> getSubtractedNumbers(List<Integer> numbers) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < numbers.size() - 1; ++i) {
            list.add(numbers.get(i + 1) - numbers.get(i));
        }

        return list;
    }

    private static int gcd(List<Integer> list) {
        return list.stream()
                .reduce(list.get(0), (prev, accr) -> gcd(accr, prev));
    }

    private static int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
}