#pragma once

typedef struct mobility{
	int idMobility;
	char tipo[20];
	float batery_level;
	float autonomy;
	int rentMobility;
	struct mobility* next;
}Mobility;

void listMobility(Mobility* mobility) {
	Mobility* insertMobility(Mobility * mobilidade, int idMobilidade, char tipo[], float batery_level, float autonomy, int rentMobility);
}
