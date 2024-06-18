// RedeSocial.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include "Conta.hpp"

class RedeSocial {
	private:
		std::map <long, Conta*> Contas;
		Conta* conta_acessada;

	public:
		RedeSocial();
		void CriarConta(std::string nome_str);
		Conta* GetConta(long id_conta);
		Conta* GetConta(std::string nome_conta);
		void AcessarConta(Conta* conta);
		void PrintContas();

		Post* FindPost(long dono_id, long id_post);
};
