template < class T >   
Forward_list<T>::Iterator::Iterator(T * flis) : it_ptr(flis) 
        {}

template < class T >   
typename Forward_list<T>::Iterator &  Forward_list<T>::Iterator::operator++(int k) 
{ 
    it_ptr++; 
    return *this; 
}

template < class T >   
typename Forward_list<T>::Iterator &  Forward_list<T>::Iterator::operator--(int x) 
{ 
    it_ptr--; 
    return *this; 
}

template < class T >   
typename Forward_list<T>::Iterator Forward_list<T>::Iterator::operator++(char k) 
{ 
    Iterator old(it_ptr);
    ++it_ptr;
    return old; 
}

template < class T >   
typename Forward_list<T>::Iterator Forward_list<T>::Iterator::operator--(char x) 
{ 
    Iterator old(it_ptr);
    --it_ptr;
    return old; 
}

template < class T >   
void Forward_list<T>::Iterator::operator=( const Iterator & it2)
{
    it_ptr = it2.it_ptr;
}

template < class T >   
bool Forward_list<T>::Iterator::operator==( const Iterator & it2) const
{
    return (it_ptr == it2.it_ptr);
}
             
template < class T >   
bool Forward_list<T>::Iterator::operator!=( const Iterator & it2) const
{
    return (it_ptr != it2.it_ptr);
}


template < class T >   
Forward_list<T>::Const_Iterator::Const_Iterator(T * flis) : const_it_ptr(flis) 
        {}

template < class T >   
void Forward_list<T>::Const_Iterator::operator=( const Const_Iterator & it2) 
{
    const_it_ptr = it2.const_it_ptr;
}

template < class T >   
bool Forward_list<T>::Const_Iterator::operator==( const Const_Iterator & it2) const
{
    return (const_it_ptr == it2.const_it_ptr);
}
             
template < class T >   
bool Forward_list<T>::Const_Iterator::operator!=( const Const_Iterator & it2) const
{
    return (const_it_ptr != it2.const_it_ptr);
}