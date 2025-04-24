#include <iostream>
#include <fstream>

#include "ExibirCreditos.h"

using namespace std;

ExibirCreditos::ExibirCreditos() {}

void ExibirCreditos::imprimeCreditos() {
    set_nomeArquivo("ExibirCreditos.txt"); // Nome do arquivo que armazena os creditos
    ler(); // Lê o arquivo e imprime na tela
    pressioneParaRetornar(); // Aguarda o usuário pressionar uma tecla para retornar

}