#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int>& array) {
    for (size_t i = 0; i < array.size() - 1; i++) {
        for (size_t j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]); // Uso de swap para intercambiar valores
            }
        }
    }
}