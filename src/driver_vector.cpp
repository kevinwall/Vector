#include "../include/vector.h"

int main( void )
{
	//construtor com lista
	sc::vector<int> vet_1 = {1, 2, 3, 4};
	//construtor copia com ranges
	sc::vector<int> vet_2 (vet_1.begin(),vet_1.end());
	//construtor default
	sc::vector<int> vet_3;

	//Construtor "default" do iterator
	sc::vector<int>::iterator beg_vet_1 = vet_1.begin();
	sc::vector<int>::iterator beg_vet_3 = vet_3.begin();

	//Tamanho lógico do vet_1
	std::cout << "Tamanho lógico de vet_1: " << vet_1.size() << std::endl;
	//Capacidade de vet_1
	std::cout << "Capcidade de vet_1: "<< vet_1.capacity() << std::endl;
	
	//Utilizando o reserve em vet_1
	vet_1.reserve(6);
	std::cout << "A nova capacidade de vet_1 depois do reserve é: "<< vet_1.capacity() << std::endl;
	
	//Verificando se o vetor é vazio
	if(vet_3.empty() == true)
	{
		std::cout<<"Este vetor é vazio"<<std::endl;

	}else{ 
			
		std::cout<<"Este vetor não é vazio"<<std::endl;
	}
	
	//Inserindo elementos em vet_3 sem o uso prévio do reserve
	vet_3.push_front(10);
	vet_3.push_back(9);
	vet_3.push_back(8);
	
	//Invalidando elementos de vet_3
	vet_3.pop_front();
	vet_3.pop_back();

	//Utilizando o método back
	std::cout << "O ultimo elemento válido de vet_3 é: " << vet_3.back() << std::endl;
	//Utilizando o método front
	std::cout << "O primeiro elemento de vet_3 é: " << vet_3.front() << std::endl;

	//"Limpando" o vetor
	vet_3.clear();

	//inserindo um lista em vet_1
	//vet_1.insert(beg_vet_1, {5, 6});

	std::cout<<"vet_1 após o insert: "<<std::endl;
	std::cout<<"[ ";
	for(; beg_vet_1 != vet_1.end(); ++beg_vet_1)
	{
		std::cout<< *beg_vet_1 <<" ";
	}
	std::cout<<"]";

	//assign com range
	vet_3.assign(vet_1.begin(),vet_1.end());

	std::cout<<"Vetor a após o insert: "<<std::endl;
	std::cout<<"[ ";
	for(; beg_vet_3 != vet_3.end(); beg_vet_3++)
	{
		std::cout<< *beg_vet_3 <<" ";
	}
	std::cout<<"]";

	return 0;
}