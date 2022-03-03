// https://www.acmicpc.net/problem/10814
import java.io.*;
import java.util.*;

class Person implements Comparable<Person>
{
    private int age;
    private String name;
    private int count;
    public Person(int a, String n, int cnt)
    {
        age = a;
        name = n;
        count = cnt;
    }

    public int getAge() { return age; }
    public int getCount() { return count; }

    @Override
    public int compareTo(Person l)
    {
        if(age != l.getAge()) return Integer.compare(age, l.getAge());
        return Integer.compare(count, l.getCount());
    }

    @Override
    public String toString()
    {
        return Integer.toString(age) + " " + name;
    }
}

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        ArrayList<Person> arr = new ArrayList<Person>();
        
        for(int i = 0; i < n; ++i)
        {
            st = new StringTokenizer(br.readLine(), " ");
            int age = Integer.parseInt(st.nextToken());
            String name = st.nextToken();
            arr.add(new Person(age, name, i));
        }

        Collections.sort(arr);

        for(Person i  : arr)
            System.out.println(i.toString());

        return;
    }
}
