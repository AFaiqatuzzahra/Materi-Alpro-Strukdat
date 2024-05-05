## Soal
1.	Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! (60 Poin)
2.	Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty. (40 poin)

## Jawaban
 1.
 ```c++
 #include <iostream>
using namespace std;

#define MAX_SIZE 5

class Stack {
private:
    int capacity;
    int top;
    int* stackArray;

public:
    Stack() {
        capacity = MAX_SIZE;
        top = -1;
        stackArray = new int[MAX_SIZE];
    }

    ~Stack() {
        delete[] stackArray;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int item) {
        if (isFull()) {
            cout << "Stack penuh, tidak bisa menambahkan elemen lagi!" << endl;
        } else {
            top++;
            stackArray[top] = item;
            cout << "Elemen " << item << " berhasil ditambahkan ke dalam stack." << endl;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack kosong, tidak ada elemen yang bisa dihapus!" << endl;
            return -1;
        } else {
            int poppedItem = stackArray[top];
            top--;
            return poppedItem;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack kosong, tidak ada elemen yang bisa dilihat!" << endl;
            return -1;
        } else {
            return stackArray[top];
        }
    }

    int size() {
        return top + 1;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);  

    cout << "Ukuran stack: " << stack.size() << endl;

    cout << "Pop elemen dari stack: " << stack.pop() << endl;
    cout << "Pop elemen dari stack: " << stack.pop() << endl;

    cout << "Elemen teratas pada stack: " << stack.peek() << endl;

    cout << "Ukuran stack: " << stack.size() << endl;

    return 0;
}
 ```
2. 
```c++
#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &s) {
    stack<int> tempStack;

    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> s;

    int n;
    cout << "Masukkan jumlah nilai yang ingin dimasukkan ke dalam stack: ";
    cin >> n;

    cout << "Masukkan nilai-nilai untuk stack:" << endl;
    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> value;
        s.push(value);
    }

    cout << "\nStack sebelum diurutkan:" << endl;
    stack<int> original = s;
    while (!original.empty()) {
        cout << original.top() << " ";
        original.pop();
    }

    sortStack(s);

    cout << "\nStack setelah diurutkan:" << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
```
