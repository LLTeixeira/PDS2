#pragma once
#include <map>
#include <iostream>

class Conta {
public:

	std::string nome;
	long id;

	Conta(std::string nome, std::map <long, Conta*>* Contas);
};