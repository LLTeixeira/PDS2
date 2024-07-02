#include "RedeSocial.hpp"
#include "Painel.hpp"
#include "Gerenciador.hpp"
#include <iostream>
#include <vector>

int main()
{
	RedeSocial rede_social = RedeSocial();

	rede_social.CriarConta("admin");
	rede_social.CriarConta("a");
	rede_social.CriarConta("Admin");
	rede_social.GetConta("a")->SeguirConta(rede_social.GetConta("admin"));
	rede_social.GetConta("admin")->CriarPost("C++ é um saco");
	rede_social.GetConta("admin")->CriarPost("Odeio C++");
	rede_social.DeletarConta("a");
	rede_social.GetConta("admin")->DeletarPost(1);

	Gerenciador gerenciador = Gerenciador(&rede_social);

	gerenciador.Iniciar();

	return 0;
}