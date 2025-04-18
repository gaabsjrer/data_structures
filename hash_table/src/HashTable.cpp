#include "../include/HashTable.hpp"
#include <iostream>

//
// ------ 2º Nível ------
//

Level2Table::Level2Table(int size)
    : size_(size)
{
    buckets_ = new Item*[size_];
    for (int i = 0; i < size_; ++i)
        buckets_[i] = nullptr;
}

Level2Table::~Level2Table() {
    for (int i = 0; i < size_; ++i) {
        Item* node = buckets_[i];
        while (node) {
            Item* tmp = node;
            node = node->next;
            delete tmp;
        }
    }
    delete[] buckets_;
}

int Level2Table::hash2(int key) const {
    if (key < 0) key = -key;
    return key % size_;
}

void Level2Table::insert(int key, const std::string& value) {
    int idx = hash2(key);
    // atualiza se já existir
    for (Item* node = buckets_[idx]; node; node = node->next) {
        if (node->key == key) {
            node->value = value;
            return;
        }
    }
    // senão insere no início
    Item* novo = new Item{key, value, buckets_[idx]};
    buckets_[idx] = novo;
}

bool Level2Table::get(int key, std::string& value) const {
    int idx = hash2(key);
    for (Item* node = buckets_[idx]; node; node = node->next) {
        if (node->key == key) {
            value = node->value;
            return true;
        }
    }
    return false;
}

//
// ------ 1º Nível ------
//

HashTable::HashTable(int n)
    : n_(n)
{
    int subSize = n_ / 10;  // assume n múltiplo de 10
    for (int i = 0; i < 10; ++i)
        level1_[i] = new Level2Table(subSize);
}

HashTable::~HashTable() {
    for (int i = 0; i < 10; ++i)
        delete level1_[i];
}

int HashTable::hash1(int key) const {
    if (key < 0) key = -key;
    return key % 10;
}

void HashTable::insert(int key, const std::string& value) {
    int idx = hash1(key);
    level1_[idx]->insert(key, value);
}

bool HashTable::get(int key, std::string& value) const {
    int idx = hash1(key);
    return level1_[idx]->get(key, value);
}
