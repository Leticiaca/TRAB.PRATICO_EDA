#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME[100]

typedef struct Costumer {

	int idCostumer; // serve para identificar o Costumer
	char Costumername MAX_NAME[100]; //nome do Costumer
	char Costumeradress MAX_NAME[100]; // morada Costumer 
	int nifCostumer;
	float balance;
	struct Costumer* next;
} Costumer;

void listCostumer(Costumer* costumer) {
	Costumer* insertCostumer(Costumer * Costumer, int idCostumer, char Costumername[], char Costumeradress, int nifCostumer, float Costumerbalance[]);
}

void listCostumer(Costumer* costumer) {
	Costumer* removeCostumer(Costumer * Costumer, int nifCostumer);
}

int existCostumer(Costumer* costumer, int nifCostumer);


