#include <stdio.h>
#include <stdlib.h>
#include "Costumer.h"

#define MaxName[100]

void listCostumer(Costumer* costumer) {  // percorre a lista de clients e imprime as informações
	printf("*********************************\n");
	printf("*      Lista de Costumer         *\n");
	printf("*********************************\n\n");

	for (Costumer* c = costumer; c != NULL; c = c->next) {
		printf("Costumer %d\n", c->idCostumer);
		printf("ID: %d\n", c->idCostumer);
		printf("Nome: %s\n", c->Costumername);
		printf("Morada: %s\n", c->Costumeradress);
		printf("NIF: %d\n", c->nifCostumer);
		printf("Saldo: %.2f\n", c->balance);
	}

	printf("\n*******************************\n");
}

Costumer* insertCostumer(Costumer* costumer, int idCostumer, char Costumername[], char Costumeradress[], int nifCostumer, float balance) { // adiciona um novo client à lista 
	Costumer* newCostumer = (Costumer*)malloc(sizeof(Costumer));

	if (newCostumer == NULL) {
		return costumer;
	}

	newCostumer->idCostumer = idCostumer;
	strcpy(newCostumer->Costumername, Costumername);
	strcpy(newCostumer->Costumeradress, Costumeradress);
	newCostumer->nifCostumer = nifCostumer;
	newCostumer->balance = balance;
	newCostumer->next = costumer;

	return newCostumer;
}




