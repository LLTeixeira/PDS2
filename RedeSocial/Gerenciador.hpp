#pragma once

#include "RedeSocial.hpp"
#include "Painel.hpp"


class Gerenciador {
	private:
		std::stack<Painel> PilhaPaineis;
		Painel PainelAtual;
		RedeSocial* rede_social;

	public:
		Gerenciador(std::stack<Painel> PilhaPaineis, RedeSocial* rede_social);
		void ConsumirPainel();
		void Iniciar();

};
