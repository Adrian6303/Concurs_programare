#include "participant.h"

#include <string.h>
#include <assert.h>
/*
Create a new participant
*/
Participant createParticipant(char* nume, char* prenume, int scor) {
	Participant rez;
	strcpy_s(rez.nume,sizeof(rez.nume), nume);
	strcpy_s(rez.prenume,sizeof(rez.nume), prenume);
	rez.scor = scor;
	return rez;
}

/*
Dealocate memory occupied by a participant
*/
void destroyParticipant(Participant* p) {
	//no memory is allocated on the heap
	//nothing to dealocate
	//mark that participant is destroyed, avoid accidental use after destroy
	p->nume[0] = '\0';
	p->prenume[0] = '\0';
	p->scor = -1;
}

int valideaza(Participant p) {
	if (strlen(p.prenume) == 0) {
		return 1;
	}
	if (strlen(p.nume) == 0) {
		return 2;
	}
	if (p.scor < 0) {
		return 3;
	}
	return 0;
}

void testCreateDestroy() {
	Participant p = createParticipant("dog", "buldog", 100);
	assert(strcmp(p.nume, "dog") == 0);
	assert(strcmp(p.prenume, "buldog") == 0);
	assert(p.scor == 100.0);

	destroyParticipant(&p);
	assert(strlen(p.nume) == 0);
	assert(strlen(p.prenume) == 0);
	assert(p.scor==-1);
}