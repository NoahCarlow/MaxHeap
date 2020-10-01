
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
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
    maxHeapify(projectList, i);
  }
  currentSize = sizeOfOtherList; // sets the current size

  //delete[] otherList;
}

// insert new project
void MaxHeap::maxHeapInsert(string newProjectName, int newCost, string print)
{
  // checks if heap has been created if not then maxHeapInsert wont run
  if(maxSize < 0)
  {
    cout << "Error: heap not created" << endl;
  }
  else
  {
    if (currentSize == maxSize)
    {
      if(print == "yes")
      {
        cout << "Before insert operation:" << endl;
        printMaxHeap();
      }

      int exponent = 0;
      while(pow(2, exponent) <= maxSize) // iterates exponent to get correct size to increase the heap by
      {
        exponent += 1;
      }

      maxSize = pow(2, exponent);
      int storeCurrentSize = currentSize;

      Project * increaseProjectList;
      increaseProjectList = new Project[maxSize + 1]; // create new array with bigger size

      // initalizes data into new sized project list
      for(int i = 0; i < maxSize + 1; i++) // we go to maxSize + 1 because we want our root node at 1 and 0 index to be NULL
      {
        increaseProjectList[i].cost = 0;
        increaseProjectList[i].projName = "";
      }

      // copies the content of current project list into the bigger sized list
      for(int i = 1; i <= currentSize; i++)
      {
        increaseProjectList[i] = projectList[i];
      }
      create(maxSize);
      currentSize = storeCurrentSize + 1;

      // copies data back into projectList after creating new array size
      for(int i = 1; i < currentSize; i++)
      {
        projectList[i] = increaseProjectList[i];
      }

      //delete[] increaseProjectList;
    }
    else
    {
      currentSize += 1; // current size will increase since we are adding a project

      if(print == "yes")
      {
        cout << "Before insert operation:" << endl;
        printMaxHeap();
      }
    }

    Project newProject; // creates new project

    newProject.cost = newCost;
    newProject.projName = newProjectName;

    projectList[currentSize] = newProject; // sets the last node equal to the new project obj
    buildMaxHeap(projectList, currentSize); // Heapifys the last node we inserted

    if(print == "yes")
    {
      cout << "After insert operation:" << endl;
      printMaxHeap();
    }
  }
}

// extract max returns the max cost of all projects and deletes project.
int MaxHeap::extractMax(string print)
{
  int maxCost = 0;
  //checks if the heap is empty
  if(maxSize < 0)
  {
    cout << "Error: heap not created" << endl;
    return 1;
  }
  else
  {
    maxCost = projectList[1].cost; // stores the max cost assumes max heap property

    if(print == "yes")
    {
      cout << "Before extract max operation:" << endl;
      printMaxHeap();
    }

    currentSize--; // removes one from current size
    projectList[1] = projectList[currentSize + 1]; // sets last node to root node

    buildMaxHeap(projectList, currentSize); // maxHeapify root node since value was changed

    if(print == "yes")
    {
      cout << "After extract max operation:" << endl;
      printMaxHeap();
    }
    cout << "Extract Max = " << maxCost << endl;

    return maxCost;
  }
}

// increase the cost of a project and sort to be max heap
void MaxHeap::increaseKey(int index, int newCost, string print)
{
  // checks if the heap is empty
  if(maxSize < 0)
  {
    cout << "Error: heap not created" << endl;
    return;
  }
  else
  {
    // checks if newCost is smaller than current cost
    if(projectList[index].cost > newCost)
    {
      cout << "Error: new cost is smaller than current cost" << endl;
      return;
    }

    if(print == "yes")
    {
      cout << "Before increase operation:" << endl;
      printMaxHeap();
    }

    projectList[index].cost = newCost; // changes the cost of project at index with new cost
    buildMaxHeap(projectList, currentSize);

    if(print == "yes")
    {
      cout << "After increase operation:" << endl;
      printMaxHeap();
    }
  }
}

// Prints the max heap
void MaxHeap::printMaxHeap() 
{
  if (maxSize < 0) 
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
