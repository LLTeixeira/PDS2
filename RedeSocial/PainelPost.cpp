#include "Painel.hpp"
#include "PainelPost.hpp"
#include "Comentario.hpp"
#include "RedeSocial.hpp"
#include <string>
#include <iostream>
#include <stack>


void PainelPost::printPainel(){
    std::cout << "========================" << std::endl;
    std::cout << "| Painel Post:" << std::endl;
    std::cout << "| [0] Sair" << std::endl;
    std::cout << "| [1] Comentar" << std::endl;
    std::cout << "| [2] Ver comentários do Post" << std::endl;
    std::cout << "| [3] Seguir / Parar de seguir o Dono" << std::endl;
    std::cout << "| [4] Avaliar" << std::endl;
    std::cout << "| [5] Compartilhar" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "|> Código: ";
}

void PainelPost::exibir(RedeSocial* rede_social){
   int escolha_cod;
    rede_social->post_atual->printPostFormatado();
    this->printPainel();
    std::cin >> escolha_cod;
    std::cin.ignore();

    set_indicador_proximo_painel(MANTER_PAINEL_ATUAL);

    switch(escolha_cod){
        case 0: 
            this->set_indicador_proximo_painel(Indicador::VOLTAR);
            break;
        case 1:
            this->comentarPost(rede_social);
            break;
        case 2:
            this->exibirComentarios(rede_social);
            break;
        case 3:
            this->seguirOuPararDeSeguirDono(rede_social);
            break;
        case 4:
            this->avaliarPost(rede_social);
            break;
        case 5:
            this->compartilharPost(rede_social);
            break;
        default:
            std::cout << "Escolha inválida!" << std::endl;
            break;
    }
}

void PainelPost::comentarPost(RedeSocial* rede_social){
    std::string conteudo_comentario;
    std::cout << "|> Escreva seu comentário:" << std::endl;
    std::getline(std::cin >> std::ws, conteudo_comentario);
    
    rede_social->conta_acessada->Comentar(conteudo_comentario, *rede_social->post_atual);

    std::cout << "Comentário adicionado com sucesso!" << std::endl;
}

void PainelPost::exibirComentarios(RedeSocial* rede_social){
    if (rede_social->post_atual->comentarios.empty()){
        std::cout << "[!] Este post não possui comentários." << std::endl;
    } else {
        std::cout << "[+] Comentários do Post:" << std::endl;
        for(const auto& comentario : rede_social->post_atual->comentarios){
            Conta* dono_comentario = rede_social->GetConta(comentario.getDonoId());
            std::cout << " - " << comentario.getConteudo() << " (por " << dono_comentario->nome << "#" << dono_comentario->id << ")" << std::endl;
        }
    }
}

void PainelPost::seguirOuPararDeSeguirDono(RedeSocial* rede_social){
    Conta* dono_post = rede_social->GetConta(rede_social->post_atual->dono_id);
    if(dono_post){
        if(rede_social->conta_acessada->estaSeguindo(dono_post)){
            rede_social->conta_acessada->pararDeSeguir(dono_post);
            std::cout << "[+] Você parou de seguir " << dono_post->nome << "." << std::endl;
        }else{
            rede_social->conta_acessada->SeguirConta(dono_post);
            std::cout << "[+] Você começou a seguir " << dono_post->nome << "#" << dono_post->id << std::endl;
        }
    }else{
        std::cout << "[-] Dono do post não encontrado." << std::endl;
    }
}

void PainelPost::avaliarPost(RedeSocial* rede_social){
    float avaliacao;
    std::cout << "|> Dê sua avaliação de (0 a 5): ";
    std::cin >> avaliacao;
    if (avaliacao >= 0 && avaliacao <= 5){
        rede_social->post_atual->avaliacoes.push_back(avaliacao);
        std::cout << "Avaliação adicionada!" << std::endl;
    }else{
        std::cout << "Avaliação inválida!" << std::endl;
    }
}

void PainelPost::compartilharPost(RedeSocial* rede_social){
    std::string mensagem_compartilhamento;
    Conta* dono_post_atual = rede_social->GetConta(rede_social->post_atual->dono_id);

    std::cout << "|> Escreva uma mensagem para compartilhar: ";
    std::getline(std::cin >> std::ws, mensagem_compartilhamento);

    //Criar um novo post com a mensagem de compartilhamento e as informações do post compartilhado 
    std::string conteudo_novo_post = mensagem_compartilhamento + "\n\n=> Post compartilhado:\n";
    conteudo_novo_post += "     | dono_post_original: " + dono_post_atual->nome + "#" + std::to_string(dono_post_atual->id) + "\n";
    conteudo_novo_post += "     | id_post_original: " + std::to_string(rede_social->post_atual->id) + "\n";
    conteudo_novo_post += "     | conteúdo: \n  " + rede_social->post_atual->content + "\n";

    rede_social->conta_acessada->CriarPost(conteudo_novo_post);
    rede_social->SetPilhaPostsPraExibir();
    rede_social->conta_acessada->ZerarPilhaPostsVistos();

    std::cout << "Post compartilhado com sucesso!" << std::endl;
}