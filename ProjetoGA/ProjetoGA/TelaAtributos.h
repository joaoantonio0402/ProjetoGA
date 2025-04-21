#pragma once

#include "Tela.h"

class TelaAtributos: public Tela
{
public:
	TelaAtributos();
	void init();
private:
	int habilidade, energia, sorte, valorRestante;
};

