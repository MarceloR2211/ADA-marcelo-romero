import time
import os

def imprimir_lista(array, tam):
    print(f"Lista de tamaño {tam}:")
    print(" ".join(map(str, array)))
    print()

def lectura(numeros, lista):
    numeros.clear()
    archivo = f"C:\\Users\\Usuar\\Desktop\\practica ADA\\random\\los{lista}.txt"

    try:
        with open(archivo, 'r') as archi:
            for linea in archi:
                numeros.append(int(linea.strip()))
    except FileNotFoundError:
        print("No se pudo abrir el archivo.")

def bubble_sort(array):
    for i in range(len(array) - 1):
        for j in range(len(array) - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]

def counting_sort(array):
    max_value = max(array)
    count = [0] * (max_value + 1)
    output = [0] * len(array)

    for num in array:
        count[num] += 1

    for i in range(1, len(count)):
        count[i] += count[i - 1]

    for num in reversed(array):
        output[count[num] - 1] = num
        count[num] -= 1

    return output

def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)

def insertion_sort(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key

def merge(arr, l, m, r):
    left = arr[l:m + 1]
    right = arr[m + 1:r + 1]
    
    i = j = 0
    k = l
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1

    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1

def merge_sort(arr, l, r):
    if l < r:
        m = (l + r) // 2
        merge_sort(arr, l, m)
        merge_sort(arr, m + 1, r)
        merge(arr, l, m, r)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def selection_sort(array):
    for i in range(len(array) - 1):
        min_idx = i
        for j in range(i + 1, len(array)):
            if array[j] < array[min_idx]:
                min_idx = j
        if min_idx != i:
            array[i], array[min_idx] = array[min_idx], array[i]

if __name__ == "__main__":
    las_cantidades = [100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
    tiempos = [[] for _ in range(7)]
    nombres_algoritmos = ["Bubble", "Counting", "Heap", "Insertion", "Merge", "Quick", "Selection Sort"]

    for tam in las_cantidades:
        array = []

        # ---------
        lectura(array, tam)
        inicio = time.time()
        bubble_sort(array)
        fin = time.time()
        tiempo_bubble = (fin - inicio) * 1000
        imprimir_lista(array, tam)
        tiempos[0].append(tiempo_bubble)

        # ------------
        lectura(array, tam)
        inicio = time.time()
        array = counting_sort(array)
        fin = time.time()
        tiempo_counting = (fin - inicio) * 1000
        imprimir_lista(array, tam)
        tiempos[1].append(tiempo_counting)

        # -----------
        lectura(array, tam)
        inicio = time.time()
        heap_sort(array)
        fin = time.time()
        tiempo_heap = (fin - inicio) * 1000
        imprimir_lista(array, tam)
        tiempos[2].append(tiempo_heap)

        # --------------
        lectura(array, tam)
        inicio = time.time()
        insertion_sort(array)
        fin = time.time()
        tiempo_insertion = (fin - inicio) * 1000
        imprimir_lista(array, tam)
        tiempos[3].append(tiempo_insertion)

        # ---------------
        lectura(array, tam)
        inicio = time.time()
        merge_sort(array, 0, len(array) - 1)
        fin = time.time()
        tiempo_merge = (fin - inicio) * 1000 
        imprimir_lista(array, tam)
        tiempos[4].append(tiempo_merge)

        # --------------
        lectura(array, tam)
        inicio = time.time()
        quick_sort(array, 0, len(array) - 1)
        fin = time.time()
        tiempo_quick = (fin - inicio) * 1000 
        imprimir_lista(array, tam)
        tiempos[5].append(tiempo_quick)

        # ----------------
        lectura(array, tam)
        inicio = time.time()
        selection_sort(array)
        fin = time.time()
        tiempo_selection = (fin - inicio) * 1000
        imprimir_lista(array, tam)
        tiempos[6].append(tiempo_selection)

    print("Resultados:")
    for i, nombre in enumerate(nombres_algoritmos):
        print(f"{nombre}:")
        for tiempo in tiempos[i]:
            print(f"{tiempo:.6f}", end=" ,")
        print()
