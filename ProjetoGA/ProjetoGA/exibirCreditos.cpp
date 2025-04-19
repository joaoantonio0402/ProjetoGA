#include <iostream>
#include <fstream>

#include "exibirCreditos.h"

using namespace std;

exibirCreditos::exibirCreditos(): arq("exibirCreditos.txt"){
 
}

void exibirCreditos::imprimeCreditos(){
    arq.ler();
}