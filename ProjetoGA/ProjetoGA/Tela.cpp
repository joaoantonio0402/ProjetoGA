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
    string line;
    ifstream entrada;
    entrada.open(nomeArquivo);

    while (getline(entrada, line)) {
        cout << line << endl;
    }
    entrada.close();
}

void Tela::pressioneParaRetornar() {
    cout << "\nPressione qualquer tecla para retornar:";
    cin.ignore().get();
}