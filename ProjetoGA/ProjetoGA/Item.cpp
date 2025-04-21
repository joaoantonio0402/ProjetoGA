#include "Item.h"
Item::Item(string nome, string tipo, int combate, int FA, int dano) {
	this->nome = nome;
	this->tipo = tipo;
	this->combate = combate;
	this->FA = FA;
	this->dano = dano;
}
string Item::get_nome() {
	return nome;
}
string Item::get_tipo() {
	return tipo;
}
int Item::get_combate() {
	return combate;
}
int Item::get_FA() {
	return FA;
}
int Item::get_dano() {
	return dano;
}