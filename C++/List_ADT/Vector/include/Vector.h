#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
#include <memory>

template < class T >
class Vector
{
    private:
        using size_type = size_t;
        size_type arrSz;
        std::unique_ptr<T[]> arr;
    
    public:
        size_type size() const;
        void clear();
        bool empty();
        void push_back( const T & x );
        void pop_back();
        const T & back() const;
        const T & front() const;
        void assign( const T & x );
}

#include "Vector.inl"

#endif