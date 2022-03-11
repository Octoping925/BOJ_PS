// https://www.acmicpc.net/problem/1655
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> maxpQueue = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> minpQueue = new PriorityQueue<>();

        while(n-->0) {
            int k = Integer.parseInt(br.readLine());
            if(maxpQueue.size() == minpQueue.size()) {
                maxpQueue.add(k);
                
                if(!minpQueue.isEmpty() && maxpQueue.peek() > minpQueue.peek()) {
                    int mxpq = maxpQueue.poll();
                    int mnpq = minpQueue.poll();
                    maxpQueue.add(mnpq);
                    minpQueue.add(mxpq);
                }
            }
            else {
                minpQueue.add(k);
                if(maxpQueue.peek() > minpQueue.peek()) {
                    int mxpq = maxpQueue.poll();
                    int mnpq = minpQueue.poll();
                    maxpQueue.add(mnpq);
                    minpQueue.add(mxpq);
                }
            }
            bw.write(Integer.toString(maxpQueue.peek()));
            bw.newLine();
        }
        
        bw.flush();
        return;
    }
}
