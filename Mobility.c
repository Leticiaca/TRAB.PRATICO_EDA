#include <stdio.h>
#include <stdlib.h>
#include "Mobility.h"


void listMobility(Mobility* mobility) {
	printf("***************************************\n");
	printf("**          Mobility List            **\n");
	printf("***************************************\n");

	if (listMobility== NULL) {
		printf("Nenhuma mobility cadastrada\n");
		return;
	}
	Mobility* current = listMobility;
	while (current != NULL) {
		printf("Id:%d\n tipo:%s batery level:%.2f%%\n Autonomy:%.2f km\n rentMobility:%s\n\n", current->idMobility, current->tipo, current->batery_level, current->autonomy, current->rentMobility ? "sim" : "não");
	
		current = current->next;
	}
}

Mobility* insertMobility(Mobility* list, int id, char tipo[], float batery_level, float autonomy, int rent) {
	Mobility* new = (Mobility*)malloc(sizeof(Mobility));

	if (new == NULL) {
		printf("Erro ao alocar memória\n");
		return list;
	}

	new->idMobility = id;
	strcpy(new->tipo, tipo);
	new->batery_level = batery_level;
	new->autonomy = autonomy;
	new->next = NULL;

	if (list == NULL) {
		return new;
	}

	Mobility* current = list;

	while (current->next != NULL) {
		current = current->next;
	}

	current->next = new;

	return list;
}