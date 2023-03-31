#include "concurs_service.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>
/*
Add a paricipant to the copetition
*/
int addParticipant(MyList* l, char* nume, char* prenume, int scor) {
	Participant p = createParticipant(nume, prenume, scor);
	int succ = valideaza(p);
	if (succ != 0) return succ;

	add(l, p);	
	return 0; // all ok
}
int deleteParticipant(MyList* l, char* nume, char* prenume, int scor) {
	Participant p = createParticipant(nume, prenume, scor);
	int succ = valideaza(p);
	if (succ != 0) return succ;

	delete(l, p);
	return 0; // all ok
}

int editParticipant(MyList* l, char* nume, char* prenume, int scor, char* nume_nou, char* prenume_nou, int scor_nou) {
	Participant p = createParticipant(nume, prenume, scor);
	Participant p_nou = createParticipant(nume_nou, prenume_nou, scor_nou);
	int succ = valideaza(p_nou);
	if (succ != 0) return succ;

	edit(l, p, p_nou);
	return 0; // all ok
}


int sortParticipant(MyList* l) {
	int n = size(l);
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			Participant p1 = get(l, j);
			Participant p2 = get(l, j + 1);
			if (p1.scor < p2.scor) {
				swap(l, j, j + 1);
			}
		}
	}
	return 0; // all ok

}
/*
Filter participants in the list
typeSubstring - cstring
return all participants where typeSubstring is a substring of the type
*/

MyList filter_Participants(MyList* l, int scor_min) {
	
	MyList rez = createEmpty();
	for (int i = 0; i < size(l); i++) {
		Participant p = get(l, i);
		if (p.scor >= scor_min) {
			add(&rez, p);
		}
	}
	return rez;
}

MyList getAllParticipants(MyList* l, char* typeSubstring) {
	if (typeSubstring == NULL || strlen(typeSubstring) == 0) {
		return copyList(l);
	}
}

MyList filter_Participants_2(MyList* l, int scor_maxim) {

	MyList rez = createEmpty();
	for (int i = 0; i < size(l); i++) {
		Participant p = get(l, i);
		if (p.scor <= scor_maxim) {
			add(&rez, p);
		}
	}
	return rez;
}




void testAddParticipant() {
	MyList l = createEmpty();
	//try to add invalid participants
	int error = addParticipant(&l, "", "b", 10);
	assert(error != 0);
	assert(size(&l) == 0);

	error = addParticipant(&l, "a", "", 10);
	assert(error != 0);
	assert(size(&l) == 0);

	error = addParticipant(&l, "a", "b", -10);
	assert(error != 0);
	assert(size(&l) == 0);

	//try to add some valid participants
	addParticipant(&l, "a", "b", 10);
	addParticipant(&l, "a2", "b2", 20);
	MyList filtered = getAllParticipants(&l, NULL);
	assert(size(&filtered) == 2);

	filtered = getAllParticipants(&l, "a2");
	assert(size(&filtered) == 1);

	filtered = getAllParticipants(&l, "2");
	assert(size(&filtered) == 1);

	filtered = getAllParticipants(&l, "a");
	assert(size(&filtered) == 2);

	filtered = filter_Participants(&l, 10);
	assert(size(&filtered) == 2);

	filtered = filter_Participants(&l, 20);
	assert(size(&filtered) == 1);

	filtered = filter_Participants(&l, 30);
	assert(size(&filtered) == 0);
}