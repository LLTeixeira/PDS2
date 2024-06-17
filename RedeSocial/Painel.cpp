#include "Painel.hpp"
#include <iostream>
#include <stack>

void  Painel::exibir(RedeSocial* rede_social, std::stack<Painel>& PilhaPainel) {
    std::cout << "Redirecionado para Painel Inicial" << std::endl;
    std::getchar();
    PilhaPainel.push(PainelInicial());
}

void PainelInicial::exibir(RedeSocial* rede_social, std::stack<Painel>& PilhaPainel) {
        int escolha;
        std::string nome;
        Conta* conta;

        std::cout << "Painel Inicial:" << std::endl;
        std::cout << "[0] Sair" << std::endl;
        std::cout << "[1] Criar conta"  << std::endl;
        std::cout << "[2] Entrar na conta"  << std::endl;
        std::cin >> escolha;

        switch (escolha) {
            case 0:
                break;
            case 1:
                std::cout << "Digite o nome que deseja usar: " << std::endl;
                std::cin >> nome;
                rede_social->CriarConta(nome);
                PilhaPainel.push(PainelInicial());
                break;
            case 2:
                std::cout << "Digite o nome do usuário: " << std::endl;
                std::cin >> nome;
                conta = rede_social->GetConta(nome);
                PilhaPainel.push(PainelPrincipal(conta));
                break;
            default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }
};

PainelPrincipal::PainelPrincipal(Conta* conta) {
    this->conta = conta;
}

void PainelPrincipal::exibir(RedeSocial* rede_social, std::stack<Painel>& PilhaPainel) {
        int escolha;
        std::cout << "Painel Principal:" << std::endl;
        std::cout << "[0] Sair" << std::endl;
        std::cin >> escolha;

        switch (escolha) {
            case 0:
                break;
            default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }
   
}