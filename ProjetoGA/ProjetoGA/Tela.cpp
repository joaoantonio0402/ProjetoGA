#include <fstream>
#include <iostream>
#include <string>

#include "Tela.h"

using namespace std;

Tela::Tela() {
    this->nomeArquivo = "";
}

void Tela::set_nomeArquivo(string s_nomeArquivo) {
    nomeArquivo = s_nomeArquivo;
}

void Tela::ler() {
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

void Tela::pressioneParaRetornar() {
    cout << "\nPressione qualquer tecla para retornar:";
    cin.ignore().get();
}
char Tela::aguardaResposta() {
    char opcao = '0';
    cout << "\nEscolha a opcao desejada:";
    cin >> opcao;
    return opcao;
}