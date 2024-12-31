#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono> 

using namespace std;

vector<long long int> read_file(const string &file_name) {
    vector<long long int> data; 
    ifstream file(file_name);

    if (!file.is_open()) { 
        cerr << "Erro ao abrir o arquivo: " << file_name << endl;
        return data; 
    }

    string line;
    while (getline(file, line)) {

        long long int value = stoll(line); 
        data.push_back(value); 
    }

    return data; 
}

void insertion_sort(vector<long long int>& A) {
    for (size_t i = 1; i < A.size(); ++i) {
        long long int aux = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > aux) {
            A[j + 1] = A[j];
            --j;
        }

        A[j + 1] = aux;
    }
}

void selection_sort(vector<long long int>& A) {
    for (size_t i = 0; i < A.size(); ++i) {
        long long int cur_minimum = i;

        for (size_t j = i + 1; j < A.size(); ++j) {
            if (A[j] < A[cur_minimum]) {
                cur_minimum = j;
            }
        }

        swap(A[i], A[cur_minimum]);
    }
}

double measure_sort_time(void (*sort_function)(vector<long long int>&), vector<long long int>& data) {
    vector<long long int> data_copy = data;
    auto start_time = chrono::high_resolution_clock::now(); 
    sort_function(data_copy); 
    auto end_time = chrono::high_resolution_clock::now();  
    chrono::duration<double> duration = end_time - start_time; 
    return duration.count(); 
}

int main() {
    vector<string> files = {
        "instancias-num/num.1000.1.in", "instancias-num/num.1000.2.in", "instancias-num/num.1000.3.in", "instancias-num/num.1000.4.in",
        "instancias-num/num.10000.1.in", "instancias-num/num.10000.2.in", "instancias-num/num.10000.3.in", "instancias-num/num.10000.4.in",
        "instancias-num/num.100000.1.in", "instancias-num/num.100000.2.in", "instancias-num/num.100000.3.in", "instancias-num/num.100000.4.in"
    };

    for (int i = 0; i < files.size(); ++i) {
        vector<long long int> data = read_file(files[i]);

        double insertion_time = measure_sort_time(insertion_sort, data);
        double selection_time = measure_sort_time(selection_sort, data);

        cout << "Arquivo " << i + 1 << " (Elementos: " << data.size() << "):" << endl;
        cout << "   Insertion Sort: " << insertion_time << " segundos" << endl;
        cout << "   Selection Sort: " << selection_time << " segundos" << endl << endl;
    }

    return 0;
}
