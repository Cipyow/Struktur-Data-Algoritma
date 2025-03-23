#include "Queue.h"
#include "Stack.h"

#define JUMLAH_TELLER 5

void PrintMenu()
{
    printf("\n=== SISTEM ANTRIAN BANK ===\n");
    printf("1. Ambil Antrian\n");
    printf("2. Proses Antrian\n");
    printf("3. Lihat Riwayat Transaksi\n");
    printf("4. Lihat Status Teller\n");
    printf("5. Keluar\n");
    printf("Pilihan Anda: ");
}

void PrintStatusTeller(Queue teller[], Stack *riwayat)
{
    printf("\n=== Status Teller ===\n");
    for(int i = 0; i < JUMLAH_TELLER; i++) {
        printf("Teller %d: ", i+1);
        if(IsEmpty(teller[i])) {
            printf("Kosong\n");
        } else {
            PrintQueue(teller[i]);
        }
    }
}

int main()
{
    Queue teller[JUMLAH_TELLER];  // Array Queue untuk setiap teller
    Stack riwayat;                // Stack untuk menyimpan semua riwayat
    int pilihan;
    int noAntrian = 0;
    int tellerDipilih;

    // Inisialisasi semua teller
    for(int i = 0; i < JUMLAH_TELLER; i++) {
        CreateQueue(&teller[i]);
    }
    CreateStack(&riwayat);

    do {
        PrintMenu();
        scanf("%d", &pilihan);

        switch (pilihan) {
        case 1: // Ambil Nomor Antrian
            noAntrian++;
            // Cari teller dengan antrian terpendek
            int tellerTerpendek = 0;
            int jumlahAntrianMin = 999;
            
            for(int i = 0; i < JUMLAH_TELLER; i++) {
                int jumlahAntrian = 0;
                address P = teller[i].First;
                while(P != NULL) {
                    jumlahAntrian++;
                    P = P->next;
                }
                if(jumlahAntrian < jumlahAntrianMin) {
                    jumlahAntrianMin = jumlahAntrian;
                    tellerTerpendek = i;
                }
            }
            
            Enqueue(&teller[tellerTerpendek], noAntrian);
            printf("\nNomor antrian anda: %d\n", noAntrian);
            printf("Silahkan menuju Teller %d\n", tellerTerpendek + 1);
            printf("Antrian di Teller %d: ", tellerTerpendek + 1);
            PrintQueue(teller[tellerTerpendek]);
            break;

        case 2: // Memproses Antrian
            printf("\nPilih Teller (1-%d): ", JUMLAH_TELLER);
            scanf("%d", &tellerDipilih);
            tellerDipilih--; // Konversi ke index 0-based
            
            if(tellerDipilih >= 0 && tellerDipilih < JUMLAH_TELLER) {
                if (!IsEmpty(teller[tellerDipilih])) {
                    int nomorDiproses = teller[tellerDipilih].First->info;
                    printf("\nTeller %d memproses nomor antrian %d\n", 
                           tellerDipilih + 1, nomorDiproses);
                    Dequeue(&teller[tellerDipilih]);
                    Push(&riwayat, nomorDiproses);
                    printf("Antrian di Teller %d: ", tellerDipilih + 1);
                    PrintQueue(teller[tellerDipilih]);
                } else {
                    printf("\nAntrian di Teller %d kosong!\n", tellerDipilih + 1);
                }
            } else {
                printf("\nNomor teller tidak valid!\n");
            }
            break;

        case 3: // Lihat Riwayat Transaksi
            if (!IsEmpty(riwayat)) {
                printf("\n=== Riwayat Transaksi Terakhir ===\n");
                PrintStack(riwayat);
            } else {
                printf("\nBelum ada riwayat transaksi!\n");
            }
            break;

        case 4: // Lihat Status Teller
            PrintStatusTeller(teller, &riwayat);
            break;

        case 5: // Keluar
            printf("\nTerima kasih!\n");
            break;

        default:
            printf("\nPilihan tidak valid!\n");
        }
    } while (pilihan != 5);
    
    // Pembersihan memori
    for(int i = 0; i < JUMLAH_TELLER; i++) {
        ClearQueue(&teller[i]);
    }
    ClearStack(&riwayat);

    return 0;
}
