#include <fstream>
#include <iostream>


#include "ExibirCreditos.h"
#include "TelaAbertura.h"

using namespace std;

TelaAbertura::TelaAbertura() {
    this->telaCreditos = ExibirCreditos();
}

int TelaAbertura::init() {
    int acao = 0;
    while(true){
        set_nomeArquivo("TelaAbertura.txt");
        ler();

        cin >> acao;

        switch (acao){
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            telaCreditos.imprimeCreditos();
            break;
        case 4:
            return 4;
        default:
            cout << "Opcao invalida" << endl;
            pressioneParaRetornar();
        }
    }
}