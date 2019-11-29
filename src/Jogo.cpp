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

	std::cout << "Insira o número de jogadores:" << std::endl;

	//Recebe o número de jogadores
	try{
		std::cin >> numeroDeJogadores;
		if ((numeroDeJogadores < 2)||(numeroDeJogadores > 5)){
			throw "Número de jogadores deve ser de 2 a 5";
		}
	}
	catch(const char* Erro){
		std::cout << Erro << std::endl;
		criaJogadores(baralhoTeste, novaPilha);
		return;
	}

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

int Jogo::getJogadorAtual(){
	return this->jogadorAtual;
}

void Jogo::setJogadorAtual(int indice){
	this->jogadorAtual = indice;
}

int Jogo::proximoJogador(){
	if (this->getJogadorAtual() == 0 && this->getSentido() == -1){
		return this->getNumJogadores()-1;
	}
	return (this->getJogadorAtual()+this->getSentido())%this->getNumJogadores();
}

std::vector<Jogador> Jogo::getJogadores(){
	return this->jogadores;
}

void Jogo::aguardaComando(std::string c){
	//Variável auxiliar para guardar o comando do jogador atual
	std::string comandoDoJogador;
				// do {
				// 	std::cin >> comandoDoJogador;
				// } while(comandoDoJogador != c);
	try{
		std::cin >> comandoDoJogador;
		if (comandoDoJogador != c){
			throw("Caractere inválido. Tente novamente.");
		}
	}
	catch(const char* Erro){
		std::cout << Erro << std::endl;
		aguardaComando(c);
	}
	
}

std::string Jogo::aguardaJogadaValida(Jogo jogoAtual, Jogador jogadorAtual, Pilha pilhaDeDescartes, int corAuxiliar){
	std::string comandoDoJogador = "";
	std::cout << "Digite o indice da carta ou a ação desejada:" << std::endl;
	do {
		if (comandoDoJogador != "") {
			std::cout << "Ação ou carta inválida, tente novamente" << std::endl;
		}
		std::cin >> comandoDoJogador;
	} while(comandoDoJogador != "c" && comandoDoJogador != "u" && !jogoAtual.checaIndiceValido(jogadorAtual, comandoDoJogador, pilhaDeDescartes, corAuxiliar));
	return comandoDoJogador;
}

void Jogo::setJogador(int indice, Jogador novoJogador){
	this->jogadores[indice] = novoJogador;
}

int Jogo::checaIndiceValido(Jogador jogadorAtual, std::string comandoDoJogador, Pilha descartes, int corAuxiliar){
	try{
		int check = jogadorAtual.checkCarta(jogadorAtual.getMao().retornaCarta(std::stoi(comandoDoJogador)),descartes, corAuxiliar);
		return check;
	}
	catch(...){
		return 0;
	}
}

int Jogo::realizaEfeitoCartaEspecial(Jogador *jogadorAtual, Baralho *baralhoTeste, Pilha descartes, int proximoJogadorBloqueado){
	if (!proximoJogadorBloqueado){
		return 0; 
	}
	Carta cartaTopo = descartes.topoDoBaralho();
	if(cartaTopo.getId() == 14) {
		for(int k=1;k<=4;k++) {
			jogadorAtual->compraCarta(baralhoTeste);
		}
		return 1;
	}
	if(cartaTopo.getId() == 10) {
		for(int k=1;k<=2;k++) {
			jogadorAtual->compraCarta(baralhoTeste);
		}
		return 1;
	}
	if(cartaTopo.getId() == 11) {
		return 1;
	}
	return 0;
}

void Jogo::imprimeJogada(Pilha pilhaDeDescartes, Jogador jogadorAtual, int corAuxiliar, std::map <int, std::string> mapeamentoCartas, std::map <int, std::string> mapeamentoCores){
	std::system("clear");
	std::cout << "--------------------------" << std::endl; 
	pilhaDeDescartes.imprimeTopo(mapeamentoCartas, mapeamentoCores, corAuxiliar);  
	std::cout << "--------------------------" << std::endl;   
	jogadorAtual.imprimeMao(mapeamentoCartas, mapeamentoCores);
	std::cout << "--------------------------" << std::endl;
}
