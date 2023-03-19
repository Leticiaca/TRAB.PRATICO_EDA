#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include"Mobility.h"
#include"Costumer.h"
#include"Manager.h"

struct Menu* next;
void show_menu();
void show_costumer_menu();
void show_manager_menu();
void show_mobility_menu();


Costumer* newCostumer(Costumer* costumer);
Costumer* removeCostumer(Costumer* costumer);
//Costumer* listCostumer(Costumer* listCostumer);
//void listCostumer(Costumer* listCostumers);
#pragma region Manager
#pragma region Mobility



