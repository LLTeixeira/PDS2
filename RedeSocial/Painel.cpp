#include "Painel.hpp"
#include <iostream>
#include <stack>

void  Painel::exibir(RedeSocial* rede_social) {
    this->indicador_proximo_painel = Indicador::INICIAL;

    std::cout << "Redirecionado para Painel Inicial" << std::endl;
    std::getchar();
}

int Painel::get_indicador_proximo_painel() {
    return this->indicador_proximo_painel;
}

void Painel::set_indicador_proximo_painel(int indicador) {
    this->indicador_proximo_painel = indicador;
}

void PainelInicial::exibir(RedeSocial* rede_social) {
        int escolha;
        std::string nome;
        Conta* conta;

        std::cout << "Painel Inicial:" << std::endl;
        std::cout << "[0] Sair" << std::endl;
        std::cout << "[1] Criar conta"  << std::endl;
        std::cout << "[2] Entrar na conta"  << std::endl;
        std::cin >> escolha;

        this->set_indicador_proximo_painel(Indicador::NADA);

        switch (escolha) {
            case 0:
                this->set_indicador_proximo_painel(Indicador::VOLTAR);
                break;
            case 1:
                std::cout << "Digite o nome que deseja usar: " << std::endl;
                std::cin >> nome;
                rede_social->CriarConta(nome);
                break;
            case 2:
                std::cout << "Digite o nome do usuário: " << std::endl;
                std::cin >> nome;
                conta = rede_social->GetConta(nome);
                rede_social->AcessarConta(conta);
                this->set_indicador_proximo_painel(Indicador::PRINCIPAL);
                break;
            default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }
};

void PainelPrincipal::exibir(RedeSocial* rede_social) {
        int escolha;
        std::cout << "Painel Principal:" << std::endl;
        std::cout << "[0] Sair" << std::endl;
        std::cin >> escolha;

        switch (escolha) {
            case 0:
                this->set_indicador_proximo_painel(Indicador::VOLTAR);
                break;
            default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }
   
}