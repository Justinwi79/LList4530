
// *********************************************************************
// * Default constructor                                               *
// * Last updated: 5/21/22                                             *
// * By: Harold Justin Windham                                         * 
// * References:                                                       * 
// * Previous link list project in COP3330                             *
// *********************************************************************

template <typename T> 
TList<T>::TList()
{
   first = nullptr;
   last = nullptr; 
   size = 0;
}

// *********************************************************************
// * Constructor                                                       *
// * Last updated: 5/21/22                                             *
// * By: Harold Justin Windham                                         * 
// * References:                                                       * 
// * Previous link list project in COP3330                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition      *
// *********************************************************************

template <typename T> 
TList<T>::TList(T val, int num) 
{
   if(num == size)
   InsertFront(val); 
}

// *********************************************************************
// * Copy constructor                                                  *
// * Last updated: 5/22/22                                             *
// * By: Harold Windham                                                * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition      *
// *********************************************************************

template <typename T> 
TList<T>::TList(const TList& L) 
{
    TListIterator<T> dd = L.GetIterator(); 
    
    size = L.size; 
    first = L.first;
    last = L.last;
    for(int i = 0; i <= L.GetSize(); i++)
    {
      InsertBack(dd.GetData());
      dd.Next();
    }
}

// *********************************************************************
// * Destructor                                                        *
// * Last updated: 5/27/22                                             *
// * By: Harold Windham                                                * 
// * References:                                                       * 
// * Previous link list project in COP3330                             *
// *********************************************************************

template <typename T> 
TList<T>::~TList() 
{
   if( first == nullptr)
   { 
      delete first; 
      first = last = nullptr; 
      size = 0; 
   }
}

// *********************************************************************
// * Copy assignment constructor                                       *
// * Last updated: 5/22/22                                             *
// * By: Harold Justin Windham                                         * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition      *
// *********************************************************************

template <typename T> //copy assignment constructor 
TList<T> &TList<T>::operator=(const TList& L)
{
   T mi = L.GetIterator(); 

   for(int i = 0; i < L.GetSize(); i++)
   {
      InsertBack(mi.GetData());
   }
   return *this; 
}

// *********************************************************************
// * Move constructor                                                  *
// * Last updated: 5/22/22                                             *
// * By: Harold Justin Windham                                         * 
// * References:                                                       * 
// * Previous link list project in COP3330                             *
// *********************************************************************

template <typename T> 
TList<T>::TList(TList && L) 
{
   first = L.first; 
   last = L.last; 
   size = L.size;
}

// *********************************************************************
// * Move assignment operator                                          *
// * Last updated: 5/22/22                                             *
// * By: Harold Justin Windham                                         * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition      *
// *********************************************************************

template <typename T> 
TList<T> &TList<T>::operator=(TList && L)
{
   Node<T> *mtp = first; 

   first = L.first; 
   return *this;
}

// *********************************************************************
// * Returns whether or not the list is empty.                         *
// * Last updated: 5/22/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. David Gaitros course videos and assignment intro  *
// *********************************************************************

template <typename T> 
bool TList<T>::IsEmpty() const 
{
   if(size == 0)
   {
      return true; 
   }
   else
   {
      return false; 
   }
}

// *********************************************************************
// * Deletes elements in list                                          *
// * Last updated: 5/22/22                                             *
// * By: Harold Justin Windham                                         * 
// * References:                                                       * 
// * Data Structures and Algorithm Analysis in C++ Fourth Edition      *
// *********************************************************************
template <typename T> 
void TList<T>::Clear() 
{
   for(int i = 0; i < size; i++)
   {
      delete *this;
   }
}

// *********************************************************************
// * Returns size of list                                              *
// * Last updated: 5/22/22                                             *
// * By: Harold Justin Windham                                         * 
// *********************************************************************

template <typename T> 
int TList<T>::GetSize() const 
{
   return size;
}

// *********************************************************************
// * Inserts element at beginning                                      *
// * Last updated: 5/23/22                                             *
// * By: Harold Justin Windham                                         * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition      *
// *********************************************************************

template <typename T> 
void TList<T>::InsertFront(const T& d)
{
   Node<T> *L = new Node<T>(d);

   if(size == 0)
   {
      L->prev = nullptr; 
      first = last = L;
   }
   else   
   {
      L->next = first; 
      first->prev = L; 
      first = L; 
   }
   size++; 
}

// *********************************************************************
// * Inserts element at end                                            *
// * Last updated: 5/23/22                                             *
// * By: Harold Justin Windham                                         * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition      *
// *********************************************************************

template <typename T> 
void TList<T>::InsertBack(const T& d) 
{
   Node<T> *L = new Node<T>(d); 

   if(size == 0)
   {
      L->prev = nullptr; 
      first = last = L;
   }
   else   
   {
      L->prev = last; 
      last->next = L; 
      last = L; 
   }
   size++; 
}

// *********************************************************************
// * Removes first element                                             *
// * Last updated: 5/23/22                                             *
// * By: Harold Justin Windham                                         * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition      *
// *********************************************************************

template <typename T> 
void TList<T>::RemoveFront() 
{
   Node<T> *L = first->next;

   L->prev = 0; 
   delete first; 
   first = L; 
   size--;
}

// *********************************************************************
// * Removes last element                                              *
// * Last updated: 5/23/22                                             *
// * By: Harold Justin Windham                                         * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition      *
// *********************************************************************

template <typename T> 
void TList<T>::RemoveBack() 
{
   Node<T> *L = last->prev;

   L->next = 0; 
   delete last; 
   last = L; 
   size--;
}

