#include "Painel.hpp"
#include "RedeSocial.hpp"
#include <string>
#include <iostream>
#include <stack>


void PainelNotificacao::printPainel(){
    std::cout << "========================" << std::endl;
    std::cout << "| Painel Notificação:" << std::endl;
    std::cout << "| [0] Sair" << std::endl;
    std::cout << "| [1] Entrar no post" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "|> Código: ";
}

void PainelNotificacao::printPostNotificacao(RedeSocial* rede_social){
    for (Notificacao notif : rede_social->conta_acessada->posts_notificacoes){
        rede_social->FindPost(notif.id_dono, notif.id_post)->printPostFormatado();
        }
}



void PainelNotificacao::exibir(RedeSocial* rede_social) {
    int escolha_cod;
    long id_dono, id_post;
    Post* post;
    
    this->printPostNotificacao(rede_social);
    this->printPainel();
    std::cin >> escolha_cod;
    std::cout << "\n\n";

    this->set_indicador_proximo_painel(Indicador::MANTER_PAINEL_ATUAL);

    switch (escolha_cod){
        case 0:
            this->set_indicador_proximo_painel(Indicador::VOLTAR);
            rede_social->conta_acessada->LimparNotificacoes();
            break;
        case 1:
            std::cout << "|> Informe o ID do dono: " << std::endl;
            std::cin >> id_dono;
            std::cout << "|> Informe o ID do post: " << std::endl;
            std::cin >> id_post;
            post = rede_social->FindPost(id_dono, id_post);
            if(post){
                rede_social->post_atual = post;
                this->set_indicador_proximo_painel(Indicador::PAINEL_POST);
            }else{
                std::cout << "[!] Post não encontrado" << std::endl;
            }
            break;
        default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }
    

}