#include "Post.hpp"
#include <numeric>
#include <iostream>

Post::Post(std::string cont, long id_poster) {
	content = cont;
	dono_id = id_poster;
}

float Post::GetScore() {
	if (avaliacoes.size() > 0) {
		float soma = std::accumulate(avaliacoes.begin(), avaliacoes.end(), 0);
		return soma / avaliacoes.size();
	}
	else {
		std::cout << "No score" << std::endl;
		return 0.0;
	}
}
