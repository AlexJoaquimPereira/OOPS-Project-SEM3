#include <iostream>
#include <iomanip>
#include<fstream>
#include<sstream>
#define ud "\033[4m"
#define unud "\033[24m"
using namespace std;

class Student{
    char name[20];
    int age;
    char branch[10];
    int roll;
    char address[20];
  public:
    Student(){}
    ~Student(){}
    void getdata(int);
    void enteredDetails();
    friend void saveToFile(Student);
};

void Student :: getdata(int r){
    roll = r;
    cout << "Roll: " << roll << endl;
    cout << "Name: "; 
    cin.getline(name, 20);
    cout << "Age: "; 
    cin >> age;
    cout << "Branch: "; 
    cin.getline(branch, 10);
}

void Student :: enteredDetails() 
{
    cout << "Student ID: " << roll << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Branch: " << branch << endl;
}