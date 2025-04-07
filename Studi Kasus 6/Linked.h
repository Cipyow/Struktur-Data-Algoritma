#ifndef LINKED_H
#define LINKED_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char infotype[50];
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address next;
} ElmtList;

typedef struct {
    address First;
} List;

boolean IsEmpty (List L);
void CreateList (List *L);
address Alokasi (infotype X);
void Dealokasi (address P);

void InsertFirst (List *L, infotype X);
void InsertLast (List *L, infotype X);
void DeleteFirst (List *L);
void DeleteLast (List *L);
void Delete (List *L, infotype X);
void DeleteAll (List *L);

void PrintList (List L);

#endif
