#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"


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

	if (!existCostumer(costumer, nifCostumer)) {
		Costumer* new = (Costumer*)malloc(sizeof(Costumer));
		if (new != NULL) {
			new->idCostumer = idCostumer;
			strcpy(new->Costumername, Costumername);
			strcpy(new->Costumeradress, Costumeradress);
			new->nifCostumer = nifCostumer;
			new->balance = balance;
			new->next = costumer;
			return(new);
		}
		else {
			return(costumer);
		}
	}
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

	//Fazer esta função
//stumer* saveCostumers(Costumer* costumer, int idCostumer, char Costumername[], char Costumeradress[], int nifCostumer, float balance) {

//eturn costumer;
//}
	
Costumer* changeCostumers(Costumer* costumer, int idNew, char newName[], char newAdress[], int nifCostumer, float balance){
	Costumer* currentnode = costumer;
	Costumer* previousnode;

	while(currentnode !=NULL && currentnode->nifCostumer != nifCostumer){
		previousnode = currentnode;
		currentnode = currentnode->next;
	}
	if (currentnode != NULL) {
		currentnode->idCostumer = idNew;
		strcpy(currentnode->Costumername, newName);
		strcpy(currentnode->Costumeradress, newAdress);
		currentnode->nifCostumer = nifCostumer;
		currentnode->balance = balance;

	}
	return (costumer);

}

                  






