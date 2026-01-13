#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <fstream>
using namespace std;
class Book {
private:
 int masach;
 char tensach[50];
 char tacgia[50];
 int namXB;
public:
 void nhap();
 void xuat();
 int getma();
};
#endif
