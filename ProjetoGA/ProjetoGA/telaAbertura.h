#pragma once

#include "Tela.h"
#include "ExibirCreditos.h"

class TelaAbertura : public Tela {
public:
	TelaAbertura();
	int init();
private:
	ExibirCreditos telaCreditos;
};