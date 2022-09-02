// https://www.acmicpc.net/problem/17081
import java.io.*;
import java.util.*;

class Position {
    int x, y;

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void move(int x, int y) {
        if(this.x + x == 0 || this.y + y == 0 || this.x + x > Main.height || this.y + y > Main.width) {
            return;
        }
        if(Main.map[this.x + x][this.y + y] == '#') {
            return;
        }

        this.x += x;
        this.y += y;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(x * 1000 + y);
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Position) {
            Position p = (Position) obj;
            return p.x == x && p.y == y;
        }
        return false;
    }
}

class Fightable {
    int hp, maxHP;
    int atk, def;
    int exp, level;
    Weapon weapon = new Weapon(0);
    Armor armor = new Armor(0);

    public boolean isKilled() {
        return this.hp <= 0;
    }

    public void getHit(int dmg) {
        this.hp -= Math.max(dmg - this.def - this.armor.def, 1);
    }

    void heal(int healPoint) {
        this.hp = Math.min(this.hp + healPoint, this.maxHP);
    }
}

class Player extends Fightable {
    Position pos;
    Accessories accessories = new Accessories();

    public Player(int x, int y) {
        pos = new Position(x, y);
        this.hp = 20;
        this.maxHP = 20;
        this.atk = 2;
        this.def = 2;
        this.exp = 0;
        this.level = 1;
    }

    public void move(char control) {
        if(control == 'U') this.pos.move(-1, 0);
        else if(control == 'D') this.pos.move(1, 0);
        else if(control == 'L') this.pos.move(0, -1);
        else if(control == 'R') this.pos.move(0, 1);
    }

    public void levelUp() {
        if(this.exp < 5 * this.level) return;
        this.exp = 0;
        this.level++;
        this.maxHP += 5;
        this.hp = this.maxHP;
        this.atk += 2;
        this.def += 2;
    }

    public void interact() {
        char m = Main.map[pos.x][pos.y];

        if(m == '^') {
            if(this.haveAccessory(AccessoryType.DX)) this.hp -= 1;
            else this.hp -= 5;

            if(this.isKilled() && this.haveAccessory(AccessoryType.RE)) {
                this.revive();
            }
        }
        else if(m == '&' || m == 'M') {
            Monster monster = Main.monsterMap.get(pos);
            if(monster instanceof BossMonster && this.haveAccessory(AccessoryType.HU)) {
                this.heal(this.maxHP);
            }

            Main.fight(this, monster);

            if(this.isKilled()) {
                if(this.haveAccessory(AccessoryType.RE)) {
                    this.revive();
                    monster.heal(monster.maxHP);
                }
            }
            else {
                if(this.haveAccessory(AccessoryType.HR)) {
                    this.heal(3);
                }
                getExp(monster.exp);
                Main.map[pos.x][pos.y] = '.';
                Main.monsterMap.remove(pos);
                this.levelUp();
            }
        }
        else if(m == 'B') {
            Treasure treasure = Main.treasureMap.get(pos);
            if(treasure instanceof Weapon) {
                this.weapon = (Weapon) treasure;
            }
            else if(treasure instanceof Armor) {
                this.armor = (Armor) treasure;
            }
            else {
                this.accessories.addAccessory((AccessoryType) treasure);
            }

            Main.map[pos.x][pos.y] = '.';
            Main.treasureMap.remove(pos);
        }
    }

    public void attack(Monster monster, int turn) {
        int dmg = this.atk + this.weapon.atk;
        if(turn == 1 && this.haveAccessory(AccessoryType.CO)) {
            if(this.haveAccessory(AccessoryType.DX)) {
                dmg *= 3;
            }
            else {
                dmg *= 2;
            }
        }

        monster.getHit(dmg);
    }

    void getExp(int exp) {
        if(this.haveAccessory(AccessoryType.EX)) exp = (int)(exp * 1.2);
        this.exp += exp;
    }

    void revive() {
        this.heal(this.maxHP);
        this.pos = new Position(Main.playerFirstPos.x, Main.playerFirstPos.y);
        this.accessories.accessories.remove(AccessoryType.RE);
    }

    boolean haveAccessory(AccessoryType type) {
        return this.accessories.contains(type);
    }
}

class Monster extends Fightable {
    public String name;

    public void init(String name, int atk, int def, int maxHP, int exp) {
        this.name = name;
        this.atk = atk;
        this.def = def;
        this.maxHP = maxHP;
        this.hp = maxHP;
        this.exp = exp;
    }

    public void attack(Player player) {
        player.getHit(this.atk);
    }
}

class BossMonster extends Monster {}

interface Treasure {}

class Weapon implements Treasure {
    int atk;
    public Weapon(int atk) {
        this.atk = atk;
    }
}

class Armor implements Treasure {
    int def;
    public Armor(int def) {
        this.def = def;
    }
}

class Accessories {
    HashSet<AccessoryType> accessories = new HashSet<>();

