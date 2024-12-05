#include <iostream>
#include <cstring>

using namespace std;

// Maksimal jumlah buku
const int MAX_BUKU = 100;

// Struktur data untuk Buku
struct Buku
{
    int id;
    char judul[50];
    char penulis[50];
    int harga;
};

// Fungsi untuk menampilkan menu
void tampilkanMenu()
{
    cout << "\n=== Toko Buku ===\n";
    cout << "1. Tambah Buku\n";
    cout << "2. Tampilkan Daftar Buku\n";
    cout << "3. Ubah Data Buku\n";
    cout << "4. Hapus Buku\n";
    cout << "5. Hitung Total Harga Pembelian dengan Diskon\n";
    cout << "6. Keluar\n";
    cout << "Pilih menu: ";
}

// Fungsi untuk menambah buku
void tambahBuku(Buku bukuList[], int &jumlahBuku)
{
    if (jumlahBuku >= MAX_BUKU)
    {
        cout << "Daftar buku penuh!\n";
        return;
    }

    cout << "Masukkan data buku:\n";
    cout << "ID Buku: ";
    cin >> bukuList[jumlahBuku].id;
    cin.ignore(); // Membersihkan newline dari input sebelumnya
    cout << "Judul Buku: ";
    cin.getline(bukuList[jumlahBuku].judul, 50);
    cout << "Nama Penulis: ";
    cin.getline(bukuList[jumlahBuku].penulis, 50);
    cout << "Harga Buku: ";
    cin >> bukuList[jumlahBuku].harga;

    jumlahBuku++;
    cout << "Buku berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan daftar buku
void tampilkanDaftarBuku(const Buku bukuList[], int jumlahBuku)
{
    if (jumlahBuku == 0)
    {
        cout << "Tidak ada buku dalam daftar.\n";
        return;
    }

    cout << "\nDaftar Buku:\n";
    cout << "ID\tJudul\t\tPenulis\t\tHarga\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < jumlahBuku; ++i)
    {
        cout << bukuList[i].id << "\t" << bukuList[i].judul << "\t" << bukuList[i].penulis << "\t" << bukuList[i].harga << "\n";
    }
}

// Fungsi untuk mengubah data buku
void ubahBuku(Buku bukuList[], int jumlahBuku)
{
    int id;
    cout << "Masukkan ID buku yang ingin diubah: ";
    cin >> id;

    for (int i = 0; i < jumlahBuku; ++i)
    {
        if (bukuList[i].id == id)
        {
            cout << "Masukkan data baru:\n";
            cin.ignore();
            cout << "Judul Buku: ";
            cin.getline(bukuList[i].judul, 50);
            cout << "Nama Penulis: ";
            cin.getline(bukuList[i].penulis, 50);
            cout << "Harga Buku: ";
            cin >> bukuList[i].harga;
            cout << "Data buku berhasil diubah!\n";
            return;
        }
    }

    cout << "Buku dengan ID tersebut tidak ditemukan.\n";
}

// Fungsi untuk menghapus buku
void hapusBuku(Buku bukuList[], int &jumlahBuku)
{
    int id;
    cout << "Masukkan ID buku yang ingin dihapus: ";
    cin >> id;

    for (int i = 0; i < jumlahBuku; ++i)
    {
        if (bukuList[i].id == id)
        {
            // Geser semua elemen setelah buku yang dihapus
            for (int j = i; j < jumlahBuku - 1; ++j)
            {
                bukuList[j] = bukuList[j + 1];
            }
            jumlahBuku--;
            cout << "Buku berhasil dihapus.\n";
            return;
        }
    }

    cout << "Buku dengan ID tersebut tidak ditemukan.\n";
}

// Fungsi untuk menghitung total harga pembelian dengan diskon
void hitungTotalHarga(const Buku bukuList[], int jumlahBuku)
{
    if (jumlahBuku == 0)
    {
        cout << "Tidak ada buku dalam daftar.\n";
        return;
    }

    int idDipilih[MAX_BUKU], jumlahDipilih = 0;
    char lanjut;

    do
    {
        cout << "Masukkan ID buku yang ingin dibeli: ";
        cin >> idDipilih[jumlahDipilih++];
        cout << "Tambah buku lain? (y/n): ";
        cin >> lanjut;
    } while ((lanjut == 'y' || lanjut == 'Y') && jumlahDipilih < MAX_BUKU);

    int totalHarga = 0;
    char penulisDipilih[MAX_BUKU][50];
    int jumlahPenulis = 0;

    for (int i = 0; i < jumlahDipilih; ++i)
    {
        bool ditemukan = false;
        for (int j = 0; j < jumlahBuku; ++j)
        {
            if (bukuList[j].id == idDipilih[i])
            {
                totalHarga += bukuList[j].harga;
                strcpy(penulisDipilih[jumlahPenulis++], bukuList[j].penulis);
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan)
        {
            cout << "Buku dengan ID " << idDipilih[i] << " tidak ditemukan.\n";
        }
    }

    // Diskon 5% jika ada minimal 2 buku dari penulis yang sama
    bool diskonPenulis = false;
    for (int i = 0; i < jumlahPenulis; ++i)
    {
        for (int j = i + 1; j < jumlahPenulis; ++j)
        {
            if (strcmp(penulisDipilih[i], penulisDipilih[j]) == 0)
            {
                diskonPenulis = true;
                break;
            }
        }
    }

    if (diskonPenulis)
    {
        totalHarga = totalHarga * 95 / 100;
        cout << "Diskon 5% diterapkan karena membeli minimal 2 buku dari penulis yang sama.\n";
    }

    // Diskon 10% jika kode voucher dimasukkan
    char kodeVoucher[10];
    cout << "Masukkan kode voucher (jika ada): ";
    cin >> kodeVoucher;
    if (strcmp(kodeVoucher, "JPYUM") == 0)
    {
        totalHarga = totalHarga * 90 / 100;
        cout << "Diskon 10% diterapkan dengan kode voucher JPYUM.\n";
    }

    cout << "Total harga setelah diskon: Rp" << totalHarga << "\n";
}

int main()
{
    Buku bukuList[MAX_BUKU];
    int jumlahBuku = 0;
    int pilihan;

    do
    {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahBuku(bukuList, jumlahBuku);
            break;
        case 2:
            tampilkanDaftarBuku(bukuList, jumlahBuku);
            break;
        case 3:
            ubahBuku(bukuList, jumlahBuku);
            break;
        case 4:
            hapusBuku(bukuList, jumlahBuku);
            break;
        case 5:
            hitungTotalHarga(bukuList, jumlahBuku);
            break;
        case 6:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    return 0;
}
