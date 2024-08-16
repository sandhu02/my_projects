import java.awt.Color;

public class Main {

    public static void main(String[] args) {
        Player player1 = new Player("X", new Color(255,0,0));
        Player player2 = new Player("O", new Color(0,0,255));
        
        BackEnd backend = new BackEnd(player1, player2);
        FrontEnd frontend = new FrontEnd(backend);
    }

}