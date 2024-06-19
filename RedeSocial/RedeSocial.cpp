#include "RedeSocial.hpp"
#include <iostream>
#include <algorithm>


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


void RedeSocial::PreencherMuralGeral(){
	for (auto it = Contas.begin(); it != Contas.end(); ++it) {
		std::vector<Post> mural_aux = it->second->Mural;

		this->mural_geral.insert(this->mural_geral.end(), mural_aux.begin(), mural_aux.end());
	}

	this->OrdenarMuralGeral();
}


void RedeSocial::OrdenarMuralGeral(){
	// Obs.: [](parametros){return ...} é uma função lambda, que definirá o critério de seleção
	std::sort(
		mural_geral.begin(), mural_geral.end(), 
        [](Post& p1, Post& p2) {return p1.GetScore() > p2.GetScore();}
	);
}

void RedeSocial::PrintarPosts(int num_de_posts){
	/*
	Ideia: 
	1°: Caso não siga ninguém OU as contas que segue não postaram nada, printará os 3 posts mais rankeados do geral
		-> Caso não tenha posts geral nenhum: printará pra criar o 1° post
	2°: Caso em que a conta siga alguém que poste algo
		-> Se (mural_seguindo.size() < num_de_posts): 
			printará os {mural_seguindo.size()} posts dos seguindo e os {num_de_posts - mural_seguindo.size()} do geral
		-> Se (mural_seguindo.size() >= num_de_posts):
			printará os {num_de_posts} posts
	*/
	if(this->conta_acessada->seguindo.empty()){
		if(this->mural_geral.empty()){
			std::cout << "[!] Sem posts para mostrar! Que tal criar o 1° post da Rede? \n\n";
		} else {
			for (int i = 0; i<num_de_posts; i++) {
				Post p = this->mural_geral[i];
				std::cout << "-----#-----#-----" << std::endl;
				std::cout << "| dono:" << Contas[p.dono_id]->nome << "#" << p.dono_id << std::endl;
				std::cout << "| id_post: " << p.id << std::endl;
				std::cout << "| conteúdo:" << std::endl;
				std::cout << p.content << "\n\n";
				std::cout << "| score: " << p.GetScore() << std::endl;
				std::cout << "-----#-----#-----" << std::endl;
			}
		}
	} else {
		this->conta_acessada->ObterMuralContasSeguindo();
		size_t len_mural_seg = this->conta_acessada->mural_seguindo.size();
		
		// Print posts de seguindo
		for (int i = 0; i<num_de_posts; i++) {
			Post p = this->conta_acessada->mural_seguindo[i];
			std::cout << "-----#-----#-----" << std::endl;
			std::cout << "| dono:" << Contas[p.dono_id]->nome << "#" << p.dono_id << std::endl;
			std::cout << "| id_post: " << p.id << std::endl;			
			std::cout << "| conteúdo:" << std::endl;
			std::cout << p.content << "\n\n";
			std::cout << "| score: " << p.GetScore() << std::endl;
			std::cout << "-----#-----#-----" << std::endl;
		}

		// Print posts gerais
		for (int i = 0; i<(num_de_posts-len_mural_seg); i++) {
			// TODO: Checar se o mural_geral não é post de algum seguindo, senão repetirá os posts...
			Post p = this->mural_geral[i];
			std::cout << "-----#-----#-----" << std::endl;
			std::cout << "| dono:" << Contas[p.dono_id]->nome << "#" << p.dono_id << std::endl;
			std::cout << "| id_post: " << p.id << std::endl;
			std::cout << "| conteúdo:" << std::endl;
			std::cout << p.content << "\n\n";
			std::cout << "| score: " << p.GetScore() << std::endl;
			std::cout << "-----#-----#-----" << std::endl;
		}
	}
	
}