#ifndef SK5_H
#define SK5_H

#include "Linked.h"

#define MAX_KOTA 5

typedef struct {
    char kota[50];
    List nama;
} DataKota;

DataKota daftarKota[MAX_KOTA];

void TambahKota(char* namaKota);
void TambahNama(char* namaKota, char* nama);
void HapusKota(char* namaKota);
void TampilkanData();
void TampilkanKota(char *namaKota);
void Statistik();

#endif