// *********************************************************************
// * Return first element                                              *
// * Last updated: 5/21/22                                             *
// * By: Harold Justin Windham                                         * 
// * References:                                                       * 
// * Previous link list project in COP3330                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition      *
// *********************************************************************

template <typename T> 
T& TList<T>::GetFirst() const 
{
   return first->data; 
}

// *********************************************************************
// * Return last element                                               *
// * Last updated: 5/21/22                                             *
// * By: Harold Justin Windham                                         * 
// * References:                                                       * 
// * Previous link list project in COP3330                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition      *
// *********************************************************************

template <typename T> 
T& TList<T>::GetLast() const 
{
   return last->data; 
}

// *********************************************************************
// * Concatenating overload function                                   *
// * Last updated: 5/27/22                                             *
// * By: Harold Justin Windham                                         * 
// *********************************************************************

template <typename T>
TList<T> operator+(const TList<T>& t1, const TList<T>& t2)
{
    //new list = copy of LHS
    TList<T> t3 = t1;
    //iterate through RHS list, insert its elements into new, combined list
    TListIterator<T> it2 = t2.GetIterator();
    for (int i = 0; i < t2.GetSize(); i++) 
    {
        t3.InsertBack(it2.GetData());
        it2.Next();
    }
    return t3;

//TList<T> t;  //just to make the rest of program compile 

  // return t; 
}

// *********************************************************************
// * Print function                                                    *
// * Last updated: 5/22/22                                             *
// * By: Harold Justin Windham                                         * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T>
void TList<T>::Print(std::ostream& os, char delim) const
{
   TListIterator<T> L = this->GetIterator(); 

   for(int i = 0; i < size; i++)
   {
      os << L.GetData() << delim; 
      L.Next(); 
   }
}


//begin TListIterator         ****************************


// *********************************************************************
// * Iterator default constructor                                      *
// * Last updated: 5/22/22                                             *
// * By: Harold Justin Windham                                         * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
TListIterator<T>::TListIterator() 
{
   ptr = nullptr;        //Node<T>*
}


// *********************************************************************
// * Iterator                                                          *
// * Last updated: 5/22/22                                             *
// * By: Harold Justin Windham                                         * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
TListIterator<T> TList<T>::GetIterator() const
{
   TListIterator<T> mi; 

   mi.ptr = first; 
   return mi;  
}

// *********************************************************************
// * Iterator                                                          *
// * Last updated: 5/22/22                                             *
// * By: Harold Justin Windham                                         * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// *********************************************************************

template <typename T> 
TListIterator<T> TList<T>::GetIteratorEnd() const
{
   TListIterator<T> mi; 
   
   mi.ptr = last; 
   return mi;
}

// *********************************************************************
// * Returns true if there is a next node                              *
// * Last updated: 5/22/22                                             *
// * By: Harold Justin Windham                                         * 
// * References:                                                       * 
// * Previous link list project in COP3330                             *
// *********************************************************************

template <typename T> 
bool TListIterator<T>::HasNext() const
{
   if(ptr->next == nullptr)
   {
      return false; 
   }
   else  
   {
      return true; 
   }
}

// *********************************************************************
// * Returns true if there is a previous node                          *
// * Last updated: 5/22/22                                             *
// * By: Harold Justin Windham                                         *
// * References:                                                       * 
// * Previous link list project in COP3330                             *
// *********************************************************************

template <typename T> 
bool TListIterator<T>::HasPrevious() const
{
   if(ptr->prev == nullptr) 
   {
      return false; 
   }
   else   
   {
      return true; 
   }
}

// *********************************************************************
// * Returns next node                                                 *
// * Last updated: 5/23/22                                             *
// * By: Harold Justin Windham                                         * 
// * References:                                                       * 
// * Previous link list project in COP3330                             *
// *********************************************************************

template <typename T> 
TListIterator<T> TListIterator<T>::Next()
{
   ptr = ptr->next; 
   return *this;
}

// *********************************************************************
// * Return previous                                                   *
// * Last updated: 5/23/22                                             *
// * By: Harold Justin Windham                                         * 
// * References:                                                       * 
// * Previous link list project in COP3330                             *
// *********************************************************************

template <typename T> 
TListIterator<T> TListIterator<T>::Previous()
{
   ptr = ptr->prev;
   return *this; 
}

// *********************************************************************
// * Data return                                                       *
// * Last updated: 5/23/22                                             *
// * By: Harold Justin Windham                                         * 
// * References:                                                       * 
// * Previous link list project in COP3330                             *
// *********************************************************************

template <typename T> 
T& TListIterator<T>::GetData() const
{

   return ptr->data;
}

// *********************************************************************
// * Insert at new node                                                *
// * Last updated: 5/24/22                                             *
// * By: Harold Justin Windham                                         * 
// * References:                                                       *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// * Previous link list project in COP3330                             *
// *********************************************************************

template <typename T> 
void TList<T>::Insert(TListIterator<T> pos, const T& d)
{
	Node<T> *current = new Node<T>(d);
   Node<T> *previous = nullptr;

   previous = pos.ptr->prev;
	current->next = pos.ptr;  
	pos.ptr->prev = current;
	
	if(previous == nullptr) 
	{
      first = current; 
   }
	else
   {
		previous->next = current;
		current->prev = previous;	
	}
	size++;
}

// *********************************************************************
// * Remove data                                                       *
// * Last updated: 5/24/22                                             *
// * By: Harold Justin Windham                                         * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 3*
// * Previous link list project in COP3330                             *
// *********************************************************************

template <typename T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos)
{
   Node<T> *current = pos.ptr;
   Node<T> *previous = current->prev; 
   Node<T> *nextt = current ->next; 

   pos.Next(); 
   nextt->prev = previous; 
   previous->next = nextt; 
   delete current; 
   size--; 
   return pos; 
}