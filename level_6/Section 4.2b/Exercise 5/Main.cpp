// Main.cpp
// Initialise a Stack of type Int of default size 5
// push and pop the elements of the stack
//
// author: amandeep singh gujral

#include <iostream>

#include "container/Stack.hpp"
#include "exception/OutOfBoundsException.hpp"

using namespace std;
using namespace ADSINGH::CONTAINER;

int main()
{

     // intstantiate a Stack of type int
     Stack<int> intStack1;

     // Push elements in stack
     try
     {
          for (int i = 0; i != 6; i++)
          {
               intStack1.Push(i+2);
          }
     }
     catch (OutOfBoundsException &ex)
     {
          cout << ex.GetMessage() << endl;
     }
     catch (...)
     {
          cout << "error: unhandeled exception!" << endl;
     }

     cout << "current_index: "<<intStack1.c_index() << endl
          <<"elements of the stack: "<< intStack1.Print() << endl << endl;

     // pop element out of stack
     try
     {
          for (int i = 5; i != -1; i--)
          {
               cout << intStack1.Pop() << endl;
          }
     }
     catch (OutOfBoundsException &ex)
     {
          cout << ex.GetMessage() << endl;
     }
     catch (...)
     {
          cout << "error: unhandeled exception!" << endl;
     }

     cout <<"curent_index: "<< intStack1.c_index() << endl;

     return 0;
}
