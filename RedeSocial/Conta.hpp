#pragma once
#include <map>
#include "Post.hpp"

class Conta {
public:

	std::string nome;
	long id;
	Conta(std::string nome, std::map <long, Conta*>& Contas);
	std::vector<Post> Mural;
	void CreatePost(std::string cont);
	void Avaliar(float av, Post& target);
	void Comentar(std::string com, Post& p);
};