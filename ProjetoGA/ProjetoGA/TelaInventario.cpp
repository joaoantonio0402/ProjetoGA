#include <fstream>
#include <iostream>
#include <vector>

#include "TelaInventario.h"

using namespace std;

TelaInventario::TelaInventario(string tipoPersonagem, int habilidade, int energia, int sorte) :
	Tela(), itens(18), itensEquipados(2), linhasArquivo(10) {
	this->tipoPersonagem = tipoPersonagem;
	this->habilidade = habilidade;
	this->energia = energia;
	this->sorte = sorte;
	this->cntItensInventario = 0;
	this->cntItensEquipados = 2; // O jogador comeca com 2 itens equipados
}

void TelaInventario::init() {
	string arquivo = ""; //Variavel que carrega o nome do arquivo do guerreiro ou mago
	
	if (tipoPersonagem == "Guerreiro") {
		arquivo = "InventarioGuerreiro.txt"; //Carrega inventario do Guerreiro
		itensEquipados[0] = "Machete"; // Adiciona item equipado
		itensEquipados[1] = "Couraca de pano"; // Adiciona item equipado

	}
	else if (tipoPersonagem == "Mago") {
		arquivo = "InventarioMago.txt"; //Carrega inventario do Mago
		itensEquipados[0] = "Anel de Doran"; // Adiciona item equipado
		itensEquipados[1] = "Tunica diferenciada"; // Adiciona item equipado
	}

	//Armazena as strings para adicionar no arquivo
	linhasArquivo[1] = "------------------INVENTARIO------------------";
	linhasArquivo[2] = "Sempre que quiser chamar seu inventario digite 'e'";
	linhasArquivo[3] = "Personagem: " + tipoPersonagem; // Personagem: Guerreiro/Mago"
	linhasArquivo[4] = "Habilidade: " + to_string(habilidade);
	linhasArquivo[5] = "Energia: " + to_string(energia);
	linhasArquivo[6] = "Sorte: " + to_string(sorte);

	atualizarItens(); //Funcao que atualiza os itens do inventario

	//Escreve os valores de linhasArquivo no arquivo
	ofstream outfile(arquivo); //Considera a variavel arquivo
	if(outfile.is_open()) {
		for(string linha : linhasArquivo){ // para cada linha(item) do vector linhasArquivo
			outfile << linha << endl;
		}
	}
	outfile.close();

	//Imprime o conteudo do arquivo
	set_nomeArquivo(arquivo);
	ler();
	
	pressioneParaRetornar();
}

void TelaInventario::adicionarItemInventario(string nomeItem) {
	//Nao permite o usuario adicionar itens com inventario lotado
	if (cntItensInventario >= 18) {
		cout << "Invetario Lotado" << endl;
		return;
	}
	itens[cntItensInventario] = nomeItem; //Adiciona o nome do item na posicao do contador
	cntItensInventario++;

	atualizarItens(); //Funcao que atualiza os itens do inventario
	return;
}

void TelaInventario::adicionarItemEquipado(Item item) {
	//Nao permite o usuario adicionar itens equipados se estiver lotado
	if (cntItensEquipados >= 2) {
		cout << "Invetario Lotado" << endl;
		return;
	}
	itensEquipados[cntItensEquipados] = item.get_nome(); //Adiciona o nome do item na posicao do contador
	cntItensEquipados++;

	atualizarItens(); //Funcao que atualiza os itens do inventario
	return;
}

void TelaInventario::removerItemInventario(string nomeItem) {
	bool itemEncontrado = false;

	// Procura o item no vetor
	for (int i = 0; i < cntItensInventario; ++i) {
		if (itens[i] == nomeItem) {
			itemEncontrado = true;

			// Desloca os itens posteriores para preencher o espa�o
			for (int j = i; j < cntItensInventario - 1; ++j) {
				itens[j] = itens[j + 1];
			}

			// Limpa o �ltimo item e decrementa o contador
			itens[cntItensInventario - 1] = "";
			cntItensInventario--;

			cout << "Item '" << nomeItem << "' removido com sucesso!" << endl;
			break; // Sai do loop ap�s remover
		}
	}

	if (!itemEncontrado) {
		cout << "Item '" << nomeItem << "' n�o encontrado no invent�rio!" << endl;
	}
	atualizarItens(); //Funcao que atualiza os itens do inventario
	return;
}

