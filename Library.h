#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Student.h"
#include "Borrow.h"
class Library {
private:
Book dsSach[100];
Student dsSV[100];
Borrow dsMuon[200];
int SoLuongSach;
int SoLuongSV;
int SoLuongMuon;
int timSachTheoMa(int ma);
int timSVTheoMa(int ma);
bool sachDangMuon(int maSach);
bool svDangMuon(int maSV);
public:
 Library();
 void themSach();
 void suaSach();
 void xoaSach();
 void hienThiSach();
 void themSV();
 void suaSV();
 void xoaSV();
 void hienThiSV();
 void muonSach();
 void traSach();
 void thongKeMuon();
 void ghiFile();
 void docFile();
};

#endif

