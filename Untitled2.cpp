#include <iostream>
#include <string>
#include "user_interface.cpp"
using namespace std;

int main(){
    User_Interface window;
    Figure* F;
    bool is_F = false;
    while(window.is_open()){
        window.read();


        while(window.create()){
            window.read();
            window.type(&F);
            is_F = true;
        }
        while(window.get()){
            if(is_F){
                window.read();
                window.command();
                window.what_get(F);
            }
            else{
                cout<<endl<<"### EROR: You don't have figure!";
            }

        }
        window.info();
        window.command();
    }
    cout<<endl<<"### Bye bye"<<endl;
    delete[] F;
}

