// ProjetoGA.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Personagem.h"
#include "TelaAbertura.h"
#include "TelaAtributos.h"
#include "TelaEscolhaPersonagem.h"
#include "TelaInventario.h"
#include "TelaDeJogo.h"
#include "Item.h"

using namespace std;

int main()
{
    int acao = 0; // Variavel que armazena a acao do usuario
    TelaAbertura app;
    acao = app.init();

    if (acao == 1) { // Condicao de um novo jogo
       
        TelaAtributos telaAtributos;
        telaAtributos.init(); // Inicia a tela para definir os valores de habilidade, energia e sorte

        string tipoPersonagem; // Variavel que armazena o nome do tipo do personagem
        TelaEscolhaPersonagem telaEscolhaPersonagem; // Cria um objeto da classe TelaEscolhaPersonagem
        tipoPersonagem = telaEscolhaPersonagem.init(); // Inicia a tela para definir o tipo do personagem, Guerreiro ou Mago
        vector<Item*> inventario;

        Personagem personagem;
        TelaInventario telaInventario(tipoPersonagem, telaAtributos.get_habilidade(), telaAtributos.get_energia(), telaAtributos.get_sorte(), &personagem);
        telaInventario.init(); // Inicia a tela do inventario, que carrega os itens do personagem e imprime na tela
        int cena = 1;
        TelaDeJogo jogo(&cena, &telaInventario, personagem); // Cria um objeto da classe TelaDeJogo, que inicia o jogo
        while (cena != 0) { // Enquanto a cena for diferente de 0, o jogo continua
            jogo.jogar(); // Inicia a tela de jogo, que imprime as opcoes de acao do personagem
        }
    }

    return 0;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
