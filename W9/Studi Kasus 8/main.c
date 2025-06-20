#include <stdio.h>
#include <stdlib.h>

int main() {
	Isi_Tree X;
	int pilihan;
	char cari
	
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
	printf("12. Membandingkan nilai 2 node tree\n");
	printf("13. membandingkan 2 tree\n");
	printf("0. Exit\n");
	printf("Pilih menu: ");
	scanf("%d", &pilihan);
	
	do {
		switch (pilihan) {
			case 1:
				printf("\n\nMasukkan jumlah node yang ingin dibuat untuk tree ini: ");
				scanf("%d", jml_node);
				Create_tree(X, &jml_node);
				break;
			case 2:
				printf("Traversal Preorder: ");
				PreOrder(X);
				break;
			case 3:
				printf("\nTraversal Inorder: ");
				InOrder(X, 1);
				break;
			case 4:
				printf("\nTraversal Postorder: ");
				PostOrder(X);
				break;
			case 5:
				printf("\nLevel Order: ");
				Level_order(X, jml_maks);
				break;
			case 6:
				printf("\nDetail Isi Tree:\n");
				PrintTree(X);
				break;
			case 7:
				printf("Masukkan info dari node yang ingin dicari: ");
				scanf("%c", &cari);
				printf("Elemen %c", cari);
				Search(X, cari) ? "Ya" : "Tidak";
				break;
			case 8:
				printf("\n\nJumlah Elemen: %d", nbElmt(X));
				break;
			case 9:
				printf("\nJumlah Daun: %d", nbDaun(X));
				break;
			case 10:
				printf("Masukkan info dari node yang ingin dicari levelnya: ");
				scanf("%c", &cari);
				printf("\nLevel dari elemen '%c' adalah %d", cari, Level(X, cari));
				break;
			case 11:
				printf("\nKedalaman tree: %d", Depth(X));
				break;
			case 12:
				
		}
		
	}
	return 0;
}
