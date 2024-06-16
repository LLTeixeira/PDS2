#pragma once

#include "Conta.hpp"
#include "RedeSocial.hpp"

class Painel {       
    public:
        void exibir(RedeSocial& rede_social);
};

class PainelInicial: public Painel {
    public:
        void exibir(RedeSocial& rede_social);
};

class PainelPrincipal: public Painel {
    private:
        Conta* conta;

    public:
        PainelPrincipal(Conta* conta);
        void exibir(RedeSocial& rede_social);
};