#include <iostream>
#include "Library.h"
using namespace std;
void hienThiMenu(){
 cout<<"\n================ QUAN LY THU VIEN ================"<<endl;
 cout<<"1. Nhap them 1 cuon sach"<<endl;
 cout<<"2. Sua thong tin sach (theo ma)"<<endl;
 cout<<"3. Xoa 1 cuon sach (theo ma)"<<endl;
 cout<<"4. Nhap thong tin sinh vien"<<endl;
 cout<<"5. Sua thong tin sinh vien (theo ma)"<<endl;
 cout<<"6. Xoa thong tin sinh vien (theo ma)"<<endl;
 cout<<"7. Muon sach"<<endl;
 cout<<"8. Tra sach"<<endl;
 cout<<"9. Liet ke toan bo sach trong thu vien"<<endl;
 cout<<"10. Liet ke sach duoc muon cua 1 sinh vien cu the"<<endl;
 cout<<"11. Liet ke toan bo sach dang duoc muon"<<endl;
 cout<<"12. Thoat khoi he thong"<<endl;
 cout<<"--------------------------------------------------"<<endl;
 cout<<"Lua chon cua ban: ";
}
int main(){
 Library lib;
 int choice;
 do{
  hienThiMenu();
  cin>>choice;
  switch(choice){
   case 1:
    lib.themSach();
    break;
   case 2:
    lib.suaSach();
    break;
   case 3:
    lib.xoaSach();
    break;
   case 4:
    lib.themSV();
    break;
   case 5:
    lib.suaSV();
    break;
   case 6:
    lib.xoaSV();
    break;
   case 7:
    lib.muonSach();
    break;
   case 8:
    lib.traSach();
    break;
   case 9:
    lib.hienThiSach();
    break;
  case 10:
    lib.thongKeSachCuaSV();
    break;
   case 11:
    lib.thongKeMuon();
    break;
   case 12:
    cout<<"Cam on ban da su dung he thong. Tam biet!"<<endl;
    break;
   default:
    cout<<"Lua chon khong hop le, vui long nhap lai!"<<endl;
  }
 }while(choice!=12);
 return 0;
}
