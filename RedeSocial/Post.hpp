#pragma once
#include <vector>
#include <string>
#include "Comentario.hpp"

class Post {
	public:
		Post(std::string cont, long id_poster);
		const std::vector<Comentario>& getComentarios() const;
		
		long id;
		long dono_id;
		std::string content;
		std::vector<float> avaliacoes;
		std::vector<Comentario> comentarios;
		float GetScore();

		bool operator==(const Post& other) const {
        return id == other.id && dono_id == other.dono_id && content == other.content;
    	}
};