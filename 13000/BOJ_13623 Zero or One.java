import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Optional;

public class Main {

    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String[] handList = br.readLine().split(" ");
            System.out.println(new Main().playZeroOrOne(handList));
        }
        catch(IOException e) {
            throw new IllegalStateException();
        }
    }

    private char playZeroOrOne(String[] handList) {
        HandList zeroHandList = getZeroHandList(handList);
        HandList oneHandList = getOneHandList(handList);

        return getWinnerList(zeroHandList, oneHandList)
                    .map(HandList::pop)
                    .orElse('*');
    }

    private HandList getZeroHandList(String[] handList) {
        HandList zeroHandList = new ZeroHandList();
        for(int i = 0; i < handList.length; ++i) {
            if(handList[i].equals("0")) {
                zeroHandList.push(i);
            }
        }

        return zeroHandList;
    }

    private HandList getOneHandList(String[] handList) {
        HandList oneHandList = new OneHandList();
        for(int i = 0; i < handList.length; ++i) {
            if(handList[i].equals("1")) {
                oneHandList.push(i);
            }
        }

        return oneHandList;
    }

    private Optional<HandList> getWinnerList(HandList... handList) {
        return Arrays.stream(handList)
                    .filter(HandList::containsOneMan)
                    .findFirst();
    }
}

interface HandList {
    void push(int idx);
    boolean containsOneMan();
    char pop();
}

class ZeroHandList implements HandList {
    private final List<Integer> idxList = new ArrayList<>();

    @Override
    public void push(int idx) {
        idxList.add(idx);
    }

    @Override
    public boolean containsOneMan() {
        return idxList.size() == 1;
    }

    @Override
    public char pop() {
        return (char) ('A' + idxList.get(0));
    }
}

class OneHandList implements HandList {
    private final List<Integer> idxList = new ArrayList<>();

    @Override
    public void push(int idx) {
        idxList.add(idx);
    }

    @Override
    public boolean containsOneMan() {
        return idxList.size() == 1;
    }

    @Override
    public char pop() {
        return (char) ('A' + idxList.get(0));
    }
}