#pragma once
#include <string>

class Comentario
{
private:
	long dono_id;
	std::string conteudo;

public:
	Comentario(long dono_id, std::string conteudo);
	long getDonoId() const;
	std::string getConteudo() const;
};