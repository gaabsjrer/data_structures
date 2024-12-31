def selection_sort(A, n):

    for i in range(n):
        cur_minimum = i

        for j in range(i+1, n):
            if A[j] < A[cur_minimum]:
                cur_minimum = j

        A[i], A[cur_minimum] = A[cur_minimum], A[i]

    return A