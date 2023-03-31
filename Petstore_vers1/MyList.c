#include "MyList.h"

#include <assert.h>
#include <string.h>

/*
Create an empty list
*/
MyList createEmpty() {
	MyList rez;
	rez.lg = 0;
	return rez;
}

UndoList createUndoEmpty()
{
	UndoList undo;
	///undo.lst = malloc(sizeof(MyList) * 100);
	undo.lg = 0;
	return undo;
}

void addUndoList(MyList l, UndoList* undo)
{
	undo->lst[undo->lg] = l;
	undo->lg++;
}

MyList undoStep(UndoList* undo)
{
	if (undo->lg >= 0) 
		undo->lg--;
		

	return undo->lst[undo->lg];
	
}
/*
Destroy list
*/
void destroy(MyList* l) {
	//nothing to dealocate for now
	l->lg = 0;
}

/*
Get an element from the list
poz - position of the element, need to be valid
return element on the given position
*/
ElemType get(MyList* l, int poz) {
	return l->elems[poz];
}

/*
return number of elements in the list
*/
int size(MyList* l) {
	return l->lg;
}

/*
Add element into the list
post: element is added to the end of the list
*/
void add(MyList* l, ElemType el) {
	l->elems[l->lg] = el;
	l->lg++;
}

void edit(MyList* l, ElemType el, ElemType el_nou) {
	
	int poz = find(l, el);
	if (poz != -1) {
		l->elems[poz] = el_nou;
	}
	

}
void delete(MyList* l, ElemType el) {

	int poz = find(l, el);
	if (poz != -1) {

		while (poz < l->lg - 1) {
			l->elems[poz] = l->elems[poz + 1];
			poz++;
		}
		l->lg--;
	}
}
int find(MyList* l, ElemType el) {

	for (int i = 0;i < size(l);i++) {
		ElemType p = get(l, i);
		if (strcmp(p.nume, el.nume)==0  && strcmp(p.prenume, el.prenume)==0){
			return i;
		}
			
	}
	return -1;

}

void swap(MyList* l, int poz1, int poz2) {
	ElemType p1 = get(l, poz1);
	ElemType p2 = get(l, poz2);
	l->elems[poz1] = p2;
	l->elems[poz2] = p1;
}


/*
Make a shallow copy of the list
return Mylist containing the same elements as l
*/
MyList copyList(MyList* l) {
	MyList rez = createEmpty();
	for (int i = 0; i < size(l); i++) {
		ElemType p = get(l, i);		
		add(&rez, p);
	}
	return rez;
}

void testCreateList() {
	MyList l = createEmpty();
	assert(size(&l) == 0);
}
void testIterateList() {
	MyList l = createEmpty();
	add(&l, createParticipant("a", "b", 10));
	add(&l, createParticipant("a2", "b2", 20));
	assert(size(&l) == 2);
	Participant p = get(&l,0);

	assert(strcmp(p.nume,"a") == 0);
	p = get(&l, 1);
	assert(strcmp(p.prenume, "b2") == 0);
	destroy(&l);
	assert(size(&l) == 0);
}

void testCopyList() {
	MyList l = createEmpty();
	add(&l, createParticipant("a", "b", 10));
	add(&l, createParticipant("a2", "b2", 20));
	MyList l2 = copyList(&l);
	assert(size(&l2) == 2);
	Participant p = get(&l2, 0);
	assert(strcmp(p.nume, "a") == 0);
}
