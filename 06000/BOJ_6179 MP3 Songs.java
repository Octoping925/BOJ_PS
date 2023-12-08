import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for(int i = 1; ; ++i) {
            int lineCount = Integer.parseInt(br.readLine());

            if(lineCount == 0) {
                break;
            }

            Stream.Builder<String> builder = Stream.builder();
            for(int j = 0; j < lineCount; j++) {
                builder.add(br.readLine());
            }

            System.out.println(i);
            builder.build().sorted().forEach(System.out::println);
        }
    }
}
