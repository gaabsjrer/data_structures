import time

files = [
    f"sort_algorithms/instancias-num/num.{size}.{i}.in"
    for size in [1000, 10000, 100000]
    for i in range(1, 5)
]

vet = [
    [int(line.strip()) for line in open(file_name, "r")]
    for file_name in files
]

def insertion_sort(A, n):

    for i in range(1, n):
        aux = A[i]
        j = i - 1

        while j >= 0 and A[j] > aux:
            A[j + 1] = A[j]
            j -= 1

        A[j + 1] = aux
    
    return A

def selection_sort(A, n):

    for i in range(n):
        cur_minimum = i

        for j in range(i+1, n):
            if A[j] < A[cur_minimum]:
                cur_minimum = j

        A[i], A[cur_minimum] = A[cur_minimum], A[i]

    return A

def measure_sort_time(sort_function, data, n):

    data_copy = data.copy() 
    start_time = time.time()
    sort_function(data_copy, n)
    end_time = time.time()

    return end_time - start_time

for i, data in enumerate(vet):       
    try:
        print(f"📊 Arquivo {i + 1} (Elementos: {len(data)})")
        
        insertion_time = measure_sort_time(insertion_sort, data, len(data))
        print(f"   Insertion Sort: {insertion_time:.5f} segundos")
        
        selection_time = measure_sort_time(selection_sort, data, len(data))
        print(f"   Selection Sort: {selection_time:.5f} segundos\n")
    
    except ValueError:
        print(f"⚠️ O arquivo {i + 1} contém dados não numéricos e foi ignorado.")
    except MemoryError:
        print(f"❌ O arquivo {i + 1} é muito grande e causou um erro de memória.")
