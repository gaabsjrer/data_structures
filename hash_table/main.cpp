#include <iostream>
#include "src/HashTable.cpp"

int main() {
    // Exemplo com capacidade total n = 100
    HashTable table(100);

    // Inserções
    table.insert(1, "Alice");
    table.insert(12, "Bob");
    table.insert(23, "Carol");
    table.insert(34, "Dave");

    // Recuperações de teste
    int keysToFind[] = {12, 99};
    for (int i = 0; i < 2; ++i) {
        int k = keysToFind[i];
        std::string name;
        if (table.get(k, name))
            std::cout << "Chave " << k << ": " << name << std::endl;
        else
            std::cout << "Chave " << k << " não encontrada." << std::endl;
    }
    return 0;
}
