#include <fstream>
#include <iostream>


#include "ExibirCreditos.h"
#include "TelaAbertura.h"

using namespace std;

TelaAbertura::TelaAbertura() {
    this->telaCreditos = ExibirCreditos();
}

void TelaAbertura::chamarTela() {
    int acao = 0;
    while(true){
        set_nomeArquivo("TelaAbertura.txt");
        ler();

        cin >> acao;

        switch (acao){
        case 1:
            return;
        case 2:
            return;
        case 3:
            telaCreditos.imprimeCreditos();
            
            break;
        case 4:
            return;
        default:
            cout << "Opcao invalida" << endl;
            break;
        }
    }
}