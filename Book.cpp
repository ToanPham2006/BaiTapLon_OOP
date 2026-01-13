#include "Book.h"
void Book::nhap(){
 cin>>masach;
 cin.ignore();
 cin.getline(tensach,50);
 cin.getline(tacgia,50);
 cin>>namXB;
 }
void Book::xuat(){
 cout<<masach<<" | "<<tensach<<" | "<<tacgia<<" | "<<namXB<<endl;
}
int Book::getma(){
 return masach;
 }

