#pragma once

#include "Tela.h"
#include "Item.h"
class TelaInventario: public Tela
{
public:
	TelaInventario(string, int, int, int);
	void init();
private:
	string tipoPersonagem;
	int habilidade;
	int energia;
	int sorte;
};

