
#include "drafStack.h"
#include <stdio.h>

void CreateEmpty(DrafStack *S){
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah DrafStack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri DrafStack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(DrafStack S){
    return Top(S) == Nil;
}
/* Mengirim true jika DrafStack kosong: lihat definisi di atas */
boolean IsFull(DrafStack S){
    return Top(S) == MaxEL -1;
}
/* Mengirim true jika tabel penampung nilai elemen DrafStack penuh */

/* ************ Menambahkan sebuah elemen ke DrafStack ************ */
void Push(DrafStack * S, Eltype X){
    Top(*S)++;
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen DrafStack S. */
/* I.S. S mungkin kosong, tabel penampung elemen DrafStack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen DrafStack ************ */
void Pop(DrafStack * S, Eltype* X){
    *X = InfoTop(*S);
    Top(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void DisplayDraf(Draf D){
    printf("| %02d/%02d/%04d %02d:%02d:%02d\n" , Day(DateTime(D)),Month(DateTime(D)),Year(DateTime(D)),Hour(Time(DateTime(D))),Minute(Time(DateTime(D))), Second(Time(DateTime(D))));
    printf("| %s\n", DrafTweet(D));
}