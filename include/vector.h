#ifndef vector.h
#define vector.h

#include <utility>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <initializer_list>
#include <iterator> // std::distance

namespace sc{
	/**@title Struct vector no qual comporta todas as funções necessárias para sua construção e também da classe iterator*/
	struct vector{
		/**@brief tipos definidos para variaves futuras usadas na programação abstrata*/
		typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				typedef size_t size_type;
		public:
			/**@title classe do iterator que comporta todas a funções que manipulará o vector*/
					class iterator{
						private:
							pointer m_ptr;
						public: // tipos das variaveis utilizadas no iterator
							typedef  std::ptrdiff_t                  difference_type;
							typedef  T                               value_type;
							typedef  T&                              reference;
							typedef  std::bidirectional_iterator_tag iterator_category;

							/**@title Constructor do iterator
							* @param valor vazio*/

							iterator( pointer ptr=nullptr );
							/**@title Desconstructor do iterator
							* @param valor vazio*/
							~iterator() ;
							/**@title Constructor de cópia iterator
							* @param const iterator& itr*/
							
							iterator( const iterator& itr );
							
							/**@title Operarador = do iterator
							*@brief Função de atribuir valores
							* @param const iterator& rhs*/
							
							iterator& operator=(const iterator& rhs);
							
							/**@title Operador * do iterator 
						 	* @param valor vazio
						 	* @return O próprio iterator*/

							T operator*(void) ;
							
							/**@title Operador ++iterator 
						 	* @param valor vazio
						 	* @return a referência */

							iterator operator++();
							
							/**@title Operador iterator++ 
						 	* @param valor inteiro
						 	* @return o iterator */

							iterator operator++(int);
							
							/**@title Operador --iterator 
						 	* @param valor vazio
						 	* @return a referência */

							iterator operator--();
							
							/**@title Operador iterator-- 
						 	* @param valor inteiro
						 	* @return o iterator */

							iterator operator--(int);
							
							/**@title Operador == iterator
						 	* @param const iterator& rhs
						 	* @return true ou false */

							bool operator==(const iterator& rhs) ;
							
							/**@title Operador != iterator
						 	* @param const iterator& rhs
						 	* @return true ou false */

							bool operator!=(const iterator& rhs) ;

							/**@title Operador += iterator
							*@brief operador que vai somar o iterator apontado pelo this com o iterator de referencia colocado após o operador
						 	* @param const iterator& rhs
						 	* @return iterator */
							
							iterator operator+=(const iterator& rhs);
							
							/**@title Operador -= iterator
							*@brief operador que vai subtrair o iterator apontado pelo this com o iterator de referencia colocado após o operador
						 	* @param const iterator& rhs
						 	* @return iterator */
							
							iterator operator-=(const iterator& rhs);

							/**@title Função iteradora do último valor
							* @param valor vazio
						 	* @return o valor da última posição do vector */
							
							const T& back();

							/**@title Função iteradora do primeiro valor
							* @param valor vazio
						 	* @return o valor da primeira posição do vector */
							
							const T& front();
							
							/**@title Função do operador []
							* @param size_type pos
						 	* @return o valor reference que está indexado na posição pos */
							
							reference operator[]( size_type pos );
							
							/**@title Função de indexação
							* @param size_type pos
						 	* @return o valor reference que está indexado na posição pos */
							
							reference at( size_type pos );
							
							/**@title Função que mostra a capacidade do vector
							* @param vazio
						 	* @return capacidade do vector */
							
							size_type size();

							/**@title Função que mostra o tamanho do vector
							* @param size_type pos
						 	* @return tamanho do vector */
							
							size_type capacity();
							
							/**@title Função que verificar se a lista tá vazia ou não
							* @param void
						 	* @return true se vazia ou false caso não */
							
							bool empty();
							
							/**@title Função que esvazia o vector
							* @param void */
							
							void clear();

							/**@title Função que coloca o parametro dado como novo tamanho do vector
							* @param size_type new_cap
						 	* @return void */
							
							void reserve( size_type new_cap );
							
							/**@title Função que "enxuta" o vector
							* @brief Ele reduz o vector até o tamanho que não indices sem elementos
							* @param void
						 	* @return void */
							
							void shrink_to_fit();
							
							/**@title Função que insere na primeira posição do vector
							* @param const T& value
						 	* @return void */
							
							void push_front(const T& value);
							
							/**@title Função que insere na última posição do vector
							* @param const T& value
						 	* @return void */
							
							void push_back(const T& value);
							
