#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    //create a list with three nodes
    LinkedList<int> list;
    list.insertFront(12);
    list.insertAt(0, 34);
    list.insertAt(list.getCount(), 85);
    for (int i = 0; i < list.getCount(); i++)
        cout << list.get(i) << " ";
    cout << endl;
    //create a second list
    LinkedList<int> list2;
    list2.insertAt(0, 34);
    list2.insertAt(1, 85);
    cout << (list == list2 ? "Lists are the same." : "Lists are different.") << endl;
    //remove the middle node
    list.removeAt(1);
    for (int i = 0; i < list.getCount(); i++)
        cout << list.get(i) << " ";
    cout << endl;
    //compare the second list again
    cout << (list == list2 ? "Lists are the same." : "Lists are different.") << endl;
    //destructor is called when program ends
    cout << "The End." << endl;
    getchar();
}