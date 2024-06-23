#include <iostream>
#include "Conta.hpp"
#include <algorithm>


Conta::Conta(std::string str_nome, std::map <long, Conta*>& Contas) {
	nome = str_nome;
	id = Contas.size() + 1;
	Contas[id] = this;
}

void Conta::CriarPost(std::string conteudo) {
	Post new_post = Post(conteudo, this->id);
	new_post.id = posts_conta.size();
	posts_conta.push_back(new_post);
	std::cout << "[+] Post criado com sucesso!\n\n";
}

void Conta::AvaliarPost(float av, Post& post_target) {
	post_target.avaliacoes.push_back(av);
}

void Conta::Comentar(std::string com, Post& p) {
	Comentario comment = Comentario(this->id, com);
	p.comentarios.push_back(comment);
}

void Conta::SetPostsContasSeguindo(){
	for (auto it = this->seguindo.begin(); it != this->seguindo.end(); ++it) {
        std::vector<Post> posts_seguindo_aux = (*it)->posts_conta;

        this->posts_seguindo.insert(this->posts_seguindo.end(), posts_seguindo_aux.begin(), posts_seguindo_aux.end());
    }

	this->OrdenarPostsSeguindo();
}

void Conta::OrdenarPostsSeguindo(){
	// Obs.: [](parametros){return ...} é uma função lambda, que definirá o critério de seleção
	std::sort(
		this->posts_seguindo.begin(), this->posts_seguindo.end(), 
        [](Post& p1, Post& p2) {return p1.GetScore() > p2.GetScore();}
	);
}

int Conta::handlerPostsVistos(int qtd_posts_solicitada) {
    int count = 0;

    while (!this->pilha_posts_vistos.empty() && count < qtd_posts_solicitada) {
        this->pilha_posts_pra_exibir.push(this->pilha_posts_vistos.top());
        this->pilha_posts_vistos.pop();
        count++;
    }

    return count;
}

void Conta::ZerarPilhaPostsVistos(){
	std::stack<Post*> pilha_zerada;
	this->pilha_posts_vistos = pilha_zerada;
}

bool Conta::estaSeguindo(Conta* outra_conta){
    for (const Conta* conta : this->seguindo) {
        if (conta->id == outra_conta->id) {
            return true;
        }
    }
    return false;
}

void Conta::SeguirConta(Conta* outra_conta) {
    if (outra_conta != nullptr && outra_conta != this) {
        this->seguindo.push_back(outra_conta);
        outra_conta->seguidores.push_back(this);
        std::cout << "[+]" << this->nome << "#" << this->id << " agora está seguindo " << outra_conta->nome << "." << std::endl;
    } else {
        std::cout << "[-] Erro ao tentar seguir a conta." << std::endl;
    }
}

void Conta::pararDeSeguir(Conta* outra_conta){
	if (outra_conta != nullptr && outra_conta != this) {
        auto it = std::remove(this->seguindo.begin(), this->seguindo.end(), outra_conta);
		this->seguindo.erase(it, this->seguindo.end());
		std::cout << "[+] Você deixou de seguir " << outra_conta->nome << "#" << outra_conta->id << std::endl; 
    } else {
        std::cout << "[-] Erro ao tentar deixar de seguir a conta!" << std::endl;
    }
}

void Conta::PrintarSeguidores() {
    std::cout << "Seguidores de " << this->nome << ":" << std::endl;
    for (Conta* seguidor : this->seguidores) {
        std::cout << "- " << seguidor->nome << std::endl;
    }
}

void Conta::PrintarSeguindo() {
    std::cout << "Você, <" << this->nome << ">, está seguindo:" << std::endl;
    for (Conta* seguindo_ : this->seguindo) {
        std::cout << "- " << seguindo_->nome << "#" << seguindo_->id << std::endl;
    }
}