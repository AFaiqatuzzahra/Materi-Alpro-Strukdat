# Soal
1.	Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)! (60 Poin)
2.	Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1. mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2. memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat. 

# Jawaban
1 
```c++ 
#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Queue {
private:
    int capacity;
    int front;
    int rear;
    int* queueArray;

public:
    Queue() {
        capacity = MAX_SIZE;
        front = -1;
        rear = -1;
        queueArray = new int[MAX_SIZE];
    }

    ~Queue() {
        delete[] queueArray;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue penuh, tidak bisa menambahkan elemen lagi!" << endl;
        } else if (isEmpty()) {
            front = rear = 0;
            queueArray[rear] = item;
        } else {
            rear = (rear + 1) % capacity;
            queueArray[rear] = item;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong, tidak ada elemen yang bisa dihapus!" << endl;
            return -1;
        } else if (front == rear) {
            int removedItem = queueArray[front];
            front = rear = -1;
            return removedItem;
        } else {
            int removedItem = queueArray[front];
            front = (front + 1) % capacity;
            return removedItem;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue kosong, tidak ada elemen yang bisa dilihat!" << endl;
            return -1;
        } else {
            return queueArray[front];
        }
    }
};

int main() {
    Queue queue;

    cout << "Apakah queue kosong? " << (queue.isEmpty() ? "Ya" : "Tidak") << endl;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Elemen terdepan pada queue: " << queue.peek() << endl;

    cout << "Elemen yang dihapus dari queue: " << queue.dequeue() << endl;
    cout << "Elemen yang dihapus dari queue: " << queue.dequeue() << endl;

    cout << "Apakah queue kosong? " << (queue.isEmpty() ? "Ya" : "Tidak") << endl;

    return 0;
}
```
2
```c++
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Animal {
public:
    string name;
    int age;
    string type;

    Animal(string n, int a, string t) : name(n), age(a), type(t) {}
};

class AnimalShelter {
private:
    queue<Animal> shelterQueue;

public:
    void enqueue(string name, int age, string type) {
        shelterQueue.push(Animal(name, age, type));
    }

    Animal dequeueAny() {
        if (shelterQueue.empty()) {
            cout << "Tidak ada hewan di shelter saat ini." << endl;
            return Animal("", -1, "");
        } else {
            Animal adoptedAnimal = shelterQueue.front();
            shelterQueue.pop();
            return adoptedAnimal;
        }
    }

    Animal dequeueDog() {
        if (shelterQueue.empty()) {
            cout << "Tidak ada anjing di shelter saat ini." << endl;
            return Animal("", -1, "");
        } else {
            for (int i = 0; i < shelterQueue.size(); ++i) {
                Animal temp = shelterQueue.front();
                shelterQueue.pop();
                if (temp.type == "dog") {
                    return temp;
                }
                shelterQueue.push(temp);
            }
            cout << "Tidak ada anjing di shelter saat ini." << endl;
            return Animal("", -1, "");
        }
    }

    Animal dequeueCat() {
        if (shelterQueue.empty()) {
            cout << "Tidak ada kucing di shelter saat ini." << endl;
            return Animal("", -1, "");
        } else {
            for (int i = 0; i < shelterQueue.size(); ++i) {
                Animal temp = shelterQueue.front();
                shelterQueue.pop();
                if (temp.type == "cat") {
                    return temp;
                }
                shelterQueue.push(temp);
            }
            cout << "Tidak ada kucing di shelter saat ini." << endl;
            return Animal("", -1, "");
        }
    }
};

int main() {
    AnimalShelter shelter;

    shelter.enqueue("Tom", 5, "cat");
    shelter.enqueue("Spike", 3, "dog");
    shelter.enqueue("Fluffy", 2, "cat");
    shelter.enqueue("Max", 4, "dog");

    cout << "Mengadopsi hewan: " << shelter.dequeueAny().name << endl;
    cout << "Mengadopsi kucing: " << shelter.dequeueCat().name << endl;
    cout << "Mengadopsi anjing: " << shelter.dequeueDog().name << endl;

    return 0;
}
```