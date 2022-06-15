// https://www.acmicpc.net/problem/5597
import java.io.*;
import java.util.*;
import java.util.function.Predicate;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<Integer> arr = new ArrayList<>();
        for(int i = 0; i < 28; ++i) {
            arr.add(Integer.parseInt(br.readLine()));
        }

        IntStream.rangeClosed(1, 30)
            .filter(x->!arr.contains(x))
            .forEach(System.out::println);
    }
}