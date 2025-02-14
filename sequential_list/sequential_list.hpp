#pragma once

#include <iostream>

class SequentialList
{
  public:
    SequentialList();                           // Construtor que inicia a lista vazia

    bool isEmpty();                             // Verifica se a lista está vazia
    bool isFull();                              // Verifica se a lista está cheia
    int size();                                 // Retorna o tamanho da lista
    int getElement(int index);                  // Retorna o elemento de uma posição
    bool changeElement(int index, int value);   // Modifica o valor do elemento de uma posição
    bool insert(int index, int value);          // Insere um elemento em uma posição
    int remove(int index);                      // Remove o elemento de uma posição
    void print();                               // Imprime o conteúdo da lista

  private:
    static const int maxSize = 100;             // Tamanho máximo da lista
    int curSize = 0;                            // Tamanho atual da lista
    int arr[maxSize];                           // Array com os elementos da lista
  };
