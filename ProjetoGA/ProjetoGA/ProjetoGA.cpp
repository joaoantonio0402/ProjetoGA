// ProjetoGA.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "TelaAbertura.h"
#include "TelaAtributos.h"
#include "TelaEscolhaPersonagem.h"
#include "TelaInventario.h"
#include "TelaDeJogo.h"
#include "Item.h"

using namespace std;

int main()
{
    int acao = 0;
    TelaAbertura app;
    acao = app.init();

    if (acao == 1) {
        string tipoPersonagem;
        TelaAtributos telaAtributos;
        telaAtributos.init();

        TelaEscolhaPersonagem telaEscolhaPersonagem;
        tipoPersonagem = telaEscolhaPersonagem.init();
        vector<Item*> inventario;

        TelaInventario telaInventario(tipoPersonagem, telaAtributos.get_habilidade(), telaAtributos.get_energia(), telaAtributos.get_sorte());
        telaInventario.init();
        int cena = 1;
        TelaDeJogo jogo(&cena, &telaInventario);
        while (cena != 0) {
            jogo.jogar();
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
