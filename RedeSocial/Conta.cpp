#include "Conta.hpp"

Conta::Conta(std::string str, std::map <long, Conta*>& Contas) {
	nome = str;
	id = Contas.size() + 1;
	Contas[id] = this;
}

void Conta::CreatePost(std::string cont) {
	Post new_post = Post(cont, this->id);
	Mural.push_back(new_post);
	new_post.id = Mural.size() - 1;
}

void Conta::Avaliar(float av, Post& target) {
	target.avaliacoes.push_back(av);
}

void Conta::Comentar(std::string com, Post& p) {
	Comentario comment = Comentario(this->id, com);
	p.comentarios.push_back(comment);
}