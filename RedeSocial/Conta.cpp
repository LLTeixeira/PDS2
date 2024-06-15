#include "Conta.hpp"

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