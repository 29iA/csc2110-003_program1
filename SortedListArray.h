#if !defined SORTEDLISTARRAY_H
#define SORTEDLISTARRAY_H

#include "Text.h"
#include "ListArrayIterator.h"
using CSC2110::String;
using CSC2110::ListArrayIterator;

template < class T >
class SortedListArray
{
	private:
		T** items;
		int max;
		int sz;
		
		//pre-fetched private functions
		int (*compare_items)(T* item_1, T* item_2);
		int (*compare_keys) (String* key, T* item);
		
		//user-made private functions
		int binSearchAdd(T* item);			//binary search add
		int binSearchRemove(search_key);	//binary search remove
		void resize(); 						//regular resize() function
		
		
	public:
		SortedList();	//constructor
		~SortedList();	//destructor
		
		bool isEmpty();
		int size();
		T* get (String* search_key);
		void add (T* item);
		void remove (String* search_key);
		
		ListArrayIterator<T>* iterator();
}

/*Private Functions directory*/
int SortedListArray<T>::binSearchAdd(T* item)
{
	int f = 0;					//f	= first
	int l = sz - 1;				//l	= last
	int m = f + ((l - f) / 2);	//m	= mid
	
	while f =< l
	{
		//TODO
	}
}

int SortedListArray<T>::binSearchRemove(search_key)
{
	//TODO
}

void SortedListArray<T>::resize()
{
	int max_size = max * 2;
	T** temp = new T*[max_size];

	//copying contents from items
	for (int i = 0; i < sz; i++)
	{
		temp[i] = items[i];
	}
	
	//initializing the rest of the array with NULL
	for (int i = sz; i < max_size; i++)
	{
		temp[i] = NULL;
	}
	
	delete[] items;	//delete the old array
	items = temp;
}

/*Public Functions directory*/
template < class T >
SortedListArray<T>::SortedListArray(int (*comp_items)(T* item_1, T* item_2), int (*comp_keys)(String* key, T* item))
{
	max_list = 2;
	items = new T*[max_list;];
	sze = 0;

	//Copy the memory address of the function into a private instance variable
	compare_items = comp_items; 
	compare_keys = comp_keys;	
}

template < class T >
SortedListArray<T>::~SortedListArray()
{
	delete[] items; //since arrays
}

template < class T >
bool SortedListArray<T>::isEmpty()
{
	return (sz == 0);
}

template < class T >
int SortedListArray<T>::size()
{
	return sz;
}

template < class T >
T* SortedListArray<T>::get(String* search_key)
{
	//prerequisite check
	if (search_key == NULL) return; //nothing there
	
	T* item = NULL;
	int index = search_key;
	
	if (index >= 1 && index <= sz) 
	{  
		item = items[index - 1];
	}
	
	return item;
}

template < class T >
void SortedListArray<T>::add(T* item)
{
	//prerequisite check
	if (item == NULL) return;
	if (sz == max) resize(); //call resize() function
	
	for (int i = sz; i >= index; i--)
	{
		items[i] = items[i - 1];
	}

	items[index - 1] = item;
	sz++;
}

template < class T >
void SortedListArray<T>::remove(String* search_key)
{
	//TODO
}

template < class T >
ListArrayIterator<T>* ListArray<T>::iterator()
{
   ListArrayIterator<T>* iter = new ListArrayIterator<T>(items, sz);
   return iter;
}