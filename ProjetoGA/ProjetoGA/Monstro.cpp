#include <fstream>
#include <iostream>
#include <string>
#include "Monstro.h"

using namespace std;

Monstro::Monstro() {
    this->nomeArquivo = "";
    this->habilidade = 0;
    this->sorte = 0;
    this->energia = 0;
    this->tesouro = 0;
    this->provisao = 0;
}

void Monstro::set_nomeArquivo(string s_nomeArquivo) {
    nomeArquivo = s_nomeArquivo;
}

void Monstro::ler() {
    char proximo; // Variavel que armazena o proximo caractere lido
    ifstream entrada; // Variavel que armazena o arquivo
    entrada.open(nomeArquivo); // Abre o arquivo

    entrada.get(proximo); // Lê o primeiro caractere do arquivo
    while (!entrada.eof()) { // Enquanto não chegar ao fim do arquivo
        cout << proximo; // Imprime o caractere lido
        entrada.get(proximo); // Lê o próximo caractere do arquivo
    }
    entrada.close(); // Fecha o arquivo
}

void Monstro::init() {
    ifstream arquivo(nomeArquivo);
    string linha;

    while (getline(arquivo, linha)) {
        if (linha.find("H:") == 0) {
            habilidade = stoi(linha.substr(2));
        }
        else if (linha.find("S:") == 0) {
            sorte = stoi(linha.substr(2));
        }
        else if (linha.find("E:") == 0) {
            energia = stoi(linha.substr(2));
        }
        else if (linha.find("T:") == 0) {
            tesouro = stoi(linha.substr(2));
        }
        else if (linha.find("P:") == 0) {
            provisao = stoi(linha.substr(2));
        }
    }
}

int Monstro::get_habilidade() {
    return habilidade;
}

int Monstro::get_energia() {
    return energia;
}

int Monstro::get_sorte() {
    return sorte;
}

int Monstro::get_tesouro() {
    return tesouro;
}

int Monstro::get_provisao() {
    return provisao;
}