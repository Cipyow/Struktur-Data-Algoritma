#include <stdio.h>
#include <string.h>
#include "morse.h"
#include "boolean.h"
#include "btrees.h"

int main() {
    Node* root = createNode(' ');
    buildMorseTree(root);

    int pilihan;
    char text[256];
    char morse[1024];
    char inFile[256], outFile[256];

    do {
        printf("Program Konversi Kode Morse\n");
        printf("1. Konversi teks ke morse\n");
        printf("2. Konversi morse ke teks\n");
        printf("3. Konversi file ke morse\n");
        printf("4. Lihat tabel kode morse\n");
        printf("5. Lihat traversal inorder\n");
        printf("0. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar();

        switch(pilihan) {
            case 1:
                printf("Masukkan teks untuk dikonversi: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0;
                printf("Kode morse: ");
                encode(text);
                getchar();
				system("cls");
                break;
            case 2:
                printf("Masukkan kode morse (pisahkan dengan spasi): ");
                fgets(morse, sizeof(morse), stdin);
                morse[strcspn(morse, "\n")] = 0;
                printf("Terjemahan kode: ");
                decode(root, morse);
                getchar();
				system("cls");
                break;
            case 3:
                printf("Mengkonversi file input.txt ke output.txt...\n");
                encodeFile(root, "input.txt", "output.txt");
                printf("\nTekan Enter untuk kembali ke menu utama...");
                getchar();
                system("cls");
                break;
            case 4:
                system("cls");
                printf("\nTABEL KODE MORSE\n");
                printf("================\n");
                for (int i = 0; i < MORSE_TABLE_SIZE; i++) {
                    printf("%c : %s\n", MORSE_TABLE[i].letter, MORSE_TABLE[i].code);
                }
                printf("\nTekan Enter untuk kembali ke menu utama...");
                getchar();
                system("cls");
                break;
            case 5:
            	printf("\nTraversal Inorder: ");
				inorder(root);
				getchar();
				system("cls");
				break;
            case 0:
                system("cls");
				printf("Anda telah keluar dari program.\n");
                break;
            
            default:
                printf("\nPilihan menu tidak valid! Silahkan coba lagi. ");
				getchar();
				system("cls");
        }
    } while (pilihan != 0);

    return 0;
}
