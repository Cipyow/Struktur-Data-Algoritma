#ifndef LINKED_H
#define LINKED_H

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;
    address next;
} ElmtList;

typedef struct {
    address First;
} List;

void CreateList(List *L);
address Alokasi(infotype X);
void InsertFirst(List *L, infotype X);
void InsertLast(List *L, infotype X);
void InsertAfter(List *L, infotype X, infotype Y);
void DeleteFirst(List *L);
void DeleteLast(List *L);
void Delete(List *L, infotype X);
void DealokasiList(List *L);
void PrintList(List L);
int SummingValue(List L);

#endif
