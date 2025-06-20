#include "nbtrees.h"

void Create_tree(Isi_Tree X, int Jml_Node) {
    // Inisialisasi seluruh array dengan nilai kosong
    for (int i = 1; i <= jml_maks; i++) {
        X[i].info = '\0';  // Info kosong
        X[i].ps_fs = 0;    // Tidak ada first son
        X[i].ps_nb = 0;    // Tidak ada next brother
        X[i].ps_pr = 0;    // Tidak ada parent
    }
    
    // Input data hanya untuk node yang diperlukan
    for (int i = 1; i <= Jml_Node; i++) {
        printf("Masukkan info node ke-%d : ", i);
        scanf(" %c", &X[i].info);
        
        if (i == 1) {
            X[i].ps_pr = 0;  // Root tidak memiliki parent
        } else {
            printf("Masukkan parent dari node %d (indeks): ", i);
            scanf("%d", &X[i].ps_pr);
            
            int pr = X[i].ps_pr;
            if (X[pr].ps_fs == 0) {
                X[pr].ps_fs = i;  // Set sebagai first son
            } else {
                int fs = X[pr].ps_fs;
                while (X[fs].ps_nb != 0) {
                    fs = X[fs].ps_nb;  // Cari next brother terakhir
                }
                X[fs].ps_nb = i;  // Set sebagai next brother
            }
        }
    }
}

boolean IsEmpty (Isi_Tree P) {
	return (P[1].info == '\0');
}

void PreOrder (Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Tree kosong!\n");
        return;
    }
    
    static int curr = 1; 
    
    if (curr == 0) return;
    
    // Print current node
    printf("%c ", P[curr].info);
    
	// Mengunjungi first son
    int temp = curr;
    curr = P[curr].ps_fs;
    PreOrder(P);
    
	// Mengunjungi next brother
    curr = P[temp].ps_nb;
    PreOrder(P);
    
    // Reset curr untuk rekursi berikutnya
    if (temp == 1) curr = 1;
}
void InOrder(Isi_Tree P, int idx) {
    if (idx != 0) {
        if (P[idx].ps_fs != 0) {
            InOrder(P, P[idx].ps_fs);
        }
        printf("%c ", P[idx].info);

        if (P[idx].ps_fs != 0) {
            int temp = P[P[idx].ps_fs].ps_nb;
            while (temp != 0) {
                InOrder(P, temp);
                temp = P[temp].ps_nb;
            }
		}
	}
}

void PostOrder (Isi_Tree P) {
	if (IsEmpty(P)) {
		printf("Tree kosong!\n");
		return;
	}
	static int curr = 1;
	if (curr == 0) return;
	// Mengunjungi first son
	int temp = curr;
	curr = P[curr].ps_fs;
	PostOrder(P);

	// Mengunjungi next brother
	curr = P[temp].ps_nb;
	PostOrder(P);

	// Print current node
	printf("%c ", P[temp].info);
	curr = P[temp].ps_pr;

	if (temp == 1) curr = 1; 
}


void Level_order(Isi_Tree X, int Maks_node) {
	if (IsEmpty(X)) {
		printf("Tree kosong!\n");
		return;
	}
	int i;
	for (i = 1; i <= Maks_node; i++) {
		printf("%c ", X[i].info);
	}
}


void PrintTree(Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Tree kosong!\n");
        return;
    }
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {  // Hanya print node yang memiliki info valid
            printf("Node ke-%d: Info: %c, First Son: %d, Next Brother: %d, Parent: %d\n", 
                   i, P[i].info, P[i].ps_fs, P[i].ps_nb, P[i].ps_pr);
        }
    }
}

boolean Search (Isi_Tree P, infotype X) {
	if (IsEmpty(P)) {
		return false;
	}
	
	int i;
	for (i = 1; i <= jml_maks; i++) {
		if (P[i].info == X) {
			return true;
		}
	}
	
	return false;
}

int nbElmt (Isi_Tree P) {
	int count = 0;
	if (IsEmpty(P)) {
		return count;
	}
	
	int i;
	for (i = 1; i <= jml_maks; i++) {
		if (P[i].info != '\0') {
			count++;
		}
	}
	return count;
}

int nbDaun (Isi_Tree P) {
	int count = 0;
	if (IsEmpty(P)) {
		return count;
	}
	
	int i;
	for (i = 1; i <= jml_maks; i++) {
		if (P[i].info != '\0' && P[i].ps_fs == 0) { // Node daun tidak memiliki first son
			count++;
		}
	}
	return count;
}

int Level(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) {
        return -1;
    }
    
    // Cari node dengan info X dan hitung levelnya
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int level = 0;
            int curr = i;
            // Naik ke atas sampai root untuk menghitung level
            while (P[curr].ps_pr != 0) {
                level++;
                curr = P[curr].ps_pr;
            }
            return level;
        }
    }
    return -1; // Node tidak ditemukan
}

int Depth(Isi_Tree P) {
    if (IsEmpty(P)) {
        return -1;
    }
    
    int depth = -1;
    // Periksa setiap node
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            int level = 0;
            int curr = i;
            // Hitung level node ini
            while (P[curr].ps_pr != 0) {
                level++;
                curr = P[curr].ps_pr;
            }
            // Update depth jika level lebih dalam
            if (level > depth) {
                depth = level;
            }
        }
    }
    return depth;
}

int Max (infotype Data1, infotype Data2) {
	return (Data1 > Data2) ? Data1 : Data2;
}

