#include "Post.hpp"
#include <numeric>
#include <iostream>

Post::Post(std::string conteudo, long id_poster) {
	content = conteudo;
	dono_id = id_poster;
}

float Post::GetScore() {
	if (avaliacoes.size() > 0) {
		float soma = std::accumulate(avaliacoes.begin(), avaliacoes.end(), 0);
		return soma / avaliacoes.size();
	}
	else {
		// std::cout << "No score" << std::endl;
		return 0.0;
	}
}

void Post::printPostFormatado(){
	std::cout << "------------------" << std::endl;
	std::cout << "| id_dono:" << this->dono_id << std::endl;
	std::cout << "| id_post: " << this->id << std::endl;
	std::cout << "| conteúdo:" << std::endl;
	std::cout << this->content << "\n\n";
	std::cout << "| score: " << this->GetScore() << std::endl;
	std::cout << "------------------" << std::endl;
}
