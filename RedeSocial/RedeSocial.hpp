#pragma once
#include "Conta.hpp"

class RedeSocial {
	private:
		std::map <long, Conta*> Contas;
		std::vector<Post*> posts_gerais;

	public:
		Conta* conta_acessada;
		Post* post_atual;
		RedeSocial();
		void CriarConta(std::string nome_str);
		Conta* GetConta(long id_conta);
		Conta* GetConta(std::string nome_conta);
		void AcessarConta(Conta* conta);
		void PrintContas();
		void PrintarPosts(int num_de_posts);
		Post* FindPost(long dono_id, long id_post);
		void SetPostsGerais();
		void OrdenarPostsGerais();
		void SetPilhaPostsPraExibir();
		void ZerarPostsGerais();
		void DeletarConta(long id_conta);
		void DeletarConta(std::string nome_conta);

		std::vector<Notificacao> GetNotificacoes();
        void LimparNotificacoes();
};
