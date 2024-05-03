## **Soal**

1.	Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 
2.	Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut (35 poin)
3.	Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” (30 poin)
contoh
Input string1 = “bahu” string2 = “buah”
Output: “anagram”
Input string1 = “makan” string2 = “minum”
Output: “tidak anagram”
4.	Tulislah sebuah fungsi program dengan asumsi sebagai berikut:
Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut! (30 Poin)

## **Jawaban**
### **1. Algoritma Sorting: Bubble Sort, Selection Sort, dan Merge Sort**

**1. Bubble Sort:**

**Alur:**

1. Iterasi melalui seluruh elemen dalam array.
2. Bandingkan elemen saat ini dengan elemen berikutnya.
3. Jika elemen saat ini lebih besar dari elemen berikutnya, tukar posisinya.
4. Ulangi langkah 1 dan 2 sampai tidak ada lagi pertukaran yang terjadi.
5. Pada iterasi selanjutnya, elemen yang sudah berada di posisi yang benar tidak perlu diperiksa lagi.

**Runtime:**

* **Best Case (Kasus Terbaik):** O(n) - Tercapai ketika array sudah terurut atau hanya ada sedikit elemen yang tidak pada tempatnya.
* **Worst Case (Kasus Terburuk):** O(n^2) - Tercapai ketika array dalam urutan terbalik atau elemen-elemennya acak.

**2. Selection Sort:**

**Alur:**

1. Temukan elemen terkecil dalam array.
2. Tukar elemen terkecil dengan elemen pertama dalam array.
3. Temukan elemen terkecil kedua dalam array yang tersisa (tidak termasuk elemen pertama).
4. Tukar elemen terkecil kedua dengan elemen kedua dalam array.
5. Ulangi langkah 3 dan 4 hingga semua elemen terurut.

**Runtime:**

* **Best Case (Kasus Terbaik):** O(n) - Tercapai ketika array sudah terurut.
* **Worst Case (Kasus Terburuk):** O(n^2) - Tercapai ketika array dalam urutan terbalik atau elemen-elemennya acak.

**3. Merge Sort:**

**Alur:**

1. Bagi array menjadi dua subarray dengan ukuran yang sama (atau hampir sama).
2. Urutkan subarray secara rekursif menggunakan Merge Sort.
3. Gabungkan dua subarray yang sudah terurut menjadi satu array yang terurut.

**Runtime:**

* **Best Case (Kasus Terbaik):** O(n log n) - Tercapai ketika array sudah terbagi menjadi subarray yang terurut (misalnya, array yang sudah diurut sebelumnya).
* **Worst Case (Kasus Terburuk):** O(n log n) - Tercapai ketika array dalam urutan terbalik atau elemen-elemennya acak.

**Kesimpulan:**

* **Bubble Sort** dan **Selection Sort** memiliki performa yang sama dalam kasus terbaik dan terburuk, O(n^2).
* **Merge Sort** memiliki performa yang lebih baik dalam kasus terbaik dan terburuk, O(n log n).
* **Merge Sort** lebih efisien untuk array yang besar, karena memiliki kompleksitas waktu yang lebih rendah.

**Pertimbangan Tambahan:**

* **Bubble Sort** dan **Selection Sort** lebih mudah diimplementasikan dibandingkan dengan **Merge Sort**.
* **Merge Sort** membutuhkan memori tambahan untuk menyimpan subarray selama proses penggabungan.

**Pilihan Algoritma:**

* **Bubble Sort** dan **Selection Sort** cocok untuk array yang kecil atau untuk situasi di mana kesederhanaan implementasi lebih penting daripada performa.
* **Merge Sort** cocok untuk array yang besar atau untuk situasi di mana performa adalah prioritas utama.

