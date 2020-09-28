
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "MaxHeap.h"

using namespace std;

// TO BE COMPLETED

// TODO -create(int n) needs to allocate memory for the projectList using the 
// parameter n, and also initialize the currentSize to 0, and the maxSize to the 
// parameter n.

// returns left node of parent node
int MaxHeap::getLeftNode(int index)
{
  return (2*index);
}
// returns right node of parent node
int MaxHeap::getRightNode(int index)
{
  return ((2*index) + 1);
}
// returns parent node of index
int MaxHeap::getParentNode(int index)
{
  return (index/2);
}

// Max Heapify starting at the index
void MaxHeap::maxHeapify(Project * otherList, int index)
{
  // gets the left and right nodes of the index
  int l = getLeftNode(index);
  int r = getRightNode(index);

  int largest = 0;

  // boundary check and checks if left node is largest
  if(l <= maxSize && otherList[l].cost > otherList[index].cost)
  {
    largest = l;
  }
  else
  {
    largest = index;
  }

  // boundary check and checks if right node is largest
  if(r <= maxSize && otherList[r].cost > otherList[largest].cost)
  {
    largest = r;
  }
  
  // if i is largest than heap property is good otherwise we must swap with largest
  if(largest != index)
  {
    // temp allocates index properties to be swapped
    int tempCost = otherList[index].cost;
    string tempName = otherList[index].projName;

    // performs the swap between the largest and index
    otherList[index].cost = otherList[largest].cost;
    otherList[index].projName = otherList[largest].projName;

    otherList[largest].cost = tempCost;
    otherList[largest].projName = tempName;

    maxHeapify(otherList, largest);
  }  
}

void MaxHeap::create(int n)
{
  if(n > 0)
  {
    // Initalizes properties of projectList
    currentSize = 0;
    maxSize = n;

    // Allocated memory for the Project array, sets to size maxSize
    projectList = new Project[maxSize];
  }
  else
  {
    cout << "Error: size has to be a positive integer.";
  }
}

// TODO -buildMaxHeap(Project * otherList, int sizeOfOtherList) needs to copy the 
// parameter otherList which is an array of Project to the projectList, and build 
// the max heap of the projectList. This needs to be done in O(n).
void MaxHeap::buildMaxHeap(Project * otherList, int sizeOfOtherList)
{
  for(int i = 0; i < sizeOfOtherList; i++)
  {
    projectList[i] = otherList[i];
  }

  int startingIndex = sizeOfOtherList/2;

  for(int i = startingIndex; i >= 0; i--)
  {
    maxHeapify(otherList, i);
  }

  currentSize = sizeOfOtherList; // sets the current size
}

// insert new project
void MaxHeap::maxHeapInsert(string newProjectName, int newCost, string print)
{
  Project newProject; // creates new project

  newProject.cost = newCost;
  newProject.projName = newProjectName;

  if(print == "yes")
  {
    cout << "Before Insert:" << endl;
    printMaxHeap();
  }

  currentSize += 1; // current size will increase since we are adding a project
  maxSize += 1; // max size will increase since we are adding a project

  projectList[maxSize] = newProject; // sets the last node equal to the new project obj
  maxHeapify(projectList, maxSize); // Heapifys the last node we inserted

  if(print == "yes")
  {
    cout << "After Insert:" << endl;
    printMaxHeap();
  }
  
}

// extract max returns the max cost of all projects and deletes project.
int MaxHeap::extractMax(string print)
{
  //checks if the heap is empty
  if(currentSize < 1)
  {
    cout << "Error: no element in heap.";
    return;
  }

  int maxCost = projectList[1].cost; // stores the max cost assumes max heap property

  if(print == "yes")
  {
    cout << "Before Max Extraction:" << endl;
    printMaxHeap();
  }

  projectList[1] = projectList[maxSize]; // sets last node to root node
  maxSize -= 1; // sets size of heap to one smaller

  maxHeapify(projectList, 1); // maxHeapify root node since value was changed

  if(print == "yes")
  {
    cout << "After Max Extraction:" << endl;
    printMaxHeap();
  }

  currentSize -= 1; // removes one from current size

  return maxCost;
}

// increase the cost of a project and sort to be max heap
void MaxHeap::increaseKey(int index, int newCost, string print)
{
  // checks if the heap is empty
  if(currentSize < 1)
  {
    cout << "Error: no element in heap.";
    return;
  }

  // checks if newCost is smaller than current cost
  if(projectList[index].cost > newCost)
  {
    cout << "Error: New cost has to be larger than current cost.";
    return;
  }

  if(print == "yes")
  {
    cout << "Before Increase:" << endl;
    printMaxHeap();
  }

  projectList[index].cost = newCost; // changes the cost of project at index with new cost
  maxHeapify(projectList, index);

  if(print == "yes")
  {
    cout << "After Increase:" << endl;
    printMaxHeap();
  }
}

// Prints the max heap
void MaxHeap::printMaxHeap() 
{
  if (projectList == NULL) 
  {
    cout << "The heap is empty" << endl;
  }
  else 
  {
    cout << "Max Size: " << maxSize << endl;
    cout << "Current Size: " << currentSize << endl;
    int nextline = 1;
    if (projectList != NULL && currentSize > 0) 
    {
        for (int i = 1; i <= currentSize; i = i*2) 
        {
          int k = i;
          while (k < i+nextline && k <= currentSize)
          {
                cout << std::left << setw(8) << projectList[k].projName;
                k++;
          }
          cout << endl; 
          k = i;
          while (k < i+nextline && k <= currentSize)
          {
                cout << std::left << setw(8) << projectList[k].cost;
                k++;
          }
          cout << endl; 
          nextline *= 2;
        }
    }
    cout << endl;
  }
}
