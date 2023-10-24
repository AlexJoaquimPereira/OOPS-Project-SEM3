#include<iostream>
#include "uimanip.cpp"
using namespace std;

int main(){
    int s = 0;
    clrscr();
    do{
        cout << header;
        cout << menu;
        cin >> s;
        clrscr();
        cout << header;
        switch(s){ // Add the cases linking to class student or class file functions

        }
        clrscr();
    }while(s!=5);
    
    cout << "Thanks for interacting\n";// Ending screen, can add a thank you page
    cin.get(); // To prevent .exe/.out file from just stopping
}