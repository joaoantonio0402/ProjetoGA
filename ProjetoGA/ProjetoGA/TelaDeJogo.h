#pragma once
#include "Tela.h"
#include "Item.h"
#include <vector>

class TelaDeJogo : public Tela
{
public:
	TelaDeJogo(int* cena, vector<Item*>& inventario);
	void jogar();
	void coletarItem(string arquivo);
private:
	int* cena;
	string arquivo;
	vector<Item*>& inventario;
};

