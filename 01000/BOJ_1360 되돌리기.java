// https://www.acmicpc.net/problem/1360
import java.io.*;

class Command {
    int mode; // 0 = type, 1 = undo
    char arg;
    int undoTime;
    int time;

    Command(String txt) {
        String[] command = txt.split(" ");
        this.mode = command[0].equals("type") ? 0 : 1;
        if(this.mode == 0) this.arg = command[1].charAt(0);
        else this.undoTime = Integer.parseInt(command[1]);
        this.time = Integer.parseInt(command[2]);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Command[] commands = new Command[n];
        for(int i = 0; i < n; ++i) {
            commands[i] = new Command(br.readLine());
        }

        int nowTime = commands[n-1].time + 1;
        for(int i = n-1; i >= 0; --i) {
            if(commands[i].time >= nowTime) {
                commands[i] = null;
                continue;
            }

            if(commands[i].mode == 1) {
                nowTime = commands[i].time - commands[i].undoTime;
            }
        }

        for(int i = 0; i < n; ++i) {
            if(commands[i] != null && commands[i].mode == 0) {
                System.out.print(commands[i].arg);
            }
        }
    }
}