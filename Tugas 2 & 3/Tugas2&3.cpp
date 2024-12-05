#include <iostream>
using namespace std;

struct matkul
{
    string nama;
    int nilai;
};

void inputData(matkul pelajaran[], int &jumlah_data);
void outputData(matkul pelajaran[], int jumlah_data);
void hitungRataRata(matkul pelajaran[], int jumlah_data);

void inputData(matkul pelajaran[], int &jumlah_data)
{
    cout << "Silahkan Masukkan Jumlah Data Tugas Matkul DDP: ";
    cin >> jumlah_data;

    for (int i = 0; i < jumlah_data; i++)
    {
        cout << "Tugas ke " << i + 1 << endl;
        cout << "Nama Tugas: ";
        cin >> pelajaran[i].nama;
        cout << "Nilai Tugas: ";
        cin >> pelajaran[i].nilai;
        cout << endl;
    }
}

void outputData(matkul pelajaran[], int jumlah_data)
{
    cout << "Data Tugas" << endl;
    for (int i = 0; i < jumlah_data; i++)
    {
        cout << "Data ke-" << i + 1 << endl;
        cout << "Nama Tugas : " << pelajaran[i].nama << endl;
        cout << "Nilai Tugas : " << pelajaran[i].nilai << endl;
        cout << endl;
    }

    hitungRataRata(pelajaran, jumlah_data);
}

void hitungRataRata(matkul pelajaran[], int jumlah_data)
{
    int total = 0;
    for (int i = 0; i < jumlah_data; i++)
    {
        total += pelajaran[i].nilai;
    }
    int rata_rata = total / jumlah_data;
    cout << "Rata-rata Nilai Tugas : " << rata_rata << endl;
    if (rata_rata > 85)
    {
        cout << " Anda mendapatkan A";
    }
    else if (rata_rata > 79)
    {
        cout << "Anda mendapatkan B";
    }
    else if (rata_rata > 70)
    {
        cout << "Anda mendapatkan C";
    }
    else if (rata_rata > 60)
    {
        cout << "Anda mendapatkan D";
    }
    else
    {
        cout << "Anda mendapatkan E";
    }
}

int main()
{
    const int max_data = 100;
    matkul pelajaran[max_data];
    int jumlah_data = 0;
    int pilih;

    do
    {
        cout << "=============================" << endl;
        cout << "Silahkan Pilih " << endl;
        cout << "1. Input Data Tugas DDP" << endl;
        cout << "2. Output Data Tugas DDP" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            inputData(pelajaran, jumlah_data);
            break;
        case 2:
            outputData(pelajaran, jumlah_data);
            break;
        case 3:
            cout << "Selamat tinggal" << endl;
            break;
        default:
            cout << "Menu tidak tersedia" << endl;
        }
        cout << endl;
    } while (pilih != 3);

    return 0;
}
