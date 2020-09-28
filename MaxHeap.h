

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

    //TO BE COMPLETED
    int getLeftNode(int index);
    int getRightNode(int index);
    int getParentNode(int index);
    void maxHeapify(Project * otherList, int index);
    void create(int n);
    void buildMaxHeap(Project * otherList, int sizeOfOtherList);
    void printMaxHeap();
    int extractMax(string print);
    void maxHeapInsert(string newProjectName, int newCost, string print);
    void increaseKey(int index, int newCost, string print);

};

#endif 
