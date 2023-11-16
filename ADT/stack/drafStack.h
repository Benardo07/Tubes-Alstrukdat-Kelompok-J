#ifndef stackt_H
#define stackt_H

#include "../boolean.h"
#include "../datetime/datetime.h"
#include "../../primitif/primitif.h"

#define Nil -1
#define MaxEL 100

typedef struct 
{
    char drafTweet[280];
    DATETIME timeDraf;
} Draf;

typedef Draf ElDraftype;
typedef int address;

typedef struct 
{
    ElDraftype T[MaxEL];
    address TOP;
} DrafStack;


#define Id(D) (D).id
#define DrafTweet(D) (D).drafTweet
#define Author(D) (D).author
#define DateTime(D) (D).timeDraf


#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

void CreateEmptyDrafStack(DrafStack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah DrafStack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri DrafStack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyDrafStack(DrafStack S);
/* Mengirim true jika DrafStack kosong: lihat definisi di atas */
boolean IsFullDrafStack(DrafStack S);
/* Mengirim true jika tabel penampung nilai elemen DrafStack penuh */

/* ************ Menambahkan sebuah elemen ke DrafStack ************ */
void PushDrafStack(DrafStack * S, ElDraftype X);
/* Menambahkan X sebagai elemen DrafStack S. */
/* I.S. S mungkin kosong, tabel penampung elemen DrafStack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen DrafStack ************ */
void PopDrafStack(DrafStack * S, ElDraftype* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void DisplayDraf(Draf D);

void CreateDraf(Draf *D,char * tweet, DATETIME waktu);

void printDraf(Draf D);


Draf printLastDraf(DrafStack S);

void DeleteLastDraf(DrafStack *S);

void EditLastDraf(DrafStack *S ,char *tweet);

void copyReverse(DrafStack S1 , DrafStack *S2);

#endif