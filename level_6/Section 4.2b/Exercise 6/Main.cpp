// Main.cpp
// Instantiate 3 Stack of type Int and size 4
// push and pop the elements of the stack
// try use of copy constructor and assignment operator
//
// author: amandeep singh gujral

#include <iostream>

#include "container/Stack.hpp"
#include "exception/StackException.hpp"

using namespace std;
using namespace ADSINGH::CONTAINER;

int main()
{

     // intstantiate a Stack of type int
     Stack<int, 4> intStack1;
     Stack<int, 4> intStack3;

     // Push elements in stack
     try
     {
          for (int i = 0; i != 6; i++)
          {
               intStack1.Push(i + 4);
          }
     }
     catch (StackException &ex)
     {
          cout << ex.GetMessage() << endl;
     }
     catch (...)
     {
          cout << "error: unhandeled exception!" << endl;
     }

     cout << "current_index: " << intStack1.c_index() << endl
          << "elements of the stack-1: " << intStack1.Print() << endl
          << endl;

     // copy constructor
     Stack<int, 4> intStack2(intStack1);

     // pop element out of stack
     cout << "elements of stack-2: " << endl;
     try
     {
          for (int i = 5; i != -1; i--)
          {
               cout << intStack2.Pop() << endl;
          }
     }
     catch (StackException &ex)
     {
          cout << ex.GetMessage() << endl;
     }
     catch (...)
     {
          cout << "error: unhandeled exception!" << endl;
     }

     cout << "curent_index: " << intStack2.c_index() << endl
          << endl;

     // test assignment operator
     intStack3 = intStack1;
     cout <<"elements of stack-3: "<<intStack3.Print()<< endl;

     return 0;
}
