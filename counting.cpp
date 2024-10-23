#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static vector<int> CountingSort(vector<int>& array) {
	int max_value = *max_element(array.begin(), array.end());
	
	vector<int> count(max_value + 1, 0);
	vector<int> output(array.size(), 0);
	
	for (int i = 0; i < array.size(); i++) {
		count[array[i]]++;
	}
	
	for (int i = 1; i <= max_value; i++) {
		count[i] += count[i - 1];
	}
	
	for (int i = array.size() - 1; i >= 0; i--) {
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	
	return output; // Retornar el array ordenado
}
