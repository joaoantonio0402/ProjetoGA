#pragma once

#include <string>;
#include <vector>

#include "Tela.h"
#include "Item.h"
class TelaInventario: public Tela
{
public:
	TelaInventario(string, int, int, int);
	void init();
	void adicionarItemInventario(Item);
	void removerItemInventario(Item);
private:
	string tipoPersonagem;
	int habilidade;
	int energia;
	int sorte;
	int itensInventario;
	vector<string> itens;
	vector<string> linhasArquivo;
	void atualizarItens();
};

