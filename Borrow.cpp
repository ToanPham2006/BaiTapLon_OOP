#include "Borrow.h"
#include <iostream>
using namespace std;
Borrow::Borrow(){
 maSV = 0; masach = 0; ngay = 0; thang = 0; nam = 0;
}
Borrow::Borrow(int sv, int s, int d, int m, int y){
 maSV = sv;
 masach = s;
 ngay = d;
 thang = m;
 nam = y;
}
int Borrow::getmaSV() {
 return maSV;
}
int Borrow::getmasach() {
 return masach;
}
void Borrow::xuat(){
 cout<<"Ma sinh vien: "<<maSV<<endl;
 cout<<"Ma sach: "<<masach<<endl;
 cout<<"Ngay muon: "<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}
void Borrow::WriteBinary(ofstream &out){
 out.write((char*)&maSV, sizeof(maSV));
 out.write((char*)&masach, sizeof(masach));
 out.write((char*)&ngay, sizeof(ngay));
 out.write((char*)&thang, sizeof(thang));
 out.write((char*)&nam, sizeof(nam));
}
void Borrow::ReadBinary(ifstream &in){
 in.read((char*)&maSV, sizeof(maSV));
 in.read((char*)&masach, sizeof(masach));
 in.read((char*)&ngay, sizeof(ngay));
 in.read((char*)&thang, sizeof(thang));
 in.read((char*)&nam, sizeof(nam));
}

