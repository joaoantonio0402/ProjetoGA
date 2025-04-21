#pragma once

#include "Tela.h"

class TelaAtributos: public Tela
{
public:
	TelaAtributos();
	void init();
	int get_habilidade();
	int get_energia();
	int get_sorte();
private:
	int habilidade, energia, sorte, valorRestante;
};

