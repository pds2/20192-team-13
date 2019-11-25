#ifndef STACK_H
#define STACK_H

#include "Carta.hpp"
#include "Baralho.hpp"

class Pilha : public Baralho{
public:
	Baralho cartasJogadas;

public:
	Pilha();
	void imprimeTopo(std::map<int, std::string> mapeamentoCartas, std::map<int, std::string> mapeamentoCores, int corAuxiliar);
	void reembaralhar(Baralho *baralhoTeste);
};

#endif