#include<iostream>
#include "uimanip.cpp"
#include "oopsmodified.cpp"
using namespace std;

int main(){
    Student s; // Should we work with only one obj, or make a list of objects?
    int choice = 0;
    clrscr;
    do{
        header();
        cout << "MENU: \n";
        cout << "-----------------------------------------------------------------------------\n";
        cout << "[1] Enter student details\n";
        cout << "[2] Edit age of a student\n";
        cout << "[3] Append the address to a student file\n";
        cout << "[4] Exit\n";
        cout << "-----------------------------------------------------------------------------\n";
        cout << "Choose your option: ";
        cin >> choice;
        clrscr;
        header();
        switch(choice){ 
            case 1:
            case 2:
            case 3:
            case 4: break;
            default: cout << "Invalid input\n";
        }
        clrscr;
    }while(choice != 4);//Change to whatever is maximum
    
    header();
    cout << "Thanks for interacting!\n";// Ending screen, can add a thank you page
    while(1); // To prevent .exe/.out file from just stopping
}