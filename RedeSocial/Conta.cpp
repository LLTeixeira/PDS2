#include <map>
#include "Conta.hpp"
#include <iostream>

Conta::Conta(std::string str, std::map <long, Conta*>* Contas) {
	nome = str;
	id = (*Contas).size() + 1;
	(*Contas)[id] = this;
}
