# <h1 align="center">Tugas 3 Teori Algorithma dan Struktur Data</h1>
<p align="center">Afifah Faiqatuzzahra</p>

## Priority Queue
Priority Queue (Antrian Prioritas) adalah tipe struktur data yang serupa dengan antrian biasa, namun dengan tambahan konsep prioritas. Elemen-elemen dalam priority queue memiliki prioritas tertentu dan elemen dengan prioritas tertinggi akan diakses lebih dulu. Priority queue dapat diimplementasikan menggunakan berbagai struktur data seperti heap, binary search tree, atau linked list. Implementasi yang paling umum adalah menggunakan heap, khususnya binary heap, karena efisiensinya.[1]

```c++
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Max Heap (Elemen terbesar memiliki prioritas tertinggi)
    priority_queue<int> maxHeap;
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);
    maxHeap.push(1);
    maxHeap.push(5);
    maxHeap.push(9);

    cout << "Max Heap: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    // Min Heap (Elemen terkecil memiliki prioritas tertinggi)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(1);
    minHeap.push(5);
    minHeap.push(9);

    cout << "Min Heap: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
```
### Penjelasan Alur Program

1. **Import Header Files**:
   ```cpp
   #include <iostream>
   #include <queue>
   #include <vector>
   ```
   Program dimulai dengan mengimpor header files yang diperlukan. `iostream` digunakan untuk input-output operasi, `queue` untuk penggunaan priority queue, dan `vector` untuk mendefinisikan min heap.

2. **Deklarasi dan Inisialisasi Max Heap**:
   ```cpp
   priority_queue<int> maxHeap;
   maxHeap.push(3);
   maxHeap.push(1);
   maxHeap.push(4);
   maxHeap.push(1);
   maxHeap.push(5);
   maxHeap.push(9);
   ```
   - `priority_queue<int>` mendeklarasikan max heap dengan tipe data `int`.
   - Elemen-elemen dimasukkan ke dalam max heap menggunakan `push()`.
   - Secara default, `priority_queue` di C++ adalah max heap, di mana elemen terbesar memiliki prioritas tertinggi.

3. **Output Max Heap**:
   ```cpp
   cout << "Max Heap: ";
   while (!maxHeap.empty()) {
       cout << maxHeap.top() << " ";
       maxHeap.pop();
   }
   cout << endl;
   ```
   - `maxHeap.top()` mengembalikan elemen terbesar dari max heap.
   - `maxHeap.pop()` menghapus elemen terbesar tersebut dari heap.
   - Proses ini diulang sampai heap kosong, mencetak elemen dari yang terbesar hingga terkecil.

4. **Deklarasi dan Inisialisasi Min Heap**:
   ```cpp
   priority_queue<int, vector<int>, greater<int>> minHeap;
   minHeap.push(3);
   minHeap.push(1);
   minHeap.push(4);
   minHeap.push(1);
   minHeap.push(5);
   minHeap.push(9);
   ```
   - `priority_queue<int, vector<int>, greater<int>>` mendeklarasikan min heap. Di sini, `greater<int>` digunakan untuk membalik urutan prioritas sehingga elemen terkecil memiliki prioritas tertinggi.
   - Elemen-elemen dimasukkan ke dalam min heap menggunakan `push()`.

5. **Output Min Heap**:
   ```cpp
   cout << "Min Heap: ";
   while (!minHeap.empty()) {
       cout << minHeap.top() << " ";
       minHeap.pop();
   }
   cout << endl;
   ```
   - `minHeap.top()` mengembalikan elemen terkecil dari min heap.
   - `minHeap.pop()` menghapus elemen terkecil tersebut dari heap.
   - Proses ini diulang sampai heap kosong, mencetak elemen dari yang terkecil hingga terbesar.

### Output
Output yang dihasilkan oleh program ini adalah:
```
Max Heap: 9 5 4 3 1 1 
Min Heap: 1 1 3 4 5 9 
```
- **Max Heap**: Elemen-elemen dicetak dalam urutan menurun, dari yang terbesar (9) hingga yang terkecil (1).
- **Min Heap**: Elemen-elemen dicetak dalam urutan menaik, dari yang terkecil (1) hingga yang terbesar (9).

