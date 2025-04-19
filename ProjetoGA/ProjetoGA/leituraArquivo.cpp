#include <fstream>
#include <iostream>
#include <string>

#include "leituraArquivo.h"

using namespace std;

leituraArquivo::leituraArquivo() {}

leituraArquivo::leituraArquivo(string nomeArquivo) {
	this->nomeArquivo = nomeArquivo;
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