#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nama[50];
	int nilai;
} Mahasiswa;

typedef struct ElmtList *address;
typedef struct ElmtList{
	Mahasiswa info;
	address next;
} ElmtList;

typedef struct{
	address First;
} List;

void CreateList(List *L);

void Dealokasi(address P);
void DeleteList(List *L);

int isEmpty(List L);
int isExist(List L, char* nama);

address Alokasi(char* nama, int nilai);
address Search(List L, char* nama);
void InsertAscending(List *L, char* nama, int nilai);
void DeleteByNama(List *L, char* nama);

void PrintList(List L);
void PrintListNilaiDesc(List L);

int CountElement(List L);
void CopyNilai(List L1, List *L2, int nilai);
void HapusSama(List *L);

#endif
