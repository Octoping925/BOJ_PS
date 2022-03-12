// https://www.acmicpc.net/problem/1931
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

class Room implements Comparable<Room>{
    public int start;
    public int end;
    
    Room(String x, String y) {
        start = Integer.parseInt(x);
        end = Integer.parseInt(y);
    }

    @Override
    public int compareTo(Room r) {
        if(end != r.end) return end - r.end;
        return start - r.start;
    }
}

public class Main
{
    static ArrayList<Room> arr = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        
        for(int i = 0; i < n; ++i) {
            String[] str = br.readLine().split(" ");
            arr.add(new Room(str[0], str[1]));
        }

        Collections.sort(arr);

        int cnt = 0, time = 0;
        for(Room i : arr) {
            if(time <= i.start || time == 0) {
                cnt++;
                time = i.end;
            }
        }

        System.out.println(cnt);
        return;
    }
}
