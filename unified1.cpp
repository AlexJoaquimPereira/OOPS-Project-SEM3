#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <iomanip>

#define ud "\033[4m"
#define unud "\033[24m"
#define clrscr "\033[2J\033[H"
using namespace std;

class Student{
    int roll;
    char name[20];
    int age;
    char branch[10];
    char address[50];
  public:
    Student(){strcpy(address, "");}
    ~Student(){}
    void getdata(int);
    void enteredDetails();
    void enteredDetailsInTableFormat();
    friend void append_address(int);
    friend void edit_age(int);
    friend void saveToFile(Student);
};

void edit_age(int rollno) {
    int newAge;
    cout << "Enter the new age for roll number " << rollno << ": ";
    cin >> newAge;
    if (newAge < 0)
    {
        cout << "Invalid age value. Age cannot be negative.\n";
        return;
    }
    Student student;
    char filename[24];
    sprintf(filename, "%d.txt", rollno);
    fstream file;
    file.open(filename, ios::in | ios::out | ios::binary);
    if (!file.is_open())
    {
        cout << "Student data file not found.\n";
        return;
    }
    file.read(reinterpret_cast<char *>(&student), sizeof(student));
    student.age = newAge;
    file.seekp(0, ios::beg);
    file.write(reinterpret_cast<char *>(&student), sizeof(student));
    file.close();
    cout << "Age updated successfully.\n";
}

void append_address(int rollno){
    char filename[24];
    sprintf(filename, "%d.txt", rollno);
    Student s;
    fstream file;
    file.open(filename, ios::in | ios::out | ios::binary);
    if (!file.is_open())
    {
        cout << "Error in opening the file!" << endl;
        return;
    }
    file.read(reinterpret_cast<char *>(&s), sizeof(s));
    cout << "Enter the address: ";
    cin.ignore();
    cin.getline(s.address, 50);
    file.seekp(0, ios::beg);
    file.write(reinterpret_cast<char *>(&s), sizeof(s));
    file.close();
}

void Student::getdata(int r){
    roll = r;
    cout << "Roll number: " << roll << endl;
    cout << "Name: ";
    cin.ignore();
    cin.getline(name, 20);
    cout << "Age: ";
    cin >> age;
    if (age < 0)
    {
        cout << "Invalid age value. Age cannot be negative.\n";
        return;
    }
    cout << "Branch: ";
    cin.ignore();
    cin.getline(branch, 10);
    cin.ignore();
}

void Student::enteredDetails(){
    cout.setf(ios::left, ios::adjustfield);
    cout << "| " << setw(11) << roll << "| " << setw(21) << name << "| " << setw(4) << age << "| "
         << setw(10) << branch << "| " << setw(18) << address << "|" << endl;
    //cout << "+------------+----------------------+-----+-----------+-------------------+" << endl;
}

void Student::enteredDetailsInTableFormat() {
    cout << "+------------+----------------------+-----+-----------+-------------------+" << endl;
    cout << "| Roll Number| Name                 | Age | Branch    | Address           |" << endl;
    cout << "+------------+----------------------+-----+-----------+-------------------+" << endl;
    cout.setf(ios::left, ios::adjustfield);
    cout << "| " << setw(11) << roll << "| " << setw(21) << name << "| " << setw(4) << age << "| "
         << setw(10) << branch << "| " << setw(18) << address << "|" << endl;
    //cout << "+------------+----------------------+-----+-----------+-------------------+" << endl;
}

void saveToFile(Student s)
{
    ofstream fout;
    char roll[24];
    sprintf(roll, "%d.txt", s.roll);
    fout.open(roll, ios::binary);
    fout.write(reinterpret_cast<char *>(&s), sizeof(s));
    fout.close();
}

void readfromfile(int r)
{
    char roll[24];
    sprintf(roll, "%d.txt", r);
    Student rf;
    ifstream fin;
    fin.open(roll, ios::binary);
    if (fin.fail())
    {
        cout << "Error in opening the file!" << endl;
        return;
    }
    fin.read(reinterpret_cast<char *>(&rf), sizeof(rf));
    rf.enteredDetailsInTableFormat();
    fin.close();
}

