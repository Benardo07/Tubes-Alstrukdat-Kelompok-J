/* File : graf.h */
/* Definisi ADT Graf dengan representasi adjacency matrix */
/* Tipe graf : Undirected dan unweighted */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"

/* Jumlah maksimum user yang terdaftar */
#define CAPACITY 20

/* Definisi TYPE Graf dengan representasi matriks */
typedef int ElType;
typedef int IdxType;
typedef struct {
    ElType m[CAPACITY][CAPACITY];
    int nodes; // Jumlah simpul pada graf
    int edges; // Jumlah busur pada graf
} Graf;


/* ********** AKSES (Selektor) ********** */
#define MATRIKS(g) (g).m
#define ELMT(g, i, j) (MATRIKS(g))[i][j]
#define SIMPUL(g) (g).nodes
#define BUSUR(g) (g).edges

/* ********** Predikat ********** */
boolean IsEmpty(Graf g);
/* I.S. Graf g terdefinisi */
/* F.S. Mengembalikan true jika graf kosong, yaitu jumlah busur nol */

boolean isDirectlyConnected(Graf g, int idx1, int idx2);
/* I.S. Graf g terdefinisi */
/* F.S. Mengembalikan true jika terdapat busur yang menghubungkan langsung */
/*      simpul 1 dengan simpul 2, false jika tidak */

boolean isIndirectlyConnected(Graf g, int idx1, int idx2);
/* I.S. Graf g terdefinisi */
/* F.S. Mengembalikan true jika simpul 1 dengan simpul 2 terhubung, */
/*      yaitu terdapat jalan (path) yang menghubungkan simpul 1 dengan simpul 2 */
/* Proses : Melakukan algoritma BFS pada graf untuk mengecek apakah simpul 1 dan simpul 2 terhubung */

/* ********** Konstruktor ********** */
void createGraph(Graf *g);
/* I.S. sembarang */
/* F.S. Graf kosong g terbentuk, dengan kondisi semua simpul tidak terhubung */
/*      satu sama lain dan jumlah busur adalan nol */

/* ********** Primitif Add/Delete ********** */
void addNode(Graf *g);
/* I.S. Graf g terdefinisi */
/* F.S. Jumlah node pada graf bertambah satu */

void connectNode(Graf *g, int idx1, int idx2);
/* I.S. Graf g terdefinisi */
/* F.S. Menghubungkan simpul 1 dengan simpul 2 */

void deleteEdge(Graf *g, int idx1, int idx2);
/* I.S. Graf g terdefinisi */
/* F.S. Menghapus busur yang menghubungkan simpul 1 dengan simpul 2*/

/* ********** Primitif Lain ********** */
void displayGraph(Graf g);
/* I.S. Graf g terdefinisi */
/* F.S. Menampilkan representasi matriks graf g pada layar */

#endif