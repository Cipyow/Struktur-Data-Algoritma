#ifndef SK6_H
#define SK6_H

#include "Linked.h"

typedef struct {
    char kota[50];
    List nama;
} DataKota;

typedef struct tElmtKota *addressKota;
typedef struct tElmtKota {
    DataKota info;
    addressKota next;
} ElmtKota;

addressKota daftarKota;

void InisialisasiDaftarKota();
void BebaskanDaftarKota();
void TambahKota(char* namaKota);
void TambahNama(char* namaKota, char* nama);
void HapusKota(char* namaKota);
void TampilkanData();
void TampilkanKota(char *namaKota);
void Statistik();

#endif
