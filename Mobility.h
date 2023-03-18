#pragma once

typedef struct Mobility{
	int idMobility;
	char tipo[20];
	float batery_level;
	float autonomy;
	int rentMobility;
	struct Mobility* next;
}Mobility;

void listMobility(Mobility* mobility);
int existMobility(Mobility mobility, int idMobility);
Mobility* insertMobility(Mobility* mobility, int idMobility, char tipo[], float batery_level, float autonomy);
Mobility* removeMobility(Mobility* mobility, int idMobility);
Mobility* changeMobility(Mobility mobility, int idMobilitiy, char tipo[], float batery_level, float autonomy);
