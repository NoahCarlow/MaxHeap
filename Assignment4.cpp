#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "MaxHeap.h"

using namespace std;

string nextCommand(int * n, int * index, int * newCost, string * printCommand, string * newProjName);


int main() {
    int n, index, newCost;
    string command, newProjName, printCommand;

    //declare variables
    MaxHeap myHeap;
    myHeap.currentSize = 0;
    myHeap.maxSize = -1; // value starts at -1 for conditions on heap being empty in MaxHeap.cpp


    while (true) {
        command = nextCommand(&n, &index, &newCost, &printCommand, &newProjName);
        //command = command.toLower();
        if (command == "quit")
         {
                cout << "Next Command: " << command << endl;

                return 0;
         }

         else if (command == "insert")
         {
                if (printCommand == "yes" || printCommand == "no")
                {
                    cout << "Next Command: " << command << " " << newProjName << " " << newCost << " " << printCommand << endl;
                    myHeap.maxHeapInsert(newProjName, newCost, printCommand);
                }
                else
                {
                    cout << "Error: invalid print command" << endl;
                }
                continue;
         }

         else if (command == "create")
         {
                cout << "Next Command: " << command << " " << n << endl;
                myHeap.create(n);
                continue;
         }

         else if (command == "print")
         {
                cout << "Next Command: " << command << endl;
                myHeap.printMaxHeap();
                continue;
         }

         else if (command == "extractmax") 
         {
                if ((printCommand == "yes" || printCommand == "no"))
                {
                    cout << "Next Command: " << command << " " << printCommand << endl;
                    myHeap.extractMax(printCommand);
                }
                else
                {
                    if (myHeap.maxSize == -1) {
                        cout << "Error: heap not created" << endl;
                    }
                    else
                    {
                        cout << "Error: invalid print command" << endl;
                    }
                }
                continue;
         }

         else if (command == "increase") 
         {
                if ((printCommand == "yes" || printCommand == "no") && index > 0)
                {
                    cout << "Next Command: " << command << " " << index << " " << newCost << " " << printCommand << endl;
                    myHeap.increaseKey(index, newCost, printCommand);
                }
                else if (index <= 0)
                {
                    cout << "Error: invalid index" << endl;
                }
                else
                {
                    if (myHeap.maxSize == -1) {
                        cout << "Error: heap not created" << endl;
                    }
                    else
                    {
                        cout << "Error: invalid print command" << endl;
                    }
                }
                continue;
         }

         else if(command == "fileread") {
             cout << "Next Command: " << command << endl;

             ifstream file("heapInfo.txt");
             string fileLine;
             string name;
             string key;
             int updateCost;
             int sizeOfFile;
             int i = 0;

             while (getline(file, fileLine)) {

                // parses the data from the file
                stringstream ss(fileLine);
                getline(ss, name, ' ');
                getline(ss, key, '\n');

                // the purpose of this loop is that the size of the file is read from line one then the rest of the file is read and stored
                istringstream(key) >> updateCost;
                if (i < 1) {
                    istringstream(name) >> sizeOfFile;
                    i++;
                }
                else if (i >= 1) {
                    if (myHeap.maxSize == -1) {
                        cout << "Error: heap not created" << endl;
                        break;
                    }
                    else if (sizeOfFile > myHeap.maxSize) {
                        cout << "Error: array size exceeds heap capacity" << endl;
                        break;
                    }
                    else {
                        myHeap.maxHeapInsert(name, updateCost, "no");
                    }
                } 
             }
             continue;
         }

         else
         {
            break;
          }
        }

        return 0;
    
}

//The following is a partial program for readinng in the commands from the keyboard.
//You need to add more code
string nextCommand(int * n, int * index, int * newCost, string * printCommand, string * newProjName) 
{
    string command = "?";

    while(true) {
        cin >> command;
        
        //empty space, tab, return
        if (command == " " || command == "\t" || command == "\n") {
            continue;
        }

        if (command == "quit" || command == "fileread" || command == "print") {
            break;
        }
       
        if (command == "insert") {
            cin >> *newProjName;
            cin >> *newCost;
            cin >> *printCommand;
            break;
        }   

        //COMPLETE OTHER CASES
       
        if (command == "create") {
            cin >> *n;
            break;
        }

        if(command == "print") {
            cin >> *printCommand;
            break;
        }

        if(command == "extractmax") {
            cin >> *printCommand;
            break;
        }

        if(command == "increase") {
            cin >> *index;
            cin >> *newCost;
            cin >> *printCommand;
            break;
        }
        
        if(command == "fileread") {
            break;
        }
        

        cout << "Error: invalid command" << endl;
    }
    return command;
}