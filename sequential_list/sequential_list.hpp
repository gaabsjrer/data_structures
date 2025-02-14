#pragma once

#include <iostream>

using namespace std;

class SequentialList
{
  public:
    SequentialList();

    bool isEmpty();                         // Verifica se a lista está vazia
    bool isFull();                          // Verifica se a lista está cheia
    int size();                             // Retorna o tamanho da lista
    int getElement(int index);              // Retorna o elemento de uma posição
    int changeElement(int index, int value);    // Modifica o valor do elemento de uma posição
    int insert(int index, int value);           // Insere um elemento da posição
    int remove(int index);                  // Remove um elemento da posição
    void print();                           // Imprime o conteúdo da lista

  private:
    int maxSize = 100;                      // Tamanho máximo da lista
    int curSize = 0;                        // Tamanho atual da lista
    int arr[maxSize];                       // Array com os elementos da lista
}


