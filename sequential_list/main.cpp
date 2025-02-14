#include <iostream>
#include "sequential_list.hpp"

using namespace std;

#define SIZE_LIST 10

int main()
{
  SequentialList list;
  
  // insere 10 números na lista
  for(int i = 1; i <= SIZE_LIST; i++)
  {
    list.insert(1, i);
  }

  list.print();

  cout << "Inserting 90 in index 11: " << endl;
  list.insert(11, 90);
  list.print();
  cout << endl;

  cout << "Inserting 100 in index 4: " << endl; 
  list.insert(4, 100);
  list.print();
  cout << endl;
  
  cout << "Removing element " << list.remove(4) << " in index 4: " << endl; 
  list.print();
  cout << endl;

  cout << "Element in index 5: " << list.getElement(5) << endl;
  list.print();
  cout << endl;

  cout << "Changing the 5th element in the list to 200: " << endl;
  list.changeElement(5, 200);
  list.print();
  cout << endl;
}
