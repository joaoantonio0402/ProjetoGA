#include <iostream>
#include <fstream>

#include "ExibirCreditos.h"

using namespace std;

ExibirCreditos::ExibirCreditos() {}

void ExibirCreditos::imprimeCreditos() {
    set_nomeArquivo("ExibirCreditos.txt");
    ler();
    pressioneParaRetornar();

}