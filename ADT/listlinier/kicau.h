#ifndef listlinier_H
#define listlinier_H
#include "../ADT/boolean.h"
#include "../adt/datetime/datetime.h"
#include "../ADT/mesinkarakter/charmachine.h"
#include "../ADT/mesinkata/wordmachine.h"

/* Definisi Node : */
typedef struct {
    int id;
    int like;
    Word text;
    Word author; // ini authornya nunggu profil nanti disesuaikan
    DATETIME waktu;
} Kicau;

typedef struct node* Address;
typedef struct node {
    Kicau info;
    Address next;
} Node;

#define INFO(p) ((p)->info)
#define NEXT(p) ((p)->next)
#define id(p) (((p)->info).id)
#define like(p) (((p)->info).like)
#define text(p) (((p)->info).text)
#define author(p) (((p)->info).author)
#define waktu(p) (((p)->info).waktu)


Address newNode(Kicau val);

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

typedef Address List;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

void CreateKicau(Kicau *k,int id, int like, Word text, Word aut, DATETIME waktu);

/****************** TEST LIST KOSONG ******************/
boolean isEmptyList(List l);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
Kicau getElmt(List l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, Kicau val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, int id);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstKicau(List *l, Kicau val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastKicau(List *l, Kicau val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertKicau(List *l, Word val,int *id);

void printKicau(List l,int id);

void kicauan(List l);

void editKicau(List *l, int id, Word auth);

void sukaKicau(List *l, int id, Word auth);

int length(List l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

void inverseList(List *l);

#endif