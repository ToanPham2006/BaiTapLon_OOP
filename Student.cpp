#include "Student.h"
#include <iostream>
#include <fstream>
using namespace std;
Student::Student() {
 maSV = 0;
 tenSV[0] = 0;
 lop[0] = 0;
}
void Student::nhap() {
 cout << "Ma sinh vien: ";
 cin >> maSV;
 cin.ignore();
 cout << "Ho ten sinh vien: ";
 cin.getline(tenSV, 50);
 cout << "Lop: ";
 cin.getline(lop, 20);
}
void Student::xuat() {
    cout << maSV << " | " << tenSV << " | " << lop << endl;
}
int Student::getma() {
 return maSV;
}
char* Student::getten() {
 return tenSV;
}
char* Student::getlop() {
 return lop;
}
void Student::WriteBinary(ofstream &out) {
 out.write((char*)&maSV, sizeof(maSV));
 out.write(tenSV, sizeof(tenSV));
 out.write(lop, sizeof(lop));
}
void Student::ReadBinary(ifstream &in) {
 in.read((char*)&maSV, sizeof(maSV));
 in.read(tenSV, sizeof(tenSV));
 in.read(lop, sizeof(lop));
}
