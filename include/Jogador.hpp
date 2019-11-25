#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <iostream>
#include <vector>

#include "Baralho.hpp"
#include "Pilha.hpp"

class Jogador {
	private:
		std::string nome;
		Baralho mao;

	public:
		Jogador(std::string nome);
		void setNome(std::string nome);
		void setMao(Baralho novaMao);
		
		//consultas do jogador/jogo
		int cartasNaMao();
		int checkCarta (Carta cartaJogada, Pilha descartes, int corAuxiliar);
		void imprimeMao(std::map<int, std::string> mapeamentoCartas, std::map<int, std::string> mapeamentoCores);
		Baralho getMao();
		std::string getNome();
		
		//açõoes do jogador
		void jogarCarta(int indice, Pilha *descartes, int *cartaJogada);
		void falarUno();
		void compraCarta(Baralho *baralhoTeste);
		
		
};

#endif
