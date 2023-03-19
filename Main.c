#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Menu.h"


int main() {
	setlocale(LC_ALL, "");

	Costumer* costumers = (Costumer*)malloc(sizeof(costumers));
	Manager* managers = (Manager*)malloc(sizeof(managers));
	Mobility* Mobilitys = (Mobility*)malloc(sizeof(Mobilitys));

	int option;
	int subOptionCostumer;
	int subOptionManager;

	show_menu();
	scanf("%d", &option);
	switch (option) {
	case 1: // Client Menu
		do {
			show_costumer_menu();
			scanf("%d", &subOptionCostumer);
			switch (subOptionCostumer) {
			case 1:
				listCostumer(costumers);
				break;

			case 2:
				//insertCostumer(&costumers);
				saveCostumers(costumers);
				break;

			case 3:
				removeCostumer(costumers, costumers->nifCostumer);
				saveCostumers(costumers);
				break;

			case 4:
				changeCostumers(costumers);
				saveCostumers(costumers);
				break;

			case 0:
				break;
			default:
				system("cls");
				printf("Option invalid!");
				break;
			}
		} while (subOptionCostumer != 0);
		break;

	case 2:
		show_manager_menu();
		scanf("%d", &subOptionManager);
		switch (subOptionManager) {
		case 1:
			listManagers(managers);
			break;

		case 2:
			insertManager(&managers, managers->idManager, managers->nameManager, managers->password);
			break;
		}

	case 3:
		show_mobility_menu();
	}
	


}
