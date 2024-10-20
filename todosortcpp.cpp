#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
using namespace std;

void imprimirLista(const vector<int>& array, int tam);

 void lectura(vector<int>& numeros, int lista){
    numeros.clear();
    ifstream archi;
    string linea;
    string archivo=to_string(lista);

    // Abre el archivo en modo lectura
    archi.open("C:\\Users\\Usuar\\Desktop\\practica ADA\\random\\los"+archivo+".txt", ios::in);

    // Verifica si el archivo se abrió correctamente
    if (archi.is_open()) {
        // Lee el archivo línea por línea
        while (getline(archi, linea)) {
            // Convierte la línea leída a entero y la almacena en el vector
            numeros.push_back(stoi(linea)); 
        }
        archi.close();  // Cierra el archivo
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
//--------------
void bubbleSort(vector<int>& array) {
    for (size_t i = 0; i < array.size() - 1; i++) {
        for (size_t j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]); // Uso de swap para intercambiar valores
            }
        }
    }
}
//--------------
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
//--------------
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;

    if (largest != i) {
      swap(arr[i],arr[largest]);
      heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heapify(arr, arr.size(), i);

    for (int i = arr.size() - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
//--------------
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
//--------------
void merge(vector<int>& array, int l, int m, int r) {//m->mid
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];

   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];

   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];

   i = 0; j = 0; k = l;

   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      } else {
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {
      array[k] = rarr[j];
      j++; k++;
   }
}

void mergeSort(vector<int>& array, int l, int r) {//l->left r->raigh
   int m;
   if(l < r) {
      int m = l+(r-l)/2;

      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
//--------------
int partition (vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
//--------------
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
//--------------



int main(){
    vector<int> las_cantidades = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    vector<vector<chrono::milliseconds>> tiempos(7);
    for (size_t i = 0; i < las_cantidades.size(); i++){
    vector<int> array;

    //////////
    lectura(array , las_cantidades[i]);
    auto inicio = chrono::high_resolution_clock::now();
    bubbleSort(array);
    auto fin = chrono::high_resolution_clock::now();
    auto duracion = chrono::duration_cast<chrono::milliseconds>(fin - inicio);
    imprimirLista(array, las_cantidades[i]);
    tiempos[0].push_back(duracion);
    cout<<endl;
    ////////
    lectura(array , las_cantidades[i]);
     inicio = chrono::high_resolution_clock::now();
    array = CountingSort(array);
     fin = chrono::high_resolution_clock::now();
    duracion = chrono::duration_cast<chrono::milliseconds>(fin - inicio);
    imprimirLista(array,las_cantidades[i]);
    tiempos[1].push_back(duracion);
    cout<<endl;
    ////////
    lectura(array , las_cantidades[i]);
     inicio = chrono::high_resolution_clock::now();
    heapSort(array);
     fin = chrono::high_resolution_clock::now();
    duracion = chrono::duration_cast<chrono::milliseconds>(fin - inicio);
    imprimirLista(array,las_cantidades[i]);
    tiempos[2].push_back(duracion);
    cout<<endl;
    ////////
    lectura(array , las_cantidades[i]);
     inicio = chrono::high_resolution_clock::now();
    insertion(array);
     fin = chrono::high_resolution_clock::now();
    duracion = chrono::duration_cast<chrono::milliseconds>(fin - inicio);
    imprimirLista(array,las_cantidades[i]);
    tiempos[3].push_back(duracion);
    cout<<endl;
    ////////
    lectura(array , las_cantidades[i]);
     inicio = chrono::high_resolution_clock::now();
    mergeSort(array,0,array.size() - 1);
     fin = chrono::high_resolution_clock::now();
    duracion = chrono::duration_cast<chrono::milliseconds>(fin - inicio);
    imprimirLista(array,las_cantidades[i]);
    tiempos[4].push_back(duracion);
    cout<<endl;
    ////////
    lectura(array , las_cantidades[i]);
     inicio = chrono::high_resolution_clock::now();
    quickSort(array,0,array.size()-1);
     fin = chrono::high_resolution_clock::now();
    duracion = chrono::duration_cast<chrono::milliseconds>(fin - inicio);
    imprimirLista(array,las_cantidades[i]);
    tiempos[5].push_back(duracion);
    cout<<endl;
    ////////
    lectura(array , las_cantidades[i]);
     inicio = chrono::high_resolution_clock::now();
    selectionSort(array);
     fin = chrono::high_resolution_clock::now();
    duracion = chrono::duration_cast<chrono::milliseconds>(fin - inicio);
    imprimirLista(array,las_cantidades[i]);
    tiempos[6].push_back(duracion);
    cout<<endl;
    ////////
    }
    cout<<"Resultados:" << endl;
    vector<string> nombres_algoritmos = {"Bubble", "Counting", "Heap", "Insertion", "Merge", "Quick", "Selection Sort"};

for (size_t algoritmo = 0; algoritmo < tiempos.size(); algoritmo++) {
    cout << nombres_algoritmos[algoritmo] << ":\n";
    for (size_t i = 0; i < las_cantidades.size(); i++) {
        cout << tiempos[algoritmo][i].count()<<" ,";
    }
    cout<<endl;
} 
    return 0;

}

// Función para imprimir el contenido de un vector y su tamaño asociado
void imprimirLista(const vector<int>& array, int tam) {
    cout << "Lista de tamaño " << tam << ":\n";
    for (size_t i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
