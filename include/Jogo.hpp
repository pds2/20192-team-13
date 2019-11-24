#include "Jogador.hpp"
#include "Carta.hpp"

#include <iostream> 
#include <vector>
#include "Carta.hpp"
#include <map>
#include <iterator>


class Jogo {
private:
	int sentido = 1;
	int jogadorAtual = 0;

	std::vector<Jogador> jogadores;
	

public:
	//Construtor padrão da classe
	Jogo();
	int getNumJogadores();
	bool falarUno(Jogador jogador);

	//Funcoes de sentido
	void inverterSentido();
	int getSentido();

	//Função para criar os jogadores
	void criaJogadores(Baralho *baralhoTeste, Pilha *novaPilha);

	int proximoJogador();
	void setJogadorAtual(int indice);
	int getJogadorAtual();
	void setJogador(int indice, Jogador novoJogador);

	std::vector<Jogador> getJogadores();

	//Funções para retorno dos mapeamentos
	std::map<int, std::string> retornaMapaID();
	std::map<int, std::string> retornaMapaCor();

	//Retorna variáveis
	Baralho getBaralho();
	Pilha getDescartes();

	//Funções auxiliares de jogo
	void imprimeJogada(Pilha pilhaDeDescartes, Jogador jogadorAtual, int corAuxiliar, std::map <int, std::string> mapeamentoCartas, std::map <int, std::string> mapeamentoCores);
	void aguardaComando(std::string c);
	std::string aguardaJogadaValida(Jogo jogoAtual, Jogador jogadorAtual, Pilha pilhaDeDescartes, int corAuxiliar);
	int checaIndiceValido(Jogador jogadorAtual, std::string comandoDoJogador, Pilha descartes, int corAuxiliar);
	int realizaEfeitoCartaEspecial(Jogador *jogadorAtual, Baralho *baralhoTeste, Pilha descartes, int proximoJogadorBloqueado);

};
