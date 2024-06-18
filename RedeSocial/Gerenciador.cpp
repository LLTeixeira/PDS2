#include <iostream>
#include "Gerenciador.hpp"


Gerenciador::Gerenciador(RedeSocial* rede_social) {
    this->PilhaPaineis = PilhaPaineis;
    this->rede_social = rede_social;
}

void Gerenciador::UsarPilha() {
    if (this->PilhaPaineis.empty()) {
        std::cout << "Saindo.." << std::endl;
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
    
    case Indicador::NADA:
        break;

    case Indicador::INICIAL:
        this->PilhaPaineis.push(&this->pi);
        break;

    case Indicador::PRINCIPAL:
        this->PilhaPaineis.push(&this->pp);
        break;

    default:
        break;
    }
}

void Gerenciador::Iniciar() {
    this->pi.set_indicador_proximo_painel(Indicador::NADA);

	this->PilhaPaineis.push(&pi);
    this->UsarPilha();
}
