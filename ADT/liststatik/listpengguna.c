#include <stdio.h>
#include <stdlib.h>

#include "../boolean.h"
#include "listpengguna.h"
#include "../../primitif/primitif.h"

/* ********** KONSTRUKTOR ********** */
//gcc -o q adt/liststatik/listpengguna.c primitif/primitif.c adt/matriks/foto.c adt/queue/prioqueue.c adt/stack/drafstack.c adt/datetime/datetime.c adt/datetime/time.c adt/pcolor/pcolor.c

/*void CreatePengguna(Pengguna *p, char name[20], char pass[20]) {
    p -> nama = name;
    p -> password = pass;
    p -> bio = "";
    p -> noHp = "";
    p -> weton = "";
    p -> jenisAkun = "";
    p -> fotoProfil = "";
}*/

/* Konstruktor : */
void newPengguna(Pengguna *p, char *nama, char *sandi) {

    strCpy(nama, NAMA(*p));
    strCpy(sandi, PASSWORD(*p));
    strCpy("Publik", JENIS(*p));
    strCpy("", BIO(*p));
    strCpy("", HP(*p));
    strCpy("", WETON(*p));
    CreatePhotoMatrix(&FOTO(*p));
    CreatePrioQueue(&FREQ(*p));
    TOTALFRIENDS(*p) = 0;
    JMLHDRAF(*p) = 0;
    CreateEmptyDrafStack(&DRAF(*p));
    //printPengguna(*p);
}

void createPengguna(Pengguna *p){
    strCpy("", NAMA(*p));
    strCpy("", PASSWORD(*p));
    strCpy("", JENIS(*p));
    strCpy("", BIO(*p));
    strCpy("", HP(*p));
    strCpy("", WETON(*p));
    //CreatePhotoMatrix(&FOTO(*p));
    CreatePrioQueue(&FREQ(*p));
    JMLHDRAF(*p) = 0;
    CreateEmptyDrafStack(&DRAF(*p));
}
//create List kosong
void CreateListPengguna(ListPengguna *l) {
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthP(ListPengguna l) {
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
    return (listLengthP(l)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPengguna l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i >= 0 && i < CAPACITY);
}

boolean isIdxEffP(ListPengguna l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    return (i >= 0 && i <= listLengthP(l)-1);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyP(ListPengguna l) {
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return listLengthP(l)==0;
}

/* *** Test List penuh *** */
boolean isFullP(ListPengguna l) {
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return (listLengthP(l)==CAPACITY);
}

void printPengguna(Pengguna p) {
    printf("%d\n",ID(p));
    printf("%s\n",NAMA(p));
    printf("%s\n",PASSWORD(p));
    printf("%s\n",BIO(p));
    printf("%s\n",HP(p));
    printf("%s\n",WETON(p));
    printf("%s\n",JENIS(p));
    PrintPhotoMatrix(FOTO(p));
}

void printListP(ListPengguna l) {
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
    IdxType i;
    int n = listLengthP(l);

    for (i=0;i<n;i++){
        printPengguna(ELMT(l,i));
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
void insertFirstP(ListPengguna *l, ElType val) {
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
    int i;
    for(i=listLengthP(*l);i>0;i--){
        ELMT(*l,i) = ELMT(*l,i-1);
    }
    ELMT(*l,0) = val;
    NEFF(*l)++;
}

void insertAtP(ListPengguna *l, ElType val, IdxType idx) {
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
    int i;
    for(i=listLengthP(*l);i>idx;i--){
        ELMT(*l,i) = ELMT(*l,i-1);
    }
    ELMT(*l,idx) = val;
    NEFF(*l)++;
}

void insertLastP(ListPengguna *l, ElType val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    ELMT(*l,listLengthP(*l)) = val;
    NEFF(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirstP(ListPengguna *l, ElType *val) {
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT(*l,0);

    int i;
    for(i=0;i<listLengthP(*l)-1;i++){
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    NEFF(*l)--;
}

/* *** Menghapus elemen pada index tertentu *** */
void deleteAtP(ListPengguna *l, ElType *val, IdxType idx) {
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT(*l,idx);

    int i;
    for(i=idx;i<listLengthP(*l)-1;i++){
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    NEFF(*l)--;
}

/* *** Menghapus elemen terakhir *** */
void deleteLastP(ListPengguna *l, ElType *val) {
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT(*l,getLastIdx(*l));
    NEFF(*l)--;
}

int searchNama(ListPengguna l, char *nama){
    //returns index if found, IDX_UNDEF if not

    int i=0;
    boolean found = false;

    while (i < listLengthP(l) && !found){
        if (isStrEqual(NAMA(ELMT(l,i)),nama)){
            found = true;
        } else {
            i++;
        }
    }

    if (!found) {i = IDX_UNDEF;}

    return i;
}

int searchNamabyRef(ListPengguna *l, char *nama){
    int i=0;
    boolean found = false;

    while (i < listLengthP(*l) && !found){
        if (isStrEqual(NAMA(ELMT(*l,i)),nama)){
            found = true;
        } else {
            i++;
        }
    }

    if (!found) {i = IDX_UNDEF;}

    return i;
}

boolean checkSandi(ListPengguna l, int idx, char *sandi){
    return strictIsStrEqual(PASSWORD(ELMT(l,idx)),sandi);
}

void setJumlahDraf(ListPengguna *l, char *nama , int jumlah){
    int idx = searchNama(*l,nama);
    if (idx != -1) { // assuming searchNama returns -1 if not found
        JMLHDRAF(ELMT(*l, idx)) = jumlah;
    } else {
        printf("Nama pengguna tidak ditemukan: %s\n", nama);
    }
}

char* searchNamabyId(ListPengguna l, int id) {
    int i;
    for (i = 0; i < listLengthP(l); i++) {
        if (ID(ELMT(l, i)) == id) {
            // char* nameCopy = malloc(strlen(NAMA(ELMT(l, i))) + 1);
            // if (nameCopy != NULL) {
            //     strCpy(NAMA(ELMT(l, i)), nameCopy);
            //     return nameCopy;
            // }
            break;
        }
    }
    return NULL;
}

int searchPenggunaByName(ListPengguna l, char *nama ){
    int i = 0;
    for(i = 0; i < listLengthP(l) ; i++){
        if(isStrEqual(NAMA(ELMT(l,i)),nama)){
            return i;
        }
    }
    return IDX_UNDEF;
}

int findIDPenggunaByName(ListPengguna *l, char *nama ){
    int i = 0;
    for(i = 0; i < listLengthP(*l) ; i++){
        if(isStrEqual(NAMA(ELMT(*l,i)),nama)){
            return ELMT(*l,i).id;
        }
    }
    return IDX_UNDEF;
}

boolean isPenggunaPrivate(ListPengguna *l, char *nama){
    int i = 0;
    for ( i =0 ; i < listLengthP(*l) ; i++){
        if(isStrEqual(NAMA(ELMT(*l,i)),nama)){
            if(isStrEqual(JENIS(ELMT(*l,i)),"Privat") ){
                return true;
            }else{
                return false;
            }
        }
    }
    return false;
}
