#pragma once
#include <vector>
#include "Comentario.hpp"

class Post {
public:
	std::string content;
	long id;
	std::vector<float> avaliacoes;
	long dono;
	std::vector<Comentario> comentarios;
	Post(std::string cont, long poster);
	float GetScore();
};