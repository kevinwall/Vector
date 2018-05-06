#include "vector.h"

namespace sc{

	template < typename T, size_t SIZE=0 >
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

					iterator( pointer ptr=nullptr ) : m_ptr( ptr ){}
	                   

	            	/// Destructor
	                ~iterator() = default;

	                /// Copy constructor
	                iterator( const iterator& itr ) : m_ptr( itr.m_ptr) {}

	                	
	                iterator& operator=(const iterator& rhs){
	                	m_ptr = rhs.m_ptr;
	               	} 

	               	T operator*(void) const{
	               		return *m_ptr;
	               	}

	               	iterator operator++(){
	               		return ++m_ptr;
	               	}

	               	iterator operator++(int){

	               		pointer temp = m_ptr;
	               		++m_ptr;
	               		return iterator(temp);

	                }

	                iterator operator--(){
	                	return --m_ptr;
	                }

	                iterator operator--(int){
	                	iterator temp( *this );
	                	--m_ptr;
	                	return temp;
	                		
	                }

	                bool operator==(const iterator& rhs) const{
	                	return m_ptr == rhs.m_ptr;
	                }

	                bool operator!=(const iterator& rhs) const{
	                	return m_ptr != rhs.m_ptr;
	                }

	                iterator operator+=(const iterator& rhs){
	                	this->m_ptr = (this->m_ptr + rhs.m_ptr);
	                	return *this; 
	                }

	                iterator operator-=(const iterator& rhs){
	                	this->m_ptr = (this->m_ptr - rhs.m_ptr);
	                	return *this; 
	                }

	                template < typename InItr>
	                iterator insert( iterator pos, InItr first, InItr last)
	                {
	               		if((last - first) > (m_capacity - m_size))
	               		{
	               			T* temp = new T[m_size+(first-last)];

	               			for(auto i{0}; i < (int)m_size; i++)
	               			{
	               				temp[i] = m_data[i];
	               			}
	               		}
	                } 

	               iterator insert( iterator pos, std::initializer_list<T> ilist ){
	                		
	                		int j = 0;

	                		if( ilist.size() > m_capacity - m_size){
	                			T* temp = new T[m_capacity + ilist.size()];

	             				for( auto i{0} ; i < (int)m_size ; i++){
	             					temp[i] = m_ptr[i];
	             				}

	             				delete [] m_ptr;

	             				for( auto k{ilist.begin()} ; k<= ilist.end() ; k++){
	             					temp[ilist.size()+j-1] = *k;
	             					j++;
	             				}

	             				m_ptr = temp;

	             			}else{

	             				T* temp = new T[m_capacity + ilist.size()];

	             				for( auto i{ilist.begin()} ; i<= ilist.end() ; i++){
	             					temp[m_size + j] = *i;
	             					j++;
	             				}

	             				m_ptr = temp;
	             			}

	             				return (*this);

	                		
	                		
	                	}
	                iterator erase(iterator first, iterator last)
					{
						iterator temp = &m_data[first - m_data];

						if( first == last)
						{
							return temp;
						}

						while(first != last)
						{
							delete *first;
							first++;
						}

						std::memmove(temp, last, (m_size -(first - m_data)) * sizeof(T) );

						m_size -= last - first;

						return temp;
					}

	                iterator erase(iterator pos)
					{
						iterator temp = &m_data[pos - m_data];

						delete *temp;

						std::memmove(temp , temp+1, (m_size - (m_data - temp) -1 ) * sizeof(T) );

						--m_size;

						return temp;
					}

    				void assign( size_type count, const T& value )
    				{

        				for (auto i{0}; i< count; i++)
        				{
            				m_data[i] = value;
        				}

        					m_size = count;
    				
    				}

    				template <typename InItr>
					void assign(InItr first, InItr last)
					{
            			size_type list_size = 0;

            			while(first != last)
            			{

                			m_data[list_size] = *first;
                			first++;
                			list_size++;
            				
            			}
            				
            			m_size = list_size;
						
					}

    				void assign(std::initializer_list<T> ilist)
    				{
        				//std::copy(ilist.begin(), ilist.end(), &m_data[0]);
        				auto pointer_list = ilist.begin();
        				int i = 0;

        				while(pointer_list != ilist.end())
        				{
        					m_data[i] = *pointer_list;
        					pointer_list++;
        					i++;
        				}

        				m_size = ilist.size();
    					
    				} 

