#include "Painel.hpp"
#include "RedeSocial.hpp"
#include <iostream>

void PainelInicial::exibir(RedeSocial& rede_social) {
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
                rede_social.VoltarPainel();
            case 1:
                std::cout << "Digite o nome que deseja usar: " << std::endl;
                std::cin >> nome;
                rede_social.CriarConta(nome);
                break;
            case 2:
                std::cout << "Digite o nome do usuário: " << std::endl;
                std::cin >> nome;
                conta = rede_social.GetConta(nome);
                rede_social.AcessaConta(conta);
                break;
            default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }
};

PainelPrincipal::PainelPrincipal(Conta* conta) {
    this->conta = conta;
}

void PainelPrincipal::exibir(RedeSocial& rede_social) {
        int escolha;
        std::cout << "Painel Principal:" << std::endl;
        std::cout << "[0] Sair" << std::endl;
        std::cin >> escolha;

        switch (escolha) {
            case 0:
                rede_social.VoltarPainel();
            default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }
   
}