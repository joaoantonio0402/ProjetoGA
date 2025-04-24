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

        cin >> acao; // Lê a ação do usuário

        switch (acao){ // Verifica a ação escolhida
        case 1:
            return 1; // Novo jogo
        case 2:
            return 2; // Carregar jogo
        case 3:
            telaCreditos.imprimeCreditos(); // Chama a tela de créditos
            break;
        case 4:
            return 4; // Sair do jogo
        default:
            cout << "Opcao invalida" << endl;
            pressioneParaRetornar();
        }
    }
}