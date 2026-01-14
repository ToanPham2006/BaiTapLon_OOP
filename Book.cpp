#include "Book.h"
#include <iostream>
using namespace std;
Book::Book() {
 masach = 0;
 namXB = 0;
 tinhtrang = 0;
 tensach[0] = 0;
 tacgia[0] = 0;
}
void Book::nhap() {
 cout<<"Ma sach: ";
 cin>>masach;
 cin.ignore();
 cout<<"Ten sach: ";
 cin.getline(tensach, 50);
 cout<<"Tac gia: ";
 cin.getline(tacgia, 50);
 cout<<"Nam xuat ban: ";
 cin>>namXB;
 cout<<"Tinh trang: ";
 cin>>tinhtrang;
}
void Book::xuat() {
 cout << masach << " | " << tensach << " | " << tacgia << " | " << namXB << " | ";
 if (tinhtrang == 0) {
 cout << "Chua muon" << endl;
}
 else {
 cout << "Da muon" << endl;
}
}
int Book::getma(){
 return masach;
 }
char* Book::getten(){
 return tensach;
}
char* Book::gettacgia() {
    return tacgia;
}
void Book::settinhtrang(int tt){
 tinhtrang = tt;
}
int Book::gettinhtrang(){
 return tinhtrang;
}
void Book::WriteBinary(ofstream &out) {
 out.write((char*)&masach, sizeof(masach));
 out.write(tensach, sizeof(tensach));
 out.write(tacgia, sizeof(tacgia));
 out.write((char*)&namXB, sizeof(namXB));
 out.write((char*)&tinhtrang, sizeof(tinhtrang));
}
void Book::ReadBinary(ifstream &in) {
 in.read((char*)&masach, sizeof(masach));
 in.read(tensach, sizeof(tensach));
 in.read(tacgia, sizeof(tacgia));
 in.read((char*)&namXB, sizeof(namXB));
 in.read((char*)&tinhtrang, sizeof(tinhtrang));
}
