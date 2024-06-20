#include <iostream>
#include "Gerenciador.hpp"


Gerenciador::Gerenciador(RedeSocial* rede_social) {
    this->PilhaPaineis = PilhaPaineis;
    this->rede_social = rede_social;
}

// Função recursiva para usar todas as pilhas
void Gerenciador::UsarPilha() {
    if (this->PilhaPaineis.empty()) {
        std::cout << "Fechando a rede social..." << std::endl;
        exit(0);
    }

    Painel* PainelAtual = this->PilhaPaineis.top();

    PainelAtual->exibir(this->rede_social);

    this->IntepretaIndicador(PainelAtual);

    this->UsarPilha();
}

void Gerenciador::IntepretaIndicador(Painel* painel) {
    switch (painel->get_indicador_proximo_painel())
    {
    case Indicador::VOLTAR:
        this->PilhaPaineis.pop();
        break;
    
    case Indicador::MANTER_PAINEL_ATUAL:
        break;

    case Indicador::PAINEL_INICIAL:
        this->PilhaPaineis.push(&this->painel_inicial);
        break;

    case Indicador::PAINEL_PRINCIPAL:
        this->PilhaPaineis.push(&this->painel_principal);
        break;

    case Indicador::PAINEL_POST:
        this->PilhaPaineis.push(&this->painel_post);
        break;

    case Indicador::PAINEL_NOTIFICACAO:
        this->PilhaPaineis.push(&this->painel_notificacao);
        break;

    default:
        break;
    }
}

void Gerenciador::Iniciar() {
    this->painel_inicial.set_indicador_proximo_painel(Indicador::MANTER_PAINEL_ATUAL);

	this->PilhaPaineis.push(&painel_inicial);
    this->UsarPilha();
}
