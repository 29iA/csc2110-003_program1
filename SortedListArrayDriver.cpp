#include "SortedListArray.h"
#include "CD.h"
using CSC2110::CD;
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
	ListArrayIterator<CD>* iter = list->iterator();

	while(iter->hasNext())
	{
		CD* cd = iter->next();
		delete cd;
	}
	delete iter;
}

int main()
{
	//include things from instruction
	ListArray<CD>* cds = CD::readCDs("cds.txt");
	SortedListArray* sl = new SortedListArray(&CD::compare_items, &CD::compare_keys);
	
	//thoroughly test your sorted list here
	
	//check 1: check size of newly made list
	cout << "Current size: " << sl->size() << endl;
	
	//check 2: insert cds into the array
	//TODO
	
	//check 3: check size of new array
	cout << "Current size: " << sl->size() << endl;
	
	if (sl->isEmpty())
		cout << "List is empty." << endl;
	else
		cout << "List is not empty, geting data..." << endl;
	
	//check 4: Display the current array
	
	//check+
	//TODO








	deleteCDs(cds);
	delete cds;

	return 0;
}
