#include "../include/Baralho.hpp"
#include "../include/Carta.hpp"
#include <fstream>
#include <iostream> 
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <random>
#include <time.h>

using namespace std;

//Construtor padrão da classe
Baralho::Baralho(){
}

Carta Baralho::topoDoBaralho(){
	return this->baralho[baralho.size()-1];
}

Carta Baralho::fundoDoBaralho(){
	return *this->baralho.begin();
}

void Baralho::adicionaCarta(Carta referencia){
	if (referencia.getId() != -1 && referencia.getCor() != -1){
		this->baralho.push_back(referencia);
	}
}

void Baralho::embaralhar(){
	srand(unsigned( time(NULL) ));
	std::random_shuffle(std::begin(this->baralho), std::end(this->baralho));
}

Carta Baralho::comprarCarta(){
	//Copia a primeira carta em uma variável auxiliar e remove do baralho
	if (this->cartasNoBaralho() > 0) {
		Carta cartaAuxiliar = *(this->baralho.begin());
		this->baralho.erase(this->baralho.begin());

		//Retorna a carta removida do baralho
		return cartaAuxiliar;
	} else {
		std::cout << "Nao existem mais cartas no baralho!" << std::endl;
		Carta cartaTeste(-1,-1);
		return cartaTeste;
	}
}

std::vector<Carta> Baralho::importaBaralho(){
	ofstream deckFile;
	string currentLine;
	string fileName = "";
	//vector para importar o baralho
	std::vector<Carta> baralho;
	int id;
	int cor;
	
	ifstream fin;
	fin.open("cartas.txt");
	while(fin.good()) {
		fin >> cor >> id;
		Carta cartaAux(id, cor);
		baralho.push_back(cartaAux);
	}
	fin.close();
	return baralho;
}

int Baralho::cartasNoBaralho(){
	return this->baralho.size();
}

vector<Carta> Baralho::getBaralho(){
	return this->baralho;
}

void Baralho::setBaralho(vector<Carta> cartas) {
	this->baralho = cartas;
}

Carta Baralho::retornaCarta(int indice){
	if(this->cartasNoBaralho() <= indice || this->cartasNoBaralho()==0){
		Carta cartaTeste(-1,-1);
		return cartaTeste;
	}
	return this->baralho[indice];
}

void Baralho::removerCarta(int indice){
	if(this->cartasNoBaralho() < indice || this->cartasNoBaralho()==0){
		std::cout << "Indice inválido. Remoção não será realizada." << std::endl;
	} else{
		this->baralho.erase(this->baralho.begin()+indice);
	}
	
}
