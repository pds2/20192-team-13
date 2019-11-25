#ifndef DECK_H
#define DECK_H

#include <algorithm>
#include <iostream> 
#include <vector>
#include "Carta.hpp"
#include <map>
#include <random>

class Baralho{
private:
	std::vector<Carta> baralho;

public:
	Baralho();
	//consultas
	Carta topoDoBaralho();
	Carta fundoDoBaralho();
	Carta retornaCarta(int indice);
	
	//funçoes do baralho
	Carta comprarCarta();
	int cartasNoBaralho();
	void embaralhar();

	//adcionar/remover carta
	void removerCarta(int indice);
	void adicionaCarta(Carta referencia);

	//montar baralho
	std::vector<Carta> importaBaralho();
	std::vector<Carta> getBaralho();
	void setBaralho(std::vector<Carta> cartas);
};
#endif
