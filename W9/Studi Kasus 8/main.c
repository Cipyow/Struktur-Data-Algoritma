#include <stdio.h>
#include <stdlib.h>
#include "nbtrees.h"

int main() {
	Isi_Tree X, Y;
	int pilihan, jml_node;
	char cari;
	
	do {
		printf("1. Create tree\n");
		printf("2. Traversal PreOrder\n");
		printf("3. Traversal InOrder\n");
		printf("4. Traversal PostOrder\n");
		printf("5. Traversal Level Order\n");
		printf("6. Print tree\n");
		printf("7. Search node tree\n");
		printf("8. Jumlah Elemen\n");
		printf("9. Jumlah Daun/Leaf\n");
		printf("10. Mencari level node tree\n");
		printf("11. Kedalaman tree\n");
		printf("12. Membandingkan 2 tree\n");
		printf("0. Exit\n");
		printf("Pilih menu: ");
		scanf("%d", &pilihan);
		getchar();
		
		switch (pilihan) {
			case 1:
				printf("\n\nMasukkan jumlah node yang ingin dibuat untuk tree ini: ");
				scanf("%d", &jml_node);
				getchar();
				Create_tree(X, jml_node);
				system("cls");
				break;
			case 2:
				printf("\nTraversal Preorder: ");
				PreOrder(X);
				getchar();
				system("cls");
				break;
			case 3:
				printf("\nTraversal Inorder: ");
				InOrder(X, 1);
				getchar();
				system("cls");
				break;
			case 4:
				printf("\nTraversal Postorder: ");
				PostOrder(X);
				getchar();
				system("cls");
				break;
			case 5:
				printf("\nLevel Order: ");
				Level_order(X, jml_maks);
				getchar();
				system("cls");
				break;
			case 6:
				printf("\nDetail Isi Tree:\n");
				PrintTree(X);
				getchar();
				system("cls");
				break;
			case 7:
				printf("\nMasukkan info dari node yang ingin dicari: ");
				scanf("%c", &cari);
				getchar();
				printf("Elemen %c", cari);
				if (Search(X, cari)) {
					printf(" ada dalam tree");
				}else{
					printf(" tidak ada ada dalam tree");
				}
				getchar();
				system("cls");
				break;
			case 8:
				printf("\nJumlah Elemen: %d", nbElmt(X));
				getchar();
				system("cls");
				break;
			case 9:
				printf("\nJumlah Daun: %d", nbDaun(X));
				getchar();
				system("cls");
				break;
			case 10:
				printf("\nMasukkan info dari node yang ingin dicari levelnya: ");
				scanf("%c", &cari);
				getchar();
				printf("Level dari elemen '%c' adalah %d", cari, Level(X, cari));
				getchar();
				system("cls");
				break;
			case 11:
				printf("\nKedalaman tree: %d", Depth(X));
				getchar();
				system("cls");
				break;
			case 12:
				printf("\nTolong buat tree ke-2 terlebih dahulu");
				printf("\nMasukkan jumlah node yang ingin dibuat untuk tree ke-2: ");
				scanf("%d", &jml_node);
				getchar();
				Create_tree(Y, jml_node);
				if(Compare(X, Y)) {
					printf("\nKedua tree sama.\n"); 
				} else {
					printf("\nKedua tree berbeda.\n");
				}
				getchar();
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
				break;
		}
	} while (pilihan != 0);
	return 0;
}
