#ifndef Vector
#define Vector

#include <utility>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <initializer_list>

namespace sc{

	template<typename T>
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
							
							template<typename InItr>
							iterator insert( iterator pos, InItr first, InItr last);
							
							iterator insert( iterator pos, std::initializer_list<T> ilist );
							
							iterator erase(iterator first, iterator last);
							
							iterator erase(iterator pos);
							
							const iterator const_back();
							
							const iterator const_front();
							
							const T& back();
							
							const T& front();
							
							reference operator[]( size_type pos );
							
							reference at( size_type pos );
							
							size_type size();
							
							size_type capacity();
							
							bool empty();
							
							void clear();
							
							void reserve( size_type new_cap );
							
							void shrink_to_fit();
							
							void push_front(const T& value);
							
							void push_back(const T& value);
							
							void pop_back();
							
							void pop_front();
							
							iterator begin();
							
							iterator end();
							
							//const_iterator cbegin() const;
							
							//const_iterator cend() const;
							
							iterator insert(iterator pos, const T& value);
							
							template <typename InItr>
							iterator insert( iterator pos, InItr first, InItr last);
							
							iterator insert(iterator pos, std::initializer_list<T> ilist);

							iterator erase( iterator pos );
							
							iterator erase( iterator first, iterator last );

							void assign(size_type count, const T & value);

							template<typename InItr>
							void assign( InItr first, InItr last );

							void assign(std::initializer_list<T> ilist);
							
							bool operator==( const vector& rhs );
							
							bool operator!=( const vector& rhs );
							
							vector(pointer ptr = nullptr);
							
							explicit vector(size_type count);
							
							vector(InputIt first, InputIt last);
							
							vector(const vector& other); 
							
							vector(std::initializer_list<T> ilist);
							
							~vector();
							
							vector& operator=(const vector& other);
							
							vector& operator=(std::initializer_list<T> ilist);
						
						private:
							pointer m_data;
							size_type m_size;
							size_type m_capacity;
	};
#include "vector.inl"	
}
#endif