### Penjelasan Detail

1. **Max Heap**:
   - Setelah setiap `push`, heap diatur ulang untuk memastikan elemen terbesar berada di puncak.
   - Metode `top()` selalu mengembalikan elemen terbesar, dan metode `pop()` menghapus elemen tersebut, menggeser elemen lain untuk menjaga properti heap.

2. **Min Heap**:
   - `priority_queue<int, vector<int>, greater<int>>` mengubah prioritas sehingga elemen terkecil berada di puncak.
   - Sama seperti pada max heap, metode `top()` mengembalikan elemen terkecil dan `pop()` menghapusnya.

Implementasi ini menunjukkan penggunaan dasar priority queue dalam C++, baik sebagai max heap maupun min heap, dan bagaimana cara mengakses serta menghapus elemen-elemen dengan prioritas tertinggi (terbesar untuk max heap dan terkecil untuk min heap).

## Hashtable
Hash table, atau tabel hash, adalah struktur data yang digunakan untuk mengimplementasikan associative array, sebuah struktur data yang memetakan kunci (key) ke nilai (value). Hash table menggunakan fungsi hash untuk menghitung indeks dalam array tempat kunci atau nilai akan disimpan.[2]

```c++
#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 10;

struct HashItem {
    int key;
    string value;
};

class HashTable {
private:
    HashItem table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i].key = -1; // Menandai slot kosong
        }
    }

    void insert(int key, string value) {
        int index = hashFunction(key);
        while (table[index].key != -1) {
            index = (index + 1) % TABLE_SIZE; // Linear probing
        }
        table[index] = {key, value};
    }

    string search(int key) {
        int index = hashFunction(key);
        while (table[index].key != -1) {
            if (table[index].key == key) {
                return table[index].value;
            }
            index = (index + 1) % TABLE_SIZE; // Linear probing
        }
        return "Not found";
    }
};

int main() {
    HashTable ht;
    ht.insert(12, "Apel");
    ht.insert(25, "Jeruk");
    ht.insert(31, "Mangga");

    cout << ht.search(12) << endl; // Output: Apel
    cout << ht.search(25) << endl; // Output: Jeruk
    cout << ht.search(37) << endl; // Output: Not found

    return 0;
}
```
### Penjelasan Alur Program Hash Table

Program ini mendemonstrasikan implementasi hash table sederhana dengan linear probing untuk penanganan collision. Berikut adalah penjelasan detail alur programnya:

1. **Import Header Files**:
   ```cpp
   #include <iostream>
   #include <string>
   ```
   Program dimulai dengan mengimpor header `iostream` untuk operasi input/output dan `string` untuk menangani string.

2. **Konstanta dan Struktur**:
   ```cpp
   const int TABLE_SIZE = 10;

   struct HashItem {
       int key;
       string value;
   };
   ```
   - `TABLE_SIZE` mendefinisikan ukuran hash table sebagai 10.
   - `HashItem` adalah struktur yang menyimpan pasangan kunci-nilai (key-value).

3. **Kelas HashTable**:
   ```cpp
   class HashTable {
   private:
       HashItem table[TABLE_SIZE];

       int hashFunction(int key) {
           return key % TABLE_SIZE;
       }

   public:
       HashTable() {
           for (int i = 0; i < TABLE_SIZE; ++i) {
               table[i].key = -1; // Menandai slot kosong
           }
       }

       void insert(int key, string value) {
           int index = hashFunction(key);
           while (table[index].key != -1) {
               index = (index + 1) % TABLE_SIZE; // Linear probing
           }
           table[index] = {key, value};
       }

       string search(int key) {
           int index = hashFunction(key);
           while (table[index].key != -1) {
               if (table[index].key == key) {
                   return table[index].value;
               }
               index = (index + 1) % TABLE_SIZE; // Linear probing
           }
           return "Not found";
       }
   };
   ```
   - **Private Member**:
     - `table[TABLE_SIZE]` adalah array dari `HashItem` yang menyimpan elemen hash table.
     - `hashFunction(int key)` adalah fungsi hash yang mengembalikan indeks dalam array berdasarkan kunci menggunakan operasi modulus.
   - **Constructor**:
     - `HashTable()` menginisialisasi semua slot dalam tabel sebagai kosong dengan kunci -1.
   - **Public Methods**:
     - `void insert(int key, string value)` menambahkan pasangan kunci-nilai ke hash table menggunakan linear probing untuk menangani collision.
     - `string search(int key)` mencari nilai berdasarkan kunci, mengembalikan nilai yang sesuai atau "Not found" jika kunci tidak ditemukan.

