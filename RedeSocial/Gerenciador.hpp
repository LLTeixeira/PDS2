#pragma once

#include "RedeSocial.hpp"
#include "PainelPost.hpp"
#include "Painel.hpp"

class Gerenciador {
    private:
        std::stack<Painel*> PilhaPaineis;
        RedeSocial* rede_social;
        PainelInicial painel_inicial;
        PainelPrincipal painel_principal;
        PainelPost painel_post;
        PainelNotificacao painel_notificacao;

    public:
        Gerenciador(RedeSocial* rede_social);
        void UsarPilha();
        void IntepretaIndicador(Painel* painel);
        void Iniciar();
};
