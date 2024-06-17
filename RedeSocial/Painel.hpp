#pragma once

#include <stack>
#include "Conta.hpp"
#include "RedeSocial.hpp"

class Painel {       
    public:
        virtual void exibir(RedeSocial* rede_social, std::stack<Painel>& PilhaPainel);
        virtual ~Painel() = default;
};

class PainelInicial: public Painel {
    public:
        void exibir(RedeSocial* rede_social, std::stack<Painel>& PilhaPainel) override;
};

class PainelPrincipal: public Painel {
    private:
        Conta* conta;

    public:
        PainelPrincipal(Conta* conta);
        void exibir(RedeSocial* rede_social, std::stack<Painel>& PilhaPainel) override;
};