4. **Main Function**:
   ```cpp
   int main() {
       HashTable ht;
       ht.insert(12, "Apel");
       ht.insert(25, "Jeruk");
       ht.insert(31, "Mangga");

       cout << ht.search(12) << endl; // Output: Apel
       cout << ht.search(25) << endl; // Output: Jeruk
       cout << ht.search(37) << endl; // Output: Not found

       return 0;
   }
   ```
   - Membuat objek `HashTable` bernama `ht`.
   - Menambahkan beberapa pasangan kunci-nilai ke hash table menggunakan metode `insert`.
   - Mencari nilai berdasarkan kunci menggunakan metode `search` dan mencetak hasilnya.

### Alur Program

1. **Inisialisasi**:
   - Hash table diinisialisasi dengan ukuran 10 dan semua slot diatur sebagai kosong.
   
2. **Insert Operasi**:
   - **Insert(12, "Apel")**:
     - `hashFunction(12)` mengembalikan 2 (`12 % 10 = 2`).
     - Slot indeks 2 kosong, sehingga pasangan {12, "Apel"} ditempatkan di sana.
   - **Insert(25, "Jeruk")**:
     - `hashFunction(25)` mengembalikan 5 (`25 % 10 = 5`).
     - Slot indeks 5 kosong, sehingga pasangan {25, "Jeruk"} ditempatkan di sana.
   - **Insert(31, "Mangga")**:
     - `hashFunction(31)` mengembalikan 1 (`31 % 10 = 1`).
     - Slot indeks 1 kosong, sehingga pasangan {31, "Mangga"} ditempatkan di sana.

3. **Search Operasi**:
   - **Search(12)**:
     - `hashFunction(12)` mengembalikan 2.
     - Slot indeks 2 berisi kunci 12, sehingga mengembalikan nilai "Apel".
   - **Search(25)**:
     - `hashFunction(25)` mengembalikan 5.
     - Slot indeks 5 berisi kunci 25, sehingga mengembalikan nilai "Jeruk".
   - **Search(37)**:
     - `hashFunction(37)` mengembalikan 7 (`37 % 10 = 7`).
     - Slot indeks 7 kosong (kunci -1), sehingga mengembalikan "Not found".

## Rekursif
Rekursif adalah teknik dalam pemrograman di mana sebuah fungsi memanggil dirinya sendiri secara langsung atau tidak langsung untuk menyelesaikan masalah. Teknik ini sangat berguna untuk masalah yang dapat dipecah menjadi sub-masalah yang lebih kecil dan identik dengan masalah asli.[3]
```c++
#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n; // Basis: F(0) = 0 dan F(1) = 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Langkah rekursif
    }
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    cout << "Suku Fibonacci ke-" << num << " adalah " << fibonacci(num) << endl;
    return 0;
}
```
### Penjelasan Alur Program Rekursif Fibonacci

Program ini menghitung suku Fibonacci ke-n menggunakan rekursi. Berikut adalah penjelasan langkah demi langkah dari alur program ini:

1. **Impor dan Pengaturan Dasar**:
   ```cpp
   #include <iostream>

   using namespace std;
   ```
   - Program dimulai dengan mengimpor header `iostream` untuk operasi input dan output.
   - `using namespace std;` digunakan agar tidak perlu menuliskan `std::` sebelum nama-nama objek standar C++.

