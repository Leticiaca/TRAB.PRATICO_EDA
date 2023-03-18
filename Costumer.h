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


/// <summary>
/// N�o sei o que � isto
/// </summary>
/// <param name="costumer"></param>
/// 
/// Mas tens duas fun��es com o mesmo nome e depois chamam outra fun��o que faz outra merda diferente
/// Para mim o que faz sentido � isto
/// 
/// 
/// 
//void listCostumer(Costumer* costumer) {
//	Costumer* insertCostumer(Costumer * Costumer, int idCostumer, char Costumername[], char Costumeradress, int nifCostumer, float Costumerbalance[]);
//}
//
//void listCostumer(Costumer* costumer) {
//	Costumer* removeCostumer(Costumer * Costumer, int nifCostumer);
//}

void listCostumer(Costumer* costumer);
Costumer* insertCostumer(Costumer* Costumer, int idCostumer, char Costumername[], char Costumeradress, int nifCostumer, float Costumerbalance[]);
Costumer* removeCostumer(Costumer* Costumer, int nifCostumer);
int existCostumer(Costumer* costumer, int nifCostumer);


