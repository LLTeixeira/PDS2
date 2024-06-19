#include "Conta.hpp"
#include <algorithm>


Conta::Conta(std::string str_nome, std::map <long, Conta*>& Contas) {
	nome = str_nome;
	id = Contas.size() + 1;
	Contas[id] = this;
}

void Conta::CriarPost(std::string cont) {
	Post new_post = Post(cont, this->id);
	Mural.push_back(new_post);
	new_post.id = Mural.size() - 1;
}

void Conta::AvaliarPost(float av, Post& post_target) {
	post_target.avaliacoes.push_back(av);
}

void Conta::Comentar(std::string com, Post& p) {
	Comentario comment = Comentario(this->id, com);
	p.comentarios.push_back(comment);
}

void Conta::ObterMuralContasSeguindo(){
	for (auto it = this->seguindo.begin(); it != this->seguindo.end(); ++it) {
        std::vector<Post> mural_seguindo_aux = it->Mural;

        this->mural_seguindo.insert(this->mural_seguindo.end(), mural_seguindo_aux.begin(), mural_seguindo_aux.end());
    }

	this->OrdenarMuralSeguindo();
}

void Conta::OrdenarMuralSeguindo(){
	// Obs.: [](parametros){return ...} é uma função lambda, que definirá o critério de seleção
	std::sort(
		this->mural_seguindo.begin(), this->mural_seguindo.end(), 
        [](Post& p1, Post& p2) {return p1.GetScore() > p2.GetScore();}
	);
}