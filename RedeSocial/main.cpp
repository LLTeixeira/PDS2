#include "RedeSocial.hpp"
#include "Painel.hpp"
#include "Gerenciador.hpp"
#include <iostream>
#include <vector>

int main()
{
	RedeSocial rede_social = RedeSocial();

	rede_social.CriarConta("Admin");

	Gerenciador gerenciador = Gerenciador(&rede_social);

	gerenciador.Iniciar();

	return 0;
}