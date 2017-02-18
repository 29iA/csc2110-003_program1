#include "SortedListArray.h"
#include "CD.h"
using CSC2110::CD;
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;

#include <iostream>
using namespace std;

/*User-made functions*/
//Reverse of deleteCDs
void addCDs(SortedListArray<CD>* sl, ListArray<CD>* list)
{
	ListArrayIterator<CD>* iter = list->iterator();
	
	while (iter->hasNext())
	{
		sl->add(iter->next());
	}
	
	delete iter;
}

//Display the CDs
void displayCDs(SortedListArray<CD>* sl)
{
	ListArrayIterator<CD>* iter = sl->iterator();
	
	while (iter->hasNext())
	{
		CD* cd = iter->next();
		cd->displayCD();
	}
	
	delete iter;
}

//Basic remove song in list
void remCDs(int index)
{
	//Huh... it's easier to just leave it in main(), oh well.
	ListArray<CD>* cds = CD::readCDs("cds.txt");
	CD* song = cds->get(index);
	SortedListArray<CD>* sl = new SortedListArray<CD>(&CD::compare_items, &CD::compare_keys);
	
	cout << "Removing CD with the index of  " << index << " from the list" << endl;
	
	sl->remove(song->getKey());
	delete cds;
	delete song;
}

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
	SortedListArray<CD>* sl = new SortedListArray<CD>(&CD::compare_items, &CD::compare_keys);
	
	//thoroughly test your sorted list here
	
	//check 1: check size of newly made list
	if (sl->isEmpty())
		cout << "Current list is empty." << endl;
	else
		cout << "Current list is not empty for some reason." << endl;
	
	cout << "Current size: " << sl->size() << endl;
	cout << endl;
	
	//check 2: add cds in using iterator
	cout << "Now adding CDs..." << endl << endl;
	addCDs(sl, cds);
	
	//check 3: check size of new array
	if (sl->isEmpty())
		cout << "List is empty for some reason..." << endl;
	else
		cout << "List is not empty, items must\'ve been added." << endl;
	
	cout << "Current size: " << sl->size() << endl;
	cout << endl;

	//check 4: display the current array
	displayCDs(sl);
	
	//check 5: deleting some items for clarity
	remCDs(1);
	remCDs(3);
	remCDs(5);
	remCDs(2);

	deleteCDs(cds);
	delete cds;

	return 0;
}
