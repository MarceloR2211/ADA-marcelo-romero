#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void insertion(vector<int>& array){
    int axi;
    for(int i=0;i<array.size();i++){
		int a=i;
		axi=array[i];
		while((a>0) and (array[a-1]>axi)){
			array[a]=array[a-1];
			a--;
		}
		array[a] = axi;
	}
}