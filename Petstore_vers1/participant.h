#pragma once

typedef struct {
	char nume[30];
	char prenume[30];
	int scor;
} Participant;


/*
Create a new participant
*/
Participant createParticipant(char* nume, char* prenume, int scor);

/*
 Dealocate memory occupied by participant
*/
void destroyParticipant(Participant* p);

void testCreateDestroy();

int valideaza(Participant);

