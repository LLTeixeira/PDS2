#pragma once
#include <map>
#include <stack>
#include <string>
#include <vector>
#include "Post.hpp"

struct Notificacao{
    long id_dono, id_post;
};

class Conta {
    public:
        Conta(std::string nome, std::map <long, Conta*>& Contas);
        std::string nome;
        long id;
        std::vector<Post> posts_conta;
        std::vector<Post> posts_seguindo;
        std::stack<Post*> pilha_posts_pra_exibir;
        std::stack<Post*> pilha_posts_vistos;
        std::vector<Conta*> seguidores;
        std::vector<Conta*> seguindo;
        
        std::vector<Notificacao> posts_notificacoes;
        void CriarPost(std::string cont);
        void AvaliarPost(float av, Post& target);
        void Comentar(std::string com, Post& p);
        void PrintarSeguidores();
        void PrintarSeguindo();
        void SetPostsContasSeguindo();
        void OrdenarPostsSeguindo();
        int handlerPostsVistos(int qtd_posts_solicitada);
        void ZerarPilhaPostsVistos();
        void SeguirConta(Conta* outra_conta);
        void pararDeSeguir(Conta* outra_conta);
        bool estaSeguindo(Conta* outra_conta);  
        std::string getNome();
		void printarPostsContasSeguindo();
        void DeletarPost(long post_id);

		void AdicionarNotificacao(Post* post);
		void LimparNotificacoes();

        ~Conta();

        bool operator==(const Conta& other) const {
            return id == other.id;
        }
};
