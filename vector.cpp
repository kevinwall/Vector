
namespace sc{

	 template < typename T, size_t SIZE=0 >
	struct vector{

		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef size_type size; 
		
		public:
		class vector
			{
			public:
				// == constructors and descrutors
				//(1)Construtor padrão que cria uma lista vazia.
				vector(pointer ptr = nullptr): m_ptr(ptr){};
				
				//(2)Constrói a lista com instâncias inseridas por padrão de contagem de T.
				explicit vector(size_type count) : m_ptr(new count.m_ptr){};
				
				//(3)Constrói a lista com o conteúdo do intervalo [first, last].
				template<type InputIt>
				vector(InputIt first, InputIt last);
				
				//(4)Construtor de cópia. Constrói a lista com a cópia profunda do conteúdo de outra.
				vector(const vector& other) : m_ptr ( other.m_ptr){};
				
				//(5)Constrói a lista com o conteúdo da lista inicializadora init.
				vector(std::initializer_list<T> ilist);
				
				//(6)Destrói a lista. Os destruidores dos elementos são chamados e o armazenamento usado é
				//alocado. Note que se os elementos forem ponteiros, os objetos apontados não serão destruídos.
				~vector() = default;
				
				//(7) Copiar operador de atribuição. Substitui o conteúdo por uma cópia do conteúdo de outro. (isto é
				//os dados em outro são movidos de outro para este contêiner). outro está em um válido, mas
				//estado não especificado posteriormente.
				vector& operator=(const vector& other);
				
				//(8) Substitui o conteúdo por aqueles identificados pela lista de inicializadores ilist.
				//Os dois métodos de atribuição operator = () (overloaded) retornam * this no final,
				vector& operator=(std::initializer_list<T> ilist);

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
	                	iterator( const iterator& itr ) : m_ptr( itr.m_ptr {}

	                	
	                	iterator& operator=(const iterator& ref){
	                		m_ptr = ref.m_ptr;
	                	} 

	                	reference operator*(void) const{
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

	                	bool operator==(const iterator& ref) const{
	                		return m_ptr == ref.m_ptr;
	                	}

	                	bool operator!=(const iterator& ref) const{
	                		return m_ptr != ref.m_ptr;
	                	}

	                	iterator operator+=(){
	                		return 
	                	}
            	};

            	class const iterator{};

		constructor();
		~destructor();
		
		};		
	};
}