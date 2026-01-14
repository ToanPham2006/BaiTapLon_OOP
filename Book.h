#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Book {
private:
 int masach;
 char tensach[50];
 char tacgia[50];
 int namXB;
 int tinhtrang; // 0: Chua muon, 1: Da muon
public:
 Book();
 void nhap();
 void xuat();
 int getma();
 char* getten();
 char* gettacgia();
 int gettinhtrang();
 void settinhtrang(int tt);
 void WriteBinary(ofstream &out);
 void ReadBinary(ifstream &in);
};

#endif
