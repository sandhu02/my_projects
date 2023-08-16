#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;    

void grid_display(string grid_list){
    cout<<" "<<grid_list[0]<<" | "<<grid_list[1]<<" | "<<grid_list[2]<<" "<<endl ;
    cout<<"---|---|---"<<endl;
    cout<<" "<<grid_list[3]<<" | "<<grid_list[4]<<" | "<<grid_list[5]<<" "<<endl ;
    cout<<"---|---|---"<<endl;
    cout<<" "<<grid_list[6]<<" | "<<grid_list[7]<<" | "<<grid_list[8]<<" "<<endl ;
}

bool win_check(string grid_list,char symbol1,char symbol2,string compare_list,string player1,string player2){
    if (grid_list[0]==symbol1 && grid_list[1]==symbol1 && grid_list[2]==symbol1 ||
        grid_list[3]==symbol1 && grid_list[4]==symbol1 && grid_list[5]==symbol1 ||
        grid_list[6]==symbol1 && grid_list[7]==symbol1 && grid_list[8]==symbol1 ||
        grid_list[0]==symbol1 && grid_list[4]==symbol1 && grid_list[8]==symbol1 ||
        grid_list[2]==symbol1 && grid_list[4]==symbol1 && grid_list[6]==symbol1 ||
        grid_list[0]==symbol1 && grid_list[3]==symbol1 && grid_list[6]==symbol1 ||
        grid_list[1]==symbol1 && grid_list[4]==symbol1 && grid_list[7]==symbol1 ||
        grid_list[2]==symbol1 && grid_list[5]==symbol1 && grid_list[8]==symbol1 ){
        grid_display(grid_list);
        cout<<"Winner is "<<player1<<endl;
        return true;
    }   
    else if (grid_list[0]==grid_list[1]==grid_list[2]==symbol2 ||
        grid_list[3]==symbol2 && grid_list[4]==symbol2 && grid_list[5]==symbol2 ||
        grid_list[6]==symbol2 && grid_list[7]==symbol2 && grid_list[8]==symbol2 ||
        grid_list[0]==symbol2 && grid_list[4]==symbol2 && grid_list[8]==symbol2 ||
        grid_list[2]==symbol2 && grid_list[4]==symbol2 && grid_list[6]==symbol2 ||
        grid_list[0]==symbol2 && grid_list[3]==symbol2 && grid_list[6]==symbol2 ||
        grid_list[1]==symbol2 && grid_list[4]==symbol2 && grid_list[7]==symbol2 ||
        grid_list[2]==symbol2 && grid_list[5]==symbol2 && grid_list[8]==symbol2 ){
        grid_display(grid_list);
        cout<<"Winner is "<<player2<<endl;
        return true;
    }
    else if(grid_list.length()==compare_list.length()){
        grid_display(grid_list);
        cout<<"Game Drawn"<<endl;
        return true;        
    }
    else{
        return false;
    }
        
}

void box_input(string &grid_list,char symbol,string &compare_list){
    grid_display(grid_list);
    
    string box_select;
    int int_box_select;
    while (true){
        while (true){
            cout<<"Select your box number : ";
            cin>>box_select;
            if (box_select=="9" || box_select=="1" || box_select=="2" || box_select=="3" || box_select=="4" || box_select=="5" || box_select=="6" || box_select=="7" || box_select=="8"){
                break;
            }
            else{
                cout<<"Box number should be between 1 and 9 : ";
            }
        }   
        
        if (compare_list.find(box_select) != std::string::npos){
            cout<<"This box has already been selected"<<endl;
            continue;
        }
        else{
            compare_list += box_select;
            break;
        }    

    }
    int_box_select=stoi(box_select);
    grid_list[int_box_select - 1]=symbol;
    
}
        
int main(){
    while (true){
        string player1;
        string player2;
        char symbol1;
        char symbol2;
        cout<<"Welcome to Tic Tac Toe"<<endl;
        cout<<endl;
        cout<<"Player 1 enter your name : ";
        cin>>player1;                                                                                  
        while (true){
            cout<<player1<<" Choose your symbol either X or O : ";
            cin>>symbol1;
            symbol1=toupper(symbol1);
            if (symbol1=='X' || symbol1=='O'){
                break;
            }
            else{
                cout<<"Invalid choice!"<<endl;    
            }
                
        }
        cout<<player1<<" your symbol is "<<symbol1<<endl;
        cout<<endl;
        cout<<"Player 2 enter your name : ";
        cin>>player2;
        if (symbol1=='X'){
            symbol2='O';
        }
        else{
            symbol2='X';
        }
        cout<<player2+" your symbol is "+symbol2<<endl;

        //toss
        int toss_select;
        string str_toss_select;
        srand(time(0));
        int toss=0+(rand()%2);
        cout<<endl;
        cout<<player2<<" Select Toss!"<<endl;
        while (true){
            cout<<"Enter 0 for head and 1 for tail : ";
            cin>>str_toss_select;
            if (str_toss_select == "0" || str_toss_select == "1"){
                toss_select=stoi(str_toss_select);
                break;
            }
            cout<<"Invalid choice!"<<endl;
        }
        
        string compare_list="";
        string grid_list="123456789";
        cout<<endl;
        char symbol;
        int turn=1;
        while (true){
            if (toss==toss_select){
                cout<<player2<<" Your turn"<<endl;
                symbol=symbol2;
                box_input(grid_list,symbol,compare_list);
                if (win_check(grid_list,symbol1,symbol2,compare_list,player1,player2)==true){
                    break;
                }
                
                cout<<endl;

                cout<<player1<<" Your turn"<<endl;
                symbol=symbol1;
                box_input(grid_list,symbol,compare_list);
                if (win_check(grid_list,symbol1,symbol2,compare_list,player1,player2)==true){
                    break;
                }
                cout<<endl;
            }
            else if (toss != toss_select){
                cout<<player1<<" Your turn"<<endl;
                symbol=symbol1;
                box_input(grid_list,symbol,compare_list);    
                if (win_check(grid_list,symbol1,symbol2,compare_list,player1,player2)==true){
                    break;
                }    
                cout<<endl;

                cout<<player2<<" Your turn"<<endl;
                symbol=symbol2;
                box_input(grid_list,symbol,compare_list);
                if (win_check(grid_list,symbol1,symbol2,compare_list,player1,player2)==true){
                    break;
                }    
                cout<<endl;
            }
        }    
    char again;
    cout<<"Enter 'E' to exit or any other key to play again : ";
    cin>>again;        
    if (again=='E' || again=='e'){
        break;
    }            

    }

    return 0;
} 