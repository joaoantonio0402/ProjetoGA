#include <iostream>
#include <fstream>
#include "TelaAtributos.h"

using namespace std;

TelaAtributos::TelaAtributos(): Tela(){
	habilidade = 0;
	energia = 0;
	sorte = 0;
	valorRestante = 12; // Valor total de pontos a serem distribuídos entre habilidade, energia e sorte
}

void TelaAtributos::init() {
	set_nomeArquivo("DefinirAtributos.txt"); // Nome do arquivo que armazena os atributos
	ler();
	cin.ignore(); // Limpa o buffer de entrada
	cout << "Digite o quanto deseja adicionar de Habilidade: "; // Solicita o valor de habilidade
	cin >> habilidade; // Lê o valor de habilidade
	// Verifica se o valor está dentro do intervalo permitido
	while (habilidade > 6 || habilidade < 0) {
		cout << "\nValor invalido" << endl;
		cout << "Digite o quanto deseja adicionar de Habilidade: ";
		cin >> habilidade;
	}
	valorRestante -= habilidade; // Atualiza o valor restante de pontos a serem distribuídos

	cout << "\nPontos restantes: " << valorRestante << endl;
	cout << "Digite o quanto deseja adicionar de energia: "; // Solicita o valor de energia
	cin >> energia; // Lê o valor de energia
	// Verifica se o valor está dentro do intervalo permitido
	while (energia < 0 || energia > valorRestante) {
		cout << "\nValor invalido" << endl;
		cout << "Digite o quanto deseja adicionar de energia: ";
		cin >> energia;
	}
	valorRestante -= energia; // Atualiza o valor restante de pontos a serem distribuídos

	cout << "\nPontos restantes: " << valorRestante << endl;
	cout << "Digite o quanto deseja adicionar de sorte: "; // Solicita o valor de sorte
	cin >> sorte; // Lê o valor de sorte
	// Verifica se o valor está dentro do intervalo permitido
	while (sorte < 0 || sorte > valorRestante || sorte > 6) {
		cout << "\nValor invalido" << endl;
		cout << "Digite o quanto deseja adicionar de sorte: ";
		cin >> sorte;
	}

}

int TelaAtributos::get_habilidade() {
	return habilidade + 6; // Adiciona o valor base de habilidade
}

int TelaAtributos::get_energia() {
	return energia + 12; // Adiciona o valor base de energia
}

int TelaAtributos::get_sorte() {
	return sorte + 6; // Adiciona o valor base de sorte
}