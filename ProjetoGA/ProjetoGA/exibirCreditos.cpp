#include <iostream>
#include <fstream>

#include "ExibirCreditos.h"

using namespace std;

ExibirCreditos::ExibirCreditos() {
    tela = Tela();
}

void ExibirCreditos::imprimeCreditos() {
    tela.set_nomeArquivo("ExibirCreditos.txt");
    tela.ler();
    tela.pressioneParaRetornar();

}