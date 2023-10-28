#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include "unified.cpp"
using namespace std;

void Student :: edit_age(int a){
    age = a;
    int pos = 0, digit = 0, r = roll;
    ofstream F1;
    char filename[24];
    sprintf(filename, "%d.txt", roll);
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
    char fn[N],fid[N],fage[N],fb[N], faddr[N]; 
    ifstream fin;
    char roll[N+4];
    sprintf(roll, "%d.txt", r);
    fin.open(roll);
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