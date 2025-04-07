#include "SK6.h"
#include "Linked.h"

int main() {
	InisialisasiDaftarKota();
	int pilihan;
	char namaKota[50], nama[50];
	
	do {
		printf("\n=== Menu ===\n");
    	printf("1. Tambah Kota\n");
    	printf("2. Tambah Nama\n");
    	printf("3. Hapus Kota\n");
    	printf("4. Tampilkan Semua Data\n");
    	printf("5. Tampilkan Data Kota\n");\
    	printf("6. Statistik\n");
    	printf("7. Keluar\n");
    	printf("Pilih menu: ");
    	scanf("%d", &pilihan);
    	getchar();
    	
		switch (pilihan) {
			case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
				namaKota[strcspn(namaKota, "\n")] = 0;
                TambahKota(namaKota);
                break;
            case 2:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
				namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama yang ingin ditambahkan: ");
                fgets(nama, sizeof(nama), stdin); 
				nama[strcspn(nama, "\n")] = 0; 
                TambahNama(namaKota, nama);
                break;
            case 3:
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(namaKota, sizeof(namaKota), stdin);
				namaKota[strcspn(namaKota, "\n")] = 0;
                HapusKota(namaKota);
                break;
            case 4:
                TampilkanData();
                break;
            case 5:
            	printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
            	TampilkanKota(namaKota);
            	break;
            case 6:
            	Statistik();
            	break;
            case 7:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
		}
	} while (pilihan != 7);
	BebaskanDaftarKota();
	return 0;
}