2. **Fungsi Rekursif Fibonacci**:
   ```cpp
   int fibonacci(int n) {
       if (n <= 1) {
           return n; // Basis: F(0) = 0 dan F(1) = 1
       } else {
           return fibonacci(n - 1) + fibonacci(n - 2); // Langkah rekursif
       }
   }
   ```
   - Fungsi `fibonacci` menerima parameter `n`, yang merupakan bilangan bulat positif.
   - **Kasus Basis**: Jika `n` kurang dari atau sama dengan 1, fungsi mengembalikan `n`. Ini mencakup dua kasus basis: `F(0) = 0` dan `F(1) = 1`.
   - **Langkah Rekursif**: Jika `n` lebih besar dari 1, fungsi memanggil dirinya sendiri dua kali dengan argumen `n-1` dan `n-2`, kemudian menjumlahkan hasilnya. Ini mengikuti definisi rekursif dari deret Fibonacci:
     \[ F(n) = F(n-1) + F(n-2) \]

3. **Fungsi Utama**:
   ```cpp
   int main() {
       int num;
       cout << "Masukkan bilangan bulat positif: ";
       cin >> num;

       cout << "Suku Fibonacci ke-" << num << " adalah " << fibonacci(num) << endl;
       return 0;
   }
   ```
   - Fungsi `main` adalah titik masuk dari program.
   - Variabel `num` dideklarasikan untuk menyimpan bilangan yang dimasukkan oleh pengguna.
   - **Input Pengguna**: Program meminta pengguna untuk memasukkan bilangan bulat positif dan menyimpannya dalam `num`.
   - **Pemanggilan Fungsi**: Program kemudian memanggil fungsi `fibonacci` dengan `num` sebagai argumen dan mencetak hasilnya.
   - **Output**: Hasilnya adalah suku Fibonacci ke-`num`.

### Jalannya Program
Misalkan pengguna memasukkan angka 5:

1. Pengguna diminta memasukkan bilangan:
   ```
   Masukkan bilangan bulat positif: 5
   ```

2. Fungsi `fibonacci(5)` dipanggil:
   - Karena `5 > 1`, fungsi memanggil `fibonacci(4)` dan `fibonacci(3)`.

3. Proses Rekursi:
   - `fibonacci(4)` memanggil `fibonacci(3)` dan `fibonacci(2)`.
   - `fibonacci(3)` memanggil `fibonacci(2)` dan `fibonacci(1)`.
   - `fibonacci(2)` memanggil `fibonacci(1)` dan `fibonacci(0)`.

4. Kasus Basis Tercapai:
   - `fibonacci(1)` mengembalikan 1.
   - `fibonacci(0)` mengembalikan 0.
   - `fibonacci(2)` mengembalikan `1 + 0 = 1`.
   - `fibonacci(3)` mengembalikan `1 + 1 = 2`.
   - `fibonacci(4)` mengembalikan `2 + 1 = 3`.
   - `fibonacci(5)` mengembalikan `3 + 2 = 5`.

5. Output:
   ```
   Suku Fibonacci ke-5 adalah 5
   ```
## Graph & tree
Graf (Graph):
Graf adalah struktur data non-linear yang terdiri dari kumpulan simpul (vertex) dan sisi (edge) yang menghubungkan simpul-simpul tersebut. Simpul dapat merepresentasikan objek atau entitas, sementara sisi merepresentasikan hubungan atau koneksi antara objek-objek tersebut.
Pohon (Tree):
Pohon adalah jenis khusus dari graf yang bersifat terhubung, tidak memiliki siklus, dan setiap simpul (kecuali akar) memiliki tepat satu induk (parent).[4]
```c++
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class Graph {
public:
    int V;
    vector<list<int>> adj;

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); // Graf tidak berarah
    }

    // BFS untuk traversal graf
    void BFS(int s) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            s = q.front();
            cout << s << " ";
            q.pop();

            for (auto i : adj[s]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

// Preorder traversal untuk pohon
void preorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    // Contoh graf
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS traversal dari simpul 2: ";
    g.BFS(2);

    // Contoh pohon
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal dari pohon: ";
    preorderTraversal(root);

    return 0;
}
```
### ALur Program
**1. Struktur Data:**

* **`Node`:**
    - Menyimpan data dari sebuah simpul pohon.
    - Memiliki dua pointer (`left` dan `right`) untuk menunjuk ke anak kiri dan anak kanan.
