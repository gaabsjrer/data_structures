def vetor(f):
    file = open(f, "r")
    A = []

    line = file.readline()

    while line:
        A.append(line.strip())
        line = file.readline() 

    file.close()

    return A

f = "sort_algorithms/instancias-num/num.1000.1.in"