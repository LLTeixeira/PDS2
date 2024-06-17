#include <iostream>
#include "Gerenciador.hpp"


Gerenciador::Gerenciador(std::stack<Painel> PilhaPaineis, RedeSocial* rede_social) {
    this->PilhaPaineis = PilhaPaineis;
    this->rede_social = rede_social;
}

void Gerenciador::ConsumirPainel() {
    if (this->PilhaPaineis.empty()) {
        std::cout << "Saindo.." << std::endl;
        exit(0);
    }

    this->PainelAtual = this->PilhaPaineis.top();
    this->PilhaPaineis.pop();

    this->PainelAtual.exibir(this->rede_social, this->PilhaPaineis);

    this->ConsumirPainel();
}

void Gerenciador::Iniciar() {
    ConsumirPainel();
}