void TelaInventario::removerItemEquipado(Item item) {
	bool itemEncontrado = false;

	// Procura o item no vetor
	for (int i = 0; i < cntItensEquipados; ++i) {
		if (itensEquipados[i] == item.get_nome()) {
			itemEncontrado = true;

			// Desloca os itens posteriores para preencher o espa�o
			for (int j = i; j < cntItensEquipados - 1; ++j) {
				itensEquipados[j] = itensEquipados[j + 1];
			}

			// Limpa o �ltimo item e decrementa o contador
			itensEquipados[cntItensEquipados - 1] = "";
			cntItensEquipados--;

			cout << "Item '" << item.get_nome() << "' removido com sucesso!" << endl;
			break; // Sai do loop ap�s remover
		}
	}

	if (!itemEncontrado) {
		cout << "Item '" << item.get_nome() << "' n�o encontrado no invent�rio!" << endl;
	}

	atualizarItens(); // Funcao que atualiza os itens do inventario
	return;
}

void TelaInventario::atualizarItens() {
	string itensStr = ""; //Variavel que armazena o itens como uma string

	for (size_t i = 0; i < itens.size(); i++) { //Percorre o array de itens
		if (!itensStr.empty()) { //Aplica a condicao somente se existir algum item no array
			itensStr += ", "; // Adiciona v�rgula entre itens
		}
		itensStr += itens[i]; //Concatena o valor de itens[i] com o valor da variavel
	}
	linhasArquivo[8] = "Equipados: " + itensEquipados[0] + ", " + itensEquipados[1] + " (" + to_string(cntItensEquipados) + "/2)"; //Armazena a string dos itens equipados para adicionar no arquivo
	linhasArquivo[9] = "[ " + itensStr + "] " + "(" + to_string(cntItensInventario) + "/18)"; //Armazena a string dos itens do inventario para adicionar no arquivo
}

void TelaInventario::substituirItem(string i_equipado, string i_inventario) { //Substitui um item equipado por um item do inventario
	bool equipadoEncontrado = false;
	bool inventarioEncontrado = false;
	int posEquipado = 0;
	int posInventario = 0;

	// Procura o item equipado
	for (int i = 0; i < cntItensEquipados; ++i) {
		if (itensEquipados[i] == i_equipado) {
			// Se o item equipado for encontrado, armazena a posicao
			equipadoEncontrado = true;
			posEquipado = i;
			break;
		}
	}

	// Procura o item do inventario
	for (int i = 0; i < cntItensInventario; ++i) {
		if (itens[i] == i_inventario) {
			// Se o item do inventario for encontrado, armazena a posicao
			inventarioEncontrado = true;
			posInventario = i;
			break;
		}
	}

	if (!equipadoEncontrado) { // Se o item equipado não for encontrado, imprime mensagem de erro
		cout << "Item equipado '" << i_equipado << "' n�o encontrado!" << endl;
		return;
	}

	if (!inventarioEncontrado) { // Se o item do inventario não for encontrado, imprime mensagem de erro
		cout << "Item do invent�rio '" << i_inventario << "' n�o encontrado!" << endl;
		return;
	}

	// troca os itens de posicao
	string temp = itensEquipados[posEquipado];
	itensEquipados[posEquipado] = itens[posInventario];
	itens[posInventario] = temp;

	atualizarItens(); // Funcao que atualiza os itens do inventario
}

void TelaInventario::imprimirInventario() { // Caso o usuario possa modificar o inventario
	ler();
	pressioneParaRetornar();
	return;
}

void TelaInventario::modificarInventario() { // Funcao caso o usuario chame o inventario
	int opcao = 0;
	string itemRemovido = "";
	string itemAdicionado = "";
	string itemEquipado = "";

	ler(); // Carrega o arquivo do inventario

	cout << "remover(1)" << endl;
	cout << "substituir(2)" << endl;
	cout << "Digite o codigo do que deseja realizar no seu inventario ou 0 para sair: ";
	cin >> opcao; // Aguarda a resposta do usuario
	switch (opcao) { // Verifica a acao escolhida
	case 1:
		cout << "Digite o nome do item que deseja remover: ";
		cin >> itemRemovido;
		removerItemInventario(itemRemovido);
		break; // Adiciona o break para evitar que o usuario entre na proxima condicao sem querer
	
	case 2: // Substitui um item equipado por um item do inventario
		cout << "Digite o nome do item equipado: ";
		cin >> itemEquipado;
		cout << "Digite o nome do item do inventario: ";
		cin >> itemAdicionado;
		substituirItem(itemEquipado, itemAdicionado); // Substitui o item equipado pelo item do inventario
		break; // Adiciona o break para evitar que o usuario entre na proxima condicao sem querer
	case 0:
		break;
	}
	return;
}
