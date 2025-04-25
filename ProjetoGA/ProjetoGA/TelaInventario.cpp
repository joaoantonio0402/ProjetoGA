#include <fstream>
#include <iostream>
#include <vector>

#include "TelaInventario.h"

using namespace std;

TelaInventario::TelaInventario(string tipoPersonagem, int habilidade, int energia, int sorte) :
	Tela(), itens(), itensEquipados(2), linhasArquivo(12) {
	this->tipoPersonagem = tipoPersonagem;
	this->habilidade = habilidade;
	this->energia = energia;
	this->energiaMax = energia;
	this->sorte = sorte;
	this->valorTesouro = 0;
	this->cntItensInventario = 0;
	this->cntItensEquipados = 2; // O jogador comeca com 2 itens equipados
	this->cntProvisoes = 0;
	this->arquivo = "";
}

void TelaInventario::init() {
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
	linhasArquivo[7] = "Tesouro: " + to_string(valorTesouro);
	linhasArquivo[8] = "Provisoes: " + to_string(cntProvisoes);

	atualizarItens(); //Funcao que atualiza os itens do inventario


	bufferParaArquivo();
	

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
	
	itens.push_back(nomeItem); //Adiciona o nome do item no vetor
	cntItensInventario++;

	atualizarItens(); //Funcao que atualiza os itens do inventario
	return;
}

void TelaInventario::adicionarItemEquipado(string nomeItem) {
	//Nao permite o usuario adicionar itens equipados se estiver lotado
	if (cntItensEquipados >= 2) {
		cout << "Invetario Lotado" << endl;
		return;
	}
	itensEquipados.push_back(nomeItem); //Adiciona o nome do item no vetor
	cntItensEquipados++;

	atualizarItens(); //Funcao que atualiza os itens do inventario
	return;
}

void TelaInventario::removerItemInventario(string nomeItem) {
	// Usando algoritmo find para localizar o item
	auto it = find(itens.begin(), itens.end(), nomeItem);

	if (it != itens.end()) {
		// Remove o item usando erase (mais eficiente que deslocamento manual)
		itens.erase(it);
		cntItensInventario--; // Atualiza o contador

		cout << "Item '" << nomeItem << "' removido com sucesso!" << endl;
	}
	else {
		cout << "Item '" << nomeItem << "' não encontrado no inventário!" << endl;
	}
	atualizarItens(); //Funcao que atualiza os itens do inventario
	return;
}

void TelaInventario::removerItemEquipado(string nomeItem) {
	// Usando algoritmo find para localizar o item
	auto it = find(itensEquipados.begin(), itensEquipados.end(), nomeItem);
	if (it != itensEquipados.end()) {
		// Remove o item usando erase (mais eficiente que deslocamento manual)
		itensEquipados.erase(it);
		cntItensEquipados--; // Atualiza o contador

		cout << "Item '" << nomeItem << "' removido com sucesso!" << endl;
	}
	else {
		cout << "Item '" << nomeItem << "' não encontrado no inventário!" << endl;
	}
	atualizarItens(); //Funcao que atualiza os itens do inventario
	return;

}

void TelaInventario::atualizarItens() {
	string itensStr = ""; //Variavel que armazena o itens como uma string

	for (string item : itens) { //Percorre o array de itens
		if (!itensStr.empty()) { //Aplica a condicao somente se existir algum item no array
			itensStr += ", "; // Adiciona v�rgula entre itens
		}
		itensStr += item; //Concatena o valor de itens[i] com o valor da variavel
	}
	linhasArquivo[10] = "Equipados: " + itensEquipados[0] + ", " + itensEquipados[1] + " (" + to_string(cntItensEquipados) + "/2)"; //Armazena a string dos itens equipados para adicionar no arquivo
	linhasArquivo[11] = "[ " + itensStr + "] " + "(" + to_string(cntItensInventario) + "/18)"; //Armazena a string dos itens do inventario para adicionar no arquivo
	bufferParaArquivo();
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
	swap(itensEquipados[posEquipado], itens[posInventario]);

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
	cout << "usar provisao(3)" << endl;
	cout << "Digite o codigo do que deseja realizar no seu inventario ou 0 para sair: ";
	cin >> opcao; // Aguarda a resposta do usuario
	switch (opcao) { // Verifica a acao escolhida
	case 1:
		cout << "Digite o nome do item que deseja remover: ";
		cin.ignore();
		getline(cin, itemRemovido); // Lê toda a linha incluindo espaços

		removerItemInventario(itemRemovido);
		break; // Adiciona o break para evitar que o usuario entre na proxima condicao sem querer
	
	case 2: // Substitui um item equipado por um item do inventario
		cout << "Digite o nome do item equipado: ";
		cin.ignore();
		getline(cin, itemEquipado); // Lê toda a linha incluindo espaços

		cout << "Digite o nome do item do inventario: ";
		getline(cin, itemAdicionado); // Lê toda a linha incluindo espaços

		substituirItem(itemEquipado, itemAdicionado); // Substitui o item equipado pelo item do inventario
		break; // Adiciona o break para evitar que o usuario entre na proxima condicao sem querer

	case 3:
		usarProvisao();
	case 0:
		break;
	}
	return;
}

void TelaInventario::adicionarProvisao() {
	cntProvisoes++;
	linhasArquivo[10] = "Provisoes: " + to_string(cntProvisoes);
	bufferParaArquivo();
}

void TelaInventario::usarProvisao() {
	if (cntProvisoes > 0) {
		cntProvisoes--; // Consume a provisao
		// Cada provisao restaura 4 de energia
		if ((energia + 4) > energiaMax){ // Se passar da energia maxima do personagem
			energia = energiaMax; // fixa na energia maxima
			return;
		}
		energia = energia + 4; // soma 4 na energia atual
		linhasArquivo[10] = "Provisoes: " + to_string(cntProvisoes);
		bufferParaArquivo();
		return;
	}
	return;
}

void TelaInventario::bufferParaArquivo() {
	//Escreve os valores de linhasArquivo no arquivo
	ofstream outfile(arquivo); //Considera a variavel arquivo
	if (outfile.is_open()) {
		for (string linha : linhasArquivo) { // para cada linha(item) do vector linhasArquivo
			outfile << linha << endl;
		}
	}
	outfile.close();
}