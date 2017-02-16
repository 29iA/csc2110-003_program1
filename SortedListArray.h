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
//0-based?
template < class T >
int SortedListArray<T>::binSearchAdd(T* item)
{
	/*
		f = first
		l = last
		m = mid
	*/
	int f = 0;
	int l = sz - 1;
	int m = f + ((l - f) / 2);
	
	while (f <= l)
	{
		int comp = (*compare_items)(item, items[m]); 
		
		if (comp == 0) //duplicate
			return (m + 1); //item found
		else if (comp < 0) 
			l = m - 1;
		else 
			f = m + 1;
		
		m = f + ((l - f) / 2);
	}
	
	return m + 1; //item not found, returning closest + 1 
}

template < class T >
int SortedListArray<T>::binSearchRemove(search_key)
{
	int f = 0;
	int l = sz - 1;
	int m = f + ((l - f) / 2);
	
	while (f <= l)
	{
		int comp = (*compare_keys)(search_key, items[m]);
		
		if (comp == 0) //duplicate
			return (m + 1); //item found
		else if (comp < 0)
			l = m - 1;
		else
			f = m + 1;
		
		m = f + ((l - f) / 2);
	}
	
	return -1;
}

void SortedListArray<T>::resize()
{
	int max_size = max * 2;
	T** temp = new T*[max_size];

	//copying contents from items
	for (int i = 0; i < sz; i++)
		temp[i] = items[i];
	
	//initializing the rest of the array with NULL
	for (int i = sz; i < max_size; i++)
		temp[i] = NULL;
	
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
	///search key not found
	if (search_key == NULL) return;
	
	T* item = NULL;
	int index = search_key;
	
	if (index >= 1 && index <= sz) 
		item = items[index - 1];
	
	return item;
}

template < class T >
void SortedListArray<T>::add(T* item)
{
	//prerequisite check
	///item not initialized
	if (item == NULL) return;
	if (sz == max) resize();
	
	//get index to location of where it is
	int index = binSearchAdd(item);
	
	//shift 1 up, leaving element 0 empty
	for (int i = sz; i >= index; i--)
		items[i] = items[i - 1];

	items[index - 1] = item;
	sz++;
}

template < class T >
void SortedListArray<T>::remove(String* search_key)
{
	//prerequisite check
	///search key not found
	if (search_key == NULL) return;
	///no list available
	if (isEmpty()) return;
	
	//assign index to the return of binSearchRemove() 
	int index = binSearchRemove(search_key);
	
	//prerequisite check 2
	///index not found
	if (index == -1 || index == NULL) return;
	
	//shift 1 down, leaving element sz - 1 empty
	for (int i = index; i < (sz - 1); i++)
		items[i] = items[i + 1];
	
	array[sz - 1] = NULL;
	sz--;
}

template < class T >
ListArrayIterator<T>* ListArray<T>::iterator()
{
   ListArrayIterator<T>* iter = new ListArrayIterator<T>(items, sz);
   return iter;
}