#pragma once
#include <string>

using namespace std;

class Monstro
{
public:
	Monstro();
	void set_nomeArquivo(string);
	void ler();
	void init();
	string get_nome();
	int get_habilidade();
	int get_sorte();
	int get_energia();
	int get_tesouro();
	int get_provisao();
private:
	string nomeArquivo;
	string nome;
	int habilidade;
	int sorte;
	int energia;
	int tesouro;
	int provisao;
};

