Name: Noah Carlow

Max Heap Description: A max-heap is a complete binary tree in which the value in each internal node is greater than or equal to the values in the children of that node.

Functions:
  -  int getLeftNode(int index);
  -  int getRightNode(int index);
  -  int getParentNode(int index);
  -  void maxHeapify(Project * otherList, int index);
  -  void create(int n);
  -  void buildMaxHeap(Project * otherList, int sizeOfOtherList);
  -  void printMaxHeap();
  -  int extractMax(string print);
  -  void maxHeapInsert(string newProjectName, int newCost, string print);
  -  void increaseKey(int index, int newCost, string print);

  -------Function Descriptions:-------

  int getLeftNode(int index); - This function will return the left node of the parent by performing the operatin 2*index

  int getRightNode(int index); - This function will return the right node of the parent by performing the operatin 2*index + 1

  int getParentNode(int index); - This function will return the parent node of the parent by performing the operatin floor(index/2)

  void maxHeapify(Project * otherList, int index); - This function will heapify the node and any effected children

  void create(int n); - This function creates an empty heap and initailizes the heap size and the max size

  void buildMaxHeap(Project * otherList, int sizeOfOtherList); - This function will traverse through an entire array and heapify it

  void printMaxHeap(); - This function will print the heap

  int extractMax(string print); - This function will extract the max value of the heap a.k.a. the root node and delete it and bring current size down by 1

  void maxHeapInsert(string newProjectName, int newCost, string print); - This function will insert a new node in the correct heap order

  void increaseKey(int index, int newCost, string print); - This function increases the value of a node at the given index

  -------HOW TO RUN-------
  You can compile all the files using the command 'make' then run using './assignment4'
