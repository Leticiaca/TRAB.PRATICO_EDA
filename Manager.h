#pragma once

#include <stdio.h>
#include <stdlib.h>

#define Maxname 100

typedef struct Manager {
	int idManager;
	char nameManager[Maxname];
	char password[Maxname];
	struct manager* next;
}Manager;

void listManagers(Manager* manager);
Manager* insertManager(Manager* manager, int idManager, char nameManager[], char password[]);
