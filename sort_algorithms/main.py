import timeit as t

setup_insertion = "from insertion import insertion_sort"

code_insertion = '''
A = [2,8,5,3,9,4,1]
insertion_sort(A, len(A))
'''

setup_selection = "from selection import selection_sort"

code_selection = '''
A = [2,8,5,3,9,4,1]
selection_sort(A, len(A))
'''

print("insertion time: ", t.timeit(setup=setup_insertion, stmt=code_insertion))
print("selection time: ", t.timeit(setup=setup_selection, stmt=code_selection))