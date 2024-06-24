#include <iostream>
#include <unordered_map>

int main() {
    int arr[] = {2, 1, 3, 4}; // array

    std::unordered_map<int, int> frequencyMap;
    int maxFrequency = 0;
    int maxDuplicate = -1; // Inisialisasi dengan nilai tidak mungkin ada di array

    for (int num : arr) { // Iterasi setiap elemen dalam array
        frequencyMap[num]++;  // Tingkatkan frekuensi di map
        if (frequencyMap[num] > maxFrequency) { 
            maxFrequency = frequencyMap[num];
            maxDuplicate = num;
        }
    }

    if (maxFrequency > 1) { // Hanya jika ada duplikat
        std::cout << "Duplikasi maksimal: " << maxDuplicate << std::endl;
        std::cout << "Muncul sebanyak: " << maxFrequency << " kali" << std::endl;
    } else {
        std::cout << "Tidak ada duplikasi." << std::endl;
    }

    return 0;
}
