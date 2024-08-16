public class BackEnd {
    Player[] slots;

    Player player1;
    Player player2;
    Player current_player;
    
    public BackEnd(Player player1,Player player2){
        this.player1 = player1;
        this.player2 = player2;
        current_player = player1;

        slots = new Player[9];
        slots[0] = new Player("1",null);
        slots[1] = new Player("2",null);
        slots[2] = new Player("3",null);
        slots[3] = new Player("4",null);
        slots[4] = new Player("5",null);
        slots[5] = new Player("6",null);
        slots[6] = new Player("7",null);
        slots[7] = new Player("8",null);
        slots[8] = new Player("9",null);
    }   

    public int getWinner(){
        //compares 1,2,3
        if (slots[0] .equals (slots[1]) && slots[1] .equals( slots[2]) && slots[2].equals(player1)){
            return 1;
        }
        if (slots[0] .equals (slots[1]) && slots[1] .equals( slots[2]) && slots[2].equals(player2)){
            return 2;
        }

        //compares 4,5,6
        if (slots[3] .equals (slots[4]) && slots[4] .equals( slots[5]) && slots[5].equals(player1)){
            return 1;
        }
        if (slots[3] .equals (slots[4]) && slots[4] .equals( slots[5]) && slots[5].equals(player2)){
            return 2;
        }

        //compares 7,8,9
        if (slots[6] .equals (slots[7]) && slots[7] .equals( slots[8]) && slots[8].equals(player1)){
            return 1;
        }
        if (slots[6] .equals (slots[7]) && slots[7] .equals( slots[8]) && slots[8].equals(player2)){
            return 2;
        }
        
        //compares 1,4,7
        if (slots[0] .equals (slots[3]) && slots[3] .equals( slots[6]) && slots[6].equals(player1)){
            return 1;
        }
        if (slots[0] .equals (slots[3]) && slots[3] .equals( slots[6]) && slots[6].equals(player2)){
            return 2;
        }

        //compares 2,5,8
        if (slots[1] .equals (slots[4]) && slots[4] .equals( slots[7]) && slots[7].equals(player1)){
            return 1;
        }
        if (slots[1] .equals (slots[4]) && slots[4] .equals( slots[7]) && slots[7].equals(player2)){
            return 2;
        }

        //compares 3,6,9
        if (slots[2] .equals (slots[5]) && slots[5] .equals( slots[8]) && slots[8].equals(player1)){
            return 1;
        }
        if (slots[2] .equals (slots[5]) && slots[5] .equals( slots[8]) && slots[8].equals(player2)){
            return 2;
        }

        //compares 1,5,9
        if (slots[0] .equals (slots[4]) && slots[4] .equals( slots[8]) && slots[8].equals(player1)){
            return 1;
        }
        if (slots[0] .equals (slots[4]) && slots[4] .equals( slots[8]) && slots[8].equals(player2)){
            return 2;
        }

        //compares 3,5,7
        if (slots[2] .equals (slots[4]) && slots[4] .equals( slots[6]) && slots[6].equals(player1)){
            return 1;
        }
        if (slots[2] .equals (slots[4]) && slots[4] .equals( slots[6]) && slots[6].equals(player2)){
            return 2;
        }
        
        //return 0 if there is no winner yet
        return 0;
    }

    public void changeSymbolAndColor(int slotNumber){
        
        slots[slotNumber].symbol = current_player.symbol;
        slots[slotNumber].color = current_player.color; 
    
    }

    public void changePlayer(){
        if (current_player == player1){
            current_player = player2;
        }
        else {
            current_player = player1;
        }
    }

    public void reset(){
        current_player = player1;

        slots[0] = new Player("1",null);
        slots[1] = new Player("2",null);
        slots[2] = new Player("3",null);
        slots[3] = new Player("4",null);
        slots[4] = new Player("5",null);
        slots[5] = new Player("6",null);
        slots[6] = new Player("7",null);
        slots[7] = new Player("8",null);
        slots[8] = new Player("9",null);
    }
}