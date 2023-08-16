#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    while (true){
        long long int_number;
        string str_number;
        while (true){
            cout<<"Enter card number : ";
            cin>>int_number;
            str_number=to_string(int_number);
            
            if (int_number>=1000000000000 && int_number<=9999999999999999 && (str_number[0]=='3' && str_number[1]=='7' || str_number[0]=='4' || str_number[0]=='5' || str_number[0]=='6') ){
                break;
            }
            else{
                cout<<"Enter a valid card number! "<<endl;
            }
        }


        int even_places_sum=0;
        int int_value;
        
        for (int i=(str_number.length())-2;i>=0;i-=2){
            int_value=(int)(str_number[i])-48;
            int double_int_value=int_value*2;
            if (double_int_value>9){
                double_int_value=floor(double_int_value/10)+double_int_value%10;
            }
            even_places_sum+=double_int_value;
        }
        
        int odd_places_sum=0;
        for (int i=(str_number.length())-1;i>=0;i-=2){
            int_value=(int)(str_number[i])-48;
            odd_places_sum+=int_value;
        }
        
        if ((even_places_sum+odd_places_sum)%10==0){
            cout<<"Card number is Valid"<<endl;
        }
        else{
            cout<<"Card number is Invalid"<<endl;
        }
    cout<<"Enter E to exit or any other key to again : ";
    char again;
    cin>>again;
    if (again=='e' || again=='E'){
        break;
    }     
    }
    return 0;
}