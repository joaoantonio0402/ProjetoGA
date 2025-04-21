#pragma once

#include <string>

using namespace std;

class Tela
{
public:
	Tela();
	void set_nomeArquivo(string);
	void ler();
	void pressioneParaRetornar();
	int aguardaResposta();
private:
	string nomeArquivo;
};