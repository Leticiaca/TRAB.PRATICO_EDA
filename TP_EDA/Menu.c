#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Menu.h"

#define MaxName 100

void MostrarMenu() {
	printf("******************************\n");
	printf("*            MENU            *\n");
	printf("******************************\n");
	printf("* 1.Cliente                  *\n");
	printf("* 2.Gestor                   *\n");
	printf("* 3.Mobilidade               *\n");
	printf("* 0.Sair                     *\n");
	printf("******************************\n");
	printf("Opcao:");
}

void MostrarCliente() {
	printf("******************************\n");
	printf("*          Cliente           *\n");
	printf("******************************\n");
	printf("* 1.Listar Clientes          *\n");
	printf("* 2.Inserir Novo Cliente     *\n");
	printf("* 3.Remover Cliente          *\n");
	printf("* 4.Alterar Cliente          *\n");
	printf("* 0.Sair                     *\n");
	printf("******************************\n");
	printf("Opcao:");
}

void MostrarGestor() {
	printf("******************************\n");
	printf("*          Gestor            *\n");
	printf("******************************\n");
	printf("* 1.Listar Gestores          *\n");
	printf("* 2.Inserir Novo Gestor      *\n");
	printf("* 3.Remover Gestor           *\n");
	printf("* 4.Alterar Gestor           *\n");
	printf("* 0.Sair                     *\n");
	printf("******************************\n");
	printf("Opcao:");
}

void MostrarMobilidade() {
	printf("******************************\n");
	printf("*		  Mobilidade         *\n");
	printf("******************************\n");
	printf("* 1.Listar Mobilidades       *\n");
	printf("* 2.Inserir Nova Mobilidade  *\n");
	printf("* 3.Remover Mobilidade       *\n");
	printf("* 4.Alterar Mobilidade       *\n");
	printf("* 0.Sair                     *\n");
	printf("******************************\n");
	printf("Opcao:");
}

#pragma endregion 

#pragma region Cliente 

// função para inserir um cliente

Cliente* CriarCliente(Cliente* cliente) {
	int idCliente;
	char nomeCliente[MaxName];
	char moradaCliente[MaxName];
	int nifCliente;
	float saldo;
	Cliente* cliente = NULL;

	printf("ID do cliente: \n");
	scanf("%d", &idCliente);
	printf("Nome do cliente: \n");
	scanf("%d", &nomeCliente);
	printf("Morada: \n");
	scanf("%d", &moradaCliente);
	printf("NIF: \n");
	scanf("%d", &nifCliente);
	printf("Saldo: \n");
	scanf("%.2f \n", &saldo);

	if (idCliente != NULL) {
		printf("\n Já existe um cliente com esse nome '%s' \n", nomeCLliente);
		return cliente;
	}
	
	return inserirCliente(cliente, idCliente, nomeCliente, moradaCliente, nifCliente, saldo);

}

//função para remover um cliente 

Cliente* removerCliente(Cliente* cliente) {
	int idCliente = 0;
	listarClientes(cliente);

	printf("ID do Cliente que quer remover:");
	scanf("%d", &idCliente);

	return removerCliente(cliente, idCliente);
}

//função para alterar um cliente

Cliente* alterarCliente(Cliente* cliente, int  nifCliente, char nomeNovo[]) {
	Cliente* modoAtual = cliente;
	Cliente* modoAnterior;

	while (modoAtual != NULL && modoAtual->nifCliente != nifCliente) {
		modoAnterior = modoAtual;
		modoAtual = modoAtual -> seguinte;
	}

	if (modoAtual != NULL) {
		strcpy(modoAtual->nomeCliente, nomeNovo);
	}
	return (cliente);
}

//função para inserir um gestor 

Gestor* criarGestor(Gestor* gestor) {
	int idGestor;
	char nomeGestor[MaxName];
	char password[MaxName];
	Gestor* gestores = NULL;

	printf("ID do gestor: ");
	scanf("%d", &idGestor);
	printf("Nome do gestor:");
	scanf("%d", &nomeGestor);
	printf("Insira password:");
	scanf("%s", &password);

	if (idGestor != NULL) {

	}
}