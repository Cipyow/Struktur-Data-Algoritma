#include <stdio.h>
#include <stdlib.h>
#include "nbtrees.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Isi_Tree X, Y;
	
	X[1].info = 'A'; X[1].ps_fs = 2; X[1].ps_nb = 0; X[1].ps_pr = 0;
	X[2].info = 'B'; X[2].ps_fs = 4; X[2].ps_nb = 3; X[2].ps_pr = 1;
	X[3].info = 'C'; X[3].ps_fs = 6; X[3].ps_nb = 0; X[3].ps_pr = 1;
	X[4].info = 'D'; X[4].ps_fs = 0; X[4].ps_nb = 5; X[4].ps_pr = 2;
	X[5].info = 'E'; X[5].ps_fs = 9; X[5].ps_nb = 0; X[5].ps_pr = 2;
	X[6].info = 'F'; X[6].ps_fs = 0; X[6].ps_nb = 7; X[6].ps_pr = 3;
	X[7].info = 'G'; X[7].ps_fs = 0; X[7].ps_nb = 8; X[7].ps_pr = 3;
	X[8].info = 'H'; X[8].ps_fs = 0; X[8].ps_nb = 0; X[8].ps_pr = 3;
	X[9].info = 'I'; X[9].ps_fs = 0; X[9].ps_nb = 10; X[9].ps_pr = 5;
	X[10].info = 'J'; X[10].ps_fs = 0; X[10].ps_nb = 0; X[10].ps_pr = 5;
	X[11].info = '\0'; X[12].info = '\0'; X[13].info = '\0'; X[14].info = '\0';
	X[15].info = '\0'; X[16].info = '\0'; X[17].info = '\0'; X[18].info = '\0';
	X[19].info = '\0'; X[20].info = '\0';

	printf("Traversal Preorder: ");
	PreOrder(X);
	printf("\nTraversal Inorder: ");
	InOrder(X, 1);
	printf("\nTraversal Postorder: ");
	PostOrder(X);
	printf("\nLevel Order: ");
	Level_order(X, 10);

	printf("\n\nIsi Tree:\n");
	PrintTree(X);
	printf("\n\nJumlah Elemen: %d", nbElmt(X));
	printf("\nJumlah Daun: %d", nbDaun(X));
	
	printf("\n\nApakah ada elemen 'G'? %s", Search(X, 'G') ? "Ya" : "Tidak");
	printf("\nLevel dari elemen 'F'? %d", Level(X, 'F'));
	printf("\nKedalaman tree: %d", Depth(X));

	printf("\nLebih besar nilai '%c' atau '%c'? %c ", X[2].info, X[1].info, Max(X[2].info, X[1].info));
	return 0;
}
