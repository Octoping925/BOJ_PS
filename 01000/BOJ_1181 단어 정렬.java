// https://www.acmicpc.net/problem/1181
import java.io.*;
import java.util.*;

class Word implements Comparable<Word>
{
    private int len;
    private String name;
    public Word(String n, int a)
    {
        len = a;
        name = n;
    }

    public String getName() { return name; }
    public int getLen() { return len; }

    @Override
    public int compareTo(Word l)
    {
        if(len != l.getLen()) return Integer.compare(len, l.getLen());
        return name.compareTo(l.getName());
    }

    @Override
    public String toString() { return name; }
}

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        TreeSet<Word> arr = new TreeSet<Word>();
        
        for(int i = 0; i < n; ++i)
        {
                String name = br.readLine();
                arr.add(new Word(name, name.length()));
        }

        for(Word i : arr.descendingSet().descendingSet())
                System.out.println(i.toString());

        return;
    }
}