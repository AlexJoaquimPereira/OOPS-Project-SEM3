#include <iostream>
#include <iomanip>
#define ud "\033[4m"
#define unud "\033[24m"
using namespace std;

void clrscr() {
    cout << "\033[2J\033[H";
}

ostream &header(ostream & out){
    out <<
    "+---------------------------------------------------------------------------+\n"
    "|                       "
                       <<ud<<"STUDENT MANAGEMENT SYSTEM"<<unud<<
                                                     "                           |\n"
    "| Developed by: Aaditya Salgaonkar      (22B-CO-001)                        |\n"
    "|             : Aarya Desai             (22B-CO-002)                        |\n"
    "|             : Aditi Malik             (22B-CO-003)                        |\n"
    "|             : Ahmed Khan              (22B-CO-004)                        |\n"
    "|             : Akaash Samson Gudlangari(22B-CO-005)                        |\n"
    "|             : Alex Joaquim Pereira    (22B-CO-006)                        |\n"
    "+---------------------------------------------------------------------------+\n";
}

ostream &menu(ostream &out){
    out << endl;
    int n = 3; //Change n value as number of menu arguments
    char *str[n];
    //You can add more options below as required
    str[0] = "Enter student details\n";
    str[1] = "Edit age of a student\n";
    str[2] = "Append the address to a student file";
    out << "MENU: \n";
    out << "-----------------------------------------------------------------------------";
    for(int i = 1; i <= n; i++){
        out << endl;
        out << "[";
        out.setf(ios::left, ios::adjustfield);
        out << i;
        out << "]";
        out.width(70);
        out << str[i-1];
    }
    out << "\n-----------------------------------------------------------------------------\n";
    out << "Choose your option: ";
}