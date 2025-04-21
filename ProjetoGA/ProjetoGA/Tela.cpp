#include <fstream>
#include <iostream>
#include <string>

#include "Tela.h"

using namespace std;

Tela::Tela() {
    this->nomeArquivo = "";
}

void Tela::set_nomeArquivo(string s_nomeArquivo) {
    nomeArquivo = s_nomeArquivo;
}

void Tela::ler() {
    char proximo;
    ifstream entrada;
    entrada.open(nomeArquivo);

    entrada.get(proximo);
    while (!entrada.eof()) {
        cout << proximo;
        entrada.get(proximo);
    }
    entrada.close();
}

void Tela::pressioneParaRetornar() {
    cout << "\nPressione qualquer tecla para retornar:";
    cin.ignore().get();
}