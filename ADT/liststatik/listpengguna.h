/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include "../boolean.h"

/*  Kamus Umum */
#define CAPACITY 20
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct
{
    int id;
    char nama[20];
    char password[20];
    char bio[135];
    char noHp[100]; //to do: ubah noHP ke int
    char weton[10];
    char jenisAkun[10];
    char fotoProfil[5][20];
} Pengguna;
typedef Pengguna ElType;
typedef struct {
   ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >=0, banyaknya elemen efektif */
} ListPengguna;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListPengguna, cara deklarasi dan akses: */
/* Deklarasi : l : ListPengguna */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ID(p) (p).id
#define NAMA(p) (p).nama
#define PASSWORD(p) (p).password
#define BIO(p) (p).bio
#define HP(p) (p).noHp
#define WETON(p) (p).weton
#define JENIS(p) (p).jenisAkun
#define FOTO(p) (p).fotoProfil

#define NEFF(l) (l).nEff
#define BUFFER(l) (l).contents
#define ELMT(l, i) (l).contents[i]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPengguna(ListPengguna *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthP(ListPengguna l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListPengguna l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListPengguna l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPengguna l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffP(ListPengguna l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyP(ListPengguna l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFullP(ListPengguna l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void printListP(ListPengguna l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
//int indexOf(ListPengguna l, ElType val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirstP(ListPengguna *l, ElType val);
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAtP(ListPengguna *l, ElType val, IdxType idx);
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLastP(ListPengguna *l, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirstP(ListPengguna *l, ElType *val);
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAtP(ListPengguna *l, ElType *val, IdxType idx);
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLastP(ListPengguna *l, ElType *val);
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
int searchNama(ListPengguna l, char *nama);
boolean checkSandi(ListPengguna l, int idx, char *sandi);
#endif
