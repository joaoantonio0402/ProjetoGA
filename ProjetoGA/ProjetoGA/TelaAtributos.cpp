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
	
	cout << "Digite o quanto deseja adicionar de Habilidade: " << endl;
	cin >> habilidade;
	while (habilidade > 6 || habilidade < 0) {
		cout << "Valor invalido" << endl;
		cout << "Digite o quanto deseja adicionar de Habilidade: " << endl;
		cin >> habilidade;
	}
	valorRestante -= habilidade;

	cout << "Digite o quanto deseja adicionar de energia: " << endl;
	cin >> energia;
	while (energia < 0 || energia > valorRestante) {
		cout << "Valor invalido" << endl;
		cout << "Digite o quanto deseja adicionar de energia: " << endl;
		cin >> energia;
	}
	valorRestante -= energia;

	cout << "Digite o quanto deseja adicionar de sorte: " << endl;
	cin >> sorte;
	while (sorte < 0 || sorte > valorRestante || sorte > 6) {
		cout << "Valor invalido" << endl;
		cout << "Digite o quanto deseja adicionar de sorte: " << endl;
		cin >> sorte;
	}
}