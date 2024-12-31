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