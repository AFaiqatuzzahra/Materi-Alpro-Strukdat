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
