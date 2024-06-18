#pragma once

#include <stack>
#include "Conta.hpp"
#include "RedeSocial.hpp"

class Painel {
    private:
        int indicador_proximo_painel;

    public:
        virtual void exibir(RedeSocial* rede_social);
        virtual ~Painel() = default;
        int get_indicador_proximo_painel();
        void set_indicador_proximo_painel(int indicador);
};

class PainelInicial: public Painel {
    public:
        void exibir(RedeSocial* rede_social) override;
};

class PainelPrincipal: public Painel {
    public:
        void exibir(RedeSocial* rede_social) override;
};

enum Indicador {
    VOLTAR = -1,
    NADA = 0,
    INICIAL = 1,
    PRINCIPAL = 2
};