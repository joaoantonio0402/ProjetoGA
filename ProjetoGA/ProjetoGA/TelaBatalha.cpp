#include <fstream>
#include <iostream>
#include <random>


#include "TelaBatalha.h"

using namespace std;

TelaBatalha::TelaBatalha(Personagem& personagem) :
    personagem(personagem),
    linhasArquivo(7),
    p_habilidade(personagem.get_habilidade()),
    p_energia(personagem.get_energia()),
    p_sorte(personagem.get_sorte()) {

    this->monstro = Monstro();
    this->batalhaIniciada = false;
    this->opcao = ' ';
}


void TelaBatalha::init(string nomeArquivo) {
    batalhaIniciada = false;
    ifstream arquivo(nomeArquivo);
    string linha;
    while (getline(arquivo, linha)) {

        if (linha.find("M:") == 0) {
            batalhaIniciada = true;
            int acao = 0;
            monstro.set_nomeArquivo(nomeArquivo);
            monstro.init();
            linhasArquivo[0] = "\n";
            linhasArquivo[1] = "------------------BATALHA------------------";
            linhasArquivo[2] = "Monstro: " + monstro.get_nome() + " Energia: " + to_string(monstro.get_energia());
            linhasArquivo[4] = "(1) Atacar";
            linhasArquivo[5] = "(2) Fugir";
            linhasArquivo[6] = "Escolha a opcao desejada:";
            bufferParaArquivo();
            set_nomeArquivo("telaBatalha.txt");
            ler();
            cin >> acao;
            if (acao == 1) {
                iniciaBatalha();
            }
            else if (acao == 2) {
                cout << "Voce fugiu!" << endl;
                exit(0);
            }
        }
   }
    arquivo.close();
    return;    
}

void TelaBatalha::iniciaBatalha() {
    int energiaMonstro = monstro.get_energia();
    while (energiaMonstro > 0 && p_energia > 0) {
        int ataqueMonstro = monstro.get_habilidade() + numeroAleatorio();
        int ataqueP = p_habilidade + numeroAleatorio();
        if (ataqueMonstro > ataqueP) {
            p_energia = p_energia - 2;
            cout << "Sua energia: " << p_energia << endl;
        }
        else if (ataqueP > ataqueMonstro) {
            energiaMonstro -= 2;
            cout << "Energia monstro: " << energiaMonstro << endl;
        }
        else {
            continue;
        }
        cout << "\nPressione qualquer tecla para ir para o proximo turno:";
        cin.get();
    }
    if (energiaMonstro <= 0) {
        cout << "Voce derrotou o monstro" << endl;
        opcao = monstro.get_cenaVencer();
    }
    else {
        cout << "Voce foi derrotado" << endl;
        monstro.get_cenaPerder();
    }
    batalhaIniciada = false;
}

int TelaBatalha::numeroAleatorio() {
    // Inicializa o gerador de números aleatórios
    random_device rd;
    mt19937 gen(rd());

    // Define o intervalo
    uniform_int_distribution<> distrib(1, 10);
    
    int random = distrib(gen);
    return random;
}

void TelaBatalha::bufferParaArquivo() {
    //Escreve os valores de linhasArquivo no arquivo
    ofstream outfile(nomeArquivo); //Considera a variavel arquivo
    if (outfile.is_open()) {
        for (string linha : linhasArquivo) { // para cada linha(item) do vector linhasArquivo
            outfile << linha << endl;
        }
    }
    outfile.close();
}

char TelaBatalha::resultadoBatalha() {
    return opcao;
}