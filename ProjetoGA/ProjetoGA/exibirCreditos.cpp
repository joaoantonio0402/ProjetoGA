#include <iostream>
#include <fstream>

#include "exibirCreditos.h"

using namespace std;

exibirCreditos::exibirCreditos() {
    arq = leituraArquivo();
}

void exibirCreditos::imprimeCreditos() {
    arq.set_nomeArquivo("exibirCreditos.txt");
    arq.ler();
}