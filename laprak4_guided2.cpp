#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;
Node *baru = nullptr;
Node *bantu = nullptr;
Node *hapus = nullptr;

// Inisialisasi
void init()
{
    head = nullptr;
    tail = nullptr;
}

// Pengecekan apakah list kosong
bool isEmpty()
{
    return head == nullptr;
}

// Membuat node baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = nullptr;
}

// Menghitung jumlah node dalam list
int hitungList()
{
    int jumlah = 0;
    bantu = head;
    while (bantu != nullptr)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Menambah node di depan list
void insertDepan(string data)
{
    buatNode(data);
    if (isEmpty())
    {
        head = baru;
        tail = baru;
        baru->next = head;
    }
    else
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Menambah node di belakang list
void insertBelakang(string data)
{
    buatNode(data);
    if (isEmpty())
    {
        head = baru;
        tail = baru;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        baru->next = head;
        tail = baru;
    }
}

// Menambah node di tengah list pada posisi tertentu
void insertTengah(string data, int posisi)
{
    if (isEmpty() || posisi == 1)
    {
        insertDepan(data);
    }
    else if (posisi > hitungList())
    {
        insertBelakang(data);
    }
    else
    {
        baru = new Node;
        baru->data = data;
        bantu = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Menghapus node di depan list
void hapusDepan()
{
    if (!isEmpty())
    {
        hapus = head;
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Menghapus node di belakang list
void hapusBelakang()
{
    if (!isEmpty())
    {
        hapus = head;
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            bantu = nullptr;
            while (hapus->next != head)
            {
                bantu = hapus;
                hapus = hapus->next;
            }
            bantu->next = head;
            tail = bantu;
        }
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Menghapus node di tengah list pada posisi tertentu
void hapusTengah(int posisi)
{
    if (!isEmpty())
    {
        if (posisi == 1)
        {
            hapusDepan();
        }
        else if (posisi == hitungList())
        {
            hapusBelakang();
        }
        else
        {
            bantu = head;
            for (int i = 1; i < posisi - 1; i++)
            {
                bantu = bantu->next;
            }
            hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Menghapus seluruh node dalam list
void clearList()
{
    while (!isEmpty())
    {
        hapusDepan();
    }
    cout << "List berhasil terhapus!" << endl;
}

// Menampilkan isi list
void tampil()
{
    if (!isEmpty())
    {
        bantu = head;
        do
        {
            cout << bantu->data << " ";
            bantu = bantu->next;
        } while (bantu != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();

    insertDepan("Bebek");
    tampil();

    insertBelakang("Cicak");
    tampil();

    insertBelakang("Domba");
    tampil();

    hapusBelakang();
    tampil();

    hapusDepan();
    tampil();

    insertTengah("Sapi", 2);
    tampil();

    hapusTengah(2);
    tampil();

    return 0;
}