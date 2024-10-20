import java.io.*;
import java.util.*;
import java.util.concurrent.TimeUnit;

public class todosortjava {
    static void imprimirLista(int[] array, int tam) {
        System.out.println("Lista de tamaño " + tam + ":");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    static void lectura(List<Integer> numeros, int lista) {
        numeros.clear();
        String archivo = "los" + lista + ".txt";
        
        try (BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\Usuar\\Desktop\\practica ADA\\random\\" + archivo))) {
            String linea;
            while ((linea = br.readLine()) != null) {
                numeros.add(Integer.parseInt(linea)); // Convierte la línea leída a entero y la almacena
            }
        } catch (IOException e) {
            System.out.println("No se pudo abrir el archivo.");
        }
    }

    // Bubble Sort
    static void bubbleSort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    // Counting Sort
    static int[] countingSort(int[] array) {
        int max_value = Arrays.stream(array).max().orElse(Integer.MAX_VALUE);
        int[] count = new int[max_value + 1];
        int[] output = new int[array.length];

        for (int num : array) {
            count[num]++;
        }

        for (int i = 1; i <= max_value; i++) {
            count[i] += count[i - 1];
        }

        for (int i = array.length - 1; i >= 0; i--) {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }

        return output; // Retornar el array ordenado
    }

    // Heap Sort
    static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, n, largest);
        }
    }

    static void heapSort(int[] arr) {
        for (int i = arr.length / 2 - 1; i >= 0; i--)
            heapify(arr, arr.length, i);

        for (int i = arr.length - 1; i >= 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }

    // Insertion Sort
    static void insertionSort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }

    // Merge Sort
    static void merge(int[] array, int l, int m, int r) {
        int nl = m - l + 1;
        int nr = r - m;

        int[] larr = new int[nl];
        int[] rarr = new int[nr];

        for (int i = 0; i < nl; i++)
            larr[i] = array[l + i];

        for (int j = 0; j < nr; j++)
            rarr[j] = array[m + 1 + j];

        int i = 0, j = 0, k = l;

        while (i < nl && j < nr) {
            if (larr[i] <= rarr[j]) {
                array[k] = larr[i];
                i++;
            } else {
                array[k] = rarr[j];
                j++;
            }
            k++;
        }
        while (i < nl) {
            array[k] = larr[i];
            i++;
            k++;
        }
        while (j < nr) {
            array[k] = rarr[j];
            j++;
            k++;
        }
    }

    static void mergeSort(int[] array, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(array, l, m);
            mergeSort(array, m + 1, r);
            merge(array, l, m, r);
        }
    }

    // Quick Sort
    static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }

    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }

    // Selection Sort
    static void selectionSort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                int temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
            }
        }
    }

    public static void main(String[] args) {
        int[] lasCantidades = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
        List<List<Long>> tiempos = new ArrayList<>();

        for (int i = 0; i < 7; i++) {
            tiempos.add(new ArrayList<>());
        }

        for (int cantidad : lasCantidades) {
            List<Integer> arrayList = new ArrayList<>();

            // Bubble Sort
            lectura(arrayList, cantidad);
            int[] array = arrayList.stream().mapToInt(Integer::intValue).toArray();
            long inicio = System.nanoTime();
            bubbleSort(array);
            long fin = System.nanoTime();
            imprimirLista(array, cantidad);
            tiempos.get(0).add(TimeUnit.NANOSECONDS.toMillis(fin - inicio));
            System.out.println();

            // Counting Sort
            lectura(arrayList, cantidad);
            array = arrayList.stream().mapToInt(Integer::intValue).toArray();
            inicio = System.nanoTime();
            array = countingSort(array);
            fin = System.nanoTime();
            imprimirLista(array, cantidad);
            tiempos.get(1).add(TimeUnit.NANOSECONDS.toMillis(fin - inicio));
            System.out.println();

            // Heap Sort
            lectura(arrayList, cantidad);
            array = arrayList.stream().mapToInt(Integer::intValue).toArray();
            inicio = System.nanoTime();
            heapSort(array);
            fin = System.nanoTime();
            imprimirLista(array, cantidad);
            tiempos.get(2).add(TimeUnit.NANOSECONDS.toMillis(fin - inicio));
            System.out.println();

            // Insertion Sort
            lectura(arrayList, cantidad);
            array = arrayList.stream().mapToInt(Integer::intValue).toArray();
            inicio = System.nanoTime();
            insertionSort(array);
            fin = System.nanoTime();
            imprimirLista(array, cantidad);
            tiempos.get(3).add(TimeUnit.NANOSECONDS.toMillis(fin - inicio));
            System.out.println();

            // Merge Sort
            lectura(arrayList, cantidad);
            array = arrayList.stream().mapToInt(Integer::intValue).toArray();
            inicio = System.nanoTime();
            mergeSort(array, 0, array.length - 1);
            fin = System.nanoTime();
            imprimirLista(array, cantidad);
            tiempos.get(4).add(TimeUnit.NANOSECONDS.toMillis(fin - inicio));
            System.out.println();

            // Quick Sort
            lectura(arrayList, cantidad);
            array = arrayList.stream().mapToInt(Integer::intValue).toArray();
            inicio = System.nanoTime();
            quickSort(array, 0, array.length - 1);
            fin = System.nanoTime();
            imprimirLista(array, cantidad);
            tiempos.get(5).add(TimeUnit.NANOSECONDS.toMillis(fin - inicio));
            System.out.println();

            // Selection Sort
            lectura(arrayList, cantidad);
            array = arrayList.stream().mapToInt(Integer::intValue).toArray();
            inicio = System.nanoTime();
            selectionSort(array);
            fin = System.nanoTime();
            imprimirLista(array, cantidad);
            tiempos.get(6).add(TimeUnit.NANOSECONDS.toMillis(fin - inicio));
            System.out.println();
        }

        System.out.println("Tiempos en milisegundos:");
        for (int i = 0; i < 7; i++) {
            System.out.println("Algoritmo " + (i + 1) + ": " + tiempos.get(i));
        }
    }
}
