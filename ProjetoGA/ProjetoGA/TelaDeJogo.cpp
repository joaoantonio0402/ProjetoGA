#include "TelaDeJogo.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

TelaDeJogo::TelaDeJogo(int* cena, TelaInventario* inventario)
    : cena(cena), inventario(inventario) {
}
void TelaDeJogo::jogar() {
	set_nomeArquivo(to_string(*cena) + ".txt");
	ler();
    coletarItem(to_string(*cena) + ".txt");
	int opcao = aguardaResposta();
	*cena = opcao;
}
void TelaDeJogo::coletarItem(string nomeArquivo){
    ifstream arquivo(nomeArquivo);
    string linha;

    while (getline(arquivo, linha)) {
        if (linha.find("I:") == 0) {
            // colocar o item no inventario
            
           // inventario.push_back(new )
        }
    }

    arquivo.close();
}
