#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

#pragma region Manager

void listManagers(Manager* manager) {  // imprime o cabeçalho para a lista de managers
	printf("***************************************\n");
	printf("**           Manager List            **\n");
	printf("***************************************\n");

	if (manager == NULL) {
		printf("None manager found\n");
		return;
	}

	for (Manager* m = manager; m != NULL; m = m->next) { // percorre a lista ligada do manager 
		printf("Id:%d Name:%s Password:%s\n", m->idManager, m->nameManager, m->password);
	}
}

Manager* insertManager(Manager* manager, int idManager, char nameManager[], char password[]) { // recebe um ponteiro para o primeiro elemento de uma lista ligada
	Manager* newManager = (Manager*)malloc(sizeof(Manager));
	if (newManager == NULL) {
		return manager;
	}

	newManager->idManager = idManager;
	strcpy(newManager->nameManager, nameManager);
	strcpy(newManager->password, password);
	newManager->next = manager;

	return newManager;
}

int existManager(Manager* manager, int idManager){
	for (Manager* current = manager; current != NULL; current = current->next) {
		if (current->idManager == idManager) {
			return 1;
		}
	}
	return 0;
}

Manager* removeManager(Manager* manager, int idManager) {
	Manager* previous = manager, * current = manager, * aux;
	if (current == NULL) {
		return NULL;
	}
	else {
		if (current->idManager == idManager) {
			aux = current->next;
			free(current);
		}
		else {
			while ((current != NULL) && (current->idManager != idManager)) {
				previous = current;
				current = current->next;
			}
			if (current == NULL) {
				return(manager);
			}
			else {
				previous->next = current->next;
				free(current);
				return(manager);
			}
		}
	}
}

Manager* changeManager(Manager* manager, int idManager, char nameNewManager[], char Newpassword[]){
	Manager* current = manager;
	while (current != NULL && current->idManager != idManager) {
		current = current->next;
	}
	if (current != NULL) {
		strcpy(current->nameManager, nameNewManager);
		strcpy(current->password, Newpassword);
	}
	return manager;
}