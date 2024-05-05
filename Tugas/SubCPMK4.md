## Soal
1.	Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! 

## Jawaban
1. Struct adalah sebuah tipe data yang dapat digunakan untuk mengelompokkan beberapa variabel yang berbeda tipe data dalam satu unit.
```c++
#include <iostream>
#include <string> // Untuk menggunakan tipe data string

using namespace std;

// Mendefinisikan struct biodata
struct Bio {
    string Name;
    int Age;
    long long Wealth; // Tipe data long long untuk wealth karena nilainya besar
};

int main() {
    // Mendeklarasikan variabel fav dengan tipe struct biodata
    Bio fav;

    // Mengisi data ke dalam variabel fav
    fav.Name = "Alva";
    fav.Age = 25;
    fav.Wealth = 271000000000000;

    // Menampilkan informasi biodata favorit
    cout << "\tName: " << fav.Name << endl;
    cout << "\tAge: " << fav.Age << endl;
    cout << "\tWealth: " << fav.Wealth << endl;
 
    return 0;
}
```