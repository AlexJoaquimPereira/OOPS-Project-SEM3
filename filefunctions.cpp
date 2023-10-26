#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include "unified.cpp"
using namespace std;

void saveToFile(Student s)
{
    ofstream fout;
    char roll[24];
    sprintf(roll, "%d.txt");
    fout.open(roll);
    fout<<s.roll<<endl;
    fout<<s.name<<endl;
    fout<<s.age<<endl;
    fout<<s.branch<<endl;
    fout.close();
}

void readfromfile(int r)
{
    const int N = 20;
    char fn[N],fid[N],fage[N],fb[N]; 
    ifstream fin;
    char roll[N+4];
    sprintf(roll, "%d.txt");
    fin.open(roll);
    fin.getline(fid,N);
    fin.getline(fn,N);
    fin.getline(fage,N);
    fin.getline(fb,N);
    
    cout << "Student ID: " << fid << endl;
    cout << "Name: " << fn << endl;
    cout << "Age: " << fage << endl;
    cout << "Branch: " << fb << endl;
}