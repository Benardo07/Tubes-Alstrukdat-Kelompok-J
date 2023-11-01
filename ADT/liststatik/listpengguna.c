#include <stdio.h>
#include <stdlib.h>

#include "../boolean.h"
#include "listpengguna.h"

/* ********** KONSTRUKTOR ********** */

/*void CreatePengguna(Pengguna *p, char name[20], char pass[20]) {
    p -> nama = name;
    p -> password = pass;
    p -> bio = "";
    p -> noHp = "";
    p -> weton = "";
    p -> jenisAkun = "";
    p -> fotoProfil = "";
}*/

/* Konstruktor : create List kosong  */
void CreateListPengguna(ListPengguna *l) {
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListPengguna l) {
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListPengguna l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}

IdxType getLastIdx(ListPengguna l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return (listLength(l)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPengguna l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i >= 0 && i < CAPACITY);
}

boolean isIdxEff(ListPengguna l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    return (i >= 0 && i <= listLength(l)-1);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPengguna l) {
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return listLength(l)==0;
}

/* *** Test List penuh *** */
boolean isFull(ListPengguna l) {
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return (listLength(l)==CAPACITY);
}

void printList(ListPengguna l) {
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
    IdxType i,j;

    for (i=0;i<listLength(l);i++){
        Pengguna p = ELMT(l,i);
        printf("%s\n",NAMA(p));
        printf("%s\n",PASSWORD(p));
        printf("%s\n",BIO(p));
        printf("%s\n",HP(p));
        printf("%s\n",WETON(p));
        printf("%s\n",JENIS(p));

        for (j=0;j<5;j++) {
            printf("%s\n",FOTO(p)[j]);
        }
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
//int indexOf(ListPengguna l, ElType val) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
/*    int i;

    for(i=0;i<listLength(l);i++){
        if (ELMT(l,i)==val) return i;
    }

    return IDX_UNDEF;
}*/

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListPengguna *l, ElType val) {
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
    int i;
    for(i=listLength(*l);i>0;i--){
        ELMT(*l,i) = ELMT(*l,i-1);
    }
    ELMT(*l,0) = val;
    NEFF(*l)++;
}

void insertAt(ListPengguna *l, ElType val, IdxType idx) {
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
    int i;
    for(i=listLength(*l);i>idx;i--){
        ELMT(*l,i) = ELMT(*l,i-1);
    }
    ELMT(*l,idx) = val;
    NEFF(*l)++;
}

void insertLast(ListPengguna *l, ElType val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    ELMT(*l,listLength(*l)) = val;
    NEFF(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListPengguna *l, ElType *val) {
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT(*l,0);

    int i;
    for(i=0;i<listLength(*l)-1;i++){
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    NEFF(*l)--;
}

/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListPengguna *l, ElType *val, IdxType idx) {
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT(*l,idx);

    int i;
    for(i=idx;i<listLength(*l)-1;i++){
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    NEFF(*l)--;
}

/* *** Menghapus elemen terakhir *** */
void deleteLast(ListPengguna *l, ElType *val) {
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT(*l,getLastIdx(*l));
    NEFF(*l)--;
}
