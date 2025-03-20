#include <stdlib.h>
#include <stdio.h>
#include "Linked.h">

#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

void CreateList(List *L) {
    L->First = Nil;
}

address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        info(P) = X;
        next(P) = Nil;
    }
    return P;
}

void InsertFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        next(P) = L->First;
        L->First = P;
    }
}

void InsertLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (L->First == Nil) {
            L->First = P;
        } else {
            address temp = L->First;
            while (next(temp) != Nil) {
                temp = next(temp);
            }
            next(temp) = P;
        }
    }
}

void InsertAfter(List *L, infotype X, infotype Y) {
    address temp = L->First;
    
	while (temp != NULL && temp->info != Y){
		temp = temp->next;
	}
	
	if (temp != Nil){
	    address P = Alokasi(X);
	    if (P != Nil) {
	        next(P) = next(temp);
	        next(temp) = P;
	    }
	}
}

void DeleteFirst(List *L) {
    if (L->First != Nil) {
        address temp = L->First;
        L->First = next(L->First);
        free(temp);
    }
}

void DeleteLast(List *L) {
    if (L->First != Nil) {
        address temp = L->First, prev = Nil;
        while (next(temp) != Nil) {
            prev = temp;
            temp = next(temp);
        }
        if (prev == Nil) {
            L->First = Nil;
        } else {
            next(prev) = Nil;
        }
        free(temp);
    }
}

void Delete(List *L, infotype X) {
    address temp = L->First, prev = Nil;
    while (temp != NULL && temp->info != X){
		prev = temp;
        temp = next(temp);
	}
    
    if (temp != Nil){
	    if (prev != Nil) {
	        next(prev) = next(temp);
	    } else {
	    	L->First = next(temp);
		}
	    free(temp);
	}
}

void DealokasiList(List *L) {
    address temp;
    while (L->First != Nil) {
        temp = L->First;
        L->First = next(L->First);
        free(temp);
    }
}

void PrintList(List L) {
    address P = L.First;
    printf("Biner: {");
    while (P != Nil) {
        printf("%d", P->info);
        if (next(P) != Nil){
        	printf(", ");
		}
        P = next(P);
    }
    printf("}\n");
}
