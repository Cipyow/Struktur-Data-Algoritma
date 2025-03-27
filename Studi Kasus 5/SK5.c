#include "SK5.h"

int jumlahKota = 0;

void TambahKota(char* namaKota) {
    if (jumlahKota < 5) {
        strcpy(daftarKota[jumlahKota].kota, namaKota);
        CreateList(&daftarKota[jumlahKota].nama);
        jumlahKota++;
    } else {
        printf("Jumlah kota sudah mencapai batas!\n");
    }
}

void TambahNama(char* namaKota, char* nama) {
    for (int i = 0; i < jumlahKota; i++) {
        if (strcmp(daftarKota[i].kota, namaKota) == 0) {
            InsertLast(&daftarKota[i].nama, nama);
            return;
        }
    }
    printf("Kota tidak ditemukan!\n");
}

void HapusKota(char* namaKota) {
    for (int i = 0; i < jumlahKota; i++) {
        if (strcmp(daftarKota[i].kota, namaKota) == 0) {
            DeleteAll(&daftarKota[i].nama);
            for (int j = i; j < jumlahKota - 1; j++) {
                daftarKota[j] = daftarKota[j + 1];
            }
            jumlahKota--;
            return;
        }
    }
    printf("Kota tidak ditemukan!\n");
}

void TampilkanData() {
	if (jumlahKota == 0) {
		printf("Tidak ada data!\n");
	}
    for (int i = 0; i < jumlahKota; i++) {
        printf("Kota: %s\n", daftarKota[i].kota);
        PrintList(daftarKota[i].nama);
    }
}

void TampilkanKota(char *namaKota) {
	for (int i = 0; i < jumlahKota; i++) {
        if (strcmp(daftarKota[i].kota, namaKota) == 0) {
            printf("Kota %s: ", daftarKota[i].kota);
            PrintList(daftarKota[i].nama);
            printf("\n");
            return;
        }
    }
    printf("Kota tidak ditemukan!\n");
}

void Statistik() {
	printf("Jumlah Kota: %d\n", jumlahKota);
}
