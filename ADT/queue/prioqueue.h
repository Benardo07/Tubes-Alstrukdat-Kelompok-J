# ifndef prioqueue_H
# define prioqueue_H

# include "../boolean.h"

# define Nil -1

typedef struct {
    int prio;  /* [1..100], prioritas dengan nilai 1..100 (1 adalah prioritas adalah tertinggi) */
    int info;  /* elemen karakter */
} infotype;

typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueChar : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    infotype T[20];   /* tabel penyimpan elemen */ 
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} PrioQueue;

#define Prio(e)     (e).prio
#define Info(e)     (e).info
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q)    (Q).MaxEl
#define Elmt(Q,i)   (Q).T[(i)]

void CreatePrioQueue(PrioQueue *Q);

boolean IsEmpty (PrioQueue Q);

boolean IsFull (PrioQueue Q);

int lengthQueue (PrioQueue Q);

void Enqueue (PrioQueue * Q, infotype X);

void Dequeue (PrioQueue * Q, infotype * X);

void DisplayPrioQueue (PrioQueue Q);

#endif