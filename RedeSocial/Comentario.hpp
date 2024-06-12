#pragma once
#include <string>

class Comentario
{
public:
	Comentario(long dono_id, std::string conteudo);
	long dono_id;
	std::string conteudo;
};