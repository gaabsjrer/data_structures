#pragma once

#include <iostream>

#define MAX_SIZE 5 // Definição do tamanho máximo da fila

class Fila {
private:
    int dados[MAX_SIZE]; // Array para armazenar os elementos da fila
    int frente; // Índice do primeiro elemento
    int tras;   // Índice do último elemento

public:
    Fila(); // Construtor para criar uma fila vazia
    bool estaVazia() const; // Verifica se a fila está vazia
    bool estaCheia() const; // Verifica se a fila está cheia
    int tamanho() const; // Retorna o tamanho da fila
    int frenteElemento() const; // Retorna o elemento na frente da fila
    void enfileirar(int valor); // Insere um elemento no final da fila
    void desenfileirar(); // Remove o elemento da frente da fila
    void imprimir() const; // Imprime os elementos da fila
};

