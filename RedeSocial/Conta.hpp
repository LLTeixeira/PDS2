#pragma once
#include <map>
#include <stack>
#include "Post.hpp"


class Conta {
	public:
		Conta(std::string nome, std::map <long, Conta*>& Contas);
		std::string nome;
		long id;
		std::vector<Post> posts_conta;
		std::vector<Post> posts_seguindo;
		std::stack<Post*> pilha_posts_pra_exibir;
		std::stack<Post*> pilha_posts_vistos;
		std::vector<Conta> seguidores;
		std::vector<Conta> seguindo;
		std::vector<Post*> posts_notificacoes;
		void CriarPost(std::string cont);
		void AvaliarPost(float av, Post& target);
		void Comentar(std::string com, Post& p);
		void SeguirConta();
		void PrintarSeguidores();
		void PrintarSeguindo();
		void SetPostsContasSeguindo();
		void OrdenarPostsSeguindo();
		int handlerPostsVistos(int qtd_posts_solicitada);
		void ZerarPilhaPostsVistos();
};