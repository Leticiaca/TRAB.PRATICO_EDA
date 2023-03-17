#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//#include "Menu.h"

typedef struct Costumer Costumer;
struct Costumer {
	int id;
	char name[50];
	char adress[100];
	int nif;
	float balance;
	Costumer* next;
};

typedef struct Manager Manager;
struct Manager {
	int id;
	char name[50];
	char username[20];
	Manager* next
};

typedef struct Mobility Mobility;
struct Mobility {
	int id;
	char description[50];
	float autonomy;
	float minimumprice;
	int quantity;
	Mobility* next;
};

int main() {
	setlocale(LC_ALL, "");

	Costumer* costumers = loadCostumers();
	Manager* managers = loadManagers();
	Mobility* mobilitys = loadMobility();

	int option;
	do {
		showMenu();
		scanf("%d", &option);
		switch (option) {
		case1: // Client Menu
			int subOptionCostumer;
			do {
				showsubMenu("Costumer");
				scanf("%d", &subOptionCostumer);
				switch (subOptionCostumer) {
					case 1;
						listCostumers(costumers);
						break;

						case 2;
							insertCostumer(&costumers);
							saveCostumers(costumers);
							break;

							case 3;
								removeCostumers(&costumers);
								saveCostumers(costumers);
								break;

								case 4;
									changeCostumers(costumers);
									saveCostumers(costumers);
									break;

									case 0;
										break;
									default:
										showMessage("Option invalid!");
										break;
				}
			} while (subOptionCostumer != 0);
			break;

		case 2:
			int subOptionManager;
			do {
				showsubMenu("Manager");
				scanf("%d", &subOptionManager);
				switch (subOptionManager) {
				case 1:
					listManagers(managers);
					break;

				case 2:
					insertManagers(&managers);
					break;
				}
			}
		}
	}
}
