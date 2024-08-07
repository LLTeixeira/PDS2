#include "Painel.hpp"
#include "PainelPost.hpp"
#include "RedeSocial.hpp"
#include <string>
#include <iostream>
#include <stack>


void PainelPrincipal::printPainel(int qtd_notificacoes){
    std::cout << "========================" << std::endl;
    std::cout << "| Painel Principal:" << std::endl;
    std::cout << "| [0] Sair" << std::endl;
    std::cout << "| [1] Ver mais posts"  << std::endl;
    std::cout << "| [2] Ver posts anteriores"  << std::endl;
    std::cout << "| [3] Criar um post"  << std::endl;
    std::cout << "| [4] Entrar no post"  << std::endl;
    std::cout << "| [5] Seguir / parar de seguir alguma conta"  << std::endl;
    std::cout << "| [6] Mostrar seguindo / seguidores"  << std::endl;
    std::cout << "| [7] Notificações {"<< qtd_notificacoes << "}" << std::endl;
    std::cout << "| [8] Deletar conta" << std::endl;
    std::cout << "| [9] Deletar post" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "|> Código: ";
}

int PainelPrincipal::get_qtd_notificacoes(RedeSocial* rede_social){
    return rede_social->conta_acessada->posts_notificacoes.size();
}

void PainelPrincipal::printPainel(){

}

void PainelPrincipal::exibir(RedeSocial* rede_social) {
        int escolha_cod, qtd_posts_solicitada, qtd_posts_exibir;
        long id_dono, id_post;
        std::string conteudo_post, nome_conta;
        Post* post;
        Conta* outra_conta;
        std::string conta_a_deletar;

        this->printPainel(this->get_qtd_notificacoes(rede_social));
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
                rede_social->conta_acessada->ZerarPilhaPostsVistos();
                break;
            case 4:
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
            case 5:
                std::cout << "|> Informe o nome da conta que deseja seguir ou parar de seguir: " << std::endl;
                std::getline(std::cin >> std::ws, nome_conta);
                
                outra_conta = rede_social->GetConta(nome_conta);
                if (outra_conta != nullptr) {
                    if (rede_social->conta_acessada->estaSeguindo(outra_conta)) {                        
                        rede_social->conta_acessada->pararDeSeguir(outra_conta);
                    } else {
                        rede_social->conta_acessada->SeguirConta(outra_conta);
                    }
                } else {
                    std::cout << "Conta " << nome_conta << " não encontrada." << std::endl;
                }
                break;
            case 6:
                rede_social->conta_acessada->PrintarSeguidores();
                rede_social->conta_acessada->PrintarSeguindo();
                break;
            case 7:
                this->set_indicador_proximo_painel(Indicador::PAINEL_NOTIFICACAO);
                break;
            case 8:
                std::cout << "|> Informe o nome da conta: " << std::endl;
                std::getline(std::cin >> std::ws, conta_a_deletar);
                if (rede_social->GetConta(conta_a_deletar) == nullptr) {
                    std::cout << "[!] Conta não encontrada " << std::endl;
                }
                else {
                    rede_social->DeletarConta(conta_a_deletar);
                    std::cout << "[!] Conta "<< conta_a_deletar << " deletada!" << std::endl;
                }
                break;
            case 9:
                std::cout << "|> Informe o id do post: " << std::endl;
                std::cin >> id_post;
                if (rede_social->conta_acessada->posts_conta.size() >= id_post - 1){
                    std::cout << "[!] Post não encontrado " << std::endl;
                }
                else {
                    rede_social->conta_acessada->DeletarPost(id_post);
                    std::cout << "[!] Post deletado!" << std::endl;
                }
                break;
            default:
                std::cout << "Escolha inválida!" << std::endl;
                break;
    }  
}
