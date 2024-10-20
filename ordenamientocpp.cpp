#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
 void lectura(vector<int>& numeros, int lista){
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


int main(){
    vector<int> las_cantidades = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    vector<chrono::duration<double>> tiempo;
    for (size_t i = 0; i < las_cantidades.size(); i++){
    vector<int> array;
    lectura(array , las_cantidades[i]);

    //////////
    auto inicio = chrono::high_resolution_clock::now();
    //codigo aqui
    auto fin = chrono::high_resolution_clock::now();
    //////////
    cout << "lista de los "+to_string(las_cantidades[i]);
    for (int k = 0; k < array.size(); k++){
        cout << array[k]<<" ";
        }

    chrono::duration<double> duracion = fin - inicio;
    tiempo.push_back(duracion);
    cout<<"listo "+to_string(las_cantidades[i])<<endl;
    }
    cout<<"Resultados:" << endl;
    for (int j = 0; j < tiempo.size(); j++){
        cout<< tiempo[j].count()<<", ";
        }
    return 0;

}