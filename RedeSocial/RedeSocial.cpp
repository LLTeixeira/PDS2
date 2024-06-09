// RedeSocial.cpp : Defines the entry point for the application.
//

#include "RedeSocial.hpp"
#include "Conta.hpp"
#include "Comentario.hpp"

void PrintContas(std::map <long, Conta*>& Contas) {

	for (auto it = Contas.begin(); it != Contas.end(); ++it) {
		std::cout << "Key: " << it->first << ", Value: " << (*(it->second)).nome << std::endl;
	}

}

Post* FindPost(long dono, long id, std::map <long, Conta*>& Contas) {
	Conta* pConta;
	auto it = Contas.find(dono); 
	if (it == Contas.end()) {
		std::cout << "Account not found\n";
		return nullptr;
	}
	else {
		pConta = Contas[dono];
		if ((*pConta).Mural.size() < id) {
			std::cout << "Post not found\n";
			return nullptr;
		}
		else {
			return &(*pConta).Mural[id];
		}
	}
}

int main()
{
	std::map <long, Conta*> Contas;

	Conta SysAdm = Conta("SysAdm", Contas);

	PrintContas(Contas);

	return 0;
}
