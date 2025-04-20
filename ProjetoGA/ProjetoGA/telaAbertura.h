#pragma once


#include "Tela.h"
#include "ExibirCreditos.h"

class TelaAbertura : public Tela {
public:
	TelaAbertura();
	void chamarTela();
private:
	ExibirCreditos telaCreditos;
};