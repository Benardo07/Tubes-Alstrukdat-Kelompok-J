# ifndef prioqueue_H
# define prioqueue_H

# include "../boolean.h"

# define Nil -1

typedef struct {
    int prio;  /* [1..100], prioritas dengan nilai 1..100 (100 adalah prioritas adalah tertinggi) */
    int userId;  /* elemen karakter */
} infotype;

infotype newPrioElmt(int userId, int prio);
/* Membentuk elemen priority queue baru, dengan INFO(elmt) = userId dan PRIO(elmt) = prio */

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
#define Info(e)     (e).userId
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q)    (Q).MaxEl
#define Elmt(Q,i)   (Q).T[(i)]

void CreatePrioQueue(PrioQueue *Q);

boolean IsPrioQueueEmpty (PrioQueue Q);

boolean IsPrioQueueFull (PrioQueue Q);

int lengthPrioQueue (PrioQueue Q);

void EnqueuePrio (PrioQueue * Q, infotype X);

void DequeuePrio (PrioQueue * Q, infotype * X);

void DisplayPrioQueue (PrioQueue Q);

void SearchByUserId(PrioQueue * Q, int searchValue);

void UpdatePrioQueue(PrioQueue *Q, int userId);

#endif