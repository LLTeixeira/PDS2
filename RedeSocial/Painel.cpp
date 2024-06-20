#include "Painel.hpp"
#include <string>
#include <iostream>
#include <stack>

void  Painel::exibir(RedeSocial* rede_social) {
    this->indicador_proximo_painel = Indicador::PAINEL_INICIAL;

    std::cout << "Redirecionado para Painel Inicial" << std::endl;
    std::getchar();
}

void Painel::printPainel(){}

int Painel::get_indicador_proximo_painel()
{
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
                rede_social->PrintarPosts(3);
                this->set_indicador_proximo_painel(Indicador::PAINEL_PRINCIPAL);
                break;
            default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }
};


void PainelPrincipal::printPainel(){
    std::cout << "========================" << std::endl;
    std::cout << "| Painel Principal:" << std::endl;
    std::cout << "| [0] Sair" << std::endl;
    std::cout << "| [1] Ver mais posts"  << std::endl;
    std::cout << "| [2] Ver posts anteriores"  << std::endl;
    std::cout << "| [3] Criar um post"  << std::endl;
    std::cout << "| [4] Entrar no post"  << std::endl;
    std::cout << "| [5] Seguir / parar de seguir alguma conta"  << std::endl;
    std::cout << "| [6] Mostrar seguindo / seguidores"  << std::endl;
    std::cout << "| [7] Notificações  {qtd_notif}"<< std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "|> Código: ";
}

void PainelPrincipal::exibir(RedeSocial* rede_social) {
        int escolha_cod, qtd_posts_solicitada, qtd_posts_exibir;;
        std::string conteudo_post;

        this->printPainel();
        std::cin >> escolha_cod;
        std::cout << "\n\n";

        this->set_indicador_proximo_painel(Indicador::MANTER_PAINEL_ATUAL);

        switch (escolha_cod) {
            case 0:
                this->set_indicador_proximo_painel(Indicador::VOLTAR);
                break;
            case 1:
                std::cout << "|> Informe quantos posts quer ver: " << std::endl;
                std::cin >> qtd_posts_solicitada;
                rede_social->PrintarPosts(qtd_posts_solicitada);  
                break;
            case 2:
                std::cout << "|> Informe quantos posts anteriores quer ver: " << std::endl;
                std::cin >> qtd_posts_solicitada;
                qtd_posts_exibir = rede_social->conta_acessada->handlerPostsVistos(qtd_posts_solicitada);
                rede_social->PrintarPosts(qtd_posts_exibir); 
                break;
            case 3:
                std::cout << "|> Informe o conteúdo do post: " << std::endl;
                std::getline(std::cin >> std::ws, conteudo_post);
                rede_social->conta_acessada->CriarPost(conteudo_post);
                rede_social->SetPilhaPostsPraExibir();
                break;
            case 4:
                // TODO: Entrar no Post (ativar e criar o Painel Post)
                this->set_indicador_proximo_painel(Indicador::PAINEL_POST);
                break;
            case 5:
                // TODO: Seguir / parar de seguir alguma conta
                break;
            case 6:
                // TODO: Mostrar seguindo / seguidores
                break;
            case 7:
                // TODO: Notificações
                break;
            default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }  
}


void PainelPost::printPainel(){
    // TODO: Criar printPainel (Painel Post)
    std::cout << "========================" << std::endl;
    std::cout << "| Painel Post:" << std::endl;
    std::cout << "| [0] Sair" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "|> Código: ";
}

void PainelPost::exibir(RedeSocial* rede_social){
    // TODO: Criar exibir PainelPost
}

void PainelNotificacao::printPainel(){
    // TODO: Criar printPainel (Painel Notificação)
    std::cout << "========================" << std::endl;
    std::cout << "| Painel Notificação:" << std::endl;
    std::cout << "| [0] Sair" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "|> Código: ";
}

void PainelNotificacao::exibir(RedeSocial* rede_social){
    // TODO: Criar exibir PainelPost
}