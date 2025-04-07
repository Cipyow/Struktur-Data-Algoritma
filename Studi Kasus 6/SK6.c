#include "SK6.h"

void InisialisasiDaftarKota() {
    daftarKota = NULL;
}

void BebaskanDaftarKota() {
    addressKota temp;
    while (daftarKota != NULL) {
        temp = daftarKota;
        daftarKota = daftarKota->next;
        DeleteAll(&temp->info.nama);
        free(temp);
    }
}

void TambahKota(char* namaKota) {
    addressKota P = (addressKota)malloc(sizeof(ElmtKota));
    if (P != NULL) {
        strcpy(P->info.kota, namaKota);
        CreateList(&P->info.nama);
        P->next = daftarKota;
        daftarKota = P;
    } else {
        printf("Gagal menambah kota, memori tidak cukup!\n");
    }
}

void TambahNama(char* namaKota, char* nama) {
    addressKota temp = daftarKota;
    while (temp != NULL) {
        if (strcmp(temp->info.kota, namaKota) == 0) {
            InsertLast(&temp->info.nama, nama);
            return;
        }
        temp = temp->next;
    }
    printf("Kota tidak ditemukan!\n");
}

void HapusKota(char* namaKota) {
    addressKota temp = daftarKota, prev = NULL;
    while (temp != NULL && strcmp(temp->info.kota, namaKota) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL) {
            daftarKota = temp->next;
        } else {
            prev->next = temp->next;
        }
        DeleteAll(&temp->info.nama);
        free(temp);
    } else {
        printf("Kota tidak ditemukan!\n");
    }
}

void TampilkanData() {
    if (daftarKota == NULL) {
        printf("Tidak ada data!\n");
    }
    addressKota temp = daftarKota;
    while (temp != NULL) {
        printf("Kota: %s\n", temp->info.kota);
        PrintList(temp->info.nama);
        temp = temp->next;
    }
}

void TampilkanKota(char *namaKota) {
    addressKota temp = daftarKota;
    while (temp != NULL) {
        if (strcmp(temp->info.kota, namaKota) == 0) {
            printf("Kota %s: ", temp->info.kota);
            PrintList(temp->info.nama);
            printf("\n");
            return;
        }
        temp = temp->next;
    }
    printf("Kota tidak ditemukan!\n");
}

void Statistik() {
    int jumlahKota = 0;
    addressKota temp = daftarKota;
    while (temp != NULL) {
        jumlahKota++;
        temp = temp->next;
    }
    printf("Jumlah Kota: %d\n", jumlahKota);
}
