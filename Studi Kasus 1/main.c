#include "Mahasiswa.h"

int main() {
	List L1, L2;
	
	// No 2
	CreateList(&L1);
	CreateList(&L2);
	
	// No 3
	printf("Isi List L1 (Ascending Nama)\n");
	InsertAscending(&L1, "Citra", 85);
	InsertAscending(&L1, "Doni", 90);
	InsertAscending(&L1, "Asep", 80);
	InsertAscending(&L1, "Berlian", 65);
	InsertAscending(&L1, "Doni", 75);
	
	// No 4
	PrintList(L1);
	
	// No 5
	printf("\nIsi List L1 (Descending Nilai)\n");
	PrintListNilaiDesc(L1);
	
	// No 6
	printf("\nJumlah Mahasiswa: %d\n", CountElement(L1));
	
	// No 7
	CopyNilai(L1, &L2, 70);
	
	// No 8
	printf("\nIsi List L2 (Setelah Menyalin L1 Dengan nilai > 70)\n");
	PrintList(L2);
	
	// No 9
	HapusSama(&L2);
	
	// No 10
	printf("\nIsi List L2 (Setelah Menghapus Duplikat)\n");
	PrintList(L2);
	
	// No 11
	DeleteList(&L1);
	DeleteList(&L2);
	PrintList(L1);
	PrintList(L2);
	
	return 0;
}
