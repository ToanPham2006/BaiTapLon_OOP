#ifndef BORROW_H
#define BORROW_H
#include <iostream>
#include <fstream>
using namespace std;
class Borrow{
private:
 int maSV;
 int masach;
 int ngay;
 int thang;
 int nam;
public:
 Borrow();
 Borrow(int sv, int s, int d, int m, int y);
 int getmaSV();
 int getmasach();
 void xuat();
 void WriteBinary(ofstream &out);
 void ReadBinary(ifstream &in);
};
#endif
