#include <stdio.h>
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <string.h>
#include <time.h>

using namespace std;
///CLASS  PERSON=========

class Person
{
    char Nama[50],Jenkel[10];
    int Umur,Tanggal,Bulan,Tahun;
    long int NoTelp;
    int ZipCode,PersonID;
    char Kota[50],Provinsi[50],Negara[50],GolDarah[5];
public:
    void PersonInfo()
    {
        cout<<"Enter Nama :";
        cin.clear();
        cin.ignore();
        cin.getline(Nama,50);
        cout<<"Enter Jenis Kelamin :";
        cin>>Jenkel;
        cout<<"Enter Umur :";
        cin>>Umur;
        cout<<"Enter Alamat :";
        cin>>Negara;
        cout<<"Enter Golongan Darah:";
        cin>>GolDarah;
    }

    void Display_info()
    {
        cout<<"Nama: "<<Nama<<endl;
        cout<<"Jenis Kelamin: "<<Jenkel<<endl;
        cout<<"Umur: "<<Umur<<endl;
        cout<<"Alamat: "<<this->Negara<<endl;
        cout<<"Golongan Darah:"<<GolDarah<<endl;
    }
};

