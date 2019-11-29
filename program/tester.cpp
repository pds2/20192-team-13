// NÃO MUDEM ESSE ARQUIVO!!!!

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Jogo.hpp"
#include "../include/Baralho.hpp"
#include <vector>
#include "../include/Carta.hpp"
#include "../include/Jogador.hpp"

TEST_CASE("Testando quantidade de cartas na mão") {
    Jogador j1("Jonas"), j2("Marzano");
    Carta c1(0,0), c2(1,1);
    Baralho mao1, mao2;
    std::vector<Carta> cartas1, cartas2;
    cartas1.push_back(c1);
    cartas2.push_back(c1);
    cartas2.push_back(c2);
    mao1.setBaralho(cartas1);
    mao2.setBaralho(cartas2);
    j1.setMao(mao1);
    j2.setMao(mao2);

    CHECK(j1.cartasNaMao() == 1);
    CHECK(j2.cartasNaMao() == 2);

}

TEST_CASE("Testando retorna cria do baralho") {
    Carta c1(0,0), c2(1,1), c3(2,2), c4(3,3);
    Baralho mao1;
    std::vector<Carta> cartas1;
    cartas1.push_back(c1);
    cartas1.push_back(c2);
    cartas1.push_back(c3);
    cartas1.push_back(c4);
    mao1.setBaralho(cartas1);

    CHECK(mao1.retornaCarta(0).getId() == c1.getId());
    CHECK(mao1.retornaCarta(1).getId() == c2.getId());
    CHECK(mao1.retornaCarta(2).getId() == c3.getId());
    CHECK(mao1.retornaCarta(3).getId() == c4.getId());
}

TEST_CASE("Testando topo e fundo do baralho") {
    Carta c1(0,0), c2(1,1);
    Baralho mao1, mao2;
    std::vector<Carta> cartas1;
    cartas1.push_back(c1);
    cartas1.push_back(c2);
    mao1.setBaralho(cartas1);

    CHECK(mao1.topoDoBaralho().getId() == c2.getId());
    CHECK(mao1.fundoDoBaralho().getId() == c1.getId());

}

TEST_CASE("Testando nome do jogador") {
    Jogador j1("Jonas"), j2("Marzano");

    CHECK(j1.getNome() == "Jonas");
    CHECK(j2.getNome() == "Marzano");

}