void readallfromfile(int r) {
    char roll[24];
    sprintf(roll, "%d.txt", r);
    Student rf;
    ifstream fin;
    fin.open(roll, ios::binary);
    if (fin.fail()) {
        cout << "Error in opening the file!" << endl;
        return;
    }
    fin.read(reinterpret_cast<char *>(&rf), sizeof(rf));
    rf.enteredDetails();
    fin.close();
}


void putroll(int roll){
    ofstream F1;
    F1.open("roll.txt", ios::out);
    F1 << roll;
    F1.close();
}

int getroll(){
    char a;
    ifstream F1;
    F1.open("roll.txt", ios::in);
    F1 >> (a);
    F1.close();
    return a - '0';
}

void header(){
    cout << "+---------------------------------------------------------------------------+\n"
         << "|                       "
                            << ud << "STUDENT MANAGEMENT SYSTEM" << unud 
                                                            << "                           |\n"
         << "| Developed by: Aaditya Salgaonkar      (22B-CO-001)                        |\n"
         << "|             : Aarya Desai             (22B-CO-002)                        |\n"        
         << "|             : Aditi Malik             (22B-CO-003)                        |\n"
         << "|             : Ahmed Khan              (22B-CO-004)                        |\n"
         << "|             : Akaash Samson Gudlangari(22B-CO-005)                        |\n"
         << "|             : Alex Joaquim Pereira    (22B-CO-006)                        |\n"
         << "+---------------------------------------------------------------------------+\n";
}

int main(){
    Student s;
    int rollcount = 0, choice = 0, rollno;
    char c;
    ifstream f1("roll.txt", ios::in);
    if(f1.good())
        rollcount = getroll();
    else putroll(0);
    f1.close();
    cout << clrscr;
    do{
        header();
        cout << "MENU: \n";
        cout << "-----------------------------------------------------------------------------\n";
        cout << "[1] Enter student details\n";
        cout << "[2] Edit age of a student\n";
        cout << "[3] Append the address to a student file\n";
        cout << "[4] Display student details from file\n";
        cout << "[5] Exit\n";
        cout << "-----------------------------------------------------------------------------\n";
        cout << "Choose your option: ";
        cin >> choice;
        cout << clrscr;
        header();
        switch (choice){
            case 1:
                rollcount++;
                s.getdata(rollcount);
                saveToFile(s);
                readfromfile(rollcount);
                getchar();
                break;
            case 2:
                cout << "Enter the roll number: ";
                cin >> rollno;
                if(rollno > rollcount || rollno <= 0){
                    cout << "Invalid roll number\n";
                    getchar();
                    break;
                }
                edit_age(rollno);
                readfromfile(rollno);
                getchar();
                break;
            case 3:
                cout << "Enter the roll number: ";
                cin >> rollno;
                if (rollno > rollcount || rollno <= 0){
                    cout << "Invalid roll number\n";
                    getchar();
                    break;
                }
                append_address(rollno);
                readfromfile(rollno);
                getchar();
                break;
            case 4:
                cout << "Do you want to view details of all students or only one? (y/n): ";
                cin >> c;
                if (c == 'y'){
                    int i = 1;
                    readfromfile(i);
                    for (i = 2; i <= rollcount; i++){
                        readallfromfile(i);
                        cout << "---------------------------\n";
                    }
                    getchar();
                    break;
                }
                cout << "Enter the roll number of the student: ";
                cin >> rollno;
                if(rollno > rollcount || rollno <= 0){
                    cout << "Invalid roll number\n";
                    getchar();
                    break;
                }
                readfromfile(rollno);
                getchar();
                break;
            case 5:
                break;
            default:
                cout << "Invalid input\n";
                getchar();
            }
        cin.ignore();
        cout << clrscr;
    } while(choice != 5);
    putroll(rollcount);

    header();
    cout << "Thanks for interacting!\n";
    getchar();
}