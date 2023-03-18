#include <stdio.h>
#include <stdlib.h>
#include "Costumer.h"

#define MaxName[100]
#pragma region Costumer

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

int existCostumer(Costumer* costumer, int nifCostumer) {
	while (costumer != NULL) {
		if (costumer->nifCostumer == nifCostumer) {
			return (1);
		}
		costumer = costumer->next;
	}
	return (0);
}

Costumer* removeCostumer(Costumer* costumer, int nifCostumer) {
	Costumer* previous = costumer, * current = costumer, * aux;

	if (current == NULL) {
		return NULL;
	}
	else {
		if (current->nifCostumer == nifCostumer) {
			aux = current->next;
			free(current);
		}
		else {
			while ((current != NULL) && (current->nifCostumer != nifCostumer)) {
				previous = current;
				current = current->next;
			}
			if (current == NULL) {
				return (costumer);
			}
			else {
				previous->next = current->next;
				free(current);
				return(costumer);
			}
		}
	}
}



