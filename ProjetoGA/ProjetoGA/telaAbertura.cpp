#include <fstream>
#include <iostream>

#include "exibirCreditos.h"
#include "telaAbertura.h"


using namespace std;

telaAbertura::telaAbertura() {
    this->arq = leituraArquivo("telaAbertura.txt");
}

void telaAbertura::chamarTela() {
    int acao;

    arq.ler();
    
    cin >> acao;

    switch(acao) {
        case 1:
            return;
        case 2:
            return;
        case 3:
            exibirCreditos().imprimeCreditos();
        case 4:
            return;
    }


}

