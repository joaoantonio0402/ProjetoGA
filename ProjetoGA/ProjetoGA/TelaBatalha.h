#pragma once

#include "Personagem.h"
#include "Tela.h"
#include "Monstro.h"

class TelaBatalha: public Tela
{
public:
	TelaBatalha();
	TelaBatalha(Personagem);
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
	Personagem personagem;
};

