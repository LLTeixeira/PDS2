#include "RedeSocial.hpp"
#include <iostream>
#include <algorithm>
#include "Post.hpp" 


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
		std::cout << "\n\n";
		std::cout << "[!] id_conta " << id_conta << " inexistente [!]" << std::endl;
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
		if ((*pConta).posts_conta.size() < id_post) {
			std::cout << "Post not found" << std::endl;
			return nullptr;
		}
		else {
			return &(*pConta).posts_conta[id_post];
		}
	}
}		


void RedeSocial::SetPostsGerais(){
	for (auto it = Contas.begin(); it != Contas.end(); ++it) {
		std::vector<Post>& posts_aux = it->second->posts_conta;

		for (int i = 0; i < posts_aux.size(); i++){
			this->posts_gerais.push_back(&posts_aux[i]);
		}
	}

	this->OrdenarPostsGerais();
}


void RedeSocial::OrdenarPostsGerais(){
	// Obs.: [](parametros){return ...} é uma função lambda, que definirá o critério de seleção
	std::sort(
		posts_gerais.begin(), posts_gerais.end(), 
        [](Post* p1, Post* p2) {return p1->GetScore() > p2->GetScore();}
	);
}

bool checaPostDuplicado(const std::vector<Post>& posts, const Post p) {
    return std::find(posts.begin(), posts.end(), p) != posts.end();
}

void RedeSocial::SetPilhaPostsPraExibir(){
	/*
	pilha_posts_pra_exibir = [
		post_seguindo_1, post_seguindo_2, ..., post_geral_rede_social_1, post_geral_rede_social_2, ...
	]
	*/
	conta_acessada->SetPostsContasSeguindo();
	this->ZerarPostsGerais();
	this->SetPostsGerais();

	// Garantir que a pilha esteja vazia
	std::stack<Post*> pilha_zerada;
	this->conta_acessada->pilha_posts_pra_exibir = pilha_zerada;

    for (Post* p : posts_gerais) {
        if (!checaPostDuplicado(conta_acessada->posts_seguindo, *p)) {
            this->conta_acessada->pilha_posts_pra_exibir.push(p);
        }
    }

    for (Post& post : conta_acessada->posts_seguindo) {
        this->conta_acessada->pilha_posts_pra_exibir.push(&post);
    }
}


void RedeSocial::PrintarPosts(int num_de_posts){
	if(this->conta_acessada->pilha_posts_pra_exibir.empty()){
		std::cout << "[!] Sem posts para mostrar! Que tal criar o 1° post da Rede? \n\n";
	} else{
		int count = 0;
		// std::cout << "\n\nLen pilha_post_exib: " << conta_acessada->pilha_posts_pra_exibir.size() << std::endl;
		while (!conta_acessada->pilha_posts_pra_exibir.empty() && count < num_de_posts) {
			Post* p = conta_acessada->pilha_posts_pra_exibir.top();
			std::cout << "------------------" << std::endl;
			std::cout << "| dono:" << GetConta(p->dono_id)->nome << "#" << p->dono_id << std::endl;
			std::cout << "| id_post: " << p->id << std::endl;
			std::cout << "| conteúdo:" << std::endl;
			std::cout << p->content << "\n\n";
			std::cout << "| score: " << p->GetScore() << std::endl;
			std::cout << "------------------" << std::endl;
			
			conta_acessada->pilha_posts_vistos.push(p);
			conta_acessada->pilha_posts_pra_exibir.pop();	

			count++;
		}
	}
}

void RedeSocial::ZerarPostsGerais(){
	std::vector<Post*> vetor_zerado;
	this->posts_gerais = vetor_zerado;
}