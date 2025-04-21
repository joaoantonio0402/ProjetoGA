#include "TelaInventario.h"

TelaInventario::TelaInventario(string tipoPersonagem, int habilidade, int energia, int sorte) : Tela() {
	this->tipoPersonagem = tipoPersonagem;
	this->habilidade = habilidade;
	this->energia = energia;
	this->sorte = sorte;
}

void TelaInventario::init() {
	if (tipoPersonagem == "Guerreiro") {
		set_nomeArquivo(""); //Carrega inventario do Guerreiro
		
	}
	else if (tipoPersonagem == "Mago") {
		set_nomeArquivo(""); //Carrega inventario do Mago
	}
	ler();
}

