#include <iostream>
#include <fstream>
#include <string>
#include "MaxHeap.h"

using namespace std;

string nextCommand(int * n, int * index, int * newCost, string * printCommand, string * newProjName);


int main() {
    int n, index, newCost;
    string command, newProjName, printCommand;

    //declare variables
    MaxHeap myHeap;
    myHeap.currentSize = 0;
    myHeap.maxSize = 0;


    while (true) {
        command = nextCommand(&n, &index, &newCost, &printCommand, &newProjName);
        //command = command.toLower();
        if (command == "quit")
         {
                cout << "Next Command: " << command << endl;
                cout << "Next Command: " << command << " " << newProjName << " " << newCost << " " << printCommand << endl;
                //TO BE COMPLETED
                //...........

                return 0;
         }

         else if (command == "insert")
         {
                cout << "Next Command: " << command << " " << newProjName << " " << newCost << " " << printCommand << endl;
                myHeap.maxHeapInsert(newProjName, newCost, printCommand);
                continue;
         }

         else if (command == "create")
         {
                cout << "Next Command: " << command << " " << n << " " << endl;
                myHeap.create(n);
                continue;
         }

         else if (command == "print")
         {
                cout << "Next Command: " << command << " " << endl;
                myHeap.printMaxHeap();
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
        

        cout << "Invalid command" << endl;
    }
    return command;
}