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

	                	
	                template< typename T >
	                typename vector<T>::iterator vector<T>::iterator::&operator=(const iterator& rhs){
	                	m_ptr = rhs.m_ptr;
	               	} 

	               	T operator*(void) const{
	               		return *m_ptr;
	               	}

	               	template< typename T >
	               	typename vector<T>::iterator vector<T>::iterator:: operator++(){
	               		return ++m_ptr;
	               	}

	               	template< typename T >
        			typename vector<T>::iterator vector<T>::iterator:: operator++(int){

	               		iterator temp( *this ){
	               			++m_ptr;
	               			return temp;
	               		}

	               		pointer temp2 = m_ptr;
	               		++m_ptr;
	               		return iterator(temp2);

	               		return m_ptr++;

                		++m_ptr;
	                	
	                	return m_ptr-1;
	                }

	                template< typename T >
        			typename vector<T>::iterator vector<T>::iterator:: operator--(){
	                	return --m_ptr;
	                }

	                template< typename T >
        			typename vector<T>::iterator vector<T>::iterator:: operator--(int){
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

	                template< typename T >
        			typename vector<T>::iterator vector<T>::iterator:: operator+=(const iterator& rhs){
	                	this->m_ptr = (this->m_ptr + rhs.m_ptr);
	                	return *this; 
	                }

	                template< typename T >
        			typename vector<T>::iterator vector<T>::iterator:: operator-=(const iterator& rhs){
	                	this->m_ptr = (this->m_ptr - rhs.m_ptr);
	                	return *this; 
	                }

	                template< typename T >
        			typename vector<T>::iterator vector<T>::iterator::insert( iterator pos, const T& value ){
	                		
	                		
	                	} 

	               template< typename T >
        			typename vector<T>::iterator vector<T>::iterator:: insert( iterator pos, std::initializer_list<T> ilist ){
	                		
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
	             				for( auto i{ilist.begin()} ; i<= ilist.end() ; i++){
	             					temp[m_size + j] = *i;
	             					j++;
	             				}

	             				m_ptr = temp;
	             			}
	                		
	                	} 

	                /*class const iterator{
            		constructor();
					~destructor();
            		};
            		*/
	            };
