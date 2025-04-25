#include "Personagem.h"

Personagem::Personagem() {
    this->habilidade = 0;
    this->sorte = 0;
    this->energia = 0;
}

int Personagem::get_habilidade() {
    return habilidade;
}

int Personagem::get_energia() {
    return energia;
}

int Personagem::get_sorte() {
    return sorte;
}

void Personagem::set_habilidade(int s_habilidade) {
    habilidade = s_habilidade;
}

void Personagem::set_energia(int s_energia) {
    energia = s_energia;
}

void Personagem::set_sorte(int s_sorte) {
    sorte = s_sorte;
}