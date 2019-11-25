#include "../include/Jogador.hpp"
#include "../include/Baralho.hpp"

#include <map>
#include <vector>

Jogador::Jogador (std::string nome) {
	this->nome = nome;
}
		
int Jogador::cartasNaMao() {
	return this->mao.cartasNoBaralho();
}
		
void Jogador::jogarCarta(int indice, Pilha *descartes, int *corJogada) {
	Carta cartaAux = this->mao.retornaCarta(indice);
	descartes->adicionaCarta(this->mao.retornaCarta(indice));	
	this->mao.removerCarta(indice);
	if((cartaAux.getId() == 13) || (cartaAux.getId() == 14)) {
		int corAux;
		do {
			std::cout << "Digite uma cor: (0) Azul, (1) Verde, (2) Vermelho, (3) Amarelo: " << std::endl;
			std::cin >> corAux;
			*corJogada = corAux;
		} while ((corAux > 4) || (corAux < 0));
	}
}


int Jogador::checkCarta (Carta cartaJogada, Pilha descartes, int corAuxiliar) {
	Carta cartaTopo = descartes.topoDoBaralho();

	if(cartaTopo.getCor() == 4){
		if (cartaJogada.getCor() == corAuxiliar || cartaJogada.getCor() == 4){
			return 1;
		} 
		return 0;
	}
	else{
		if((cartaJogada.getCor() == cartaTopo.getCor()) || (cartaJogada.getId() == cartaTopo.getId()) || (cartaJogada.getCor() == 4)) {
			return 1;
		}			
		return 0;
	}
	

}

std::string Jogador::getNome(){
	return this->nome;
}

void Jogador::setNome(std::string nome){
	this->nome = nome;
}

Baralho Jogador::getMao(){
	return this->mao;
}

void Jogador::setMao(Baralho novaMao){
	this->mao = novaMao;
}

void Jogador::imprimeMao(std::map<int, std::string> mapeamentoCartas, std::map<int, std::string> mapeamentoCores){
	std::cout << "Cartas do jogador " << this->nome << std::endl;
	std::string cor;
	for (int i = 0; i < this->cartasNaMao(); ++i){
		cor = mapeamentoCores.find(getMao().retornaCarta(i).getCor())->second;
		if(cor == "Azul") {
			std::cout << "\033[1;34m";
		} else if(cor == "Verde") {
			std::cout << "\033[1;32m";
		} else if(cor == "Vermelho") {
			std::cout << "\033[1;31m";
		} else if(cor == "Amarelo") {
			std::cout << "\033[1;33m";
		} else if(cor == "Wild") {
			std::cout << "\033[1;35m";
		}
		std::cout << i << ":" << mapeamentoCartas.find(getMao().retornaCarta(i).getId())->second << ", " 
		<< mapeamentoCores.find(getMao().retornaCarta(i).getCor())->second << "\033[0m" << std::endl;
	}
	
	std::cout << "--------------------------" << std::endl;
	std::cout << "Outras ações:\n" << std::endl;
	std::cout << "C: comprar uma carta" << std::endl;
	std::cout << "U: Falar Uno!" << std::endl;
}

void Jogador::compraCarta(Baralho *baralhoTeste) {
	Baralho novaMao = this->getMao();
	novaMao.adicionaCarta(baralhoTeste->comprarCarta());
	this->setMao(novaMao);
}

void Jogador::falarUno() {
	if(this->cartasNaMao() == 1) {
		std::cout << this->getNome() << "falou UNO!" << std::endl;
	} else {
		std::cout << "falou UNO na hora errada! Compre uma carta" << std::endl;
		std::vector<Carta> maoAux = this->getMao().getBaralho();
		maoAux.push_back(this->mao.comprarCarta());
		this->mao.setBaralho(maoAux);
	}
}
