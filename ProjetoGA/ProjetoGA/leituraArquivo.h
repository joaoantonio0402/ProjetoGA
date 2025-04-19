#pragma once

#include <string>

using namespace std;

class leituraArquivo
{
public:
	leituraArquivo();
	void set_nomeArquivo(string);
	void ler();

private:
	string nomeArquivo;
};