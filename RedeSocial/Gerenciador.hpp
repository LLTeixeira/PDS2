#pragma once

#include "RedeSocial.hpp"
#include "Painel.hpp"


class Gerenciador {
	private:
		std::stack<Painel*> PilhaPaineis;
		RedeSocial* rede_social;
		PainelInicial pi;
		PainelPrincipal pp;

	public:
		Gerenciador(RedeSocial* rede_social);
		void UsarPilha();
		void IntepretaIndicador(Painel* painel);
		void Iniciar();

};
