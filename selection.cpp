#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void selectionSort(vector<int>& array) {
    for (int i = 0; i < array.size() - 1; i++) {
        int axi = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[axi]) {
                axi = j;
            }
        }
        if (axi != i) {
            swap(array[i], array[axi]);
        }
    }
}