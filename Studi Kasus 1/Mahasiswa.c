#include "Mahasiswa.h"

/* Creator/Costructor */
void CreateList(List *L) {
	L->First = NULL;
}

/* Destructor */
void Dealokasi(address P) {
	free(P);
}

void DeleteList(List *L) {
	address P;
	while (!isEmpty(*L)) {
		P = L->First;
		L->First = L->First->next;
		Dealokasi(P);
	}
}

/* Validator */
int isEmpty(List L) {
	return(L.First == NULL);
}

int isExist(List L, char* nama) {
    return (Search(L, nama) != NULL);
}

/* Get/Set */
address Alokasi(char* nama, int nilai){
	address P = (address)malloc(sizeof(ElmtList));
	if (P != NULL) {
		strcpy(P->info.nama, nama);
		P->info.nilai = nilai;
		P->next = NULL;
	}
}

address Search(List L, char* nama) {
    address P = L.First;
    while (P != NULL) {
        if (strcmp(P->info.nama, nama) == 0) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void InsertAscending(List *L, char* nama, int nilai) {
    address P = Alokasi(nama, nilai);
    if (P != NULL) {
        if (isEmpty(*L) || strcmp(nama, L->First->info.nama) < 0) {
            P->next = L->First;
            L->First = P;
        } else {
            address temp = L->First;
            while (temp->next != NULL && strcmp(nama, temp->next->info.nama) > 0) {
                temp = temp->next;
            }
            P->next = temp->next;
            temp->next = P;
        }
    }
}

void DeleteByNama(List *L, char* nama) {
    if (!isEmpty(*L)) {
        address P = L->First;
        address Q = NULL;

        if (strcmp(P->info.nama, nama) == 0) {
            L->First = P->next;
            Dealokasi(P);
        } else {
            while (P != NULL && strcmp(P->info.nama, nama) != 0) {
                Q = P;
                P = P->next;
            }
            if (P != NULL) {
                Q->next = P->next;
                Dealokasi(P);
            }
        }
    }
}

/* PrintObject */
void PrintList(List L) {
    address P = L.First;
    
    if(P == NULL) {
    	printf("\nList L1 dan L2 telah dihapus\n");
	}
	
    while (P != NULL) {
        printf("Nama: %s, Nilai UTS: %d\n", P->info.nama, P->info.nilai);
        P = P->next;
    }
}

void PrintListNilaiDesc(List L) {
    // Membuat array sementara untuk sorting
    int count = CountElement(L);
    Mahasiswa *temp = (Mahasiswa*)malloc(count * sizeof(Mahasiswa));
    
    // Copy data ke array
    address P = L.First;
    int i = 0;
    while (P != NULL) {
        temp[i] = P->info;
        P = P->next;
        i++;
    }
    
    // Bubble sort berdasarkan nilai (descending)
    for (i = 0; i < count-1; i++) {
        for (int j = 0; j < count-i-1; j++) {
            if (temp[j].nilai < temp[j+1].nilai) {
                Mahasiswa t = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = t;
            }
        }
    }
    
    // Print hasil sorting
    for (i = 0; i < count; i++) {
        printf("Nama: %s, Nilai UTS: %d\n", temp[i].nama, temp[i].nilai);
    }
    
    free(temp);
}

/* Modul Tambahan */
int CountElement(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void CopyNilai(List L1, List *L2, int nilai) {
    address P = L1.First;
    while (P != NULL) {
        if (P->info.nilai > nilai) {
            InsertAscending(L2, P->info.nama, P->info.nilai);
        }
        P = P->next;
    }
}

void HapusSama(List *L) {
    address temp = L->First;
    while (temp != NULL) {
        address runner = temp;
        while (runner->next != NULL) {
            if (strcmp(temp->info.nama, runner->next->info.nama) == 0) {
                address temp = runner->next;
                runner->next = runner->next->next;
                Dealokasi(temp);
            } else {
                runner = runner->next;
            }
        }
        temp = temp->next;
    }
}
