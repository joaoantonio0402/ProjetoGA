#include <iostream>
#include <fstream>
#include "TelaAtributos.h"

using namespace std;

TelaAtributos::TelaAtributos(): Tela(){
	habilidade = 0;
	energia = 0;
	sorte = 0;
	valorRestante = 12;
}

void TelaAtributos::init() {
	set_nomeArquivo("DefinirAtributos.txt");
	ler();
	cin.ignore();
	cout << "Digite o quanto deseja adicionar de Habilidade: ";
	cin >> habilidade;
	while (habilidade > 6 || habilidade < 0) {
		cout << "\nValor invalido" << endl;
		cout << "Digite o quanto deseja adicionar de Habilidade: ";
		cin >> habilidade;
	}
	valorRestante -= habilidade;

	cout << "\nPontos restantes: " << valorRestante << endl;
	cout << "Digite o quanto deseja adicionar de energia: ";
	cin >> energia;
	while (energia < 0 || energia > valorRestante) {
		cout << "\nValor invalido" << endl;
		cout << "Digite o quanto deseja adicionar de energia: ";
		cin >> energia;
	}
	valorRestante -= energia;

	cout << "\nPontos restantes: " << valorRestante << endl;
	cout << "Digite o quanto deseja adicionar de sorte: ";
	cin >> sorte;
	while (sorte < 0 || sorte > valorRestante || sorte > 6) {
		cout << "\nValor invalido" << endl;
		cout << "Digite o quanto deseja adicionar de sorte: ";
		cin >> sorte;
	}


}

int TelaAtributos::get_habilidade() {
	return habilidade;
}

int TelaAtributos::get_energia() {
	return energia;
}

int TelaAtributos::get_sorte() {
	return sorte;
}