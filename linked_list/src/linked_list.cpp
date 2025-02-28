#include "../include/linked_list.hpp"

No::No()
{
  proximo = NULL;
}

int No::getConteudo()
{
  return conteudo;
}

No No::getProximo()
{
  return proximo;
}

void No::setConteudo(int n)
{
  conteudo = n;
}
void No::setProximo(No n)
{
  proximo = n;
}

LinkedList::LinkedList()
{
  cabeca = NULL;
  tamanho = 0;
}

bool LinkedList::vazia()
{
   if(tamanho == 0)
     return true;
   
   return false;
}

int LinkedList::tamanho()
{
  return tamanho;
}

int LinkedList::elemento(int pos)
{
  No aux = cabeca;
  int count = 1;

  if(vazia ()) return -1;

  if ((pos < 1) || (pos > tamanho))
    return -1;

  while(count < pos)
  {
    aux = aux.getProximo();
    count++;
  }

  return aux.getConteudo;
}

int LinkedList::modificaElemento(int pos, int valor)
{
}

void LinkedList::insere(int pos, int valor)
{
  if (vazia() && (pos != 1))
    return false;

  if (pos == 1)
    return insereInicioLista(dado);
  
  if (pos == tamanho + 1)
    return insereFimLista();

  else
    return insereMeioLista();
}

int LinkedList::remove(int pos)
{
  if (vazia())
    return -1;

  if (pos == 1)
    return removeInicioLista();

  else
    return removeNaLista(pos);
}

bool LinkedList::insereInicioLista(int valor);
{
  No* novoNo = new No();

  novoNo->setConteudo(valor);
  novoNo->setProx(cabeca);
  cabeca = novoNo;
  tamanho++;

  return true;
}

bool LinkedList::insereFimLista(int valor);
{
  No* novoNo = new No();
  novoNo->setConteudo(dado);

  No* aux = cabeca;

  while (aux->getProx() != nullptr)
    aux = aux->getProx();

  novoNo->setProx(nullptr);
  aux->setProx(novoNo);
  tamanho++;

  return true;
}

bool LinkedList::insereMeioLista(int pos, int valor);
{
  int cont = 1;
  No* novoNo = new No(); 
  novoNo->setConteudo(valor);

  No* aux = cabeca;

  while ((cont < pos - 1) && (aux != nullptr)) 
  {
    aux = aux->getProx();
    cont++;
  }

  if (aux == nullptr) return false;

  novoNo->setProx(aux->getProx());
  aux->setProx(novoNo);
  tamanho++;

  return true;
}

int LinkedList::removeInicioLista();
{
  No* p = cabeca;
  int dado = p->getConteudo();

  cabeca = p->getProx();
  tamanho--;

  delete p;

  return dado;   
}

int LinkedList::removeNaLista();
{
  No* atual = nullptr;
  No* antecessor = nullptr;
  int dado = -1, cont = 1;

  atual = cabeca;

  while ((cont < pos) && (atual != nullptr)) 
  {
    antecessor = atual;
    atual = atual->getProx();
    cont++;
  }

  if (atual == nullptr)
    return -1;
  
  dado = atual->getConteudo();

  if (antecessor != nullptr) 
    antecessor->setProx(atual->getProx());

  else 
    cabeca = atual->getProx();

  tamanho--;

  delete atual;

  return dado; 
}

void LinkedList::print()
{

}
