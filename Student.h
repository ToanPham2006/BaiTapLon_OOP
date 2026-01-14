#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <fstream>
using namespace std;
class Student {
 private:
 int maSV;
 char tenSV[50];
 char lop[20];
public:
 Student();
 void nhap();
 void xuat();
 int getma();
 char* getten();
 char* getlop();
 void WriteBinary(ofstream &out);
 void ReadBinary(ifstream &in);
};
#endif
