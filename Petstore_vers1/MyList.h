#pragma once
#include "participant.h"
typedef Participant ElemType;
typedef struct {
	ElemType elems[50];
	int lg;
} MyList;

typedef struct {
	MyList lst[50];
	int lg;
} UndoList;

/*
  Create an empty list
*/
MyList createEmpty();

UndoList createUndoEmpty();

void addUndoList(MyList l, UndoList* undo);

MyList undoStep(UndoList* undo);

/*
  Destroy list
*/
void destroy(MyList* l);

/*
  Get an element from the list
  poz - position of the element, need to be valid
  return element on the given position
*/
ElemType get(MyList* l, int poz);

/*
  return number of elements in the list
*/
int size(MyList* l);

/*
  Add element into the list
  post: element is added to the end of the list
*/
void add(MyList* l, ElemType el);

/*
  Make a shallow copy of the list
  return Mylist containing the same elements as l
*/

void edit(MyList* l, ElemType el, ElemType el_nou);

void delete(MyList* l, ElemType el);

int find(MyList* l, ElemType el);

void swap(MyList* l, int poz1, int poz2);

MyList copyList(MyList* l);

void testCreateList();
void testIterateList();
void testCopyList();