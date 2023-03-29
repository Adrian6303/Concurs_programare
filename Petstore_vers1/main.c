#include "participant.h"
#include "MyList.h"
#include "concurs_service.h"

#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void testAll() {
	testCreateDestroy();
	testCreateList();
	testIterateList();
	testCopyList();
	testAddParticipant();
}
/*
  Read participants from standard input and add to programing competition
*/
void readParticipant(MyList* l) {
	printf("Nume:");
	char nume[30];
	scanf_s("%s", nume, 30);
	printf("Prenume:");
	char prenume[30];
	scanf_s("%s", prenume, 30);
	printf("Scor:");
	int scor;
	scanf_s("%d", &scor);
	int error = addParticipant(l, nume, prenume, scor);
	if (error != 0) {
		printf("Participant invalid.\n");
	}
	else {
		printf("Participant adaugat.\n");
	}
}

void printAllParticipants(MyList* l) {
	printf("Participanti:\n");
	printf("%15s %15s %5s \n", "Nume", "Prenume", "Scor");
	for (int i = 0; i < size(l); i++) {
		Participant p = get(l, i);
		printf("%15s %15s %5d\n", p.nume, p.prenume, p.scor);
	}
}
void filterParticipants(MyList* l) {
	printf("Scorul minim:");
	int scor_minim=0;
	scanf_s("%d", &scor_minim);
	
	MyList filteredL = filter_Participants(l, scor_minim);
	printAllParticipants(&filteredL);
}

void sortParticipantsByScore(MyList* l) {

	sortParticipant(l);
	printf("Lista a fost filtrata dupa cel mai mare scor!\n");
}
void editParticipants(MyList* l) {
	printf("Nume:");
	char nume[30];
	scanf_s("%s", nume, 30);
	printf("Prenume:");
	char prenume[30];
	scanf_s("%s", prenume, 30);
	printf("Scor:");
	int scor;
	scanf_s("%d", &scor);

	printf("Nume nou:");
	char nume_nou[30];
	scanf_s("%s", nume_nou, 30);
	printf("Prenume nou:");
	char prenume_nou[30];
	scanf_s("%s", prenume_nou, 30);
	printf("Scor nou:");
	int scor_nou;
	scanf_s("%d", &scor_nou);

	int error = editParticipant(l, nume, prenume, scor, nume_nou, prenume_nou, scor_nou);
	if (error != 0) {
		printf("Participant invalid.\n");
	}
	else {
		printf("Participant modificat.\n");
	}
}

void deleteParticipants(MyList* l) {
	printf("Nume:");
	char nume[30];
	scanf_s("%s", nume, 30);
	printf("Prenume:");
	char prenume[30];
	scanf_s("%s", prenume, 30);
	printf("Scor:");
	int scor;
	scanf_s("%d", &scor);
	int error = deleteParticipant(l, nume, prenume, scor);
	if (error != 0) {
		printf("Participant invalid.\n");
	}
	else {
		printf("Participant sters.\n");
	}
}

void run() {
	MyList allParticipants = createEmpty();
	int ruleaza = 1;
	while (ruleaza) {
		printf("1 Adauga\n2 Modifica\n3 Sterge\n4 Filtreaza\n5 Sorteaza\n6 All\n0 Exit\nCommand:");
		int cmd = 0;
		scanf_s("%d", &cmd);
		switch (cmd) {
		case 1:
			readParticipant(&allParticipants);
			break;
		case 2:
			editParticipants(&allParticipants);
			break;
		case 3:
			deleteParticipants(&allParticipants);
			break;
		case 4:
			filterParticipants(&allParticipants);
			break;
		case 5:
			sortParticipantsByScore(&allParticipants);
			break;
		case 6:
			printAllParticipants(&allParticipants);
			break;
		case 0:
			ruleaza = 0;		
			break;
		default:
			printf("Comanda invalida!!!\n");
		}
	}
}

int main() {	
	
	testAll();
	run();
	_CrtDumpMemoryLeaks();

	return 0;
}