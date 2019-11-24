#include "../include/Jogo.hpp"
#include "../include/Baralho.hpp"
#include "../include/Carta.hpp"
#include "../include/Pilha.hpp"
#include "../include/Jogador.hpp"
#include "../include/Carta.hpp"

#include <iostream> 
#include <vector>
#include <map>
#include <iterator>

std::map<int, std::string> Jogo::retornaMapaID(){
	std::map <int, std::string> id;
	for(int a=0; a <= 9; a++) {
		id.insert(std::pair <int, std::string> (a, std::to_string(a)));
	}
	id.insert(std::pair<int, std::string> (10, "+2"));
	id.insert(std::pair<int, std::string> (11, "Block"));
	id.insert(std::pair<int, std::string> (12, "Inverte"));
	id.insert(std::pair<int, std::string> (13, "Muda Cor"));
	id.insert(std::pair<int, std::string> (14, "Muda Cor +4"));
	
	return id; 
}

std::map<int, std::string> Jogo::retornaMapaCor(){
	std::map <int, std::string> cor;
	
	cor.insert(std::pair <int, std::string> (0, "Azul"));
	cor.insert(std::pair <int, std::string> (1, "Verde"));
	cor.insert(std::pair <int, std::string> (2, "Vermelho"));
	cor.insert(std::pair <int, std::string> (3, "Amarelo"));
	cor.insert(std::pair <int, std::string> (4, "Wild"));
	
	return cor; 
}

Jogo::Jogo(){
}
	
//Passar para classe jogador	
bool Jogo::falarUno(Jogador jogador) {
	std::cout << "UNO!" << std::endl;
	if (jogador.cartasNaMao() == 1) {
		return true;
	} else {
		return false;
	}
}

void Jogo::inverterSentido(){
	this->sentido = this->sentido * -1; 
}

int Jogo::getSentido(){
	return this->sentido;
}

int Jogo::getNumJogadores(){
	return this->jogadores.size();
}

void Jogo::criaJogadores(Baralho *baralhoTeste, Pilha *novaPilha){
	int numeroDeJogadores;
	std::vector<Jogador> jogadores;
	std::string nomeDoJogador;

	std::cout << "Bem vindo ao jogo UNO!" << std::endl;
	std::cout << "Insira o número de jogadores:" << std::endl;

	//Recebe o número de jogadores
	std::cin >> numeroDeJogadores;

	//Para cada jogador, pede o seu nome
	for (int i = 0; i < numeroDeJogadores; i++){
		std::cout << "Insira o nome do jogador " << i + 1 << ":";
		std::cin >> nomeDoJogador;
		Jogador auxiliar(nomeDoJogador);
			Baralho novaMao = auxiliar.getMao();
			for (int k=1;k<=9;k++) {
				novaMao.adicionaCarta(baralhoTeste->comprarCarta());
			}
			auxiliar.setMao(novaMao);
		jogadores.push_back(auxiliar);
	}

	//Pega a primeira carta não-especial do baralho e coloca no descarte para iniciar o jogo
	Carta cartaAuxiliar = baralhoTeste->comprarCarta();
	while(cartaAuxiliar.getId() >= 10){
		baralhoTeste->adicionaCarta(baralhoTeste->comprarCarta());
		cartaAuxiliar = baralhoTeste->comprarCarta();
	}
	novaPilha->adicionaCarta(cartaAuxiliar);
	this->jogadores = jogadores;
}