	                /*class const iterator{
            		constructor();
					~destructor();
            		};
            		*/
	            };
//CLASSE VECTOR=================================================================================================================================================================================
	        	const T& back() const
				{
					return m_data[m_size];
				}

				const T& front() const
				{
					return m_data[0];
				} 

				//Operações do array dinâmico

				reference operator[]( size_type pos )
				{
					return m_data[pos];
				}

				reference at( size_type pos )
				{
					if( pos >= m_size || pos < 0 )
					{
						throw std::out_of_range("A posição dada está fora dos limites do Vetor");

					}else{
						return m_data[pos];
					}
				}

				size_type size() const
				{
					return m_size;
				}

				size_type capacity() const
				{
					return m_capacity;
				}

				bool empty() const
				{
					return m_size == 0;
				}

				void clear()
				{
					for(auto i{0}; i < (int)m_size; i++)
					{
						m_data[i].~T();
					}

					m_size = 0;
				}	

				void reserve( size_type new_cap )
				{
					if( new_cap > m_capacity )
					{
						T* temp = new T[new_cap];

						for(auto i{0}; i < (int)m_size ; i++)
						{
							temp[i] = m_data[i];
						}

						delete [] m_data;

						m_data = temp;
						m_capacity = new_cap;
					}
				}

				void shrink_to_fit()
				{
					if(m_capacity > m_size)
					{
						T* temp = new T[m_size];

						for(auto i{0}; i < (int)m_size ; i++)
						{
							temp[i] = m_data;
						}

						delete [] m_data;

						m_data = temp;
						m_capacity = m_size;
					}
				}

    			void push_front(const T& value)
    			{
       				reserve(m_size+1);

       				T* temp = new T[m_size];

        			for(auto i{0}; i < (int)m_size; i++)
        			{
        				temp[i] = m_data[i];
        			}
        			clear();

        			m_size = m_size + 1;
        			m_data[0] = value;
        			
        			for(auto i{1}; i < (int)m_size; i++)
        			{
        				m_data[i] = temp[i-1];
        			}

        			delete [] temp;
    			}

    			void push_back(const T& value)
    			{
        			if(m_size < m_capacity)
        			{
        				m_data[m_size] = value;
        			}else{
        				reserve(m_capacity+1);
        				m_data[m_size] = value;
        			}
    			}

    			void pop_back()
    			{
    				m_size--;
    			}

    			void pop_front()
    			{
    				T* temp = new T[m_size];

       				std::memmove(temp, &m_data[1], m_size*sizeof(T));

        			m_size--;

        			std::memmove(m_data, temp, m_size*sizeof(T));
    			}

    			iterator begin()
    			{
            		return iterator(&m_data[0]);
    			}

    			iterator end()
    			{
            		return iterator(&m_data[m_size]);
    			}

    			/*const_iterator cbegin() const
    			{
        			return const_iterator(&m_data[0]);
    			}

				const_iterator cend() const
    			{
        			return const_iterator(&m_data[m_size]);
    			}
				*/

    			iterator insert(iterator pos, const T& value)
    			{
        			auto i = m_size+1;
        			reserve(i);

       				iterator aux = begin();

        			auto index = (std::distance(&aux, &pos)/m_size*sizeof(T))-3*sizeof(T);

        			value_type new_vector [m_size];

        			std::memmove(new_vector, m_data[index], m_size*sizeof(T));

        			if(index < m_size){
            			m_data[index] = value;
        			}

        			std::memmove(&m_data[index+1], new_vector, m_size*sizeof(T));

        			return pos;
    			}

    			template <typename InItr>
      			iterator insert( iterator pos, InItr first, InItr last)
      			{
            		size_type i = 0;
					auto ini(first);

					while(ini != last)
					{
						i++;
						ini++;
					}

					auto new_cap = i + m_size;
					reserve(new_cap);

					iterator aux = begin();
					auto index = (std::distance(&aux, &pos)/m_size*sizeof(T))-3*sizeof(T);

					value_type new_vector [m_size];

					std::memmove(new_vector, &m_data[index], m_size*sizeof(T));

					while(first != last)
					{
						m_data[index] = *first;
						index++;
						first++;
					}

					std::memmove(&m_data[index], new_vector, m_size*sizeof(T));
					
            		return pos;
   				}

    			iterator insert(iterator pos, std::initializer_list<T> ilist)
    			{
        			auto i = m_size + ilist.size();
        			reserve(i);

        			iterator aux = begin();

        			auto index = (std::distance(&aux, &pos)/m_size*sizeof(T))-3*sizeof(T);

        			value_type new_vector [m_size];

        			std::memmove(new_vector, m_data, m_size*sizeof(T));

        			if(index < m_size){
            			std::copy(ilist.begin(), ilist.end(), &m_data[index]);
       				}
       				
        			std::memmove(&m_data[index+ilist.size()], new_vector, m_size*sizeof(T));

        			return pos;
    			}
				//Sobrecarga de operadores

				bool operator==( const vector& rhs ) //Provavelmente deve ser colocado um const aqui
				{
					bool ig = true;

					if( m_size == rhs.size() )
					{
						for(auto i{0}; i < (int)m_size ; i++)
						{
							if( m_data[i] != rhs[i] )
							{
								ig = false;

								return ig;
							}
						}

					}else{
						throw std::runtime_error("Os vetores não são compatíveis");
					}

					return ig;
				}


				bool operator!=( const vector& rhs ) //Provavelmente deve ser colocado um const aqui
				{
					bool ig = true;

					if( m_size == rhs.size() )
					{
						for(auto i{0}; i < (int)m_size ; i++)
						{
							if( m_data[i] == rhs[i] )
							{
								ig = false;
								
								return ig;
							}
						}
						
					}else{
						throw std::runtime_error("Os vetores não são compatíveis");
					}

					return ig;
				}


				// == constructors and descrutors
				//(1)Construtor padrão que cria uma lista vazia.
				vector(pointer ptr = nullptr): m_data(ptr){}
				
				//(2)Constrói a lista com instâncias inseridas por padrão de contagem de T.
				explicit vector(size_type count)
				{
					m_size = count;
				}
				
				//(3)Constrói a lista com o conteúdo do intervalo [first, last].
				template< typename InputIt >
				vector(InputIt first, InputIt last)
				{
					m_capacity = first - last;
					m_size = m_capacity;
					m_data = new T[m_capacity];
					int i = 0;

					while(first != last)
					{
						m_data[i] = *first;
						i++;
						first++;
					}
				}
				
				//(4)Construtor de cópia. Constrói a lista com a cópia profunda do conteúdo de outra.
				vector(const vector& other)
				{
					m_capacity = other.m_capacity;
					m_size = other.m_size;
					m_data = new T[m_capacity];

					std::copy( &other.m_data[0], &other.m_data[other.m_size], &m_data[0] );
				}
				
				//(5)Constrói a lista com o conteúdo da lista inicializadora init.
				vector(std::initializer_list<T> ilist)
				{
					m_capacity = ilist.size();
					m_size = m_capacity;
					m_data = new T[m_capacity];

					std::copy( ilist.begin(), ilist.end(), &m_data[0] );
				}
				
				//(6)Destrói a lista. Os destruidores dos elementos são chamados e o armazenamento usado é
				//alocado. Note que se os elementos forem ponteiros, os objetos apontados não serão destruídos.
				~vector() = default;
				
				//(7) Copiar operador de atribuição. Substitui o conteúdo por uma cópia do conteúdo de outro. (isto é
				//os dados em outro são movidos de outro para este contêiner). outro está em um válido, mas
				//estado não especificado posteriormente.
				vector& operator=(const vector& other)
				{
					std::copy( &other.m_data[0], &other.m_data[other.m_size], &m_data[0]);

					m_size = other.m_size;

					return(*this);
				}
				
				//(8) Substitui o conteúdo por aqueles identificados pela lista de inicializadores ilist.
				//Os dois métodos de atribuição operator = () (overloaded) retornam * this no final,
				vector& operator=(std::initializer_list<T> ilist)
				{
					std::copy( ilist.begin(), ilist.end(), &m_data[0]);

					m_size = ilist.size();

					return(*this);
				}

        //Membros especiais da classe.
		private:
			pointer m_data;
			size_type m_size;
			size_type m_capacity;
	};
}

