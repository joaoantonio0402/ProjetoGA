#include <iostream>
#include <string>

#include "Tela.h"
#include "TelaEscolhaPersonagem.h"


TelaEscolhaPersonagem::TelaEscolhaPersonagem() : Tela() {
}

string TelaEscolhaPersonagem::init() { // Retorna o nome do tipo do personagem
	int tipoPersonagem;

	set_nomeArquivo("TelaEscolhaPersonagem.txt");
	ler();
	cin >> tipoPersonagem;

	while (true) {
		if (tipoPersonagem == 1) {
			return "Guerreiro";
		}
		else if (tipoPersonagem == 2) {
			return "Mago";
		}
		else {
			cout << "\nValor invalido" << endl;
			ler();
			cin >> tipoPersonagem;
		}
	}
}