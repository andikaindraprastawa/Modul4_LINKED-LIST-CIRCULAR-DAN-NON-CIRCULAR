#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string nama;
    string nim;
    Node *next;
};

// Pointer Global
Node *head = nullptr;

// Fungsi-fungsi
bool isEmpty()
{
    return head == nullptr;
}

void tambahDepan()
{
    string nama, nim;
    cout << "========[TAMBAH DEPAN]=======" << endl;
    cout << "Masukkan Nama  : ";
    cin >> nama;
    cout << "Masukkan NIM   : ";
    cin >> nim;

    Node *baru_2311102033 = new Node;
    baru_2311102033->nama = nama;
    baru_2311102033->nim = nim;
    baru_2311102033->next = head;
    head = baru_2311102033;

    cout << "Data telah ditambahkan" << endl;
}

void tambahBelakang()
{
    cout << "========[TAMBAH BELAKANG]=======" << endl;
    string nama, nim;
    cout << "Masukkan Nama  : ";
    cin >> nama;
    cout << "Masukkan NIM   : ";
    cin >> nim;

    Node *baru_2311102033 = new Node;
    baru_2311102033->nama = nama;
    baru_2311102033->nim = nim;
    baru_2311102033->next = nullptr;

    if (isEmpty())
    {
        head = baru_2311102033;
    }
    else
    {
        Node *tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = baru_2311102033;
    }

    cout << "Data telah ditambahkan" << endl;
}

void tambahTengah()
{
    cout << "========[TAMBAH TENGAH]=======" << endl;
    string nama, nim;
    int posisi;
    cout << "Masukkan Nama    : ";
    cin >> nama;
    cout << "Masukkan NIM     : ";
    cin >> nim;
    cout << "Masukkan Posisi  : ";
    cin >> posisi;

    if (posisi < 1)
    {
        cout << "Posisi harus lebih dari 0." << endl;
        return;
    }

    if (posisi == 1)
    {
        tambahDepan();
        return;
    }

    Node *current = head;
    for (int i = 1; i < posisi - 1; ++i)
    {
        if (!current)
        {
            cout << "Posisi melebihi panjang linked list." << endl;
            return;
        }
        current = current->next;
    }

    if (!current)
    {
        cout << "Posisi melebihi panjang linked list." << endl;
        return;
    }

    Node *baru_2311102033 = new Node;
    baru_2311102033->nama = nama;
    baru_2311102033->nim = nim;
    baru_2311102033->next = current->next;
    current->next = baru_2311102033;

    cout << "Data telah ditambahkan" << endl;
}

void ubahDepan()
{
    cout << "========[UBAH DEPAN]=======" << endl;
    if (isEmpty())
    {
        cout << "List masih kosong." << endl;
        return;
    }
    string prev_nama = head->nama;

    string nama, nim;
    cout << "Masukkan Nama Baru : ";
    cin >> nama;
    cout << "Masukkan NIM Baru  : ";
    cin >> nim;

    head->nama = nama;
    head->nim = nim;

    cout << "Data " << prev_nama << " telah diganti dengan data " << nama << endl;
}

void ubahBelakang()
{
    cout << "========[UBAH BELAKANG]=======" << endl;
    if (isEmpty())
    {
        cout << "List masih kosong." << endl;
        return;
    }

    Node *current = head;
    while (current->next)
    {
        current = current->next;
    }

    string nama, nim;
    cout << "Masukkan Nama Baru : ";
    cin >> nama;
    cout << "Masukkan NIM Baru  : ";
    cin >> nim;

    string namaSebelum = current->nama;
    current->nama = nama;

    cout << "Data " << namaSebelum << " telah diganti dengan data " << nama << endl;
}

void ubahTengah()
{
    cout << "========[UBAH TENGAH]=======" << endl;
    if (isEmpty())
    {
        cout << "List masih kosong." << endl;
        return;
    }

    int posisi;
    cout << "Masukkan Posisi Data yang akan Diubah: ";
    cin >> posisi;

    Node *current = head;
    for (int i = 1; i < posisi; ++i)
    {
        if (!current)
        {
            cout << "Posisi melebihi panjang linked list." << endl;
            return;
        }
        current = current->next;
    }

    if (!current)
    {
        cout << "Posisi melebihi panjang linked list." << endl;
        return;
    }

    string prev_nama = current->nama;
    string prev_nim = current->nim;

    string nama, nim;
    cout << "Masukkan Nama Baru : ";
    cin >> nama;
    cout << "Masukkan NIM Baru  : ";
    cin >> nim;

    current->nama = nama;
    current->nim = nim;

    cout << "Data " << prev_nama << " telah diganti dengan data " << nama << endl;
}

