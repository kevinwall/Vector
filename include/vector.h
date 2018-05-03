#ifndef vector
#define vector

#include <utility>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <initializer_list>

namespace sc{
	struct vector{
		typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				typedef size_t size_type;
		public:
					class iterator{
						private:
							pointer m_ptr;
						public:
							typedef  std::ptrdiff_t                  difference_type;
							typedef  T                               value_type;
							typedef  T&                              reference;
							typedef  std::bidirectional_iterator_tag iterator_category;

							iterator( pointer ptr=nullptr );
							~iterator() ;
							iterator( const iterator& itr );
							iterator& operator=(const iterator& rhs);
							T operator*(void) ;
							iterator operator++();
							iterator operator++(int);
							iterator operator--();
							iterator operator--(int);
							bool operator==(const iterator& rhs) ;
							bool operator!=(const iterator& rhs) ;
							iterator operator+=(const iterator& rhs);
							iterator operator-=(const iterator& rhs);
							iterator insert( iterator pos, const T& value );
							iterator insert( iterator pos, const T& value );
							const iterator const_back();
							const iterator const_front();
							iterator back();
							iterator front();
							T& operator[]( size_type pos );
							T& at( size_type pos );
							size_type capacity() ;
							void reserve( size_type new_cap );
							void shrink_to_fit();
							bool operator==( const vector& rhs );
							bool operator!=( const vector& rhs );
							vector(pointer ptr = nullptr);
							explicit vector(size_type count);

							vector(const vector& other); 
							vector(std::initializer_list<T> ilist);
							~vector();
							vector& operator=(const vector& other);
							vector& operator=(std::initializer_list<T> ilist);
						
						private:
							pointer m_data;
							size_type m_front;
							size_type m_size;
							size_type m_capacity;
	};
#include "vector.inl"	
}
#endif