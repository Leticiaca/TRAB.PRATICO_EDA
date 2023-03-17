#include <stdio.h>
#include <stdlib.h>
#include "Manager.h"

void listManagers(Manager* manager) {  // imprime o cabeçalho para a lista de managers
	printf("***************************************\n");
	printf("**           Manager List            **\n");
	printf("***************************************\n");

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