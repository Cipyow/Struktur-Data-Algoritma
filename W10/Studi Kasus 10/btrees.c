#include "btrees.h"
#include <stdio.h>

void Create_tree(Isi_Tree X, int Jml_Node) {
        for (int i = 1; i <= jml_maks; i++) {
        X[i].info = '\0';
        X[i].kiri = 0;
        X[i].kanan = 0;
    }
    
        for (int i = 1; i <= Jml_Node; i++) {
        printf("Masukkan info node ke-%d : ", i);
        scanf(" %c", &X[i].info);
        
        if (i > 1) {
            printf("Masukkan parent untuk node %d: ", i);
            int parent;
            scanf("%d", &parent);
            
            printf("Masukkan posisi (1:kiri, 2:kanan): ");
            int pos;
            scanf("%d", &pos);
            
            if (pos == 1) {
                if (X[parent].kiri == 0) {
                    X[parent].kiri = i;
                } else {
                    printf("Posisi kiri sudah terisi!\n");
                    i--;
                }
            } else if (pos == 2) {
                if (X[parent].kanan == 0) {
                    X[parent].kanan = i;
                } else {
                    printf("Posisi kanan sudah terisi!\n");
                    i--;
                }
            }
        }
    }
}

boolean IsEmpty(Isi_Tree P) {
    return (P[1].info == '\0');
}

void PreOrder(Isi_Tree P, int root) {
    if (root != 0) {
        printf("%c ", P[root].info);
        PreOrder(P, P[root].kiri);
        PreOrder(P, P[root].kanan);
    }
}

void InOrder(Isi_Tree P, int root) {
    if (root != 0) {
        InOrder(P, P[root].kiri);
        printf("%c ", P[root].info);
        InOrder(P, P[root].kanan);
    }
}

void PostOrder(Isi_Tree P, int root) {
    if (root != 0) {
        PostOrder(P, P[root].kiri);
        PostOrder(P, P[root].kanan);
        printf("%c ", P[root].info);
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    if (IsEmpty(X)) {
        printf("Tree kosong!\n");
        return;
    }
    
    int maxLevel = Depth(X);
    for (int level = 0; level <= maxLevel; level++) {
        for (int i = 1; i <= Maks_node; i++) {
            if (X[i].info != '\0' && Level(X, X[i].info) == level) {
                printf("%c ", X[i].info);
            }
        }
    }
}

void PrintTree(Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Tree kosong!\n");
        return;
    }
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            printf("Node ke-%d: Info: %c, Kiri: %d, Kanan: %d\n", 
                   i, P[i].info, P[i].kiri, P[i].kanan);
        }
    }
}

boolean Search(Isi_Tree P, infotype X) {
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

int nbElmt(Isi_Tree P) {
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

int nbDaun(Isi_Tree P) {
    if (IsEmpty(P)) {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].kiri == 0 && P[i].kanan == 0) {
            count++;
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) return -1;
    
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int level = 0;
            int curr = i;
            
            // Traverse up until root
            while (curr != 1 && curr != 0) {
                level++;
                // Find parent
                for (int j = 1; j <= jml_maks; j++) {
                    if (P[j].kiri == curr || P[j].kanan == curr) {
                        curr = j;
                        break;
                    }
                }
            }
            return level;
        }
    }
    return -1;
}

int Depth(Isi_Tree P) {
    if (IsEmpty(P)) return -1;
    
    int maxDepth = -1;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            int level = Level(P, P[i].info);
            if (level > maxDepth) {
                maxDepth = level;
            }
        }
    }
    return maxDepth;
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

boolean Compare(Isi_Tree P, Isi_Tree Q) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != Q[i].info || 
            P[i].kiri != Q[i].kiri || 
            P[i].kanan != Q[i].kanan) {
            return false;
        }
    }
    return true;
}