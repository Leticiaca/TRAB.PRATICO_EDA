#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Costumer.h"
#include "Manager.h"
#include "Mobility.h"
//#include "Menu.h"


int main() {
	setlocale(LC_ALL, "");

	Costumer* costumers = loadCostumers();
	Manager* managers = loadManagers();
	Mobility* mobilitys = loadMobility();

	int option;
	int subOptionCostumer;
	int subOptionManager;

	showMenu();
	scanf("%d", &option);
	switch (option) {
	case 1: // Client Menu
		do {
			showsubMenu("Costumer");
			scanf("%d", &subOptionCostumer);
			switch (subOptionCostumer) {
			case 1:
				listCostumers(costumers);
				break;

			case 2:
				insertCostumer(&costumers);
				saveCostumers(costumers);
				break;

			case 3:
				removeCostumers(&costumers);
				saveCostumers(costumers);
				break;

			case 4:
				changeCostumers(costumers);
				saveCostumers(costumers);
				break;

			case 0:
				break;
			default:
				showMessage("Option invalid!");
				break;
			}
		} while (subOptionCostumer != 0);
		break;

	case 2:
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
