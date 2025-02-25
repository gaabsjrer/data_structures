#include <iostream>
#include "src/sequential_list.cpp"

using namespace std;

#define SIZE_LIST 10

int main()
{
  SequentialList list;
  
  cout << "My list: " << endl;

  // insere 10 números na lista
  for(int i = 1; i <= SIZE_LIST; i++)
  {
    list.insert(1, i);
  }

  list.print();
  cout << endl;
  
  // insere 90 no final da lista
  cout << "Inserting 90 in index 11: " << endl;
  list.insert(11, 90);
  list.print();
  cout << endl;

  // insere 100 na posição 4 da lista
  cout << "Inserting 100 in index 4: " << endl; 
  list.insert(4, 100);
  list.print();
  cout << endl;
  
  // remove o elemento da posição 4 da lista 
  cout << "Removing element " << list.remove(4) << " in index 4: " << endl; 
  list.print();
  cout << endl;
  
  // pega o elemento da posição 5
  cout << "Element in index 5: " << list.getElement(5) << endl;
  list.print();
  cout << endl;
  
  // muda o elemento da posição 5 para 200
  cout << "Changing the 5th element (" << list.changeElement(5, 200) << ") in the list to 200: " << endl;
  list.print();
  cout << endl;
}