    public void addAccessory(AccessoryType type) {
        if(accessories.size() == 4) return;
        accessories.add(type);
    }
    public boolean contains(AccessoryType type) {
        return accessories.contains(type);
    }
}

enum AccessoryType implements Treasure {
    HR, RE, CO, EX, DX, HU, CU
}

public class Main
{
    public static int width;
    public static int height;
    public static char[][] map;
    public static HashMap<Position, Monster> monsterMap = new HashMap<>();
    public static HashMap<Position, Treasure> treasureMap = new HashMap<>();
    char[] controlArr;
    Player player;
    BossMonster bossMonster;
    int treasureCount;
    public static Position playerFirstPos;
    int turn;

    public BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        new Main().solution();
    }

    void solution() throws IOException {
        setMap();
        controlArr = br.readLine().toCharArray();
        setMonster();
        setTreasure();

        for(turn = 0; turn < controlArr.length; ++turn) {
            player.move(controlArr[turn]);
            player.interact();

            if(bossMonster.isKilled() || player.isKilled()) {
                turn++;
                break;
            }
        }

        printMap();
        printStatus();
        printMessage();
    }

    static void fight(Player player, Monster monster) {
        int fightTurn = 0;
        while(!player.isKilled() && !monster.isKilled()) {
            ++fightTurn;
            player.attack(monster, fightTurn);
            if(monster.isKilled()) break;

            if(fightTurn == 1 && monster instanceof BossMonster && player.accessories.contains(AccessoryType.HU)) {
                continue;
            }
            monster.attack(player);
        }
    }

    void setMap() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        height = Integer.parseInt(st.nextToken());
        width = Integer.parseInt(st.nextToken());
        map = new char[height + 1][width + 1];

        for(int i = 1; i <= height; ++i) {
            char[] tmp = br.readLine().toCharArray();
            for(int j = 1; j <= width; ++j) {
                switch(tmp[j - 1]) {
                    case '@':
                        player = new Player(i, j);
                        playerFirstPos = new Position(i, j);
                        map[i][j] = '.';
                        break;
                    case '.':
                    case '#':
                    case '^':
                        map[i][j] = tmp[j - 1];
                        break;
                    case '&':
                        monsterMap.put(new Position(i, j), new Monster());
                        map[i][j] = tmp[j - 1];
                        break;
                    case 'M':
                        bossMonster = new BossMonster();
                        monsterMap.put(new Position(i, j), bossMonster);
                        map[i][j] = tmp[j - 1];
                        break;
                    case 'B':
                        map[i][j] = tmp[j - 1];
                        treasureCount++;
                        break;
                }
            }
        }
    }

    void setMonster() throws IOException {
        for(int i = 0; i < monsterMap.size(); ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            String name = st.nextToken();
            int atk = Integer.parseInt(st.nextToken());
            int def = Integer.parseInt(st.nextToken());
            int maxHP = Integer.parseInt(st.nextToken());
            int exp = Integer.parseInt(st.nextToken());

            Monster monster = monsterMap.get(new Position(x, y));
            monster.init(name, atk, def, maxHP, exp);
        }
    }

    void setTreasure() throws IOException {
        for(int i = 0; i < treasureCount; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            String type = st.nextToken();
            String value = st.nextToken();

            switch(type) {
                case "A":
                    treasureMap.put(new Position(x, y), new Armor(Integer.parseInt(value)));
                    break;
                case "W":
                    treasureMap.put(new Position(x, y), new Weapon(Integer.parseInt(value)));
                    break;
                case "O":
                    treasureMap.put(new Position(x, y), AccessoryType.valueOf(value));
                    break;
            }
        }
    }

    void printMap() {
        for(int i = 1; i <= height; ++i) {
            StringBuilder sb = new StringBuilder();
            for(int j = 1; j <= width; ++j) {
                if(player.pos.x == i && player.pos.y == j && !player.isKilled()) {
                    sb.append('@');
                }
                else {
                    sb.append(map[i][j]);
                }
            }
            System.out.println(sb);
        }
    }

    void printStatus() {
        System.out.println("Passed Turns : " + turn);
        System.out.println("LV : " + player.level);
        System.out.printf("HP : %d/%d\n", Math.max(player.hp, 0), player.maxHP);
        System.out.printf("ATT : %d+%d\n", player.atk, player.weapon.atk);
        System.out.printf("DEF : %d+%d\n", player.def, player.armor.def);
        System.out.printf("EXP : %d/%d\n", player.exp, player.level * 5);
    }

    void printMessage() {
        if(bossMonster.isKilled()) System.out.println("YOU WIN!");
        else if(player.isKilled()) {
            String reason;
            if(map[player.pos.x][player.pos.y] == '^') reason = "SPIKE TRAP";
            else reason = monsterMap.get(player.pos).name;

            System.out.println("YOU HAVE BEEN KILLED BY " + reason + "..");
        }
        else if(turn == controlArr.length) System.out.println("Press any key to continue.");
    }

}