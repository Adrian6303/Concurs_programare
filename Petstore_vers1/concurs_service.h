#pragma once

#include "MyList.h"
/*
Add a participant in list
*/
int addParticipant(MyList* l, char* nume, char* prenume, int scor);

int deleteParticipant(MyList* l, char* nume, char* prenume, int scor);

int editParticipant(MyList* l, char* nume, char* prenume, int scor, char* nume_nou, char* prenume_nou, int scor_nou);

int sortParticipant(MyList* l);




/*
  Filter participants in the competition 
  typeSubstring - cstring
  return all participants where typeSubstring is a substring of the type
*/

MyList getAllParticipants(MyList* l, char* typeSubstring);

MyList filter_Participants(MyList* l, int scor_min);

MyList filter_Participants_2(MyList* l, int scor_maxim);

void testAddParticipant();