### **2. Pada soal nomor 2 saya menggunakan Bublle sort dengan kode sebagai berikut **
```C++
#include <iostream>
using namespace std;

// Fungsi untuk melakukan Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            // Jika elemen saat ini lebih besar dari elemen berikutnya, tukar posisinya
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah bilangan: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan bilangan: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Memanggil fungsi bubbleSort untuk mengurutkan array
    bubbleSort(arr, n);
    
    cout << "Array yang telah diurutkan: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
```
`#include <iostream>`: Memasukkan library iostream yang diperlukan untuk operasi input-output.
`using namespace std;`: Mendeklarasikan bahwa kita akan menggunakan namespace std.
`void bubbleSort(int arr[], int n) { /* ... */ }`: Mendefinisikan fungsi bubbleSort yang akan menerima sebuah array arr dan panjangnya n. Fungsi ini akan mengurutkan array menggunakan algoritma Bubble Sort.
`for (int i = 0; i < n-1; i++) { /* ... */ }`: Loop luar yang akan melakukan iterasi melalui semua elemen array kecuali elemen terakhir.
`for (int j = 0; j < n-i-1; j++) { /* ... */ }`: Loop dalam yang akan membandingkan setiap elemen dengan elemen berikutnya.
`if (arr[j] > arr[j+1]) { /* ... */ }`: Pernyataan kondisional untuk memeriksa apakah elemen saat ini lebih besar dari elemen berikutnya.
`int temp` = arr[j];: Menyimpan nilai elemen saat ini ke dalam variabel sementara temp.
`arr[j]` = arr[j+1];: Mengganti nilai elemen saat ini dengan nilai elemen berikutnya.
`arr[j+1]` = temp;: Mengganti nilai elemen berikutnya dengan nilai yang disimpan di dalam temp.
`int n;`: Deklarasi variabel n untuk menyimpan jumlah bilangan yang akan dimasukkan.
`cout << "Masukkan jumlah bilangan: ";`: Menampilkan pesan untuk meminta pengguna memasukkan jumlah bilangan.
`cin >> n;`: Mengambil input jumlah bilangan dari pengguna.
`int arr[n];`: Deklarasi array dengan panjang n untuk menyimpan bilangan yang dimasukkan.
`cout << "Masukkan bilangan: ";`: Menampilkan pesan untuk meminta pengguna memasukkan bilangan.
`cin >> arr[i];`: Mengambil input bilangan dari pengguna dan menyimpannya ke dalam array.
`bubbleSort(arr, n);`: Memanggil fungsi bubbleSort untuk mengurutkan array.
`cout << "Array yang telah diurutkan: \n";`: Menampilkan pesan bahwa array telah diurutkan.
`cout << arr[i] << " ";`: Mencetak setiap elemen dari array yang telah diurutkan.
`cout << endl;`: Menampilkan newline untuk pemisah setelah mencetak seluruh array yang telah diurutkan.
`return 0;`: Mengembalikan nilai 0 yang menandakan bahwa program selesai dijalankan dengan sukses.
Kesimpulannya code diatas untuk mengurutkan data bilangan terkecil mmenuju bilangan terbesar menggunakan bubble sorting.

### **3. Berikut contoh kode anagram atau tidak anagram **
```c++
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Fungsi untuk mengurutkan string
string sortString(string str) {
    sort(str.begin(), str.end());
    return str;
}

// Fungsi untuk memeriksa apakah dua string adalah anagram atau tidak
string checkAnagram(string str1, string str2) {
    // Jika panjang kedua string tidak sama, langsung kembalikan "tidak anagram"
    if (str1.length() != str2.length()) {
        return "tidak anagram";
    }

    // Urutkan kedua string
    str1 = sortString(str1);
    str2 = sortString(str2);

    // Jika kedua string setelah diurutkan sama, maka mereka adalah anagram
    if (str1 == str2) {
        return "anagram";
    } else {
        return "tidak anagram";
    }
}

int main() {
    string string1, string2;

    // Meminta pengguna memasukkan dua string
    cout << "Masukkan string pertama: ";
    cin >> string1;
    cout << "Masukkan string kedua: ";
    cin >> string2;

    // Memeriksa apakah dua string tersebut adalah anagram atau tidak
    string result = checkAnagram(string1, string2);
    
    // Menampilkan hasil
    cout << "Output: " << result << endl;

    return 0;
}
```

### **4.BErikut kode penggabungan Array A dengan Array B **
```C++
#include <iostream>
#include <algorithm>
using namespace std;

// Fungsi untuk menggabungkan dua array yang sudah terurut dan mengurutkan hasilnya
void mergeArrays(int arr1[], int m, int arr2[], int n) {
    // Masukkan semua elemen array B ke dalam array A
    for (int i = 0; i < n; i++) {
        arr1[m + i] = arr2[i];
    }

    // Urutkan array A yang sudah digabung dengan array B
    sort(arr1, arr1 + m + n);
}

int main() {
    int m, n;

    // Meminta pengguna memasukkan ukuran array A dan B
    cout << "Masukkan ukuran array A: ";
    cin >> m;
    cout << "Masukkan ukuran array B: ";
    cin >> n;

    // Deklarasi array A dan B berdasarkan ukuran yang dimasukkan pengguna
    int A[m + n], B[n];

    // Meminta pengguna memasukkan elemen-elemen array A
    cout << "Masukkan elemen-elemen array A secara terurut: ";
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    // Meminta pengguna memasukkan elemen-elemen array B
    cout << "Masukkan elemen-elemen array B secara terurut: ";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // Panggil fungsi untuk menggabungkan dan mengurutkan array
    mergeArrays(A, m, B, n);

    // Tampilkan array hasil gabungan dan pengurutan
    cout << "Array hasil penggabungan dan pengurutan: ";
    for (int i = 0; i < m + n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
```
