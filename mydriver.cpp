#include <iostream>
#include <string>
#include "tlist.h"

using namespace std;

// *********************************************************************
// * PrintList provided by Dr. Gaitros in driver.cpp                   *
// * Remainder of mydriver.cpp last updated: 5/27/22                   *
// * By: Harold Justin Windham                                         * 
// * References:                                                       *
// * driver.cpp from this assignment                                   *
// *********************************************************************

template <typename T> 
void PrintList(const TList<T>& L, string label)
{
   cout << label << " size is: " << L.GetSize() << "\n"
        << label << " = "; 
   L.Print(cout);
   cout << "\n\n";
}

int main()
{
    //doubles
    TList<double> L1;	
    cout << "\nL1 is doubles and L2 is integers\n" << endl; 
    cout << "Inserting and removing doubles.\n\n" ; 

    for (int i = 0; i < 10; i++)
	    L1.InsertBack(i*1.5);

    PrintList(L1, "L1");

    L1.RemoveBack();
    PrintList(L1, "L1");

    L1.RemoveFront();
    PrintList(L1, "L1");

    L1.RemoveBack();
    PrintList(L1, "L1");

    L1.RemoveFront();
    PrintList(L1, "L1");

    for (int i = 0; i < 8; i++)
        L1.InsertFront(i+.5);

    PrintList(L1, "L1");

    L1.RemoveBack();
    PrintList(L1, "L1");

    L1.RemoveFront();
    PrintList(L1, "L1");

    L1.RemoveBack();
    PrintList(L1, "L1");

    L1.RemoveFront();
    PrintList(L1, "L1");


    TListIterator<double> mi = L1.GetIterator(); 

    cout << "Inserting doubles with iterators.\n\n"; 

    L1.Insert(mi, 33.5); 
    mi.Next(); 
    mi.Next(); 
    L1.Insert(mi, 55.5); //inserted 2 spots over from "33.5" 

    PrintList(L1, "L1"); 

    mi.Next(); 
    mi.Next(); 
    mi = L1.Remove(mi); //remove "1.5"

    PrintList(L1, "L1"); 

    // integers 
    TList<int> L2;	

    cout << "Inserting and removing integers. \n\n"; 

    for (int i = 0; i < 10; i++)
	    L2.InsertBack(i);

    PrintList(L2, "L2");

    L2.RemoveBack();
    PrintList(L2, "L2");

    L2.RemoveFront();
    PrintList(L2, "L2");

    L2.RemoveBack();
    PrintList(L2, "L2");

    L2.RemoveFront();
    PrintList(L2, "L2");

    for (int i = 0; i < 12; i++)
        L2.InsertFront(i);

    PrintList(L2, "L2");

    L2.RemoveBack();
    PrintList(L2, "L2");

    L2.RemoveFront();
    PrintList(L2, "L2");

    L2.RemoveBack();
    PrintList(L2, "L2");

    L2.RemoveFront();
    PrintList(L2, "L2");

    TListIterator<int> mi2 = L2.GetIterator(); 

    cout << "Inserting and removing integers with iterators.\n\n" ; 

    L2.Insert(mi2, 77); 
    mi2.Next(); 
    mi2.Next(); 
    L2.Insert(mi2, 25); //inserted 2 spots over from "77" 

    PrintList(L2, "L2"); 

    mi2.Next(); 
    mi2.Next(); 
    mi2 = L2.Remove(mi2); //remove "5" from recently added

    PrintList(L2, "L2"); 

}