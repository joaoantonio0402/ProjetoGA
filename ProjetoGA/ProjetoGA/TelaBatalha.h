#pragma once
#include <vector>

#include "Personagem.h"
#include "Tela.h"
#include "Monstro.h"

class TelaBatalha: public Tela
{
public:
	TelaBatalha(Personagem& personagem);
	void init(string);
private:
	string nomeArquivo;
	int p_habilidade;
	int p_sorte;
	int p_energia;
	int tesouroMonstro;
	int provisaoMonstro;
	Monstro monstro;
	void iniciaBatalha();
	int numeroAleatorio();
	void bufferParaArquivo();
	vector<string> linhasArquivo; // Array que armazena as string que irao virar as linhas do arquivo
	Personagem& personagem;
};

