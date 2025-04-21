#pragma once
#include <string>
using namespace std;

class Item
{public:
	Item(string nome, string tipo, int combate, int FA, int dano);
	string get_nome();
	string get_tipo();
	int get_combate();
	int get_FA();
	int get_dano();
	//implementar os sets
private:
	string nome;
	string tipo;
	int combate, FA, dano;
};

