#include "Comentario.hpp"

Comentario::Comentario(long d, std::string cont){
	dono_id = d;
	conteudo = cont;
}

long Comentario::getDonoId() const{
	return dono_id;
}

std::string Comentario::getConteudo() const{
	return this->conteudo;
}