//CLASSE VECTOR=================================================================================================================================================================================
	  
				template< typename T >
        		const T& vector<T>::back() const
				{
					return m_data[m_size];
				}

				template< typename T >
        		const T& vector<T>::front() const
				{
					return m_data[0];
				} 

				//Operações do array dinâmico
				template<typename T>
				typename vector<T>::reference vector<T>::operator[]( size_type pos )
				{
					return m_data[pos];
				}

				template <typename T>
				typename vector<T>::reference vector<T>::at( size_type pos )
				{
					if( pos >= m_size || pos < 0 )
					{
						throw std::out_of_range("A posição dada está fora dos limites do Vetor");

					}else{
						return m_data[pos];
					}
				}

				template<typename T>
				typename vector<T>::size_type vector<T>::size() const
				{
					return m_size;
				}

				template<typename T>
				typename vector<T>::size_type vector<T>::capacity() const
				{
					return m_capacity;
				}	

				template<typename T>
				bool vector<T>::empty() const
				{
					return m_size == 0;
				}

				template<typename T>
				void vector<T>::clear()
				{
					for(auto i{0}; i < (int)m_size; i++)
					{
						m_data[i].~T();
					}

					m_size = 0;
				}	

				template<typename T>
				void vector<T>::reserve( size_type new_cap )
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

				template<typename T>
				void vector<T>::shrink_to_fit()
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

				template<typename T>
				void vector<T>::push_front(const T& value)
    			{
       				reserve(m_size+1);

       				T* temp = new T[m_size];

        			for(auto i{0}; i < m_size; i++)
        			{
        				temp[i] = m_data[i];
        			}
        			clear();

        			m_size = m_size + 1;
        			m_data[0] = value;
        			
        			for(auto i{1}; i < m_size)
        			{
        				m_data[i] = temp[i-1];
        			}
        			
        			delete [] temp;
        		}

        		template<typename T>
        		void vector<T>::push_back(const T& value)
    			{
        			if(m_size < m_capacity)
        			{
        				m_data[m_size] = value;
        			}else{
        				reserve(m_capacity+1);
        				m_data[m_size] = value;
        			}
        		}
    			
    			template<typename T>
    			void vector<T>::pop_back()
    			{
    				m_size--;
    			} 

    			template <typename T>
    			void vector<T>::pop_front()
    			{
    				T* temp = new T[m_size];

       				std::memmove(temp, &m_data[1], m_size*sizeof(T));

        			m_size--;

        			std::memmove(m_data, temp, m_size*sizeof(T));
    			} 

    			template <typename T>
    			typename vector<T>::iterator vector<T>::begin(void)
    			{
            		return iterator(&m_data[0]);
    			}

    			template <typename T>
    			typename vector<T>::iterator vector<T>::end(void)
    			{
            		return iterator(&m_data[m_size]);
    			}

    			template <typename T>
    			typename vector<T>::const_iterator vector<T>::cbegin(void) const
    			{
        			return const_iterator(&m_data[0]);
    			} 

    			template <typename T>
    			typename vector<T>::const_iterator vector<T>::cend(void) const
    			{
        			return const_iterator(&m_data[m_size]);
    			} 

    			template <typename T>
    			typename vector<T>::iterator vector<T>::insert(typename vector<T>::iterator pos, const T& value)
    			{
        			auto i = m_size+1;
        			reserve(i);

        			iterator aux = begin();

        			auto index = (std::distance(&aux, &pos)/m_size*sizeof(T))-3*sizeof(T);

        			value_type new_vector [m_size];

        			std::memmove(new_vector, m_data[index], m_size*sizeof(T));

        			if(index < m_size)
        			{
            			m_data[index] = value;
        			}

        			std::memmove(&m_data[index+1], new_vector, m_size*sizeof(T));

       				return pos;
    			}

    			template <typename T>
     			template <typename InItr>
      			typename vector<T>::iterator vector<T>::insert( typename vector<T>::iterator pos, InItr first, InItr last)
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

   				template<typename T>
    			typename vector<T>::iterator vector<T>::insert( typename vector<T>::iterator pos, std::initializer_list<T> ilist)
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

    			template<typename T>
    			typename vector<T>::iterator vector<T>:: erase( typename vector<T>::iterator first, typename vector<T>::iterator last ){
    					
    				auto i(0),j(0);
    				value_type new_vector [m_size];

    				assert(first <= last);
					assert(last <= cend());
					assert(first < cend());

					if (first == last) {
						return begin() + std::distance(cbegin(), first);
					}else{
						if(m_data[i] != *first){
							new_vector[j] = m_data[i];
							j++;
						}else{
							m_size--;
						}
						i++;
						first++;
					}
					return first;
    			}

    			template<typename T>
    			typename vector<T>::iterator vector<T>::erase( typename vector<T>::iterator pos ){
    				assert(pos < cend());
    				return erase(pos,pos+1);
    			}	

    			template<typename T>
    			typename vector<T>::iterator vector<T>::assign(typename vector<T>::size_type count, const T & value){
        			for (size_type i = 0; i< count; i++){
            			m_data[i] = value;
        			}
        			m_size = count;
				}	

				 template<typename T>
    			 template <typename InItr>
					void vector<T>::assign(InItr first, InItr last){
            		auto i = 0;
            			
            		while(first != last){
                		m_data[i] = *first;
                		first++;
                		i++;
            		}
            		
            		m_size = i;
            		
					}

    			template<typename T>
    			void vector<T>::assign(std::initializer_list<T> ilist){
        		
        		assign(ilist.begin(), ilist.end());
        		
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
				template <typename T>
				vector<T>::vector(void): m_data(ptr){}
				
				//(2)Constrói a lista com instâncias inseridas por padrão de contagem de T.
				template <typename T>
				vector<T>::vector(typename vector<T>::size_type count)
				{
					m_size = count;
				}
				
				//(3)Constrói a lista com o conteúdo do intervalo [first, last].
				template< typename T>
				template< typename InputIt >
				vector<T>::vector(InputIt first, InputIt last)
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
				template <typename T>
				vector<T>::vector(const vector& other)
				{
					m_capacity = other.m_capacity;
					m_size = other.m_size;
					m_data = new T[m_capacity];

					std::copy( &other.m_data[0], &other.m_data[other.m_size], &m_data[0] );
				}
				
				//(5)Constrói a lista com o conteúdo da lista inicializadora init.
				template<typename T>
				vector<T>::vector( std::initializer_list<T> ilist)
				{
					m_capacity = ilist.size();
					m_size = m_capacity;
					m_data = new T[m_capacity];

					std::copy( ilist.begin(), ilist.end(), &m_data[0] );
				}
				
				//(6)Destrói a lista. Os destruidores dos elementos são chamados e o armazenamento usado é
				//alocado. Note que se os elementos forem ponteiros, os objetos apontados não serão destruídos.
				template <typename T>
				vector<T>~vector(void) = default;
				
				
				//(7) Copiar operador de atribuição. Substitui o conteúdo por uma cópia do conteúdo de outro. (isto é
				//os dados em outro são movidos de outro para este contêiner). outro está em um válido, mas
				//estado não especificado posteriormente.
				template<typename T>
				vector<T>& vector<T>::operator=(const vector& other)
				{
					std::copy( &other.m_data[0], &other.m_data[other.m_size], &m_data[0]);

					m_size = other.m_size;
				}
				
				//(8) Substitui o conteúdo por aqueles identificados pela lista de inicializadores ilist.
				//Os dois métodos de atribuição operator = () (overloaded) retornam * this no final,
				template<typename T>
				vector<T>& vector<T>::operator=(std::initializer_list<T> ilist)
				{
					std::copy( ilist.begin(), ilist.end(), &m_data[0]);

					m_size = ilist.size();
				}

        //Membros especiais da classe.
		private:
			pointer m_data;
			size_type m_size;
			size_type m_capacity;
	};
