def insertion_sort(A, n):
    aux = 0

    for i in range(1, n-1):
        aux = A[i]
        j = i-1

        while j >= 0 and A[j] > aux:
            A[j+1] = A[j]
            j = j-1

        A[j+1] = aux
    
    return A

A = [2,8,5,3,9]
print("não ordenado: ", A)

print("ordenado: ", insertion_sort(A, len(A)))