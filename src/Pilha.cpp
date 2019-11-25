#include <fstream>
#include <iostream> 
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <random>

#include "../include/Pilha.hpp"
#include "../include/Carta.hpp"

Pilha::Pilha() : Baralho::Baralho(){
}

void Pilha::imprimeTopo(std::map<int, std::string> mapeamentoCartas, std::map<int, std::string> mapeamentoCores, int corAuxiliar) {
	Carta cartaAux = this->topoDoBaralho();
	std::string cor, valor;
	if (cartaAux.getCor()==4){
		cor = mapeamentoCores.find(corAuxiliar)->second;
		valor = mapeamentoCores.find(corAuxiliar)->second;
	}
	else{
		cor = mapeamentoCores.find(cartaAux.getCor())->second;
		valor = mapeamentoCores.find(cartaAux.getCor())->second;
	}
	std::cout << "Carta no topo da pilha: " << std::endl;
		if(cor == "Azul") {
			std::cout << "\033[1;34m";
		} else if(cor == "Verde") {
			std::cout << "\033[1;32m";
		} else if(cor == "Vermelho") {
			std::cout << "\033[1;31m";
		} else if(cor == "Amarelo") {
			std::cout << "\033[1;33m";
		}

	std::cout << mapeamentoCartas.find(cartaAux.getId())->second << ", " << valor << "\033[0m" << std::endl;
}

void Pilha::reembaralhar(Baralho *baralhoTeste) {
	//Armazena ultima carta jogada
	Carta cartaAux = this->cartasJogadas.topoDoBaralho();
	std::vector<Carta> baralhoAux = this->cartasJogadas.getBaralho();
	baralhoAux.erase(baralhoAux.end());
	
	//Copia descarte para o baralho
	baralhoTeste->setBaralho(baralhoAux);
	baralhoTeste->embaralhar();
	
	//Passa carta armazenada para pilha
	std::vector<Carta> cartas;
	cartas.push_back(cartaAux);
	this->cartasJogadas.setBaralho(cartas);
}
