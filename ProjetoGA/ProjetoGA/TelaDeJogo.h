#pragma once
#include "Tela.h"
#include "Item.h"
#include "TelaInventario.h"
#include <vector>

class TelaDeJogo : public Tela
{
public:
	TelaDeJogo(int* cena, TelaInventario *inventario);
	void jogar();
	void coletarItem(string arquivo);
private:
	int* cena;
	string arquivo;
	TelaInventario *inventario;
};

