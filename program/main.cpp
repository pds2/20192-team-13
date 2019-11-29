#include "../include/Carta.hpp"
#include "../include/Baralho.hpp"
#include "../include/Pilha.hpp"
#include "../include/Jogador.hpp"
#include "../include/Jogo.hpp"

#include <map>

int main(int argc, char const *argv[])
{
	std::cout << "Bem vindo ao jogo UNO!" << std::endl;

	//Inicia um novo jogo
	Jogo jogoAtual;
	
	//Cria o baralho principal
	Baralho baralhoPrincipal;
	baralhoPrincipal.setBaralho(baralhoPrincipal.importaBaralho());
	baralhoPrincipal.embaralhar();

	//Cria a pilha de descartes
	Pilha pilhaDeDescartes;

	//Cria os jogadores da partida
	jogoAtual.criaJogadores(&baralhoPrincipal, &pilhaDeDescartes);
	
	//Mapeamento de cartas e cores
	std::map <int, std::string> mapeamentoCartas = jogoAtual.retornaMapaID();
	std::map <int, std::string> mapeamentoCores = jogoAtual.retornaMapaCor();

	//Variável que armazena o comando do jogador
	std::string comandoDoJogador;

	//Variável que armazena o nome do vencedor
	std::string nomeDoVencedor = "";

	//Variável para armazenar a cor temporária definida por um jogador que joga uma carta do tipo Wild
	int corAuxiliar = -1;
	//Flag de controle de bloqueio
	int proximoJogadorBloqueado = 0;

	std::cout << "Bem vindo ao jogo UNO!" << std::endl;

	//Executa o jogo enquanto não houver vencedor
	while(nomeDoVencedor == ""){
		//Inicio do turno do jogador atual
		std::system("clear");
		Jogador jogadorAtual = jogoAtual.getJogadores()[jogoAtual.getJogadorAtual()];
		std::cout << "Vez do jogador " << jogadorAtual.getNome() << std::endl;
		
		//Checa se o jogador não foi impedido de realizar sua jogada
		if(jogoAtual.realizaEfeitoCartaEspecial(&jogadorAtual, &baralhoPrincipal, pilhaDeDescartes, proximoJogadorBloqueado)){
			std::cout << "Você bloqueado pelo seu adversário! Digite p para passar seu turno" << std::endl;
			jogoAtual.aguardaComando("p");
			proximoJogadorBloqueado = 0;
		} else {
			std::cout << "Digite p para iniciar seu turno" << std::endl;

			//Aguarda comando do jogador para iniciar o turno
			jogoAtual.aguardaComando("p");

			//Imprime a visualização da jogada
			jogoAtual.imprimeJogada(pilhaDeDescartes, jogadorAtual, corAuxiliar, mapeamentoCartas, mapeamentoCores);
			
			//Aguarda comando válido com número da carta ou da ação do jogador atual
			comandoDoJogador = jogoAtual.aguardaJogadaValida(jogoAtual, jogadorAtual, pilhaDeDescartes, corAuxiliar);
			
			if(comandoDoJogador == "c") {
				jogadorAtual.compraCarta(&baralhoPrincipal);
			}
			else if (comandoDoJogador == "u") {
				jogadorAtual.falarUno();
			}
			else if(jogoAtual.checaIndiceValido(jogadorAtual, comandoDoJogador, pilhaDeDescartes, corAuxiliar)){
				jogadorAtual.jogarCarta(std::stoi(comandoDoJogador), &pilhaDeDescartes, &corAuxiliar);
				//Verifica se o próximo jogador será bloqueado
				if (pilhaDeDescartes.topoDoBaralho().getId() >= 10){
					proximoJogadorBloqueado = 1;
				} else {
					proximoJogadorBloqueado = 0;
				}
			}
		}
		//Checa se o jogador atual foi o vencedor
		if (jogadorAtual.cartasNaMao() == 0){
			nomeDoVencedor = jogadorAtual.getNome();
		}

		//Passa para o próximo jogador
		if (pilhaDeDescartes.topoDoBaralho().getId()==12){jogoAtual.inverterSentido();}
		jogoAtual.setJogador(jogoAtual.getJogadorAtual(), jogadorAtual);
		jogoAtual.setJogadorAtual(jogoAtual.proximoJogador());
		
	}
	std::cout << "Jogador vencedor: " << nomeDoVencedor << std::endl;
	return 0;
}

