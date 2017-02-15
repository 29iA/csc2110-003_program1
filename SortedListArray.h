#include "ListArray.h"
#include "ListArrayIterator.h"

template < class T >
class SortedList
{
	private:
		T** items;	//pointer
		int max;
		int sz;
		
		//private functions
		static int compare_items (T* item_one, T* item_two) //Used when inserting an item
		static int compare_keys (String* search_key, T* item) //Used to remove or retrieve an item
		
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

template < class T >
SortedList::SortedList()
{
	max = 0
	items = new T*[max];
	sz = 0;
}

template < class T >
SortedList::~SortedList()
{
	
}

template < class T >
bool SortedList::isEmpty()
{
	return (sz == 0);
}

template < class T >
int SortedList::size()
{
	return sz;
}

template < class T >
T* SortedList::get(String* search_key)
{
	
}

template < class T >
void SortedList::add(T* item)
{
	
}

template < class T >
void SortedList::remove(String* search_key)
{
	
}

template < class T >
ListArrayIterator<T>* ListArray<T>::iterator()
{
   ListArrayIterator<T>* iter = new ListArrayIterator<T>(items, sz);
   return iter;
}