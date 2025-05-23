#include "TelaDeJogo.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

TelaDeJogo::TelaDeJogo(int* cena, TelaInventario* inventario, Personagem& personagem)
    : cena(cena), inventario(inventario), personagem(personagem), telaBatalha(TelaBatalha(personagem)) { // Inicializa o ponteiro cena e o ponteiro inventario
   
}
void TelaDeJogo::jogar() {
    char opcao = ' ';
	set_nomeArquivo(to_string(*cena) + ".txt"); // Nome do arquivo que armazena a cena atual
	ler();


    telaBatalha.init((to_string(*cena) + ".txt"));
    if(!telaBatalha.batalhaIniciada){
        coletarItem(to_string(*cena) + ".txt"); // Coleta os itens da cena atual
        opcao = aguardaResposta(); // Lê a opção do usuário
        while (opcao == 'e') { // Tecla para chamar o inventario em qualquer acao
            inventario->modificarInventario(); // Chama a tela do inventario
            // Retorna para a condição anterior
            ler();
            opcao = aguardaResposta();
        }
        *cena = opcao - '0';
    }
    else {
        char resultado = telaBatalha.resultadoBatalha();
        *cena = resultado - '0';
    }
}
void TelaDeJogo::coletarItem(string nomeArquivo){
    ifstream arquivo(nomeArquivo);
    string linha;

    
    while (getline(arquivo, linha)) {
        
        if (linha.find("I:") == 0) {
            
            string nomeItem = "";
            int index = 2;
            
             // Comeca do indice 2 para pular "I:"
            while (index < linha.size() && linha[index] != ';') {
            nomeItem += linha[index];
            index++;
            }
            
            inventario->adicionarItemInventario(nomeItem);// colocar o item no inventario
        }
        else if (linha.find("P:") == 0) {
            inventario->adicionarProvisao();
        }
    }
    arquivo.close();
    return;
}
