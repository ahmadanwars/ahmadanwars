///===========GETDATA()=======================
void patient::getdata()
{
PersonInfo();
cout<<"\nMasukkan Nomor Pendaftaran Pasien: ";
cin>>NoPendaftaran;
cout<<"\nMasukkan Pekerjaan Pasien: ";
cin>>Pekerjaan;
cout<<"\nMasukkan Pembayaran Pasien:";
cin>>Pembayaran;
cout<<"\nMasukkan Tanggal Masuk(dd/mm/yyyy):";
cin>>TanggalMasuk;
cout<<"\nMasukkan Tanggal Keluar(dd/mm/yyyy):";
cin>>TanggalKeluar;
patient_bayar();
strncpy(medicine, "null", sizeof(medicine) - 1);
    medicine[sizeof(medicine) - 1] = 0;
}

void patient::showdata()
{
cout<<"\nNo Pendaftaran Pasien: "<<NoPendaftaran<<"\n";
Display_info();
cout<<"\nPekerjaan : "<<Pekerjaan;
cout<<"\nTanggal Masuk : "<<TanggalMasuk;
cout<<"\nTanggal Keluar :"<<TanggalKeluar;
cout<<"\nPembayaran :"<<total;
cout<<"\nResep Obat: "<<medicine;

}
