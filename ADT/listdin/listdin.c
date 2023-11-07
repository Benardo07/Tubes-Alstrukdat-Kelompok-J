# include <stdio.h>
# include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinTree(ListDinTree *l, int capacity){
    CAPACITYDINTREE(*l)= capacity;
    NEFFDINTREE(*l)=0;
    BUFFERDINTREE(*l) = (ElDinType *) malloc(capacity*sizeof(ElDinType));
};
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListDinTree(ListDinTree *l){
    CAPACITYDINTREE(*l)=0;
    NEFFDINTREE(*l)=0;
    free(BUFFERDINTREE(*l));
};
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFFDINTREE(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int ListDinTreeLength(ListDinTree l){
    return NEFFDINTREE(l);
};
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
int getFirstIdxDinTree(ListDinTree l){
    return IDX_MIN_B;
};
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
int getLastIdxDinTree(ListDinTree l){
    return ListDinTreeLength(l)-1;
};
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidDinTree(ListDinTree l, int i){
    return (i>=IDX_MIN_B && i<CAPACITYDINTREE(l));
};
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffDinTree(ListDinTree l, int i){
    return (i>=IDX_MIN_B && i<=NEFFDINTREE(l));
};
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFFDINTREE(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyDinTree(ListDinTree l){
    return (ListDinTreeLength(l)==0);
};
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullDinTree(ListDinTree l){
    return (ListDinTreeLength(l)==CAPACITYDINTREE(l));
};
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListDinTree(ListDinTree *l){
    int n,i;
    do{
        scanf("%d",&n);
    }while(n<0||n>CAPACITYDINTREE(*l));
    CreateListDinTree(l,n);
    for(i=IDX_MIN_B;i<n;i++){
        scanf("%d",&ELMTDINTREE(*l,i));
    }
    NEFFDINTREE(*l) = n;
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
void printListDinTree(ListDinTree l){
     int i;
    printf("[");
    for (i=getFirstIdxDinTree(l);i<ListDinTreeLength(l); i++){
      printf("%d", ELMTDINTREE(l,i));
      if (i!=ListDinTreeLength(l)-1){
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

/* ********** OPERATOR ARITMATIKA ********** */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika NEFFDINTREE l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
int indexOfDinTree(ListDinTree l,ElDinType val){
    int idx = IDX_UNDEF_B;
    int i;
    for (i = 0; i < ListDinTreeLength(l); i++) {
        if (ELMTDINTREE(l, i) == val) {
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

/* ********** NILAI EKSTREM ********** */

/* ********** OPERASI LAIN ********** */
void copyListDinTree(ListDinTree lIn, ListDinTree *lOut){
    CreateListDinTree(lOut,CAPACITYDINTREE(lIn));
    int i;
    for(i=IDX_MIN_B;i<NEFFDINTREE(lIn);i++){
        ELMTDINTREE(*lOut,i)=ELMTDINTREE(lIn,i);
    }
    NEFFDINTREE(*lOut)=NEFFDINTREE(lIn);
};

void deleteListDinAt(ListDinTree *l , int idx){
    if (idx < IDX_MIN_B || idx >= NEFFDINTREE(*l)) {
        printf("Index out of bounds\n");
        return;
    }

    // If necessary, free the memory of the node at the specified index
    // free(ELMTDINTREE(*l, idx));

    // Shift elements to the left to fill the gap
    for (int i = idx; i < NEFFDINTREE(*l) - 1; i++) {
        ELMTDINTREE(*l, i) = ELMTDINTREE(*l, i + 1);
    }

    // Decrease the effective number of elements
    NEFFDINTREE(*l)--;
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, NEFFDINTREE dan CAPACITYDINTREE sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
// ElType sumList(ListDinTree l){
//     int i,sum=0;
//     for(i=IDX_MIN_B;i<ListDinTreeLength(l);i++){
//         sum += ELMTDINTREE(l,i);
//     }
//     return sum;
// };
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countValDinTree(ListDinTree l, ElDinType val){
    int i,count=0;
    for(i=IDX_MIN_B;i<ListDinTreeLength(l);i++){
        if(ELMTDINTREE(l,i)==val){
            count ++;
        }
    }
    return count;
};
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
// void swap(ElDinType *a, ElDinType *b) {
//     ElDinType temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void sortDin(ListDinTree *l, boolean asc){
//     int i, j;
//     int n = ListDinTreeLength(*l);
//     for (i = 0; i < n - 1; i++) {
//         for (j = 0; j < n - i - 1; j++) {
//             if (asc) {
//                 if (ELMTDINTREE(*l, j) > ELMTDINTREE(*l, j + 1)) {
//                     swap(&ELMTDINTREE(*l, j), &ELMTDINTREE(*l, j + 1));
//                 }
//             } else {
//                 if (ELMTDINTREE(*l, j) < ELMTDINTREE(*l, j + 1)) {
//                     swap(&ELMTDINTREE(*l, j), &ELMTDINTREE(*l, j + 1));
//                 }
//             }
//         }
//     }
// };
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastDinTree(ListDinTree *l, ElDinType val){

    ELMTDINTREE(*l,ListDinTreeLength(*l)) = val;
    NEFFDINTREE(*l)+=1;

};
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastDinTree(ListDinTree *l, ElDinType *val){
   *val = ELMTDINTREE(*l, NEFFDINTREE(*l)-1);
    NEFFDINTREE(*l)-=1;
};
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinTree(ListDinTree *l, int num){
    CAPACITYDINTREE(*l)+=num;
    BUFFERDINTREE(*l)= realloc(BUFFERDINTREE(*l),(CAPACITYDINTREE(*l)) * sizeof(ElDinType));
};
/* Proses : Menambahkan CAPACITYDINTREE l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListDinTree(ListDinTree *l, int num){
    CAPACITYDINTREE(*l) -= num;
    BUFFERDINTREE(*l)= realloc(BUFFERDINTREE(*l),(CAPACITYDINTREE(*l)) * sizeof(ElDinType));
};
/* Proses : Mengurangi CAPACITYDINTREE sebanyak num */
/* I.S. List sudah terdefinisi, ukuran CAPACITYDINTREE > num, dan NEFFDINTREE < CAPACITYDINTREE - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressListDinTree(ListDinTree *l){
    BUFFERDINTREE(*l) = realloc(BUFFERDINTREE(*l), NEFFDINTREE(*l) * sizeof(ElDinType));
    CAPACITYDINTREE(*l)=NEFFDINTREE(*l);
};
/* Proses : Mengubah capacity sehingga capacity = NEFFDINTREE */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = NEFFDINTREE */