#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

#pragma region Mobility
//struct Mobility* next;


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

Mobility* insertMobility(Mobility* mobility,int idMobility, char tipo[], float batery_level, float autonomy){
	if (!existMobility(mobility, idMobility)) {
		Mobility* new = malloc(sizeof( mobility));

		if (new != NULL) {
			new->idMobility = idMobility;
			strcpy(new->tipo, tipo);
			new->batery_level = batery_level;
			new->autonomy = autonomy;
			new->next = mobility;

			if (mobility ==NULL){
				mobility = new;
			}
			return new;
		}
	}

	return mobility;
}

int existMobility(Mobility* mobility, int idMobility) {
	while (mobility != NULL) {
		if (mobility->idMobility == idMobility) return(1);
		mobility = mobility->next;
	}
	return (0);
}

Mobility* removeMobility(Mobility* mobility, int idMobility) {
	Mobility* previous = mobility, * current = mobility, * aux;

	if (current == NULL) return NULL;
	else if (current->idMobility == idMobility) {
		aux = current->next;
		free(current);
	}
	else {
		while ((current != NULL) && (current->idMobility != idMobility)) {
			previous = current;
			current = current->next;
		}
		if (current == NULL) return (mobility);
		else {
			previous->next = current->next;
			free(current);
			return(mobility);
		}
	}
}

Mobility* changeMobility(Mobility* mobility, int idMobility, char tipo[], float batery_level, float autonomy) {
	Mobility* currentnode = mobility;
	Mobility* previousnode;

	while (currentnode != NULL && currentnode->idMobility != idMobility) {
		previousnode = currentnode;
		currentnode = currentnode->next;
	}
	if (currentnode != NULL) {
		currentnode->idMobility = idMobility;
		strcpy(currentnode->tipo, tipo);
		currentnode->batery_level = batery_level;
		currentnode->autonomy = autonomy;
	}
	return (mobility);
}