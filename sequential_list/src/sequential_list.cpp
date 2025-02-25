#include <iostream>
#include "../include/sequential_list.hpp"

using namespace std;

// inicializa a lista vazia
SequentialList::SequentialList()
{
  curSize = 0;
}

// verifica se a lista está vazia
bool SequentialList::isEmpty()
{
  if(curSize == 0)
    return true;

  return false;
}

// verifica se a lista está cheia
bool SequentialList::isFull()
{
  if(curSize == maxSize)
    return true;

  return false;
}

// retorna o tamanho da lista
int SequentialList::size()
{
  return curSize;
}

// retorna o elemento na posição
int SequentialList::getElement(int index)
{
  if((index > maxSize) || (index<=0))
    return -1;

  return arr[index-1];
}

// 
int SequentialList::changeElement(int index, int value)
{
  int foo;

  if((index > maxSize) || (index<=0))
    return -1;
  
  foo = arr[index-1];

  arr[index-1] = value;

  return foo;
}

bool SequentialList::insert(int index, int value)
{
  if(isFull() || (index > curSize+1) ||(index <= 0))
    return false;
  
  for(int i = curSize; i >= index; i--)
    arr[i] = arr[i-1];

  arr[index-1] = value;
  curSize++;

  return true;
}

int SequentialList::remove(int index)
{
  int foo;

  if((index > curSize) || (index < 1))
    return -1;
  
  foo = arr[index-1];

  for(int i = index-  1; i < curSize - 1; i++)
    arr[i] = arr[i+1];

  curSize--;

  return foo;
}

void SequentialList::print()
{
  cout << "[";

  for(int i = 0; i < curSize; i++)
  {
    if(i == curSize-1)
    {
      cout << arr[i];
      continue;
    }
    cout << arr[i] << ", ";
  }

  cout << "]" << endl;  
}
