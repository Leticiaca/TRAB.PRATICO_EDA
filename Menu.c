#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"

#define MAX_NAME 50
#define MAX_MOBILE_NUM 50
#define MAX_MOBILE_MODEL 50
#pragma region Menu 

typedef struct Costumer {
	int id;
	char name[MAX_NAME];
	char adress[MAX_NAME];
	int nif;
	float balance;
	struct Costumer* next;
}Costumer;

typedef struct Manager {
	int id;
	char name[MAX_NAME];
	char password[MAX_NAME];
	struct Manager* next;
}Manager;

typedef struct Mobility {
	int idMobility;
	char tipo[50];
	char batery_level[10];
	char autonomy[10];
	int rentMobility;
	struct Mobility* next;
}Mobility;


void show_menu() {
	printf("******************************\n");
	printf("*            MENU            *\n");
	printf("******************************\n");
	printf("* 1. Costumer                *\n");
	printf("* 2. Manager                 *\n");
	printf("* 3. Mobilidade              *\n");
	printf("* 0. Sair                    *\n");
	printf("******************************\n");
	printf("Opcao: ");
}

void show_costumer_menu() {
	printf("******************************\n");
	printf("*          Costumer          *\n");
	printf("******************************\n");
	printf("* 1. Listar Costumers        *\n");
	printf("* 2. Inserir Novo Costumer   *\n");
	printf("* 3. Remover Costumer        *\n");
	printf("* 4. Alterar Costumer        *\n");
	printf("* 0. Sair                    *\n");
	printf("******************************\n");
	printf("Opcao: ");
}

void show_manager_menu() {
	printf("******************************\n");
	printf("*          Manager           *\n");
	printf("******************************\n");
	printf("* 1. Listar Manageres        *\n");
	printf("* 2. Inserir Novo Manager    *\n");
	printf("* 3. Remover Manager         *\n");
	printf("* 4. Alterar Manager         *\n");
	printf("* 0. Sair                    *\n");
	printf("******************************\n");
	printf("Opcao: ");
}

void show_mobility_menu() {
	printf("******************************\n");
	printf("*          Mobility          *\n");
	printf("******************************\n");
	printf("* 1. Listar Mobilitys        *\n");
	printf("* 2. Inserir Nova Mobility   *\n");
	printf("* 3. Remover Mobility        *\n");
	printf("* 4. Alterar Mobility        *\n");
	printf("* 0. Sair                    *\n");
	printf("******************************\n");
	printf("Opcao: ");
}

#pragma region Costumer 
Costumer* newCostumer(int id, char* name, char* adress, int nif, float balance) {
	Costumer* costumer = (Costumer*)malloc(sizeof(Costumer));
	if (costumer == NULL) {
		printf("Erro ao alocar memória para o cliente\n");
	}

	costumer->id = id;
	strcpy(costumer->name, name);
	strcpy(costumer->adress, adress);
	costumer->nif = nif;
	costumer->balance, balance;
	costumer->next = NULL;
	return costumer;
}

Costumer* removeCostumer(Costumer* listCostumers, int id) {
	if (listCostumers == NULL) {
		return NULL;
	}
	Costumer* current = listCostumers;
	Costumer* previous = NULL;
	while (current != NULL) {
		if (current->id == id) {
			if (previous == NULL) {
				listCostumers = current->next;
			}
			else {
				previous->next = current->next;
			}
			free(current);
			return listCostumers;
		}
		previous = current;
		current = current->next;
	}
	printf("Costumer com id %d não encontrado\n", id);
	return listCostumers;
}

void listCostumer(Costumer* listCostumers) {
	if (listCostumers == NULL) {
		printf("None costumer found\n");
		return;
	}
	printf("Id\tname\tdress\iNif\tbalance\n");
	Costumer* current = listCostumers;
	while (current != NULL) {
		printf("%d\t%s\t%s\t%.2f\n", current->id, current->name, current->adress, current->nif, current->balance);
		current = current->next;
	}
}

Manager* newManager(int id, char* name, char*password){
	Manager* manager = (Manager*)malloc(sizeof(Manager));
	if(manager==NULL){
		printf("Erro ao alocar memória para o manager\n");
	}

	manager->id = id;
	strcpy(manager->name, name);
	strcpy(manager->password, password);
	manager->next = NULL;
	return manager;
}

Manager* removeManager(Manager* listManagers, int id) {
	if (listManagers == NULL) {
		return NULL;
	}
	Manager* current = listManagers;
	Manager* previous = NULL;
	while (current != NULL) {
		if (current->id == id) {
			if (previous == NULL) {
				listManagers = current->next;
			}
			else {
				previous->next = current->next;
			}
			free(current);
			return listManagers;
		}
		previous = current;
		current = current->next;
	}
	printf("Manager com id %d não encontrado\n", id);
	return listManagers;
}

void listManagers(Manager* listManagers) {
	if (listManagers == NULL) {
		printf("None manager found\n");
		return;
	}
	printf("Id\tname\tpassword\n");
	Manager* current = listManagers;
	while (current != NULL) {
		printf("%d\t%s\t%s\n", current->id, current->name, current->password);
		current = current->next;
	}
}

Mobility* createMobility(Mobility* mobility) {
	Mobility* newMobility = (Mobility*)malloc(sizeof(Mobility));
	
	printf("ID de mobility:");
	scanf("%d", &(newMobility->idMobility));
	printf("Type de mobility:");
	scanf("%s", newMobility->tipo);
	printf("Batery level:");
	scanf("%f", &(newMobility->batery_level));
	printf("A Mobilty is rent ?");
	scanf("%d", &(newMobility->rentMobility));

	newMobility->next = mobility;
	return newMobility;
}

Mobility* removeMobility(Mobility* mobility) {
	int idMobility = 0;
	Mobility* currentnode = mobility;
	Mobility* previousnode = NULL;

	listMobility(mobility);

	printf("Id de mobility que pretende remover:");
	scanf("%d", &idMobility);

	while (currentnode != NULL && currentnode->idMobility != idMobility) {
		previousnode = currentnode;
		currentnode = currentnode->next;
	}
	if (previousnode == NULL) {
		mobility = currentnode->next;
	}
	else {
		previousnode->next = currentnode->next;
	}
	free(currentnode);
	printf("Mobility com Id %d removida com sucesso\n", idMobility);
	return mobility;
}

Mobility* changeMobility(Mobility* mobility, int idMobility, char newtipo[]) {
	Mobility* currentnode = mobility;

	while (currentnode != NULL && currentnode->idMobility != idMobility) {
		currentnode = currentnode->next;
	}
	if (currentnode == NULL) {
		printf("Mobility com Id %d não encontrado\n", idMobility);
		return mobility;
	}
	strcpy(currentnode->tipo, newtipo);
	printf("Tipo de mobility com Id %d alterado para %s\n", idMobility);
	return mobility;
}