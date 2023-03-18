class patient: public Person
{
int  NoPendaftaran;
char Pekerjaan[30];
char TanggalMasuk[30];
char TanggalKeluar[30];
int Pembayaran,total;

public:
    char medicine[100];
void patient_bayar();
void getdata(); 
void showdata(); 
int retidno();
void modify_medicine(int n);
    void write_patient(); 
    void display_all(); 
    void display_p(int n); 
    void modify_patient(int n); 
    void delete_patient(int n); 
};


void patient::patient_bayar()
{
    system("CLS");
cout << "********************************************************************************";
cout << "\n\n\t\t\t\tBiaya Pasien\n\n ";
cout << "*******************************************************************************";
cout << "\nBiaya Perawatan Rumah Sakit                    :\t  50";
cout << "\nBiaya Operasional Rumah Sakit               :\t  50";
cout << "\nBiaya Perorangan Pasien               :\t " << Pembayaran;
total = 50 + 50 + Pembayaran;
cout << "\nTotal Biaya                          :\t"  << total<<"\n";
cout << "********************************************************************************";
}
