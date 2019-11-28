JOGO DE CARTAS - UNO
Objetivo

O objetivo deste trabalho é replicar Uno, um jogo de cartas multiplayer, em um ambiente virtual. Nos interessamos por esse tema pois desenvolver um jogo é colocar o foco no usuário a todo momento, já que é uma categoria de software que existe com a única finalidade de fazer que o usuário tenha uma boa experiência. Assim, pensamos que superar este desafio será importante para o nosso crescimento durante a disciplina.
USER STORIES

Apenas um usuário: o jogador!

    “Como jogador, quero ver quais cartas estão na mão para tomar decisões”

    Decidir qual carta jogar.
    Ver as cartas na que há na mao.
    Apagar a mão do jogador anterior impresso na tela

    “Como jogador, quero poder adicionar meu nome para que possa identificar minha vez ”

    Pedir nome do jogador
    Exibir o nome do jogador que irá jogar
    Confirmar a vez do jogador para poder jogar

    “Como jogador, quero poder gritar “Uno!” para indicar que tenho só uma carta na mão”

    Ver quantas quartas tem na mão
    Poder gritar “Uno!” a hora que quiser
    Comer uma carta se gritar “Uno!” com mais de uma carta na mão

    “Como jogador, quero ser capaz de pegar cartas do baralho quando quiser ou se necessário”

    Pegar uma carta caso não tenha na mão uma compativel para jogar
    Pegar uma carta se quiser
    Embaralhar caso necessário

    “Como jogador, quero poder utilizar as cartas de cores neutras para poder escolher qual a proxima cor jogar”

    Jogar especial (+4 ou muda cor)
    Escolher a cor que o próximo jogador deve jogar
    Jogar em cima de qualquer carta

    “Como jogador, quero lançar uma carta para completar uma jogada”

    Ver a última carta lançada
    Ver todas as cartas na mão do jogador
    Checar se o jogador pode jogar a carta escolhida

CARTÕES CRC
CARTA
Responsabilidades

    Número/Símbolo
    Cor

Colaborações

    Baralho
    Pilha de descarte
    Mão do jogador

JOGADOR
Responsabilidades

    Nome
    Pegar carta
    Jogar carta
    Falar “Uno!”

Colaborações

    Mão do jogador
    Baralho
    Pilha de descarte

MÃO DO JOGADOR
Responsabilidades

    Quantidade de cartas
    Coleção de cartas existentes na mão do jogador
    Verficar a quantidade de cartas
    Inicializar a mão (9 cartas para cada)

Colaborações

    Jogador
    Baralho

PILHA DE DESCARTE
Responsabilidades

    Coleção de cartas descartadas

Colaborações

    Baralho
    Jogador

BARALHO

Um baralho do jogo Uno! é composto de acordo com a seguinte estrutura:

    19 cartas azuis – de 0 a 9;
    19 cartas verdes – de 0 a 9;
    19 cartas vermelhas – de 0 a 9;
    19 cartas amarelas – de 0 a 9;
    8 cartas “Compra duas cartas” – duas de cada cor;
    8 cartas “Salta”- duas de cada cor;
    8 cartas “Inverte”- duas de cada cor;
    4 cartas “Muda de cor”;
    4 cartas “Muda de cor e compra 4 cartas”;

Responsabilidades

    Numero de cartas restantes no baralho
    Coleção de cartas no baralho
    Embaralhar (dada uma coleção incial de cartas, gerar uma mesma coleção com a mesma quantidade inicial porém sem ordem definida)
    Voltar baralho (Coletar todas as cartas descartadas da mesa e inseri-las no baralho, quando a quantidade de cartas no baralho chegar a 0)

Colaborações

    Jogador
    Pilha descarte
