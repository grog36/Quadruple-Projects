public class Driver {
    public static void main(String[] args) {
        Board board = new Board(1);
        System.out.println(board.getStatus());
        board.playMove(0, 2);
        System.out.println(board.getStatus());
    }
}