#include "RedeSocial.hpp"
#include "Painel.hpp"
#include "Gerenciador.hpp"
#include <iostream>

int main()
{
	RedeSocial rede_social;

	rede_social.CriarConta("Admin");

	std::stack<Painel> PilhaPainel;
	PilhaPainel.push(PainelInicial());

	std::cout << PilhaPainel.empty() << std::endl;

	Gerenciador gerenciador = Gerenciador(PilhaPainel, &rede_social);

	gerenciador.Iniciar();

	return 0;
}