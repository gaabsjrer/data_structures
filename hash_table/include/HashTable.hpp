#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <string>

// Nó da lista do 2º nível
struct Item {
    int key;
    std::string value;
    Item* next;
};

// Tabela de 2º nível: vetor de listas
class Level2Table {
public:
    Level2Table(int size);
    ~Level2Table();

    void insert(int key, const std::string& value);
    bool get(int key, std::string& value) const;

private:
    int size_;       // número de buckets = n/10
    Item** buckets_; // array de ponteiros para lista
    int hash2(int key) const;
};

// Tabela de 1º nível: vetor de 10 ponteiros para Level2Table
class HashTable {
public:
    HashTable(int n);
    ~HashTable();

    void insert(int key, const std::string& value);
    bool get(int key, std::string& value) const;

private:
    int n_;                    // capacidade total
    Level2Table* level1_[10];  // 10 ponteiros para tabelas de 2º nível
    int hash1(int key) const;
};

#endif // HASHTABLE_HPP
