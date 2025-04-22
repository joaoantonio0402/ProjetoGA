#include <fstream>
#include <iostream>
#include <vector>

#include "TelaInventario.h"

using namespace std;

TelaInventario::TelaInventario(string tipoPersonagem, int habilidade, int energia, int sorte) : Tela(), itens(18), itensEquipados(2), linhasArquivo(10) {
	this->tipoPersonagem = tipoPersonagem;
	this->habilidade = habilidade;
	this->energia = energia;
	this->sorte = sorte;
	this->cntItensInventario = 0;
	this->cntItensEquipados = 2;
}

void TelaInventario::init() {
	string arquivo = "";
	
	string linha = "";
	
	if (tipoPersonagem == "Guerreiro") {
		arquivo = "InventarioGuerreiro.txt"; //Carrega inventario do Guerreiro
		itensEquipados[0] = "Machete";
		itensEquipados[1] = "Couraca de pano";

	}
	else if (tipoPersonagem == "Mago") {
		arquivo = "InventarioMago.txt"; //Carrega inventario do Mago
		itensEquipados[0] = "Anel de Doran";
		itensEquipados[1] = "Tunica diferenciada";
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
	
	pressioneParaRetornar();
}

void TelaInventario::adicionarItemInventario(Item item) {
	if (cntItensInventario >= 18) {
		cout << "Invetario Lotado" << endl;
		return;
	}
	itens[cntItensInventario] = item.get_nome();
	cntItensInventario++;

	atualizarItens();
	return;
}

void TelaInventario::adicionarItemEquipado(Item item) {
	if (cntItensEquipados >= 2) {
		cout << "Invetario Lotado" << endl;
		return;
	}
	itensEquipados[cntItensEquipados] = item.get_nome();
	cntItensEquipados++;

	atualizarItens();
	return;
}

void TelaInventario::removerItemInventario(Item item) {
	bool itemEncontrado = false;

	// Procura o item no vetor
	for (int i = 0; i < cntItensInventario; ++i) {
		if (itens[i] == item.get_nome()) {
			itemEncontrado = true;

			// Desloca os itens posteriores para preencher o espaço
			for (int j = i; j < cntItensInventario - 1; ++j) {
				itens[j] = itens[j + 1];
			}

			// Limpa o último item e decrementa o contador
			itens[cntItensInventario - 1] = "";
			cntItensInventario--;

			cout << "Item '" << item.get_nome() << "' removido com sucesso!" << endl;
			break; // Sai do loop após remover
		}
	}

	if (!itemEncontrado) {
		cout << "Item '" << item.get_nome() << "' não encontrado no inventário!" << endl;
	}
	atualizarItens();
	return;
}

void TelaInventario::removerItemEquipado(Item item) {
	bool itemEncontrado = false;

	// Procura o item no vetor
	for (int i = 0; i < cntItensEquipados; ++i) {
		if (itensEquipados[i] == item.get_nome()) {
			itemEncontrado = true;

			// Desloca os itens posteriores para preencher o espaço
			for (int j = i; j < cntItensEquipados - 1; ++j) {
				itensEquipados[j] = itensEquipados[j + 1];
			}

			// Limpa o último item e decrementa o contador
			itensEquipados[cntItensEquipados - 1] = "";
			cntItensEquipados--;

			cout << "Item '" << item.get_nome() << "' removido com sucesso!" << endl;
			break; // Sai do loop após remover
		}
	}

	if (!itemEncontrado) {
		cout << "Item '" << item.get_nome() << "' não encontrado no inventário!" << endl;
	}

	atualizarItens();
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
	linhasArquivo[7] = "Equipados: " + itensEquipados[0] + ", " + itensEquipados[1] + " (" + to_string(cntItensEquipados) + "/2)";
	linhasArquivo[8] = "[ " + itensStr + "] " + "(" + to_string(cntItensInventario) + "/18)";
}

void TelaInventario::substituirItem(Item i_equipado, Item i_inventario) {
	bool equipadoEncontrado = false;
	bool inventarioEncontrado = false;
	int posEquipado = 0;
	int posInventario = 0;

	// Procura o item equipado
	for (int i = 0; i < cntItensEquipados; ++i) {
		if (itensEquipados[i] == i_equipado.get_nome()) {
			equipadoEncontrado = true;
			posEquipado = i;
			break;
		}
	}

	// Procura o item do inventario
	for (int i = 0; i < cntItensInventario; ++i) {
		if (itens[i] == i_inventario.get_nome()) {
			inventarioEncontrado = true;
			posInventario = i;
			break;
		}
	}

	if (!equipadoEncontrado) {
		cout << "Item equipado '" << i_equipado.get_nome() << "' não encontrado!" << endl;
		return;
	}

	if (!inventarioEncontrado) {
		cout << "Item do inventário '" << i_inventario.get_nome() << "' não encontrado!" << endl;
		return;
	}

	// troca os itens de posicao
	string temp = itensEquipados[posEquipado];
	itensEquipados[posEquipado] = itens[posInventario];
	itens[posInventario] = temp;

	atualizarItens();
}

void TelaInventario::imprimirInventario() {
	ler();
	pressioneParaRetornar();
	return;
}


