#include "Queue.h"

void PrintMenu()
{
    printf("\n=== SISTEM ANTRIAN BANK ===\n");
    printf("1. Ambil Antrian\n");
    printf("2. Proses Antrian\n");
    printf("3. Keluar\n");
    printf("Pilihan Anda: ");
}

int main()
{
    Queue Q;
    CreateQueue (&Q);
    int pilihan;
    int noAntrian = 0;

    do {
        PrintMenu();
        scanf("%d", &pilihan);

        switch (pilihan) {
        case 1: // Ambil Nomor Antrian
            noAntrian++;
            Enqueue(&Q, noAntrian);
            printf("\nNomor antrian anda: %d\n", noAntrian);
            printf("Antrian: ");
			PrintQueue (Q);
            break;

        case 2: // Memproses Antrian
            if (!IsEmpty(Q)) {
                printf("\nNomor antrian %d sedang diproses\n", Q.First->info);
                Dequeue(&Q);
                printf("Antrian: ");
				PrintQueue (Q);
            } else {
                printf("\nAntrian kosong!\n");
            }
            break;

        case 3: // Keluar
            printf("\nTerima kasih!\n");
            break;

        default:
            printf("\nPilihan tidak valid!\n");
        }
    } while (pilihan != 3);
    
    ClearQueue (&Q);
    PrintQueue (Q); // Memastikan Queue sudah clear

    return 0;
}
