#pragma once
#include <string>

using namespace std;

class Personagem
{
public:
	Personagem();
	void set_nomeArquivo(string);
	void ler();
	void init();
	int get_habilidade();
	int get_sorte();
	int get_energia();
	void set_habilidade(int);
	void set_sorte(int);
	void set_energia(int);

private:
	int habilidade;
	int sorte;
	int energia;
};