							/**@title Função que apaga na última posição do vector
						 	* @return void */
							
							void pop_back();
							
							/**@title Função que apaga na primeira posição do vector
						 	* @return void */
							
							void pop_front();
							
							/**@title Função que mostra o iterator referente a primeira posição
							* @param void
						 	* @return void */
							
							iterator begin();
							
							/**@title Função que mostra o iterator referente a última posição
							* @param void
						 	* @return void */
							
							iterator end();
							
							/**@title Função que mostra o const iterator referente a primeira posição
							* @param void
						 	* @return void */
							
							const_iterator cbegin() const;
							
							/**@title Função que mostra o const iterator referente a última posição
							* @param void
						 	* @return void */
							
							const_iterator cend() const;
							
							/**@title Função insert que insere value na posição anterior à apontada pelo iterator
							* @param iterator pos e const T& value
						 	* @return O iterator apontando pra nova posição seguinte à do value */
							
							iterator insert(iterator pos, const T& value);
							
							/**@title Função insert que insere o valores de um range na posição anterior à apontada pelo iterator
							* @param iterator pos e InItr first, InItr last
						 	* @return O iterator apontando pra nova posição seguinte à do range */
							
							iterator insert( iterator pos, InItr first, InItr last);
							
							/**@title Função insert que insere uma lista na posição anterior à apontada pelo iterator
							* @param iterator pos e std::initializer_list<T> ilist
						 	* @return O iterator apontando pra nova posição seguinte à da lista */
							
							iterator insert(iterator pos, std::initializer_list<T> ilist);

							/**@title Função erase que apaga o valor na posição anterior à apontada pelo iterator
							* @param iterator pos 
						 	* @return O iterator apontando pra nova posição seguinte à do value apagado*/
							
							iterato erase( iterator pos );
							
							/**@title Função erade que apaga os elementos dentro de um range na posição anterior à apontada pelo iterator
							* @param iterator first e iterator last
						 	* @return O iterator apontando pra nova posição seguinte à dos elementos apagados dentro do range */
							
							iterator erase( iterator first, iterator last );

							/**@title Função assign que substitui uma contagem no vector
							* @brief substitui os valores pelo value que estão na contagem
							* @param size_type count e const T & value
						 	* @return void */
							
							void assign(size_type count, const T & value);

							/**@title Função assign que substitui o vector por elementos dados em um range
							* @param InItr first e InItr last
						 	* @return void */

							template<typename InItr>
							void assign( InItr first, InItr last );

							/**@title Função assign que substituir o vector por uma lista inicializadora
							* @param std::initializer_list<T> ilist
						 	* @return void */
							
							void assign(std::initializer_list<T> ilist);
							
							/**@title Função booleana que compara igualdade entre dois vectors
							* @param const vector& rhs
						 	* @return true caso sejam iguais e false caso não */
							
							bool operator==( const vector& rhs );
							
							/**@title Função booleana que compara diferença entre dois vectors
							* @param const vector& rhs
						 	* @return true caso sejam diferentes e false caso não */
							
							bool operator!=( const vector& rhs );
							
							/**@title Constructor de um vector
							* @param valor nulo e simplório
						 	* @return void */
							
							vector(pointer ptr = nullptr);
							
							/**@title Constructor de um explicit vector
							* @brief Por ser explicit,não se pode chamar implicitamente,ou seja, tem que chamar 
							* a assinatura de forma totalemnte igual que foi escrita
							* @param size_type count
						 	* @return void */
							
							explicit vector(size_type count);
							
							/**@title Constructor de elemento de um range pra um vector
							* @param InputIt first, InputIt last
						 	* @return void */
							
							vector(InputIt first, InputIt last);
							
							/**@title Constructor de referências em um vector
							* @param const vector& other
						 	* @return void */
							
							vector(const vector& other); 
							
							/**@title Constructor de uma lista inicializadora do vector
							* @param valor nulo e simplório
						 	* @return void */
							
							vector(std::initializer_list<T> ilist);
							
							/**@title Desconstructor de um vector
							* @param void
						 	* @return void */
							
							~vector();
							
							/**@title Operator = para atribuição de um vector
							* @param const vector& other
						 	* @return void */
							
							vector& operator=(const vector& other);
							
							/**@title Operator = para atribuição de uma lista inicializadora à um vector
							* @param std::initializer_list<T> ilist
						 	* @return void */
							
							vector& operator=(std::initializer_list<T> ilist);
						
						private:
							pointer m_data;
							size_type m_size;
							size_type m_capacity;
	};
#include "vector.inl"	
}
#endif