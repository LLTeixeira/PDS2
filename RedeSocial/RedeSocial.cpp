// RedeSocial.cpp : Defines the entry point for the application.
//

#include "RedeSocial.hpp"
#include "Conta.hpp"
#include "Post.hpp"
#include "Comentario.hpp"
#include <map>

void PrintContas(std::map <long, Conta*>* Contas) {

	for (auto it = (*Contas).begin(); it != (*Contas).end(); ++it) {
		std::cout << "Key: " << it->first << ", Value: " << (*(it->second)).nome << std::endl;
	}

}

int main()
{
	std::map <long, Conta*> Contas;

	Conta SysAdm = Conta("SysAdm", &Contas);

	PrintContas(&Contas);

	return 0;
}
