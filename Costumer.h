#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MaxName[100]

typedef struct Costumer {

	int idCostumer; // serve para identificar o Costumer
	char Costumername MaxName[100]; //nome do Costumer
	char Costumeradress MaxName[100]; // morada Costumer 
	int nifCostumer;
	float balance;
	struct Costumer* next;
} Costumer;

void listCostumer(Costumer* costumer) {
	Costumer* insertCostumer(Costumer * Costumer, int idCostumer, char Costumername[], char Costumeradress, int nifCostumer, float Costumerbalance[]);
}

