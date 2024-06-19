#include "Painel.hpp"
#include <iostream>
#include <stack>

void  Painel::exibir(RedeSocial* rede_social) {
    this->indicador_proximo_painel = Indicador::PAINEL_INICIAL;

    std::cout << "Redirecionado para Painel Inicial" << std::endl;
    std::getchar();
}

int Painel::get_indicador_proximo_painel() {
    return this->indicador_proximo_painel;
}

void Painel::set_indicador_proximo_painel(int indicador) {
    this->indicador_proximo_painel = indicador;
}

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
        printPainel();
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
                rede_social->PreencherMuralGeral();
                std::cout << "-----------------------------" << std::endl;
                std::cout << "=> POSTAGENS:" << std::endl;
                std::cout << "-----------------------------" << std::endl;
                rede_social->PrintarPosts(3);
                this->set_indicador_proximo_painel(Indicador::PAINEL_PRINCIPAL);
                break;
            default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }
};

void PainelPrincipal::exibir(RedeSocial* rede_social) {
        
        int escolha_cod;
        printPainel();
        std::cin >> escolha_cod;
        std::cout << "\n\n";

        this->set_indicador_proximo_painel(Indicador::MANTER_PAINEL_ATUAL);

        switch (escolha_cod) {
            case 0:
                this->set_indicador_proximo_painel(Indicador::VOLTAR);
                break;
            case 1:
                int qtd_posts;
                std::cout << "|> Informe quantos posts quer ver: " << std::endl;
                std::cin >> qtd_posts;
                rede_social->PrintarPosts(qtd_posts);  // TODO: Criar lógica para gravar quais posts já foram exibidos, para não repetir informações
                break;
            case 2:
                // TODO: Criar post / painel post
                this->set_indicador_proximo_painel(Indicador::PAINEL_POST);
                break;
            case 3:
                // TODO: Entrar no Post
                break;
            case 4:
                // TODO: Seguir / parar de seguir alguma conta
                break;
            case 5:
                // TODO: Mostrar seguindo / seguidores
                break;
            case 6:
                // TODO: Notificações
                break;
            default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }  
}

void PainelPrincipal::printPainel(){
    std::cout << "========================" << std::endl;
    std::cout << "| Painel Principal:" << std::endl;
    std::cout << "| [0] Sair" << std::endl;
    std::cout << "| [1] Ver mais posts"  << std::endl;
    std::cout << "| [2] Criar um post"  << std::endl;
    std::cout << "| [3] Entrar no post"  << std::endl;
    std::cout << "| [4] Seguir / parar de seguir alguma conta"  << std::endl;
    std::cout << "| [5] Mostrar seguindo / seguidores"  << std::endl;
    std::cout << "| [6] Notificações  {qtd_notif}"<< std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "|> Código: ";
}