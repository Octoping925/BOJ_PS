// https://www.acmicpc.net/problem/1062 
import java.io.*;
import java.util.*;

class Bitmask {

    private int bit;
    private int size;

    Bitmask() {
        bit = 0;
        size = 0;
    }

    public int getSize() {
        return size;
    }

    public Bitmask addBit(int add) {
        if (!this.isHere(add)) {
            bit |= (1 << add);
            size++;
        }
        return this;
    }

    public Bitmask addBit(String add) {
        for (char c : add.toCharArray()) {
            this.addBit(c - 'a');
        }
        return this;
    }

    public Bitmask subBit(int add) {
        if (this.isHere(add)) {
            bit &= ~(1 << add);
            size--;
        }
        return this;
    }

    public boolean isHere(int x) {
        return (bit & (1 << x)) > 0;
    }

    public boolean isBiggerThan(Bitmask bit) {
        return (this.bit & bit.bit) == bit.bit;
    }
}

public class Main {

    static Bitmask[] bitmask;
    static Bitmask allBitmask;
    static int n, k, max;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        allBitmask = new Bitmask();
        bitmask = new Bitmask[n];
        for (int i = 0; i < n; ++i) {
            String str = br.readLine();
            bitmask[i] = new Bitmask().addBit(str);
            allBitmask.addBit(str);
        }

        if (allBitmask.getSize() <= k) {
            max = n;
        } else {
            Bitmask bit = new Bitmask().addBit("antic");
            back(bit, -1);
        }

        System.out.println(max);
    }

    static void back(Bitmask bit, int lastAddIdx) {
        if (bit.getSize() == k) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (bit.isBiggerThan(bitmask[i])) {
                    sum++;
                }
            }
            max = Math.max(sum, max);
            return;
        }

        for (int i = lastAddIdx + 1; i < 26; ++i) {
            if (allBitmask.isHere(i)) {
                back(bit.addBit(i), i);
                bit.subBit(i);
            }
        }
    }
}
