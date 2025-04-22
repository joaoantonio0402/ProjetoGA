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
	void substituirItem(Item, Item);
	void adicionarItemEquipado(Item);
	void removerItemEquipado(Item);
	void imprimirInventario();
private:
	string tipoPersonagem;
	int habilidade;
	int energia;
	int sorte;
	int cntItensInventario;
	int cntItensEquipados;
	vector<string> itens;
	vector<string> itensEquipados;
	vector<string> linhasArquivo;
	void atualizarItens();
	
};

