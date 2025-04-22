#include <fstream>
#include <iostream>
#include <vector>

#include "TelaInventario.h"

using namespace std;

TelaInventario::TelaInventario(string tipoPersonagem, int habilidade, int energia, int sorte) : Tela(), itens(20), linhasArquivo(10){
	this->tipoPersonagem = tipoPersonagem;
	this->habilidade = habilidade;
	this->energia = energia;
	this->sorte = sorte;
	this->itensInventario = 2;
}

void TelaInventario::init() {
	string arquivo = "";
	
	string linha = "";
	
	if (tipoPersonagem == "Guerreiro") {
		arquivo = "InventarioGuerreiro.txt"; //Carrega inventario do Guerreiro
		itens[0] = "Machete";
		itens[1] = "Couraca de pano";

	}
	else if (tipoPersonagem == "Mago") {
		arquivo = "InventarioMago.txt"; //Carrega inventario do Mago
	}

	linhasArquivo[1] = "------------------INVENTARIO------------------";
	linhasArquivo[2] = "Personagem: " + tipoPersonagem;
	linhasArquivo[3] = "Habilidade: " + to_string(habilidade);
	linhasArquivo[4] = "Energia: " + to_string(energia);
	linhasArquivo[5] = "Sorte: " + to_string(sorte);

	atualizarItens();

	ofstream outfile(arquivo);
	if(outfile.is_open()) {
		for(string linha : linhasArquivo){
			outfile << linha << endl;
		}
	}
	outfile.close();

	set_nomeArquivo(arquivo);
	ler();
	
}

void TelaInventario::adicionarItemInventario(Item item) {
	if (itensInventario >= 20) {
		cout << "Invetario Lotado" << endl;
		return;
	}
	itens[itensInventario] = item.get_nome();
	itensInventario++;

	atualizarItens();
	return;
}

void TelaInventario::removerItemInventario(Item item) {
	bool itemEncontrado = false;

	// Procura o item no vetor
	for (int i = 0; i < itensInventario; ++i) {
		if (itens[i] == item.get_nome()) {
			itemEncontrado = true;

			// Desloca os itens posteriores para preencher o espaço
			for (int j = i; j < itensInventario - 1; ++j) {
				itens[j] = itens[j + 1];
			}

			// Limpa o último item e decrementa o contador
			itens[itensInventario - 1] = "";
			itensInventario--;

			cout << "Item '" << item.get_nome() << "' removido com sucesso!" << endl;
			break; // Sai do loop após remover
		}
	}

	if (!itemEncontrado) {
		cout << "Item '" << item.get_nome() << "' não encontrado no inventário!" << endl;
	}

	return;
}

void TelaInventario::atualizarItens() {
	string itensStr = "";
	for (size_t i = 0; i < itens.size(); i++) {
		if (!itensStr.empty()) {
			itensStr += ", "; // Adiciona vírgula entre itens
		}
		itensStr += itens[i];
	}
	linhasArquivo[7] = "[ " + itensStr + "]";
}


