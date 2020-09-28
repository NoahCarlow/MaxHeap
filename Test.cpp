#include <iostream>
#include <fstream>
#include <string>
#include "MaxHeap.h"

using namespace std;

int main()
{
    MaxHeap test;
    test.create(5);
    test.printMaxHeap();

    Project *projectList;

    test.buildMaxHeap(projectList, 4);
    test.printMaxHeap();
}