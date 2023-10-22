#include <iostream>
#include <iomanip>
#define ud "\033[4m"
#define unud "\033[24m"
using namespace std;

void clrscr() {
    cout << "\033[2J\033[H";
}

void header(){
    cout <<
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