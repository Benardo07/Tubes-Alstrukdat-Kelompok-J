# include <stdio.h>
# include <stdlib.h>
# include "listdinutas.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinUtas(ListDin *l, int capacity){
    CAPACITYDIN(*l)= capacity;
    NEFFDIN(*l)=0;
    BUFFERDIN(*l) = (Kicau *) malloc(capacity*sizeof(Kicau));
};
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l){
    CAPACITYDIN(*l)=0;
    NEFFDIN(*l)=0;
    free(BUFFERDIN(*l));
};
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthDin(ListDin l){
    return NEFFDIN(l);
};
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdxDin(ListDin l){
    return IDX_MIN;
};
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdxDin(ListDin l){
    return listLengthDin(l)-1;
};
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidDin(ListDin l, IdxType i){
    return (i>=IDX_MIN && i<CAPACITYDIN(l));
};
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffDin(ListDin l, IdxType i){
    return (i>=IDX_MIN && i<=NEFFDIN(l));
};
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyDin(ListDin l){
    return (listLengthDin(l)==0);
};
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullDin(ListDin l){
    return (listLengthDin(l)==CAPACITYDIN(l));
};
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListDin(ListDin *l){
    int n,i;
    do{
        scanf("%d",&n);
    }while(n<0||n>CAPACITYDIN(*l));
    CreateListDinUtas(l,n);
    for(i=IDX_MIN;i<n;i++){
        scanf("%d",&ELMTDIN(*l,i));
    }
    NEFFDIN(*l) = n;
};
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printListDin(ListDin l){
     int i;
    printf("[");
    for (i=getFirstIdxDin(l);i<listLengthDin(l); i++){
      printf("%d", ELMTDIN(l,i));
      if (i!=listLengthDin(l)-1){
         printf(",");
      }
   }
   printf("]");
};
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfDin(ListDin l, int val){
    int idx = IDXUNDEFDIN;
    int i;
    for (i = 0; i < listLengthDin(l); i++) {
        if (ELMTDIN(l, i).id == val) {
            idx = i;
            break;
        }
    }
    return idx;
};
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */


/* ********** OPERASI LAIN ********** */
void copyListDin(ListDin lIn, ListDin *lOut){
    CreateListDinUtas(lOut,CAPACITYDIN(lIn));
    int i;
    for(i=IDX_MIN;i<NEFFDIN(lIn);i++){
        ELMTDIN(*lOut,i)=ELMTDIN(lIn,i);
    }
    NEFFDIN(*lOut)=NEFFDIN(lIn);
};


/* ********** SORTING ********** */
void swap(Kicau *a, Kicau *b) {
    Kicau temp = *a;
    *a = *b;
    *b = temp;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastDin(ListDin *l, Kicau val){
    if (isFullDin(*l)){
        expandList(l,CAPACITYDIN(*l));
    }
    ELMTDIN(*l,listLengthDin(*l)) = val;
    NEFFDIN(*l)+=1;
};
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastDin(ListDin *l, Kicau *val){
   *val = ELMTDIN(*l, NEFFDIN(*l)-1);
    NEFFDIN(*l)-=1;
};
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
    CAPACITYDIN(*l)+=num;
    BUFFERDIN(*l)= realloc(BUFFERDIN(*l),(CAPACITYDIN(*l)) * sizeof(Kicau));
};
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num){
    CAPACITYDIN(*l) -= num;
    BUFFERDIN(*l)= realloc(BUFFERDIN(*l),(CAPACITYDIN(*l)) * sizeof(Kicau));
};
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l){
    BUFFERDIN(*l) = realloc(BUFFERDIN(*l), NEFFDIN(*l) * sizeof(Kicau));
    CAPACITYDIN(*l)=NEFFDIN(*l);
};
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */