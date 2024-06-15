#pragma once
#include <map>
#include "Post.hpp"

class Conta {
	public:
		Conta(std::string nome, std::map <long, Conta*>& Contas);
		std::string nome;
		long id;
		std::vector<Post> Mural;
		std::vector<Conta> seguidores;
		std::vector<Conta> seguindo;
		void CriarPost(std::string cont);
		void AvaliarPost(float av, Post& target);
		void Comentar(std::string com, Post& p);
		void SeguirConta();
		void PrintarSeguidores();
		void PrintarSeguindo();
};