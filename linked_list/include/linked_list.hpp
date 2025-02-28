#pragma once

#include <iostream>
#include <stdlib.h>

class No
{
  public:
    No();

    // gets e sets
    int getConteudo();
    No getProximo();

    void setConteudo();
    void setProximo();

  private:
    int conteudo;
    No proximo;
};

class LinkedList
{
  public:
    LinkedList();
    
    bool vazia();
    int tamanho();
    bool elemento(int pos);
    int modificaElemento(int pos, int valor);
    void insere(int pos, int valor);
    int remove(int pos);
    void print();

  private:
    No cabeca;
    int tamanho;

    bool insereInicioLista(int valor);
    bool insereFimLista(int valor);
    bool insereMeioLista(int pos, int valor);
    
    int removeInicioLista();
    int removeNaLista(int pos);
};
