#include <stdio.h>
#include "graf.h"

int main() {
    /* KAMUS LOKAL */
    Graf g;

    /* ALGORITMA */
    createGraph(&g);
    if (isGraphEmpty(g)) printf("Graf kosong\n");
    printf("\n");
    
    for(int i=0; i<5; ++i) addNode(&g);
    printf("setelah ditambahkan 5 node:\n"); displayGraph(g);

    connectNode(&g, 0, 1);
    printf("setelah idx 0 dan idx 1 dihubungkan:\n"); displayGraph(g);
    connectNode(&g, 1, 4);
    printf("setelah idx 1 dan idx 4 dihubungkan:\n"); displayGraph(g);

    printf("\n");
    if (isAdjacent(g, 0, 1)) printf("idx 0 dan idx 1 bertetanggaan\n");
    if (!isAdjacent(g, 0, 4)) printf("idx 0 dan idx 4 tidak bertetanggaan\n");
    if (isConnected(g, 0, 4)) printf("idx 0 dan idx 4 terhubung\n");
    printf("\n");

    deleteEdge(&g, 0, 1);
    printf("setelah idx 0 dan idx 1 diputus:\n"); displayGraph(g);
    deleteEdge(&g, 1, 4);
    printf("setelah idx 1 dan idx 4 diputus:\n"); displayGraph(g);
    printf("\n");

    if (isGraphEmpty(g)) printf("Graf kosong\n");

    return 0;
}