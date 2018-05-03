#include <utility>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <initializer_list>

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

	               		iterator temp( *this );
	               			++m_ptr;
	               			return temp;
	               		

	               		pointer temp2 = m_ptr;
	               		++m_ptr;
	               		return iterator(temp2);

	               		return m_ptr++;

                		++m_ptr;
	                	
	                	return m_ptr-1;
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

	                iterator insert( iterator pos, const T& value ){
	                		
	                		if( m_capacity > m_size){
	                			*m_ptr = *value;
	             			
	             				}else{
	             				T* temp = new T[2*m_capacity];
	             				
	             				for(auto i{0} ; i < 2*m_capacity ; i++){
	             					temp[i] = m_ptr[i];
	             				}

	             				delete [] m_ptr;
								
								for( auto i{0} ; i<= pos ; i++){
	             					temp[pos-1] = value;
	             				}

	             				m_ptr = temp;

	             				}

	             			return (*this);
	                		
	                	} 

	               iterator insert( iterator pos, const T& value ){
	                		
	                		if( illist.size() > m_capacity - m_size){
	                			T* temp = new T[m_capacity + ilist.size()];

	             				for( auto i{0} ; i < m_capacity + ilist.size() ; i++){
	             					temp[i] = m_ptr[i];
	             				}

	             				delete [] m_ptr;

	             				for( auto i{0} ; i<= pos ; i++){
	             					temp[pos-1] = value;
	             				}

	             				m_ptr = temp;
	                		}
	             		return (*this);
	                	} 

	                /*class const iterator{
            		constructor();
					~destructor();
            		};
            		*/
	            };
//CLASSE VECTOR=================================================================================================================================================================================
	            const iterator const_back() const
				{
					return iterator(&m_data[m_size]);
				}

				const iterator const_front() const
				{
					return iterator(&m_data[front]);
				}

				iterator back() const
				{
					return iterator(&m_data[m_size]);
				}

				iterator front() const
				{
					return iterator(&m_data[front]);
				} 

				//Operações do array dinâmico

				T& operator[]( size_type pos )
				{
					return &m_data[pos];
				}

				T& at( size_type pos )
				{
					if( pos > m_size || pos < m_front )
					{
						throw std::out_of_range("A posição dada está fora dos limites do Vetor");

					}else{
						return &m_data[pos];
					}
				}

				size_type capacity() const
				{
					return m_capacity;
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

						//Talvez seja necessário atualizar os iteradores também
						//RETORNAR AQUI APÓS OS MESMOS SEREM IMPLEMENTADOS
						//Talvez também seja interessante a adição de uma mensagem de aviso caso o new_cap seja menor ou igual a m_capacity
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

						//Também deve ser necessário atualizar os iteradores
						//RETORNAR AQUI APÓS OS MESMOS SEREM IMPLEMENTADOS

					}
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
				explicit vector(size_type count) : m_data(new count.m_data){}
				
				//(3)Constrói a lista com o conteúdo do intervalo [first, last].
				template< typename InputIt >
				vector(InputIt first, InputIt last)
				{
					m_capacity = first - last;
					m_size = m_capacity;
					m_data = new T[m_capacity];

					std::copy( first, last, &m_data[0] );
				}
				
				//(4)Construtor de cópia. Constrói a lista com a cópia profunda do conteúdo de outra.
				vector(const vector& other) : m_data ( other.m_data)
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
				~vector()
				{
					delete [] m_data;
				}
				
				//(7) Copiar operador de atribuição. Substitui o conteúdo por uma cópia do conteúdo de outro. (isto é
				//os dados em outro são movidos de outro para este contêiner). outro está em um válido, mas
				//estado não especificado posteriormente.
				vector& operator=(const vector& other)
				{
					std::copy( &other.m_data[0], &other.m_data[other.m_size], &m_data[0]);

					m_size = other.m_size;
				}
				
				//(8) Substitui o conteúdo por aqueles identificados pela lista de inicializadores ilist.
				//Os dois métodos de atribuição operator = () (overloaded) retornam * this no final,
				vector& operator=(std::initializer_list<T> ilist)
				{
					std::copy( ilist.begin(), ilist.end(), &m_data[0]);

					m_size = ilist.size();
				}

        //Membros especiais da classe.
		private:
			pointer m_data;
			size_type m_front;
			size_type m_size;
			size_type m_capacity;
	};
}

