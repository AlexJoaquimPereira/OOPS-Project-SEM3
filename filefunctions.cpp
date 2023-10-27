#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include "unified.cpp"
using namespace std;

void Student :: edit_age(int a){
    age = a; //Or call saveToFile(this)from here
    int pos = 0, digit = 0, r = roll;
    ofstream F1;
    char filename[24];
    sprintf(filename, "%d.txt", roll);
    F1.open(filename, ios::out);
    while(r){
        digit *= 10;
        digit += r%10;
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
    sprintf(filename, "%d.txt", roll);
    F1.open(filename, ios::app);
    F1 << address << "\n";
    F1.close();
}

void saveToFile(Student s)
{
    ofstream fout;
    char roll[24];
    sprintf(roll, "%d.txt", s.roll);
    fout.open(roll);
    fout<<s.roll<<endl;
    fout<<s.name<<endl;
    fout<<s.age<<endl;
    fout<<s.branch<<endl;
    fout.close();
}

Student readfromfile(int r)
{
    const int N = 50;
    char fn[N],fid[N],fage[N],fb[N]; 
    ifstream fin;
    char roll[N+4];
    sprintf(roll, "%d.txt", r);
    fin.open(roll);
    fin.getline(fid,N);
    fin.getline(fn,N);
    fin.getline(fage,N);
    fin.getline(fb,N);

    Student s(fn, (int)fage, fb, (int)fid);
    return s;
}