import time

files = [
    f"instancias-num/num.{size}.{i}.in"
    for size in [1000, 10000, 100000]
    for i in range(1, 5)
]

vet = [
    [int(line.strip()) for line in open(file_name, "r")]
    for file_name in files
]

def insertion_sort(A):

    for i in range(1, len(A)):
        aux = A[i]
        j = i - 1

        while j >= 0 and A[j] > aux:
            A[j + 1] = A[j]
            j -= 1

        A[j + 1] = aux
    
    return A

def selection_sort(A):

    for i in range(len(A)):
        cur_minimum = i

        for j in range(i+1, len(A)):
            if A[j] < A[cur_minimum]:
                cur_minimum = j

        A[i], A[cur_minimum] = A[cur_minimum], A[i]

    return A

def measure_sort_time(sort_function, data):

    data_copy = data.copy() 
    start_time = time.time()
    sort_function(data_copy)
    end_time = time.time()

    return end_time - start_time

for i, data in enumerate(vet):       
    insertion_time = measure_sort_time(insertion_sort, data)
    selection_time = measure_sort_time(selection_sort, data)

    print(f"Arquivo {i + 1} (Elementos: {len(data)}): ")
    print(f"   Insertion Sort: {insertion_time:.5f} segundos")
    print(f"   Selection Sort: {selection_time:.5f} segundos\n")
