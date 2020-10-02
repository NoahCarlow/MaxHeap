

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <string>
using namespace std;

// struct Project
struct Project {
    int cost;
    string projName;
};

// create a MaxHeap
struct MaxHeap {
    int maxSize;
    int currentSize;
    struct Project * projectList;

    // This function will return the left node of the parent by performing the operatin 2*index
    int getLeftNode(int index);

    // This function will return the right node of the parent by performing the operatin 2*index + 1
    int getRightNode(int index);

    // This function will return the parent node of the parent by performing the operatin floor(index/2)
    int getParentNode(int index);

    // This function will heapify the node and any effected children
    void maxHeapify(Project * otherList, int index);

    // This function creates an empty heap and initailizes the heap size and the max size
    void create(int n);

    // This function will traverse through an entire array and heapify it
    void buildMaxHeap(Project * otherList, int sizeOfOtherList);

    // This function will print the heap
    void printMaxHeap();

    // This function will extract the max value of the heap a.k.a. the root node and delete it and bring current size down by 1
    int extractMax(string print);

    // This function will insert a new node in the correct heap order
    void maxHeapInsert(string newProjectName, int newCost, string print);

    // This function increases the value of a node at the given index
    void increaseKey(int index, int newCost, string print);

};

#endif 
