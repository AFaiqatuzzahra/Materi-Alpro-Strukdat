# Soal

1.	Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! (35 Poin)
2.	Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut (35 Poin)
3.	Tulislah sebuah fungsi program dengan kondisi sebagai berikut:
Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! (30 Poin)
Input: bola, {“Adi”,””,””, “”, “bermain”, “”, “bola”, “”, “”, “sedang”}
Output: 6

# Jawaban
## Nomor 1
### 1. Linear Search:

#### Alur Algoritma:
- Linear Search, juga dikenal sebagai sequential search, adalah metode sederhana untuk mencari elemen tertentu di dalam array.
- Algoritma Linear Search memeriksa setiap elemen dalam array satu per satu, dimulai dari indeks awal hingga indeks terakhir.
- Setiap elemen diuji untuk kesesuaian dengan elemen yang dicari.
- Jika elemen yang dicari ditemukan, indeksnya akan dikembalikan. Jika tidak ditemukan, pencarian akan berlanjut hingga akhir array.

#### Runtime Complexity:
- **Best Case**: Pada kasus terbaik, elemen yang dicari berada pada indeks pertama array. Runtime Complexity untuk best case adalah O(1).
- **Worst Case**: Pada kasus terburuk, elemen yang dicari berada pada indeks terakhir array atau tidak ada sama sekali. Runtime Complexity untuk worst case adalah O(n), di mana n adalah jumlah elemen dalam array.

### 2. Binary Search:

#### Alur Algoritma:
- Binary Search adalah algoritma pencarian yang efisien, tetapi hanya dapat digunakan pada array yang sudah diurutkan secara terurut.
- Algoritma Binary Search membandingkan elemen tengah array dengan elemen yang dicari.
- Jika elemen tengah sama dengan elemen yang dicari, pencarian selesai.
- Jika elemen tengah lebih kecil dari elemen yang dicari, pencarian dilanjutkan pada setengah kanan array.
- Jika elemen tengah lebih besar dari elemen yang dicari, pencarian dilanjutkan pada setengah kiri array.
- Proses ini diulangi hingga elemen yang dicari ditemukan atau tidak ada lagi elemen yang bisa diuji.

#### Runtime Complexity:
- **Best Case**: Pada kasus terbaik, elemen yang dicari berada tepat di tengah array. Runtime Complexity untuk best case adalah O(1).
- **Worst Case**: Pada kasus terburuk, elemen yang dicari tidak ada dalam array atau berada di ujung array. Runtime Complexity untuk worst case adalah O(log n), di mana n adalah jumlah elemen dalam array. Hal ini disebabkan karena setiap iterasi mengurangi setengah dari rentang pencarian.

Dalam kedua algoritma, terdapat faktor yang mempengaruhi kompleksitas waktu pencarian, yaitu bagaimana data disusun dan apakah elemen yang dicari ditemukan atau tidak.

## Nomor 2 menggunakan Binary search 
```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> arr;
    int n;
    cout << "Masukkan jumlah bilangan dalam array: ";
    cin >> n;

    cout << "Masukkan bilangan array (dipisahkan oleh spasi): ";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end()); // Mengurutkan array

    int target;
    cout << "Masukkan bilangan yang ingin dicari: ";
    cin >> target;

    int result = binary_search(arr, target);

    if (result != -1) {
        cout << "Elemen " << target << " ditemukan pada indeks " << result << ".\n";
    } else {
        cout << "Elemen " << target << " tidak ditemukan dalam array.\n";
    }

    return 0;
}
```
Penjelasan kode diatas adalah

1. Pada awalnya, program memuat pustaka standar iostream, vector, dan algorithm.
2. Fungsi `binary_search` didefinisikan untuk melakukan pencarian biner pada vektor yang berisi bilangan bulat. Fungsi ini menerima dua parameter: vektor `arr` yang berisi bilangan bulat yang sudah diurutkan, dan `target` yang merupakan bilangan yang ingin dicari. Fungsi ini mengembalikan indeks dari `target` jika ditemukan, atau `-1` jika tidak ditemukan.
3. Di dalam fungsi `binary_search`, algoritma pencarian biner dilakukan. Variabel `left` dan `right` digunakan untuk menunjukkan indeks batas kiri dan kanan pada setiap iterasi pencarian.
4. Pada `main` function, vektor `arr` digunakan untuk menyimpan bilangan-bilangan yang dimasukkan oleh pengguna.
5. Pengguna diminta untuk memasukkan jumlah bilangan dalam array dan kemudian memasukkan bilangan-bilangan tersebut satu per satu.
6. Setelah semua bilangan dimasukkan, vektor `arr` diurutkan menggunakan fungsi `sort()` dari pustaka `<algorithm>`.
7. Pengguna diminta untuk memasukkan bilangan yang ingin dicari.
8. Fungsi `binary_search` dipanggil untuk mencari bilangan yang diinginkan dalam array.
9. Hasil pencarian dicetak ke layar, yaitu apakah bilangan tersebut ditemukan dan diindeks ke berapa.

## Nomor 3
``` c++
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

int cari_indeks_kata(const string& kata, const vector<string>& array) {
    auto it = lower_bound(array.begin(), array.end(), kata); 


    if (it != array.end() && *it == kata) {
        return it - array.begin(); 
    }

    return -1; 
}

int main() {
    int n;
    cout << "Masukkan panjang array: ";
    cin >> n;

    vector<string> array(n);
    cout << "Masukkan " << n << " kata :" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    string kata;
    cout << "Masukkan kata yang dicari: ";
    cin >> kata;

    int hasil = cari_indeks_kata(kata, array);
    
    if (hasil != -1) {
        cout << "Kata ditemukan pada indeks: " << hasil << endl;
    } else {
        cout << "Kata tidak ditemukan." << endl;
    }

    return 0;
}
```
