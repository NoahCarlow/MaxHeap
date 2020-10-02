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
                    cout << "Next Command: " << command << " " << newProjName << " " << newCost << " " << printCommand << endl;
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
                if ((printCommand == "yes" || printCommand == "no") && myHeap.maxSize != -1)
                {
                    cout << "Next Command: " << command << " " << printCommand << endl;
                    myHeap.extractMax(printCommand);
                }
                else
                {
                    cout << "Next Command: " << command << " " << printCommand << endl;
                    if (myHeap.maxSize == -1) {
                        cout << "Error: heap not created" << endl;
                    }
                    else if(myHeap.currentSize == 0) {
                        cout << "Error: heap empty" << endl;
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
                if ((printCommand == "yes" || printCommand == "no") && index > 0 && index <= myHeap.currentSize)
                {
                    cout << "Next Command: " << command << " " << index << " " << newCost << " " << printCommand << endl;
                    myHeap.increaseKey(index, newCost, printCommand);
                }
                else if (index < 0 || index > myHeap.currentSize)
                {
                    cout << "Next Command: " << command << " " << index << " " << newCost << " " << printCommand << endl;
                    if (myHeap.maxSize == -1) {
                        cout << "Error: heap not created" << endl;
                    }
                    else {
                        cout << "Error: invalid index" << endl;
                    }
                }
                else
                {
                    cout << "Next Command: " << command << " " << index << " " << newCost << " " << printCommand << endl;
                    cout << "Error: invalid print command" << endl;
                    
                }
                continue;
         }

         else if(command == "fileread") {
            cout << "Next Command: " << command << endl;

            ifstream file;
            file.open("heapInfo.txt");

            string name;
            string cost;
            string sizeOfFile;
            int sizeOfFileInt;
            MaxHeap tempHeap;

            Project * tempArray;
            if (file.good()) {
                getline(file, sizeOfFile);
            }
            istringstream(sizeOfFile) >> sizeOfFileInt;
            //cout << sizeOfFileInt;

            if (myHeap.maxSize == -1) {
                cout << "Error: heap not created" << endl;
            }
            else if (sizeOfFileInt > myHeap.maxSize) {
                cout << "Error: array size exceeds heap capacity" << endl;
            }
            else
            {
                tempHeap.create(sizeOfFileInt);
                tempArray = new Project[sizeOfFileInt + 1];
                
                for(int i = 1; i <= sizeOfFileInt; i++) {
                    int cost1;
                    file >> tempArray[i].projName;
                    file >> cost;
                    istringstream(cost) >> cost1;
                    tempArray[i].cost = cost1;
                }
                myHeap = tempHeap;
                myHeap.buildMaxHeap(tempArray, sizeOfFileInt);
                file.close();
            }
            continue;
         }

        return 0;
    
    }
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