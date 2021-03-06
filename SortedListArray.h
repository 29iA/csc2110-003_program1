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
		int max_list;
		int sze;
		
		/*pre-made pointers*/
		int (*compare_items)(T* item_1, T* item_2);
		int (*compare_keys) (String* key, T* item);
		
		/*private methods*/
		//pre: Takes item as parameter, use pre-made static pointer *compare_items
		//post: Use binary search algorithm, return the index of where the item is or should be at
		int binSearchAdd(T* item);
		
		//pre: Takes search_key as parameter, use pre-made static pointer *compare_items
		//post: Use binary search algorithm, return the index of where the item is or should be at
		int binSearchRemove(String* search_key);
		
		//pre: Takes nothing
		//post: Doubles the array, moves everything from old array to new array
		void resize(); //regular resize() function
		
	public:
		SortedListArray(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));	//constructor
		~SortedListArray(); //destructor
		
		//pre: Takes nothing
		//post: Return true if sze var is empty, false if sze != 0
		bool isEmpty();
		
		//pre: Takes nothing
		//post: Return sze variable
		int size();
		
		//pre: Takes search_key as parameter, see if it's in the sorted list
		//post: Returns the item found from search_key, else returns NULL if not found
		T* get (String* search_key);
		
		//pre: Takes item as parameter, perform NULL/sze check, resize() if necessary
		//post: Add the item in location specified by index from binSearchAdd and increment sze
		void add (T* item);
		
		//pre: Takes search_key as parameter, perform NULL/list isEmpty() check
		//post: Remove item in location specified by index from binSearchRemove and decrement sze
		void remove (String* search_key);
		
		//pre: Takes nothing, creates pointer 
		//post: Returns iter pointer
		ListArrayIterator<T>* iterator();
};

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
	int l = sze - 1;
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
int SortedListArray<T>::binSearchRemove(String* search_key)
{
	int f = 0;
	int l = sze - 1;
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

template < class T >
void SortedListArray<T>::resize()
{
	int max_size = max_list * 2;
	T** temp = new T*[max_size];

	//copying contents from items
	for (int i = 0; i < sze; i++)
		temp[i] = items[i];
	
	//initializing the rest of the array with NULL
	for (int i = sze; i < max_size; i++)
		temp[i] = NULL;
	
	delete[] items;	//delete the old array
	items = temp;
}

/*Public Functions directory*/
template < class T >
SortedListArray<T>::SortedListArray(int (*comp_items)(T* item_1, T* item_2), int (*comp_keys)(String* key, T* item))
{
	max_list = 2;
	items = new T*[max_list];
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
	return (sze == 0);
}

template < class T >
int SortedListArray<T>::size()
{
	return sze;
}

template < class T >
T* SortedListArray<T>::get(String* search_key)
{
	//prerequisite check
	///search key not found
	if (search_key == NULL) return 0;
	
	T* item = NULL;
	int index = binSearchRemove(search_key);
	
	if (index >= 1 && index <= sze) 
		item = items[index - 1];
	
	return item;
}

template < class T >
void SortedListArray<T>::add(T* item)
{
	//prerequisite check
	///item not initialized
	if (item == NULL) return;
	if (sze == max_list) resize();
	
	//get index to location of where it is
	int index = binSearchAdd(item);
	
	//presequisite check 2
	///index not found
	if (index == -1 || index == NULL) return;
	
	//shift 1 up, leaving element 0 empty
	for (int i = sze; i >= index; i--)
		items[i] = items[i - 1];

	items[index - 1] = item;
	sze++;
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
	
	//shift 1 down, leaving element sze - 1 empty
	for (int i = index; i < (sze - 1); i++)
		items[i] = items[i + 1];
	
	items[sze - 1] = NULL;
	sze--;
}

template < class T >
ListArrayIterator<T>* SortedListArray<T>::iterator()
{
   ListArrayIterator<T>* iter = new ListArrayIterator<T>(items, sze);
   return iter;
}

#endif