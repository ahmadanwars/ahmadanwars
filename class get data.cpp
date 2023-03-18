void patient::getdata()
{
PersonInfo();
cout<<"\nEnter The registration number of the patient: ";
cin>>NoPendaftaran;
cout<<"\nEnter The occupation of the patient: ";
cin>>Pekerjaan;
cout<<"\nEnter The bill of the patient:";
cin>>Pembayaran;
cout<<"\nEnter The date admitted(dd/mm/yyyy):";
cin>>TanggalMasuk;
cout<<"\nEnter The date discharged(dd/mm/yyyy):";
cin>>TanggalKeluar;
patient_bill();
strncpy(medicine, "null", sizeof(medicine) - 1);
    medicine[sizeof(medicine) - 1] = 0;
}

void patient::showdata()
{
cout<<"\nRegistration number of patient: "<<reg_no<<"\n";
Display_info();
cout<<"\nOccupation : "<<occupation;
cout<<"\nAdmit date : "<<date_admit;
cout<<"\nDischarhge date :"<<date_discharge;
cout<<"\nBill :"<<total;
cout<<"\nPrescribed Medicine: "<<medicine;

}

int  patient::retidno()
{
return reg_no;
}

void patient::modify_medicine(int n)
{
bool found=false;
patient p;
fstream File;
File.open("patient.dat",ios::binary|ios::in|ios::out);
if(!File)
{
cout<<"File could not be open !! Press any Key...";
cin.ignore();
cin.get();
return;
}
    while(!File.eof() && found==false)
{

File.read(reinterpret_cast<char *> (&p), sizeof(patient));
if(p.retidno()==n)
{
p.showdata();
cout<<"\n\nPlease Enter The Medicine of patient"<<endl;
                cin>>p.medicine;
    int pos=(-1)*static_cast<int>(sizeof(p));
    File.seekp(pos,ios::cur);
    File.write(reinterpret_cast<char *> (&p), sizeof(patient));
    cout<<"\n\n\t Record Updated";
    found=true;
}
}
File.close();
if(found==false)
cout<<"\n\n Record Not Found ";
cin.ignore();
cin.get();
}


void patient::write_patient()  // writing into file
{
patient p;
ofstream outFile;
outFile.open("patient.dat",ios::binary|ios::app);
p.getdata();
outFile.write(reinterpret_cast<char *> (&p), sizeof(patient));
outFile.close();
    cout<<"\n\nPatient record Has Been Created ";
cin.ignore();
cin.get();
}

void patient::display_all()  //reading from file
{
patient p;
ifstream inFile;
inFile.open("patient.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
cin.ignore();
cin.get();
return;
}
cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
while(inFile.read(reinterpret_cast<char *> (&p), sizeof(patient)))
{
p.showdata();
cout<<"\n\n=======================================================================================\n";
}
inFile.close();
cin.ignore();
cin.get();
}

void patient::display_p(int n) //reading specific file
{
patient p;
ifstream inFile;
inFile.open("patient.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
cin.ignore();
cin.get();
return;
}
bool flag=false;
while(inFile.read(reinterpret_cast<char *> (&p), sizeof(patient)))
{
if(p.retidno()==n)
{
  p.showdata();
flag=true;
}
}
inFile.close();
if(flag==false)
cout<<"\n\nrecord not exist";
cin.ignore();
cin.get();
}


void patient:: modify_patient(int n)   //modifying patient details
{
bool found=false;
patient p;
fstream File;
File.open("patient.dat",ios::binary|ios::in|ios::out);
if(!File)
{
cout<<"File could not be open !! Press any Key...";
cin.ignore();
cin.get();
return;
}
    while(!File.eof() && found==false)
{

File.read(reinterpret_cast<char *> (&p), sizeof(patient));
if(p.retidno()==n)
{
p.showdata();
cout<<"\n\nPlease Enter The New Details of patient"<<endl;
                p.getdata();
    int pos=(-1)*static_cast<int>(sizeof(p));
    File.seekp(pos,ios::cur);
    File.write(reinterpret_cast<char *> (&p), sizeof(patient));
    cout<<"\n\n\t Record Updated";
    found=true;
}
}
File.close();
if(found==false)
cout<<"\n\n Record Not Found ";
cin.ignore();
cin.get();
}


void patient:: delete_patient(int n)  //deleting a particular file
{
patient p;
ifstream inFile;
inFile.open("patient.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
cin.ignore();
cin.get();
return;
}
ofstream outFile;
outFile.open("Temp.dat",ios::out);
inFile.seekg(0,ios::beg);
while(inFile.read(reinterpret_cast<char *> (&p), sizeof(patient)))
{
if(p.retidno()!=n)
{
outFile.write(reinterpret_cast<char *> (&p), sizeof(patient));
}
}
outFile.close();
inFile.close();
remove("patient.dat");
rename("Temp.dat","patient.dat");
cout<<"\n\n\tRecord Deleted ..";
cin.ignore();
cin.get();
}
