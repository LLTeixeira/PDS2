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