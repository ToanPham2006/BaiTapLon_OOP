#include "Library.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
Library::Library():SoLuongSach(0),SoLuongSV(0),SoLuongMuon(0){
 docFile();
}
int Library::timSachTheoMa(int ma){
 for(int i=0;i<SoLuongSach;i++){
  if(dsSach[i].getma()==ma){
   return i;
  }
 }
 return -1;
}
int Library::timSVTheoMa(int ma){
 for(int i=0;i<SoLuongSV;i++){
  if(dsSV[i].getma()==ma){
   return i;
  }
 }
 return -1;
}
bool Library::sachDangMuon(int maSach){
 for(int i=0;i<SoLuongMuon;i++){
  if(dsMuon[i].getmasach()==maSach){
   return true;
  }
 }
 return false;
}
bool Library::svDangMuon(int maSV){
 for(int i=0;i<SoLuongMuon;i++){
  if(dsMuon[i].getmaSV()==maSV){
   return true;
  }
 }
 return false;
}
void Library::themSach(){
 dsSach[SoLuongSach].nhap();
 SoLuongSach++;
 ghiFile();
}
void Library::suaSach(){
 int ma;
 cout<<"Nhap ma sach can sua: ";
 cin>>ma;
 int viTri=timSachTheoMa(ma);
 if(viTri==-1){
  cout<<"Khong tim thay ma sach nay!"<<endl;
  return;
 }
 cout<<"--- Nhap thong tin moi cho sach (Ma: "<<ma<<") ---"<<endl;
 dsSach[viTri].nhap();
 ghiFile();
 cout<<"Cap nhat thong tin sach thanh cong!"<<endl;
}
void Library::xoaSach(){
 int ma;
 cout<<"Nhap ma sach can xoa: ";
 cin>>ma;
 int vitri=timSachTheoMa(ma);
 if(vitri==-1){
  cout<<"Khong tim thay sach!"<<endl;
  return;
 }
 if(sachDangMuon(ma)){
  cout<<"Loi: Sach dang co sinh vien muon, khong the xoa!"<<endl;
 }
 else{
  for(int i=vitri;i<SoLuongSach-1;i++) dsSach[i]=dsSach[i+1];
  SoLuongSach--;
  ghiFile();
  cout<<"Xoa thanh cong!"<<endl;
 }
}
void Library::hienThiSach(){
 cout<<"  DANH SACH SACH  "<<endl;
 for(int i=0;i<SoLuongSach;i++) dsSach[i].xuat();
}
void Library::themSV(){
 dsSV[SoLuongSV].nhap();
 SoLuongSV++;
 ghiFile();
}
void Library::suaSV(){
 int ma;
 cout<<"Nhap ma sinh vien can sua: ";
 cin>>ma;
 int viTriSV=timSVTheoMa(ma);
 if(viTriSV==-1){
  cout<<"Khong tim thay sinh vien nay!"<<endl;
  return;
 }
cout<<"   Nhap thong tin moi cho sinh vien (Khong sua thong tin muon)   "<<endl;
 dsSV[viTriSV].nhap();
 ghiFile();
 cout<<"Cap nhat thong tin sinh vien thanh cong!"<<endl;
}
void Library::xoaSV(){
 int ma;
 cout<<"Nhap ma SV can xoa: ";
 cin>>ma;
 int vitri=timSVTheoMa(ma);
 if(vitri==-1){
  cout<<"Khong tim thay sinh vien!"<<endl;
  return;
 }
 if(svDangMuon(ma)){
  cout<<"Loi: Sinh vien dang muon sach, khong the xoa!"<<endl;
 }
 else{
  for(int i=vitri;i<SoLuongSV-1;i++) dsSV[i]=dsSV[i+1];
  SoLuongSV--;
  ghiFile();
  cout<<"Xoa thanh cong!"<<endl;
 }
}
void Library::muonSach(){
 int msv,ms,d,m,y;
 cout<<"Nhap ma SV: ";
 cin>>msv;
 cout<<"Nhap ma sach: ";
 cin>>ms;
 int viTriSV=timSVTheoMa(msv);
 int viTriS=timSachTheoMa(ms);
 if(viTriSV==-1||viTriS==-1){
  cout<<"Ma SV hoac Ma Sach khong ton tai!"<<endl;
  return;
 }
 if(dsSach[viTriS].gettinhtrang()==1){
  cout<<"Sach nay da co nguoi muon!"<<endl;
  return;
 }
 cout<<"Ngay muon (d m y): ";
 cin>>d>>m>>y;
 dsMuon[SoLuongMuon]=Borrow(msv,ms,d,m,y);
 SoLuongMuon++;
 dsSach[viTriS].settinhtrang(1);
 ghiFile();
 cout<<"Muon sach thanh cong!"<<endl;
}
void Library::traSach(){
 int ms;
 cout<<"Nhap ma sach tra: ";
 cin>>ms;
 int viTriS=timSachTheoMa(ms);
 if(viTriS==-1||dsSach[viTriS].gettinhtrang()==0){
  cout<<"Sach khong o trang thai dang muon!"<<endl;
  return;
 }
 for(int i=0;i<SoLuongMuon;i++){
  if(dsMuon[i].getmasach()==ms){
   for(int j=i;j<SoLuongMuon-1;j++) dsMuon[j]=dsMuon[j+1];
   SoLuongMuon--;
   break;
  }
 }
 dsSach[viTriS].settinhtrang(0);
 ghiFile();
 cout<<"Tra sach thanh cong!"<<endl;
}
void Library::thongKeSachCuaSV(){
 int ma;
 cout<<"Nhap ma sinh vien can kiem tra: ";
 cin>>ma;
 int viTriSV=timSVTheoMa(ma);
 if(viTriSV==-1){
  cout<<"Sinh vien khong ton tai!"<<endl;
  return;
 }
 cout<<"\n--- Danh sach sach sinh vien ["<<dsSV[viTriSV].getten()<<"] dang muon ---\n";
 bool coMuon=false;
 for(int i=0;i<SoLuongMuon;i++){
  if(dsMuon[i].getmaSV()==ma){
   int viTriS=timSachTheoMa(dsMuon[i].getmasach());
   if(viTriS!=-1){
    dsSach[viTriS].xuat();
    coMuon=true;
   }
  }
 }
 if(!coMuon){
  cout<<"Sinh vien nay hien khong muon cuon sach nao."<<endl;
 }
}
void Library::thongKeMuon(){
 cout<<"  THONG KE MUON SACH  "<<endl;
 for(int i=0;i<SoLuongMuon;i++){
  int viTriSV=timSVTheoMa(dsMuon[i].getmaSV());
  int viTriS=timSachTheoMa(dsMuon[i].getmasach());
  cout<<"SV: ";
  if(viTriSV>=0){
   cout<<dsSV[viTriSV].getten();
  }
  else{
   cout<<"Khong tim thay sinh vien";
  }
  cout<<" | Sach: ";
  if(viTriS>=0){
   cout<<dsSach[viTriS].getten();
  }
  else{
   cout<<"Khong tim thay sach";
  }
  cout<<" | ";
  dsMuon[i].xuat();
 }
}
void Library::ghiFile(){
 ofstream fS("sach.dat",ios::binary);
 fS.write((char*)&SoLuongSach,sizeof(int));
 for(int i=0;i<SoLuongSach;i++) dsSach[i].WriteBinary(fS);
 fS.close();
 ofstream fSV("sv.dat",ios::binary);
 fSV.write((char*)&SoLuongSV,sizeof(int));
 for(int i=0;i<SoLuongSV;i++) dsSV[i].WriteBinary(fSV);
 fSV.close();
 ofstream fM("muon.dat",ios::binary);
 fM.write((char*)&SoLuongMuon,sizeof(int));
 for(int i=0;i<SoLuongMuon;i++) dsMuon[i].WriteBinary(fM);
 fM.close();
}
void Library::docFile(){
 ifstream fS("sach.dat",ios::binary);
 if(fS){
  fS.read((char*)&SoLuongSach,sizeof(int));
  for(int i=0;i<SoLuongSach;i++) dsSach[i].ReadBinary(fS);
  fS.close();
 }
 ifstream fSV("sv.dat",ios::binary);
 if(fSV){
  fSV.read((char*)&SoLuongSV,sizeof(int));
  for(int i=0;i<SoLuongSV;i++) dsSV[i].ReadBinary(fSV);
  fSV.close();
 }
 ifstream fM("muon.dat",ios::binary);
 if(fM){
  fM.read((char*)&SoLuongMuon,sizeof(int));
  for(int i=0;i<SoLuongMuon;i++) dsMuon[i].ReadBinary(fM);
  fM.close();
 }
}
