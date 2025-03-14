#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL, *tail = NULL;
void buatNodeBaru(int nilai) {
    Node *n = new Node;
    n->data = nilai;
    n->prev = NULL;
    n->next = NULL;
    head = n;
    tail = n;
    cout << "Nilai " << nilai << " berhasil dimasukkan di node awal.\n";
}
void tambahDiDepan(int nilai) {
    Node *n = new Node;
    n->data = nilai;
    n->next = head;
    n->prev = NULL;
    head->prev = n;
    head = n;
    cout << "Node dengan nilai " << nilai << " berhasil ditambahkan pada posisi depan.\n";
}
void tambahDiBelakang(int nilai) {
    Node *n = new Node;
    n->data = nilai;
    n->prev = tail;
    n->next = NULL;
    tail->next = n;
    tail = n;
    cout << "Node dengan nilai " << nilai << " berhasil ditambahkan pada posisi belakang.\n";
}
void tambahDiTengah(int nilai, int posisi) {
    Node *x = head;
    while (x != NULL && x->data != posisi) {
        x = x->next;
    }
    if (x == NULL) {
        cout << "Node dengan nilai " << posisi << " tidak ditemukan.\n";
        return;
    }
    Node *n = new Node;
    n->data = nilai;
    n->next = x->next;
    if (x->next != NULL) x->next->prev = n;
    x->next = n;
    n->prev = x;
    cout << "Node dengan nilai " << nilai << " berhasil ditambahkan setelah node dengan nilai " << posisi << ".\n";
}
void hapusDiDepan() {
    if (head == NULL) {
        cout << "Linked List kosong, tidak ada yang dihapus.\n";
        return;
    }
    Node *x = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete x;
    cout << "Node di posisi depan berhasil dihapus.\n";
}
void hapusDiBelakang() {
    if (tail == NULL) {
        cout << "Linked List kosong, tidak ada yang dihapus.\n";
        return;
    }
    Node *x = tail;
    tail = tail->prev;
    if (tail != NULL) tail->next = NULL;
    delete x;
    cout << "Node di posisi belakang berhasil dihapus.\n";
}
void hapusDiTengah(int nilai) {
    Node *x = head;
    while (x != NULL && x->data != nilai) {
        x = x->next;
    }
    if (x == NULL) {
        cout << "Node dengan nilai " << nilai << " tidak ditemukan.\n";
        return;
    }
    if (x->prev != NULL) x->prev->next = x->next;
    if (x->next != NULL) x->next->prev = x->prev;
    if (x == head) head = x->next;
    if (x == tail) tail = x->prev;
    delete x;
    cout << "Node dengan nilai " << nilai << " berhasil dihapus.\n";
}
void tampilDariDepan() {
    if (head == NULL) {
        cout << "Linked List kosong.\n";
        return;
    }
    Node *x = head;
    cout << "Isi Linked List dari depan: ";
    while (x != NULL) {
        cout << x->data << " ";
        x = x->next;
    }
    cout << endl;
}
void tampilDariBelakang() {
    if (tail == NULL) {
        cout << "Linked List kosong.\n";
        return;
    }
    Node *x = tail;
    cout << "Isi Linked List dari belakang: ";
    while (x != NULL) {
        cout << x->data << " ";
        x = x->prev;
    }
    cout << endl;
}
int main() {
    int pilihan, nilai, posisi;
    do {
        cout << "Menu:\n";
        cout << "1. Buat Node Awal\n";
        cout << "2. Tambah Node\n";
        cout << "3. Hapus Node\n";
        cout << "4. Tampil Data\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan [1..5]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                buatNodeBaru(nilai);
                break;
            case 2:
                cout << "Pilihan:\n";
                cout << "1. Tambah Node di Depan\n";
                cout << "2. Tambah Node di Belakang\n";
                cout << "3. Tambah Node di Tengah\n";
                cout << "4. Batal\n";
                cout << "Masukkan pilihan [1..4]: ";
                cin >> pilihan;
                if (pilihan == 1) {
                    cout << "Masukkan nilai: ";
                    cin >> nilai;
                    tambahDiDepan(nilai);
                } else if (pilihan == 2) {
                    cout << "Masukkan nilai: ";
                    cin >> nilai;
                    tambahDiBelakang(nilai);
                } else if (pilihan == 3) {
                    cout << "Masukkan nilai: ";
                    cin >> nilai;
                    cout << "Masukkan nilai node setelahnya: ";
                    cin >> posisi;
                    tambahDiTengah(nilai, posisi);
                }
                break;
            case 3:
                cout << "Pilihan:\n";
                cout << "1. Hapus Node di Depan\n";
                cout << "2. Hapus Node di Belakang\n";
                cout << "3. Hapus Node di Tengah\n";
                cout << "4. Batal\n";
                cout << "Masukkan pilihan [1..4]: ";
                cin >> pilihan;
                if (pilihan == 1) {
                    hapusDiDepan();
                } else if (pilihan == 2) {
                    hapusDiBelakang();
                } else if (pilihan == 3) {
                    cout << "Masukkan nilai node yang ingin dihapus: ";
                    cin >> nilai;
                    hapusDiTengah(nilai);
                }
                break;
            case 4:
                cout << "Pilihan:\n";
                cout << "1. Tampil dari depan\n";
                cout << "2. Tampil dari belakang\n";
                cout << "3. Batal\n";
                cout << "Masukkan pilihan [1..3]: ";
                cin >> pilihan;
                if (pilihan == 1) {
                    tampilDariDepan();
                } else if (pilihan == 2) {
                    tampilDariBelakang();
                }
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}

