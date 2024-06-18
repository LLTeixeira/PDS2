#include "RedeSocial.hpp"
#include <iostream>

RedeSocial::RedeSocial() {
	this->conta_acessada = nullptr;
};

void RedeSocial::AcessarConta(Conta* conta) {
	this->conta_acessada = conta;
}

void RedeSocial::CriarConta(std::string nome_str) {
	Conta* conta_ = new Conta(nome_str, Contas);
}

Conta* RedeSocial::GetConta(long id_conta){
	if (id_conta > Contas.size() || id_conta <= 0){
		std::cout << "id_conta " << id_conta << " inexistente!" << std::endl;
		return nullptr;
	}

	return Contas[id_conta];
}

Conta* RedeSocial::GetConta(std::string nome_conta){
	Conta* conta = nullptr;

	for (std::map<long, Conta*>::iterator it = Contas.begin(); it != Contas.end(); ++it) {
        if (it->second->nome == nome_conta) {
			conta = it->second;
		}
    }

	return conta;
}


void RedeSocial::PrintContas() {
	for (auto it = Contas.begin(); it != Contas.end(); ++it) {
		std::cout << "Key: " << it->first << ", Value: " << (*(it->second)).nome << std::endl;
	}
}

Post* RedeSocial::FindPost(long dono_id, long id_post) {
	Conta* pConta;
	auto it = Contas.find(dono_id); 
	if (it == Contas.end()) {
		std::cout << "Account not found" << std::endl;
		return nullptr;
	}
	else {
		pConta = Contas[dono_id];
		if ((*pConta).Mural.size() < id_post) {
			std::cout << "Post not found" << std::endl;
			return nullptr;
		}
		else {
			return &(*pConta).Mural[id_post];
		}
	}
}		
