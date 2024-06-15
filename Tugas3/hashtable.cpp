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
