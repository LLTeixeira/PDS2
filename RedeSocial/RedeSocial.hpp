// RedeSocial.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <stack>
#include "Painel.hpp"
#include "Conta.hpp"

class RedeSocial {
	private:
		std::map <long, Conta*> Contas;
        std::stack<Painel> PilhaPaineis; 
        Painel PainelAtual;

	public:
        RedeSocial();

		void AcessaConta(Conta* conta);
		void CriarConta(std::string nome_str);
		Conta* GetConta(long id_conta);
		Conta* GetConta(std::string nome_conta);
		void PrintContas();

		Post* FindPost(long dono_id, long id_post);

		void ExibirPainelAtual();
		void VoltarPainel();
		void TrocarPainel(Painel proximo_painel);

		void Inicializa();
};
