#include <stdio.h>
#include "graf.h"
#include "../queue/queue.h"

/* ********** Predikat ********** */
boolean isGraphEmpty(Graf g) {
/* I.S. Graf g terdefinisi */
/* F.S. Mengembalikan true jika graf kosong, yaitu jumlah busur nol */
    return BUSUR(g) == 0;
}

boolean isDirectlyConnected(Graf g, int idx1, int idx2) {
/* I.S. Graf g terdefinisi, idx1 dan idx2 merupakan indeks yang valid pada graf */
/* F.S. Mengembalikan true jika terdapat busur yang menghubungkan langsung */
/*      simpul 1 dengan simpul 2, false jika tidak */
    return ELMT_GRAPH(g, idx1, idx2) == 1;
}

boolean isIndirectlyConnected(Graf g, int idx1, int idx2) {
/* I.S. Graf g terdefinisi */
/* F.S. Mengembalikan true jika user dengan id_1 terhubung dengan user dengan id_2, */
/*      yaitu terdapat jalan yang menghubungkan simpul 1 dengan simpul 2 */
/* Proses : Melakukan algoritma BFS pada graf untuk mengecek apakah simpul 1 dan simpul 2 terhubung */
    if (isDirectlyConnected(g, idx1, idx2)) return true;

    boolean visited[SIMPUL(g)];
    for (int i=0; i<SIMPUL(g); ++i) visited[i] = false;

    Queue q; CreateQueue(&q);
    enqueue(&q, idx1);
    visited[idx1] = true;

    ElType val;
    while(!isEmpty(q)) {
        int cur = HEAD(q);
        dequeue(&q, &val);

        for(int i=0; i<SIMPUL(g); ++i) {
            if (ELMT_GRAPH(g, cur, i) == 1) {
                if (i == idx2) return true;

                if (!visited[i]) {
                    visited[i] = true;
                    enqueue(&q, i);
                }
            }
        }
    }

    return false;
}

/* ********** Konstruktor ********** */
void createGraph(Graf *g) {
/* I.S. sembarang */
/* F.S. Graf kosong g terbentuk, dengan kondisi semua simpul tidak terhubung */
/*      satu sama lain dan jumlah busur adalan nol */
    IdxType i, j;
    for (i=0; i<CAPACITY_GRAPH; ++i) {
        for (j=0; j<CAPACITY_GRAPH; ++j) {
            ELMT_GRAPH(*g, i, j) = 0;
        }
    }

    SIMPUL(*g) = 0;
    BUSUR(*g) = 0;
}

/* ********** Primitif Add/Delete ********** */
void addNode(Graf *g) {
/* I.S. Graf g terdefinisi */
/* F.S. Jumlah node pada graf bertambah satu */
    ELMT_GRAPH(*g, SIMPUL(*g), SIMPUL(*g)) = 1;
    SIMPUL(*g)++;
}

void connectNode(Graf *g, int idx1, int idx2) {
/* I.S. Graf g terdefinisi, idx1 dan idx2 merupakan indeks yang valid pada graf */
/* F.S. Simpul 1 dengan simpul 2 terhubung */
    ELMT_GRAPH(*g, idx1, idx2) = 1;
    ELMT_GRAPH(*g, idx2, idx1) = 1;
    BUSUR(*g)++;
}

void deleteEdge(Graf *g, int idx1, int idx2) {
/* I.S. Graf g terdefinisi, idx1 dan idx2 merupakan indeks yang valid pada graf matriks */
/* F.S. Menghapus busur yang menghubungkan simpul 1 dengan simpul 2 */
    ELMT_GRAPH(*g, idx1, idx2) = 0;
    ELMT_GRAPH(*g, idx2, idx1) = 0;
    BUSUR(*g)++;
}

/* ********** Primitif Lain ********** */
void displayGraph(Graf g) {
/* I.S. Graf g terdefinisi */
/* F.S. Menampilkan representasi matriks graf g pada layar */
    IdxType i, j;
    for (i=0; i<SIMPUL(g); ++i) {
        for (j=0; j<SIMPUL(g); ++j) {
            printf("%d ", ELMT_GRAPH(g, i, j));
        }
        printf("\n");
    }
}