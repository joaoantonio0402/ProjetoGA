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
	void removerItemInventario(string);
	void substituirItem(string, string); // Substitui um item equipado por um item do inventario
	void adicionarItemEquipado(Item);
	void removerItemEquipado(Item);
	void imprimirInventario(bool);
private:
	string tipoPersonagem; //Valor esperado como parametro
	int habilidade; //Valor esperado como parametro
	int energia; //Valor esperado como parametro
	int sorte; //Valor esperado como parametro
	int cntItensInventario; // Contador itens no inventario
	int cntItensEquipados; // Contador itens equipados
	vector<string> itens; // Array que armazena os itens do inventario
	vector<string> itensEquipados; // Array que armazena os itens equipados
	vector<string> linhasArquivo; // Array que armazena as string que irao virar as linhas do arquivo
	void atualizarItens(); // Funcao que atualiza os itens do inventario
	void modificarInventario();
};

