#include "Forward_list.hpp"

int main () {
	Forward_list<char> lista;
	
	lista.push_front('k');
	lista.push_back('#');
	lista.print();
	
	std::cout << "A frente da lista:" << lista.front() << std::endl;
	std::cout << "O fim da lista:" << lista.back() << std::endl; 
	
	lista.push_back('p');
	lista.push_front('@');
	lista.push_back('%');
	lista.pop_front();
	lista.print();

	std::cout << "A frente da lista:" << lista.front() << std::endl;
	std::cout << "O fim da lista:" << lista.back() << std::endl;	
	std::cout << "O tamaho da lista:" << lista.size() << std::endl;
	
	lista.push_front('~');
	lista.pop_back();
	lista.print();
	std::cout << "O tamanho da lista:" << lista.size() << std::endl;
	
	Forward_list<char> lista2(lista);
	std::cout << "A lista 2 e:" << std::endl;
	lista2.print();
	std::cout << "O tamanho da lista:" << lista2.size() << std::endl;
	
	lista.assign('s');
	std::cout << "A lista 1 apos o assign(s):" << std::endl;
	
	lista.print();
	
//
	
	lista.clear();
	
	lista.print();
	// lista.find('~')
	std::cout << "O tamanho da lista:" << lista.size() << std::endl;
	
	return EXIT_SUCCESS;
}