#include "Painel.hpp"
#include <string>
#include <iostream>
#include <stack>


void PainelInicial::printPainel(){
    std::cout << "========================" << std::endl;
    std::cout << "| Painel Inicial:" << std::endl;
    std::cout << "| [0] Sair" << std::endl;
    std::cout << "| [1] Criar conta"  << std::endl;
    std::cout << "| [2] Entrar na conta"  << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "|> Código: ";
}

void PainelInicial::exibir(RedeSocial* rede_social) {
        std::string nome;
        Conta* conta;
        int escolha_cod;
        this->printPainel();
        std::cin >> escolha_cod;
        std::cout << "\n\n";

        this->set_indicador_proximo_painel(Indicador::MANTER_PAINEL_ATUAL);

        switch (escolha_cod) {
            case 0:
                this->set_indicador_proximo_painel(Indicador::VOLTAR);
                break;
            case 1:
                std::cout << "|> Digite o nome que deseja usar: " << std::endl;
                std::cin >> nome;
                rede_social->CriarConta(nome);
                break;
            case 2:
                std::cout << "|> Digite o nome do usuário: " << std::endl;
                std::cin >> nome;
                conta = rede_social->GetConta(nome);
                if (conta == nullptr){
                    std::cout << "[!] Conta inexistente [!] \n";
                    break;
                }

                rede_social->AcessarConta(conta);
                rede_social->SetPilhaPostsPraExibir();
                std::cout << "\n";
                std::cout << "☷ POSTAGENS\n\n";
                rede_social->PrintarPosts(1);
                this->set_indicador_proximo_painel(Indicador::PAINEL_PRINCIPAL);
                break;
            default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }
};