#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void display_dash(string dash_list){
    for (int j=0;j<dash_list.length();j++){
        cout<<dash_list[j]<<" ";
    }
    cout<<endl;

}

int main(){
    while (true){
        string words[]={"amsterdam","london","lahore","houston","boston","mumbai","karachi","moscow","warsaw","dublin"};
        srand(time(0));
        string word_selected=words[0+(rand()%10)];
        string og_word_selected=word_selected;
        int tries=word_selected.length();
        cout<<"Number of tries is "<<tries<<endl;
        string guessed_letters="";
        string dash_list="";

        for (int i=1;i<=word_selected.length();i++){
            dash_list=dash_list+"_";
        }    
        char user_input;

        while (true){
            
            display_dash(dash_list);
            cout<<"Guess the word one letter at a time : ";
            cin>>user_input;
            cout<<endl;
            if (word_selected.find(user_input) != string::npos){
                dash_list[word_selected.find(user_input)]=user_input;
                word_selected[word_selected.find(user_input)]='*';
                guessed_letters+=user_input;
            }
            else{
                if (dash_list.find(user_input) != string::npos){
                    cout<<"The letter has already been selected "<<endl;
                }
                if (guessed_letters.find(user_input) != string::npos){
                    cout<<"The letter has already been selected and is a wrong guess "<<endl;
                }    
                    
                else{
                    cout<<"Wrong Guess! Try again! "<<endl;
                    tries-=1;
                    guessed_letters+=user_input;
                }

                    
            }
            if (dash_list == og_word_selected){
                display_dash(dash_list);
                cout<<"Congratulations! You guessed the word!"<<endl;
                break;
            }
                  
            cout<<"Number of tries left is "<<tries<<endl;
            cout<<endl;
            if (tries<1){
                cout<<"You ran out of number of chances!";
                cout<<endl;
                break;
            }
        }
        char again;
        cout<<"Enter E to exit or any other key to go again : ";
        cin>>again;
        cout<<endl;
        if (again=='e' || again=='E'){
            break;
        }
    
    
    }

    
    return 0;
}
