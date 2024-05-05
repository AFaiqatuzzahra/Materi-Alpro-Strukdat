## Soal
1.	Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular) (40 Poin)
2.	Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list! (35 Poin)
3.	Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! (50 Poin)

## Jawaban
```c++
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void tambah(Node*& head, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void hapusDuplikasi(Node* head) {
    if (!head) return;

    unordered_set<int> hashSet;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr) {
        if (hashSet.find(curr->data) != hashSet.end()) {
            prev->next = curr->next;
            delete curr;
        } else {
            hashSet.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

void cetak(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void hapusSemua(Node*& head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    int n;
    cout << "Masukkan jumlah angka: ";
    cin >> n;

    cout << "Masukkan angka-angka: ";
    for (int i = 0; i < n; ++i) {
        int nilai;
        cin >> nilai;
        tambah(head, nilai);
    }

    cout << "Linked list sebelum penghapusan duplikasi: ";
    cetak(head);

    hapusDuplikasi(head);

    cout << "Linked list setelah penghapusan duplikasi: ";
    cetak(head);

    hapusSemua(head);

    return 0;
}
```

2. Algoritma:
    1. Tentukan node sebelum node yang ingin dihapus.
    2. Ubah pointer node sebelumnya sehingga menunjuk ke node setelah node yang akan dihapus.
    3. Hapus node yang diinginkan.
    4. Bebaskan memori yang digunakan oleh node yang dihapus.
- Program:
```c++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void tambah(Node*& head, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void hapusTengah(Node*& head, int posisi) {
    if (!head) return;

    Node* prev = nullptr;
    Node* curr = head;
    int counter = 1;

    while (curr && counter < posisi) {
        prev = curr;
        curr = curr->next;
        counter++;
    }

    if (!curr) {
        cout << "Posisi di luar jangkauan" << endl;
        return;
    }

    if (prev) {
        prev->next = curr->next;
        delete curr;
    } else { 
        head = curr->next;
        delete curr;
    }
}


void cetak(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void hapusSemua(Node*& head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    tambah(head, 10);
    tambah(head, 20);
    tambah(head, 30);
    tambah(head, 40);
    tambah(head, 50);

    cout << "Linked list sebelum penghapusan: ";
    cetak(head);

    hapusTengah(head, 3);

    cout << "Linked list setelah penghapusan: ";
    cetak(head);

    hapusSemua(head);

    return 0;
}
```

3. 
```c++
#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void tambah(Node*& head, char karakter) {
    Node* newNode = new Node;
    newNode->data = karakter;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void cetak(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool apakahPalindrom(Node* head) {
    if (!head || !head->next) return true; // Jika linked list kosong atau hanya memiliki satu node, itu adalah sebuah palindrom

    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    stack<char> s;
    while (slow->next) {
        s.push(slow->next->data);
        slow = slow->next;
    }

        while (!s.empty()) {
        if (head->data != s.top()) {
            return false;
        }
        head = head->next;
        s.pop();
    }
    return true;
}

void hapusSemua(Node*& head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    cout << "Masukkan elemen-elemen linked list (tekan enter setelah setiap elemen, akhiri dengan 'stop' jika sudah selesai):" << endl;
    string input;
    while (true) {
        cin >> input;
        if (input == "stop") break;
        char karakter = input[0];
        tambah(head, karakter);
    }

    cout << "Linked list: ";
    cetak(head);

    if (apakahPalindrom(head)) {
        cout << "Linked list adalah sebuah palindrom." << endl;
    } else {
        cout << "Linked list bukanlah sebuah palindrom." << endl;
    }

    hapusSemua(head);

    return 0;
}
```