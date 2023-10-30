#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<sys/stat.h>
#include<list>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/stat.h>
#endif

#define ud "\033[4m"
#define unud "\033[24m"
#define clrscr cout<<"\033[2J\033[H"
#define NEW "\n"
using namespace std;

void createDirectory() {
#ifdef _WIN32
    CreateDirectoryA("stud_details", NULL);
#else
    mkdir("stud_details")
#endif
}

class Student{
    int roll;
    char name[20];
    int age;
    char branch[10];
    char address[50];
  public:
    Student(){ strcpy(address, "");}
    Student(char[], int, char[],int);
    Student(char[], int, char[],int, char[]);
    ~Student(){}
    void getdata(int);
    void enteredDetails();
    void append_address(char[]);
    void edit_age(int);
    friend void saveToFile(Student);
};

void Student :: edit_age(int a){
    age = a;
    int pos = 0, digit = 0, r = roll;
    ofstream F1;
    char filename[24];
    sprintf(filename, "stud_details/%d.txt", roll);
    F1.open(filename, ios::out);
    while(r){
        digit++;
        r /= 10;
    }
    pos = digit + strlen(name) ;
    F1.seekp(pos, ios::beg);
    F1 << age << "\n";
    F1.close();
}

void Student :: append_address(char addr[]){
    strcpy(address, addr);
    ofstream F1;
    char filename[24];
    sprintf(filename, "stud_details/%d.txt", roll);
    F1.open(filename, ios::app);
    F1 << address << "\n";
    F1.close();
}

Student :: Student (char n[], int a, char br[], int r){
    strcpy(name, n);
    age = a;
    strcpy(branch, br);
    roll = r;
}

Student :: Student (char n[], int a, char br[], int r, char add[]){
    strcpy(name, n);
    age = a;
    strcpy(branch, br);
    roll = r;
    strcpy(address, add);
}

void Student :: getdata(int r){
    roll = r;
    cout << "Roll number: " << roll << endl;
    cout << "Name: ";
    cin.ignore();
    cin.getline(name, 20);
    cout << "Age: "; 
    cin >> age;
    cout << "Branch: "; 
    cin.ignore();
    cin.getline(branch, 10);
    cin.ignore();
}

void Student :: enteredDetails() 
{
    cout << "Roll number: " << roll << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Branch: " << branch << endl;
    if(strcmp(address, ""))
        cout << "Address: " << address << endl;
}

void saveToFile(Student s)
{
    ofstream fout;
    char roll[24];
    sprintf(roll, "stud_details/%d.txt", s.roll);
    fout.open(roll, ios::out);
    fout<<s.roll<<"\n";
    fout<<s.name<<"\n";
    fout<<s.age<<"\n";
    fout<<s.branch<<"\n";
    fout.close();
}

Student readfromfile(int r)
{
    const int N = 50;
    char fn[N],fid[N],fage[N],fb[N], faddr[N]; 
    ifstream fin;
    char roll[N+4];
    sprintf(roll, "stud_details/%d.txt", r);
    fin.open(roll, ios::in);
    fin.getline(fid,N);
    fin.getline(fn,N);
    fin.getline(fage,N);
    fin.getline(fb,N);
    if(!fin.eof()){
        fin.getline(faddr, N);
        Student s1(fn, stoi(fage), fb, stoi(fid), faddr);
        return s1;
    }
    Student s1(fn, stoi(fage), fb, stoi(fid));
    return s1;
}

void putroll(int roll){
    ofstream F1;
    F1.open("stud_details/roll.txt", ios::out | ios::trunc);
    F1 << roll;
    F1.close();
}

int getroll(){
    char a[10];
    ifstream F1;
    F1.open("stud_details/roll.txt", ios::in);
    F1.getline(a, 10);
    F1.close();
    return stoi(a);
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

int main(){
    list <Student> stud;
    list <Student> ::iterator it;
    Student s;
    int rollcount = 0, choice = 0, rollno, temp;
    char add[50], filename[24], c;
    createDirectory();
    ifstream f1("stud_details/roll.txt", ios::in);
    if(f1.is_open())
        rollcount = getroll();
    else putroll(0);
    f1.close();
    for(int i = 1; i <= rollcount; i++){
        s = readfromfile(i);
        stud.push_back(s);
    }
    stud.sort();
    clrscr;
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
        clrscr;
        header();
        switch(choice){ 
            case 1:
                rollcount++;
                s.getdata(rollcount);
                stud.push_back(s);
                saveToFile(s);
                s = readfromfile(rollcount);
                s.enteredDetails();
                break;
            case 2:
                cout << "Enter the roll number: ";
                cin >> rollno;
                if(rollno > rollcount || rollno <= 0){
                    cout << "Invalid roll number\n";
                    break;
                }
                it = stud.begin();
                for(int i = 2; i <= rollno; i++)
                    ++it;
                cout << "Enter the new age of the student: ";
                cin >> temp;
                it->edit_age(temp);
                s = readfromfile(rollno);
                s.enteredDetails();
                break;         
            case 3:
            cout << "Enter the roll number: ";
                cin >> rollno;
                if(rollno > rollcount || rollno <= 0){
                    cout << "Invalid roll number\n";
                    break;
                }
                it = stud.begin();
                for(int i = 2; i <= rollno; i++)
                    ++it;
                cout << "Enter the address of the student: ";
                cin.ignore();
                cin.getline(add, 50);
                it->append_address(add);
                s = readfromfile(rollno);
                s.enteredDetails();
                break;
            case 4:
                cout << "Do you want to view details of all students or only one? (y/n): ";
                cin >> c;
                if(c == 'y'){
                    for(int i = 1; i <= rollcount; i++){
                        s = readfromfile(i);
                        s.enteredDetails();
                        cout << "---------------------------\n";
                    }
                    break;
                }
                cout << "Enter the roll number of the student: ";
                cin >> rollno;
                if(rollno > rollcount || rollno <= 0){
                    cout << "Invalid roll number\n";
                    break;
                }
                s = readfromfile(rollno);
                s.enteredDetails();
                break;
            case 5: break;
            default: cout << "Invalid input\n";
        }
        cin.ignore();
        clrscr;
    }while(choice != 5);
    putroll(rollcount);

    header();
    cout << "Thanks for interacting!\n";
    while(1);
}