
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
  if(l <= currentSize && otherList[l].cost > otherList[index].cost)
  {
    largest = l;
  }
  else
  {
    largest = index;
  }

  // boundary check and checks if right node is largest
  if(r <= currentSize && otherList[r].cost > otherList[largest].cost)
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
  if(n >= 0)
  {
    // Initalizes properties of projectList
    currentSize = 0;
    maxSize = n;

    // Allocated memory for the Project array, sets to size maxSize
    projectList = new Project[maxSize + 1]; // array is set one size bigger to take into account 0 index being NULL

    // fills project with default data so array isn't garbage
    for(int i = 0; i < maxSize + 1; i++) // we go to maxSize + 1 because we want our root node at 1 and 0 index to be NULL
    {
      projectList[i].cost = 0;
      projectList[i].projName = "";
    }
  }
  else
  {
    cout << "Error: invalid heap capacity\n";
  }
}

// TODO -buildMaxHeap(Project * otherList, int sizeOfOtherList) needs to copy the 
// parameter otherList which is an array of Project to the projectList, and build 
// the max heap of the projectList. This needs to be done in O(n).
void MaxHeap::buildMaxHeap(Project * otherList, int sizeOfOtherList)
{
  for(int i = 1; i <= sizeOfOtherList; i++)
  {
    projectList[i] = otherList[i];
  }

  int startingIndex = sizeOfOtherList/2;

  for(int i = startingIndex; i >= 1; i--)
  {
    maxHeapify(otherList, i);
  }
  currentSize = sizeOfOtherList; // sets the current size

  delete otherList;
}

// insert new project
void MaxHeap::maxHeapInsert(string newProjectName, int newCost, string print)
{
  // checks if heap has been created if not then maxHeapInsert wont run
  if(maxSize == 0)
  {
    cout << "Error: heap not created" << endl;
  }
  else
  {
    if (currentSize == maxSize)
    {
      // TODO PWER OF 2 THING HERE
    }

    Project newProject; // creates new project

    newProject.cost = newCost;
    newProject.projName = newProjectName;

    if(print == "yes")
    {
      cout << "Before Insert:" << endl;
      printMaxHeap();
    }

    currentSize += 1; // current size will increase since we are adding a project

    projectList[currentSize] = newProject; // sets the last node equal to the new project obj
    buildMaxHeap(projectList, currentSize); // Heapifys the last node we inserted

    if(print == "yes")
    {
      cout << "After Insert:" << endl;
      printMaxHeap();
    }
  }
}

// extract max returns the max cost of all projects and deletes project.
int MaxHeap::extractMax(string print)
{
  int maxCost = 0;
  //checks if the heap is empty
  if(maxSize == 0)
  {
    cout << "Error: heap not created" << endl;
    return 1;
  }
  else
  {
    maxCost = projectList[1].cost; // stores the max cost assumes max heap property

    if(print == "yes")
    {
      cout << "Before Max Extraction:" << endl;
      printMaxHeap();
    }

    currentSize--; // removes one from current size
    projectList[1] = projectList[currentSize + 1]; // sets last node to root node

    buildMaxHeap(projectList, currentSize); // maxHeapify root node since value was changed

    if(print == "yes")
    {
      cout << "After Max Extraction:" << endl;
      printMaxHeap();
      cout << "Extract Max = " << maxCost << endl;
    }

    return maxCost;
  }
}

// increase the cost of a project and sort to be max heap
void MaxHeap::increaseKey(int index, int newCost, string print)
{
  // checks if the heap is empty
  if(maxSize == 0)
  {
    cout << "Error: heap not created" << endl;
    return;
  }
  else
  {
    // checks if newCost is smaller than current cost
    if(projectList[index].cost > newCost)
    {
      cout << "Error: New cost has to be larger than current cost." << endl;
      return;
    }

    if(print == "yes")
    {
      cout << "Before Increase:" << endl;
      printMaxHeap();
    }

    projectList[index].cost = newCost; // changes the cost of project at index with new cost
    buildMaxHeap(projectList, currentSize);

    if(print == "yes")
    {
      cout << "After Increase:" << endl;
      printMaxHeap();
    }
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
