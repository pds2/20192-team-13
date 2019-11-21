#ifndef Carta_HPP
#define Carta_HPP

#include <string>

class Carta
{
private:
	//Atributos: ID da carta e cor
	int _id;
	int _cor;
public:
	//Construtor padrão da classe
	Carta(int, int);
	
	//Metodos de get das informações da carta
	int getId();
	int getCor();	
};
#endif
