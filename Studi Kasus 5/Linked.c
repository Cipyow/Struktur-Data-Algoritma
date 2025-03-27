#include "Linked.h"

boolean IsEmpty (List L) {
	return L.First == NULL;
}

void CreateList (List *L) {
	L->First = NULL;
}

address Alokasi (infotype X) {
	address P = (address)malloc(sizeof(ElmtList));
	if (P != NULL) {
		strcpy(P->info, X);
		P->next = NULL;
	}
	return P;
}

void Dealokasi (address P) {
	if (P != NULL) {
		free(P);
	}
}

void InsertFirst (List *L, infotype X) {
	address P = Alokasi(X);
	if (P != NULL) {
		P->next = L->First;
		L->First = P;		
	}
}

void InsertLast (List *L, infotype X) {
	address P = Alokasi(X);
	if (P == NULL) { 
		return;
	}
	if (L->First == NULL) {
		L->First = P;
	} else {
		address temp = L->First;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = P;
	}
}

void DeleteFirst (List *L) {
	if (L->First != NULL) {
		address temp = L->First;
		L->First = L->First->next;
		Dealokasi(temp);
	}
}

void DeleteLast (List *L) {
	if (L->First != NULL) {
		address temp = L->First, prev = NULL;
		while (temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}
		if (prev == NULL) {
			L->First = NULL;
		} else {
			prev->next = NULL;
		}
		Dealokasi(temp);
	}
}

void Delete (List *L, infotype X) {
	if (L->First != NULL) {
        address temp = L->First, prev = NULL;
        while (temp != NULL && strcmp(temp->info, X) != 0) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL) {
	        if (prev == NULL) {
	            L->First = temp->next;
	        } else {
	            prev->next = temp->next;
	        }
	        Dealokasi(temp);
		}
    }
}

void DeleteAll (List *L) {
	address temp;
	while (L->First != NULL) {
		temp = L->First;
		L->First = L->First->next;
		Dealokasi (temp);
	}
}

void PrintList (List L) {
	address P;
	if (L.First == NULL) {
		printf("List kosong!\n");
	} else {
		P = L.First;
		while (P != NULL) {
			printf("%s ", P->info);
			P = P->next;
		}
		printf("\n");
	}
}