* **`Graph`:**
    - Merepresentasikan graf dengan menggunakan adjacency list (daftar ketetanggaan).
    - `V`: Jumlah simpul dalam graf.
    - `adj`: Sebuah vektor yang berisi list. Setiap list pada indeks tertentu menyimpan simpul-simpul yang bertetangga dengan simpul pada indeks tersebut.

**2. Metode dan Fungsi:**

* **`Graph::addEdge(int v, int w)`:**
    - Menambahkan sebuah edge (hubungan) antara simpul `v` dan `w` dalam graf.
    - Karena graf tidak berarah, edge ditambahkan dua arah (`v` ke `w` dan `w` ke `v`).
* **`Graph::BFS(int s)`:**
    - Melakukan Breadth-First Search (BFS) traversal pada graf mulai dari simpul `s`.
    - Menggunakan antrian (`queue`) untuk menyimpan simpul-simpul yang akan dikunjungi.
    - `visited`: Vektor boolean untuk melacak apakah simpul sudah dikunjungi atau belum.
    - Secara sistematis mengunjungi simpul-simpul berdasarkan urutan levelnya dalam graf.
* **`preorderTraversal(Node* root)`:**
    - Melakukan preorder traversal pada pohon yang dimulai dari simpul `root`.
    - Preorder traversal mengunjungi simpul akar terlebih dahulu, kemudian anak kiri, dan terakhir anak kanan.
    - Fungsi ini bersifat rekursif, yaitu memanggil dirinya sendiri untuk mengunjungi anak kiri dan anak kanan secara bergantian.

**3. Fungsi `main()`:**

* **Membuat dan Inisialisasi Graf:**
    - Membuat objek `Graph` bernama `g` dengan 4 simpul.
    - Menambahkan beberapa edge untuk membentuk struktur graf.
* **BFS pada Graf:**
    - Memanggil fungsi `g.BFS(2)` untuk melakukan BFS traversal mulai dari simpul 2. Output akan menampilkan urutan simpul yang dikunjungi.
* **Membuat dan Inisialisasi Pohon:**
    - Membuat simpul akar (`root`) dengan nilai 1.
    - Secara manual membentuk struktur pohon dengan menghubungkan simpul-simpul lainnya menggunakan pointer `left` dan `right`.
* **Preorder Traversal pada Pohon:**
    - Memanggil fungsi `preorderTraversal(root)` untuk melakukan preorder traversal pada pohon yang telah dibuat. Output akan menampilkan nilai simpul-simpul dalam urutan preorder.

**Ringkasan Alur Program:**
1. Membuat graf dan menambahkan edge.
2. Melakukan BFS traversal pada graf mulai dari simpul 2.
3. Membuat pohon secara manual.
4. Melakukan preorder traversal pada pohon.

## Daftar Pustaka
[1] K. Parvizi, “Adaptive Cache-Friendly Priority Queue: Enhancing Heap-Tree Efficiency for Modern Computing,” arXiv.org, Nov. 24, 2023. https://arxiv.org/abs/2310.06663 (accessed Jun. 15, 2024).
‌[2] P. Jindal, A. Kumar, and S. Kumar, “Minimum and maximum ratio of number of red internal nodes to black internal nodes in Red Black tree,” International Journal of Computer Applications, vol. 5, no. 9, pp. 1–2, Aug. 2010, doi: https://doi.org/10.5120/965-1112.
‌[3] D. Firdaus and Y. Jumaryadi, “Implementation of Document Management System using Levenshtein Distance Algorithm,” International Journal of Computer Applications, vol. 176, no. 16, pp. 18–24, 2020, Accessed: Jun. 15, 2024. [Online]. Available: https://www.ijcaonline.org/archives/volume176/number16/31284-2020920091/
[4] S. D. Joshi and V. S. Inamdar, “Performance Improvement in Large Graph Algorithms on GPU using CUDA: an Overview,” International Journal of Computer Applications, vol. 10, no. 10, pp. 10–14, Nov. 2010, doi: https://doi.org/10.5120/1520-1992.
‌
‌