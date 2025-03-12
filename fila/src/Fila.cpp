#include "../include/Fila.hpp"

Fila::Fila() {
    frente = 0;
    tras = -1;
}

bool Fila::estaVazia() const {
    return frente > tras;
}

bool Fila::estaCheia() const {
    return tras == MAX_SIZE - 1;
}

int Fila::tamanho() const {
    return estaVazia() ? 0 : (tras - frente + 1);
}

int Fila::frenteElemento() const {
    if (estaVazia()) {
        throw std::runtime_error("Fila vazia! Não há elemento na frente.");
    }
    return dados[frente];
}

void Fila::enfileirar(int valor) {
    if (estaCheia()) {
        throw std::runtime_error("Fila cheia! Não é possível enfileirar.");
    }
    dados[++tras] = valor;
}

void Fila::desenfileirar() {
    if (estaVazia()) {
        throw std::runtime_error("Fila vazia! Não é possível desenfileirar.");
    }
    frente++;
}

void Fila::imprimir() const {
    if (estaVazia()) {
        std::cout << "Fila vazia!" << std::endl;
        return;
    }
    std::cout << "Fila: ";
    for (int i = frente; i <= tras; i++) {
        std::cout << dados[i] << " ";
    }
    std::cout << std::endl;
}

