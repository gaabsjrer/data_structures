#include "sequential_list"
#include <iostream>

using namespace std;

SequentialList::SequentialList()
{
  curSize = 0;
}

bool SequentialList::isEmpty()
{
  if(curSize == 0)
    return true;

  return false;
}

bool SequentialList::isFull()
{
  if(curSize == maxSize)
    return true;

  return false;
}

int SequentialList::size()
{
  return curSize;
}

int SequentialList::getElement(int index)
{}

int SequentialList::changeElement(int index, int value)
{}

int SequentialList::insert(int index. int value)
