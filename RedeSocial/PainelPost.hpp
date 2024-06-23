#pragma once
#include "Painel.hpp"
#include "Post.hpp"

class PainelPost : public Painel {

    public:
        void exibir(RedeSocial* rede_social) override;
        void printPainel() override;

        void comentarPost(RedeSocial* rede_social);
        void exibirComentarios(RedeSocial* rede_social);
        void seguirOuPararDeSeguirDono(RedeSocial* rede_social);
        void avaliarPost(RedeSocial* rede_social);
        void compartilharPost(RedeSocial* rede_social);
};