void hapusDepan()
{
    cout << "========[HAPUS DEPAN=======" << endl;
    if (isEmpty())
    {
        cout << "List masih kosong." << endl;
        return;
    }
    string namaHapus = head->nama;
    Node *hapus = head;
    head = head->next;
    delete hapus;

    cout << "Data " << namaHapus << " berhasil dihapus" << endl;
}

void hapusBelakang()
{
    cout << "========[HAPUS BELAKANG]=======" << endl;
    if (isEmpty())
    {
        cout << "List masih kosong." << endl;
        return;
    }

    Node *current = head;
    Node *previous = nullptr;

    while (current->next)
    {
        previous = current;
        current = current->next;
    }

    if (previous)
    {
        previous->next = nullptr;
    }
    else
    {
        head = nullptr;
    }

    cout << "Data " << current->nama << " berhasil dihapus" << endl;

    delete current;
}

void hapusTengah()
{
    cout << "========[HAPUS TENGAH]=======" << endl;
    if (isEmpty())
    {
        cout << "List masih kosong." << endl;
        return;
    }

    int posisi;
    cout << "Masukkan Posisi Data yang akan Dihapus: ";
    cin >> posisi;

    if (posisi < 1)
    {
        cout << "Posisi harus lebih dari 0." << endl;
        return;
    }

    if (posisi == 1)
    {
        hapusDepan();
        return;
    }

    Node *current = head;
    Node *previous = nullptr;
    int count = 1;
    while (current != nullptr && count < posisi)
    {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == nullptr)
    {
        cout << "Posisi melebihi panjang linked list." << endl;
        return;
    }

    previous->next = current->next;

    cout << "Data " << current->nama << " berhasil dihapus" << endl;

    delete current;
}

void hapusList()
{
    cout << "========[HAPUS LIST]=======" << endl;
    while (!isEmpty())
    {
        hapusDepan();
    }
    cout << "List berhasil dihapus" << endl;
}

void tampilkanData()
{
    cout << "========[TAMPILKAN DATA]=======" << endl;
    if (isEmpty())
    {
        cout << "List masih kosong." << endl;
        return;
    }

    cout << "==================================================================" << endl;
    cout << "| No |      NAMA      |     NIM     |" << endl;
    cout << "==================================================================" << endl;

    Node *current = head;
    int no = 1;
    while (current)
    {
        cout << "| " << setw(3) << no << " | " << setw(15) << current->nama << " | " << setw(11) << current->nim << " |" << endl;
        current = current->next;
        no++;
    }
    cout << "==================================================================" << endl;
}

int main()
{
    int pilihan;
    do
    {
        cout << "===========| SELAMAT DATANG DI PROGRAM SINGLE LINKED LIST |==========" << endl;
        cout << "=====================================================================" << endl;
        cout << "|                             MENU                                  |" << endl;
        cout << "=====================================================================" << endl;
        cout << "| [1]   Tambah Depan                                                |" << endl;
        cout << "| [2]   Tambah Belakang                                             |" << endl;
        cout << "| [3]   Tambah Tengah                                               |" << endl;
        cout << "| [4]   Ubah Depan                                                  |" << endl;
        cout << "| [5]   Ubah Belakang                                               |" << endl;
        cout << "| [6]   Ubah Tengah                                                 |" << endl;
        cout << "| [7]   Hapus Depan                                                 |" << endl;
        cout << "| [8]   Hapus Belakang                                              |" << endl;
        cout << "| [9]   Hapus Tengah                                                |" << endl;
        cout << "| [10]  Hapus List                                                  |" << endl;
        cout << "| [11]  Tampilkan                                                   |" << endl;
        cout << "| [12]  Keluar                                                      |" << endl;
        cout << "=====================================================================" << endl;
        cout << "\nMasukkan Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahDepan();
            break;
        case 2:
            tambahBelakang();
            break;
        case 3:
            tambahTengah();
            break;
        case 4:
            ubahDepan();
            break;
        case 5:
            ubahBelakang();
            break;
        case 6:
            ubahTengah();
            break;
        case 7:
            hapusDepan();
            break;
        case 8:
            hapusBelakang();
            break;
        case 9:
            hapusTengah();
            break;
        case 10:
            hapusList();
            break;
        case 11:
            tampilkanData();
            break;
        case 12:
            cout << "Terima kasih telah menggunakan Program Single Linked List Non-Circular!" << endl;
            cout << "Semoga harimu menyenangkan dan sukses selalu! " << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (pilihan != 12);

    return 0;
}