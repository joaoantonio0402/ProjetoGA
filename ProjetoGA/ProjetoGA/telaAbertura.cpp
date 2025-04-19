#include <fstream>
#include <iostream>


#include "exibirCreditos.h"
#include "telaAbertura.h"

using namespace std;

telaAbertura::telaAbertura() {
    this->arq = leituraArquivo();
}

void telaAbertura::chamarTela() {
    int acao = 0;
    while(true){
        arq.set_nomeArquivo("telaAbertura.txt");
        arq.ler();

        cin >> acao;

        switch (acao){
        case 1:
            return;
        case 2:
            return;
        case 3:
            arq.set_nomeArquivo("exibirCreditos.txt");
            arq.ler();
            break;
        case 4:
            return;
        default:
            cout << "Opcao invalida" << endl;
            break;
        }
    }
}