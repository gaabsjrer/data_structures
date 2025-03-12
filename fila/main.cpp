#include "src/Fila.cpp"

int main() {
    Fila fila;

    std::cout << "Fila criada!" << std::endl;
    fila.imprimir();

    // Testando enfileirar
    std::cout << "Inserindo elementos..." << std::endl;
    fila.enfileirar(10);
    fila.enfileirar(20);
    fila.enfileirar(30);
    fila.enfileirar(40);
    fila.enfileirar(50);
    
    fila.imprimir();

    // Tentativa de enfileirar com a fila cheia
    try {
        fila.enfileirar(60);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Consultar elemento na frente
    std::cout << "Elemento na frente: " << fila.frenteElemento() << std::endl;

    // Remover elementos
    std::cout << "Removendo elementos..." << std::endl;
    fila.desenfileirar();
    fila.desenfileirar();

    fila.imprimir();

    // Testando se a fila está vazia
    std::cout << "A fila está vazia? " << (fila.estaVazia() ? "Sim" : "Não") << std::endl;
    
    return 0;
}

