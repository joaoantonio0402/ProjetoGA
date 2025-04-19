#include <fstream>
#include <iostream>
#include <string>

#include "leituraArquivo.h"

using namespace std;

leituraArquivo::leituraArquivo() {
    this->nomeArquivo = "";
}

void leituraArquivo::set_nomeArquivo(string s_nomeArquivo) {
    nomeArquivo = s_nomeArquivo;
}

void leituraArquivo::ler() {
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