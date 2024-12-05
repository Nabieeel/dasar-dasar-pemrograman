#include <iostream>
using namespace std;
int main()
{
    int angka_tebak, menu;
    int angka_benar = 7;
    string nama, nim;
    cout << "Selamat Datang, Silahkan Login\n";
    cout << "Masukkan Nama : ";
    cin >> nama;
    cout << "Masukkan NIM : ";
    cin >> nim;

    if (nama == "nabiel" and nim == "157")
    {
        cout << "login berhasil, silahkan pilih permainan\n";
        cout << "1. permainan tebak angka\n";
        cout << "2. Input Nilai\n";
        cout << "3. Keluar \n";
        cout << "menu: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Selamat datang di permainan tebak angka\n";
            cout << "Tebak angka dari 1-10\n";
            do
            {
                cout << "Masukkan Angka: ";
                cin >> angka_tebak;
                if (angka_tebak > angka_benar)
                {
                    cout << "Angka Terlalu Besar\n";
                }
                else if (angka_tebak < angka_benar)
                {
                    cout << "Angka Terlalu Kecil\n";
                }
                else
                {
                    cout << "Selamat Tebakan Kamu Benar, Angkanya Adalah " << angka_benar;
                    break;
                }
            } while (angka_tebak != angka_benar);
            break;
        case 2:
            int jml_data;
            int nilai_pel[jml_data] = {};

            cout << "Silahkan  masukkan jumlah data nilai pelajaran : ";
            cin >> jml_data;

            for (int i = 0; i < jml_data; i++)
            {
                cout << "Nilai ke " << i + 1 << endl;
                cout << "Nilai Pelajaran :";
                cin >> nilai_pel[i];
                cout << endl;
            }
            break;

            break;
        }
    }
    else
    {
        cout << "Login Gagal, Silahkan Coba Lagi";
    }
    return 0;
}