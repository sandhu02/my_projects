import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;


public class FrontEnd extends JFrame {
    BackEnd backend;

    JButton button_1;
    JButton button_2;
    JButton button_3;
    JButton button_4;
    JButton button_5;
    JButton button_6;
    JButton button_7;
    JButton button_8;
    JButton button_9;

    public FrontEnd(BackEnd backend) {
        this.backend = backend;
        
        setTitle("Tic Tac Toe");
        setSize(600,600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
        setLayout(new GridLayout(3,3));

        button_1 = new JButton(backend.slots[0].symbol);
        button_2 = new JButton(backend.slots[1].symbol);
        button_3 = new JButton(backend.slots[2].symbol);
        button_4 = new JButton(backend.slots[3].symbol);
        button_5 = new JButton(backend.slots[4].symbol);
        button_6 = new JButton(backend.slots[5].symbol);
        button_7 = new JButton(backend.slots[6].symbol);
        button_8 = new JButton(backend.slots[7].symbol);
        button_9 = new JButton(backend.slots[8].symbol);

        button_1.setBackground(backend.slots[0].color);
        button_2.setBackground(backend.slots[1].color);
        button_3.setBackground(backend.slots[2].color);
        button_4.setBackground(backend.slots[3].color);
        button_5.setBackground(backend.slots[4].color);
        button_6.setBackground(backend.slots[5].color);
        button_7.setBackground(backend.slots[6].color);
        button_8.setBackground(backend.slots[7].color);
        button_9.setBackground(backend.slots[8].color);
        
        MyActionListener listener = new MyActionListener();

        button_1.addActionListener(listener);
        button_2.addActionListener(listener);
        button_3.addActionListener(listener);
        button_4.addActionListener(listener);
        button_5.addActionListener(listener);
        button_6.addActionListener(listener);
        button_7.addActionListener(listener);
        button_8.addActionListener(listener);
        button_9.addActionListener(listener);

        add(button_1);
        add(button_2);
        add(button_3);
        add(button_4);
        add(button_5);
        add(button_6);
        add(button_7);
        add(button_8);
        add(button_9);
    }

    public class MyActionListener implements ActionListener{

        public void checkwinner(){
            if (backend.getWinner() == 1){
                JOptionPane.showMessageDialog(null,"Winner is "+backend.player1.symbol);
                backend.reset();
            }
            else if (backend.getWinner() == 2){
                JOptionPane.showMessageDialog(null,"Winner is "+backend.player2.symbol);    
                backend.reset();                
            }
        }

        public void fillSlot(int slotNumber){
            if (backend.slots[slotNumber].symbol == "X" || backend.slots[slotNumber].symbol == "O"){
                JOptionPane.showMessageDialog(null, "Slot Already Selected");
            }
            else{
                backend.changeSymbolAndColor(slotNumber);   
            }
        }

        public void actionPerformed(ActionEvent ae){
            if (ae.getActionCommand().equals( backend.slots[0].symbol)){
                fillSlot(0);
            }
            if (ae.getActionCommand().equals( backend.slots[1].symbol)){
                fillSlot(1);   
            }
            if (ae.getActionCommand().equals( backend.slots[2].symbol)){
                fillSlot(2);                
            }
            if (ae.getActionCommand().equals( backend.slots[3].symbol)){
                fillSlot(3);                
            }
            if (ae.getActionCommand().equals( backend.slots[4].symbol)){
                fillSlot(4);                
            }
            if (ae.getActionCommand().equals( backend.slots[5].symbol)){
                fillSlot(5);                
            }
            if (ae.getActionCommand().equals( backend.slots[6].symbol)){
                fillSlot(6);
            }    
            if (ae.getActionCommand().equals( backend.slots[7].symbol)){
                fillSlot(7);                
            }
            if (ae.getActionCommand().equals( backend.slots[8].symbol)){
                fillSlot(8);                
            }

            checkwinner();
            backend.changePlayer();
            dispose();
            FrontEnd f = new FrontEnd(backend);
        }
    }
    
}