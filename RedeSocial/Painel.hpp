#pragma once

#include <stack>
#include "Conta.hpp"
#include "RedeSocial.hpp"

class Painel {
    private:
        int indicador_proximo_painel;

    // protected:
    //     void setIndicadorProximoPainel(int indicador) {
    //         this->indicador_proximo_painel = indicador;
    //     }

    public:
        virtual void exibir(RedeSocial* rede_social);
        virtual ~Painel() = default;
        virtual void printPainel();
        int get_indicador_proximo_painel();
        void set_indicador_proximo_painel(int indicador);
};

class PainelInicial: public Painel {
    public:
        void exibir(RedeSocial* rede_social) override;
        void printPainel() override;
};

class PainelPrincipal: public Painel {
    public:
        void exibir(RedeSocial* rede_social) override;
        void printPainel() override;
        int get_qtd_notificacoes(RedeSocial* rede_social);
        void printPainel(int qtd_notificacoes);
};


class PainelNotificacao: public Painel {
    public:
        void exibir(RedeSocial* rede_social) override;
        void printPainel() override;
        void printPostNotificacao(std::vector<Post*> notificacoes);
};

enum Indicador {
    VOLTAR = -1,
    MANTER_PAINEL_ATUAL = 0,
    PAINEL_INICIAL = 1,
    PAINEL_PRINCIPAL = 2,
    PAINEL_POST = 3,
    PAINEL_NOTIFICACAO = 4,
};
