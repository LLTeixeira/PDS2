#pragma once
#include <vector>
#include "Comentario.hpp"

class Post {
	public:
		Post(std::string cont, long poster);
		long id;
		long dono_id;
		std::string content;
		std::vector<float> avaliacoes;
		std::vector<Comentario> comentarios;
		float GetScore();
};