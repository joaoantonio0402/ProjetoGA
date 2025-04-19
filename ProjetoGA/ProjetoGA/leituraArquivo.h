#pragma once

#include <string>

using namespace std;

class leituraArquivo
{
public:
	leituraArquivo();
	leituraArquivo(string);
	void ler();

private:
	string nomeArquivo;
};

