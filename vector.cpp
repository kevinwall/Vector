#include <utility>

namespace sc{

	 template < typename T, size_t SIZE=0 >
	struct vector{

		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef size_t size_type; 
		
		public:
		class vector
			{

			//Membros especiais da classe.
			private:
				pointer m_ptr;
				size_type m_front;
				size_type m_size;
				size_type m_capacity;

			public:
				//Funções comuns de listas.
				size_type size() const
				{
					return m_size;
				}

				void clear()
				{
					m_size = 0;
				}

				bool empty()
				{
					return m_size == 0;
				}

				void push_front( const T& value )
				{
					//Talvez seja necessário "passar" os valores para uma posição mais atrás afim de "dar espaço" para o novo elemento
					m_ptr[m_front] = *value;
				}

				void push_back( const T& value )
				{
					m_ptr[m_size++] = *value;
				}

				void pop_back()
				{
					--m_size;
				}	

				void pop_front()
				{
					++m_front;
				}	

				const rhserence back() const
				{
					return &m_ptr[m_size]
				}

				const rhserence front() const
				{
					return &m_ptr[front];
				}	

				//Operações do array dinâmico

				T& operator[]( size_type pos )
				{
					return &m_ptr[pos];
				}

				T& at( size_type pos )
				{
					if( pos > m_size || pos < m_front )
					{
						throw std::out_of_range("A posição dada está fora dos limites do Vetor");

					}else{
						return &m_ptr[pos];
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
							temp[i] = m_ptr[i];
						}

						delete [] m_ptr;

						m_ptr = temp;
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
							temp[i] = m_ptr;
						}

						delete [] m_ptr;

						m_ptr = temp;
						m_capacity = m_size;

						//Também deve ser necessário atualizar os iteradores
						//RETORNAR AQUI APÓS OS MESMOS SEREM IMPLEMENTADOS

					}
				}

				//Sobrecarga de operadores

				bool operator==( const vector& lhs, const vector& rhs ) //Provavelmente deve ser colocado um const aqui
				{
					bool ig = true;

					if( lhs.size() == rhs.size() )
					{
						for(auto i{0}; i < (int)lhs.size() ; i++)
						{
							if( lhs[i] != rhs[i] )
							{
								ig = false;
								break;
								//Não sei se isso funciona;
							}
						}

					}else{
						throw std::runtime_error("Os vetores não são compatíveis");
					}

					return ig;
				}


				bool operator!=( const vector& lhs, const vector& rhs ) //Provavelmente deve ser colocado um const aqui
				{
					bool ig = true;

					if( lhs.size() == rhs.size() )
					{
						for(auto i{0}; i < (int)lhs.size() ; i++)
						{
							if( lhs[i] == rhs[i] )
							{
								ig = false;
								break;
								//Não sei se isso funciona;
							}
						}
						
					}else{
						throw std::runtime_error("Os vetores não são compatíveis");
					}

					return ig;
				}


				// == constructors and descrutors
				//(1)Construtor padrão que cria uma lista vazia.
				vector(pointer ptr = nullptr): m_ptr(ptr){};
				
				//(2)Constrói a lista com instâncias inseridas por padrão de contagem de T.
				explicit vector(size_type count) : m_ptr(new count.m_ptr){};
				
				//(3)Constrói a lista com o conteúdo do intervalo [first, last].
				template<type InputIt>
				vector(InputIt first, InputIt last){};
				
				//(4)Construtor de cópia. Constrói a lista com a cópia profunda do conteúdo de outra.
				vector(const vector& other) : m_ptr ( other.m_ptr){};
				
				//(5)Constrói a lista com o conteúdo da lista inicializadora init.
				vector(std::initializer_list<T> ilist){};
				
				//(6)Destrói a lista. Os destruidores dos elementos são chamados e o armazenamento usado é
				//alocado. Note que se os elementos forem ponteiros, os objetos apontados não serão destruídos.
				~vector() = default;
				
				//(7) Copiar operador de atribuição. Substitui o conteúdo por uma cópia do conteúdo de outro. (isto é
				//os dados em outro são movidos de outro para este contêiner). outro está em um válido, mas
				//estado não especificado posteriormente.
				vector& operator=(const vector& other){};
				
				//(8) Substitui o conteúdo por aqueles identificados pela lista de inicializadores ilist.
				//Os dois métodos de atribuição operator = () (overloaded) retornam * this no final,
				vector& operator=(std::initializer_list<T> ilist){};

				class iterator{
					public:
						typedef  std::ptrdiff_t                  difference_type;
	                    typedef  T                               value_type;
	                    typedef  T*                              pointer;
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

	                	rhserence operator*(void) const{
	                		return *m_ptr;
	                	}

	                	iterator operator++(){
	                		return ++m_ptr;
	                	}

	                	iterator operator++(int){

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

	                	friend iterator insert( iterator pos, const T& value ){
	                		reserve( size_type new_cap );
	                		

	                	} 


            	};

            	class const iterator{
            		constructor();
					~destructor();
            	};
		};		
	};
}