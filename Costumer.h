#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 100

typedef struct Costumer {

	int idCostumer; // serve para identificar o Costumer
	char Costumername [MAX_NAME]; //nome do Costumer
	char Costumeradress [MAX_NAME]; // morada Costumer 
	int nifCostumer;
	float balance;
	struct Costumer* next;
} Costumer;


//void listCostumer(Costumer* costumer);
//Costumer* insertCostumer(Costumer* costumer, int idCostumer, char Costumername[], char Costumeradress, int nifCostumer, float balance[]);
//Costumer* removeCostumer(Costumer* costumer, int nifCostumer);
//Costumer* changeCostumers(Costumer* costumer);
//int existCostumer(Costumer* costumer, int nifCostumer);
//void saveCostumers(Costumer* costumer);



