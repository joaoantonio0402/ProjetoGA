#include <fstream>
#include <random>


#include "TelaBatalha.h"

using namespace std;

TelaBatalha::TelaBatalha(){}

TelaBatalha::TelaBatalha(Personagem personagem): personagem(personagem) {
    this->monstro = Monstro();
    this->p_habilidade = 0;
    this->p_energia = 0;
    this->p_sorte = 0;
}

void TelaBatalha::init(string nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    string linha;

    p_habilidade = personagem.get_habilidade();
    p_energia = personagem.get_energia();
    p_sorte = personagem.get_sorte();

    while (getline(arquivo, linha)) {

        if (linha.find("M:") == 0) {
            monstro.set_nomeArquivo(nomeArquivo);
            monstro.init();
            iniciaBatalha();
        }
    }
    arquivo.close();
    return;    
}

void TelaBatalha::iniciaBatalha() {
    int energiaMonstro = monstro.get_energia();
    while (energiaMonstro > 0 || p_energia > 0) {
        int ataqueMonstro = monstro.get_habilidade() + numeroAleatorio();
        int ataqueP = p_habilidade + numeroAleatorio();
        if (ataqueMonstro > ataqueP) {
            p_energia -= 2;
        }
        else if (ataqueP > ataqueMonstro) {
            energiaMonstro -= 2;
        }
        else {
            continue;
        }

    }
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