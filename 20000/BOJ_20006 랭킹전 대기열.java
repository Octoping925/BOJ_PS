// https://www.acmicpc.net/problem/20006
import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class Player {
    int level;
    String id;

    public static Player of(String levelAndId) {
        String[] levelAndID = levelAndId.split(" ");
        return new Player(Integer.parseInt(levelAndID[0]), levelAndID[1]);
    }

    private Player(int level, String id) {
        this.level = level;
        this.id = id;
    }

    public boolean isMatchable(Player opponent) {
        return this.level - 10 <= opponent.level
                && opponent.level <= this.level + 10;
    }

    @Override
    public String toString() {
        return String.format("%d %s", level, id);
    }
}

class RoomList {
    List<Room> rooms = new ArrayList<>();

    public Optional<Room> getAvailableRoom(Player player) {
        return rooms.stream()
                .filter(room -> room.canEnter(player))
                .findFirst();
    }

    public void createRoom(Player player) {
        this.rooms.add(new Room(player));
    }

    @Override
    public String toString() {
        return rooms.stream()
                .map(Room::toString)
                .collect(Collectors.joining("\n"));
    }
}

class Room {
    List<Player> players;

    public Room(Player player) {
        this.players = new ArrayList<>();
        this.players.add(player);
    }

    private Player getRoomMaster() {
        return this.players.get(0);
    }

    public boolean isStarted() {
        return players.size() == Config.ROOM_SIZE;
    }

    public boolean canEnter(Player player) {
        Player roomMaster = getRoomMaster();
        return !isStarted() && roomMaster.isMatchable(player);
    }

    public void enter(Player player) {
        this.players.add(player);
    }

    @Override
    public String toString() {
        return (isStarted() ? "Started!" : "Waiting!") + '\n' +
                players.stream()
                        .sorted(Comparator.comparing(player -> player.id))
                        .map(Player::toString)
                        .collect(Collectors.joining("\n"));
    }
}

class Config {
    public static int ROOM_SIZE;
}

public class Main {

    RoomList roomList = new RoomList();

    public static void main(String[] args) throws IOException {
        new Main().solution();
    }

    void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int players = Integer.parseInt(st.nextToken());
        Config.ROOM_SIZE = Integer.parseInt(st.nextToken());

        for(int i = 0; i < players; ++i) {
            Player player = Player.of(br.readLine());

            roomList.getAvailableRoom(player)
                    .ifPresentOrElse(
                            room -> room.enter(player),
                            () -> roomList.createRoom(player)
                    );
        }

        System.out.println(roomList.toString());
    }
}
