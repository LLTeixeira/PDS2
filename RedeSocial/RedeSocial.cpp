// RedeSocial.cpp : Defines the entry point for the application.
//

#include "RedeSocial.hpp"
#include "Conta.hpp"
#include "Comentario.hpp"


class RedeSocial {
	private:
		std::map <long, Conta*> Contas;

	public:
		void CriarConta(std::string nome_str) {
			Conta* conta_ = new Conta(nome_str, Contas);
		}

		Conta* GetConta(long id_conta){
			if (id_conta > Contas.size() || id_conta <= 0){
				std::cout << "id_conta " << id_conta << " inexistente!" << std::endl;
				return nullptr;
			}

			return Contas[id_conta];
		}

		void PrintContas() {
			for (auto it = Contas.begin(); it != Contas.end(); ++it) {
				std::cout << "Key: " << it->first << ", Value: " << (*(it->second)).nome << std::endl;
			}
		}

		Post* FindPost(long dono_id, long id_post) {
			Conta* pConta;
			auto it = Contas.find(dono_id); 
			if (it == Contas.end()) {
				std::cout << "Account not found" << std::endl;
				return nullptr;
			}
			else {
				pConta = Contas[dono_id];
				if ((*pConta).Mural.size() < id_post) {
					std::cout << "Post not found" << std::endl;
					return nullptr;
				}
				else {
					return &(*pConta).Mural[id_post];
				}
			}
		}		
};


int main()
{
	RedeSocial rede_social = RedeSocial();
	
	rede_social.CriarConta("SysAdm");
	rede_social.CriarConta("GuidoVanRussen");
	rede_social.PrintContas();

	Conta *c1 = rede_social.GetConta(2);
	std::cout << c1->id << std::endl;



	return 0;
}
