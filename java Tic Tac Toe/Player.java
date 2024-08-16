import java.awt.Color;

public class Player {
    String symbol;
    Color color;

    public Player(String symbol, Color color) {
        this.symbol = symbol;
        this.color = color;
    }
    
    
    public boolean equals(Player player2){
        if (this.symbol.equals(player2.symbol) && this.color .equals(player2.color)){
            return true;
        }
        return false;
    }
}
