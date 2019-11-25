#include "../include/Carta.hpp"

//Retorna o ID da carta atual
int Carta::getId(){
	return this->_id;
}

//Retorna a cor da carta atual
int Carta::getCor(){
	return this->_cor;
}

//Construtor padrão da classe
Carta::Carta(int id, int cor){
	this->_id=id;
	this->_cor=cor;
}

