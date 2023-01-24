import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        List<String> list = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            list.add(br.readLine());
        }

        String max = findMax(list);
        while(list.size() < k) {
            list.add(max);
        }

        list.stream()
                .sorted((x, y) -> (y+x).compareTo(x+y))
                .forEach(System.out::print);
    }

    private static String findMax(List<String> list) {
        boolean isAllSameLength = list.stream().allMatch(s -> s.length() == list.get(0).length());
        if(isAllSameLength) {
            return list.stream().max(Comparator.naturalOrder()).get();
        }

        int maxLength = list.stream()
                .mapToInt(String::length)
                .max()
                .getAsInt();

        return list.stream()
                .filter(s -> s.length() == maxLength)
                .max(Comparator.naturalOrder())
                .get();
    }
}
