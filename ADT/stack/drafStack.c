
#include "drafStack.h"

#include <stdio.h>
#include "..\mesinkata\wordmachine.h"

void CreateEmptyDrafStack(DrafStack *S){
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah DrafStack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri DrafStack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyDrafStack(DrafStack S){
    return Top(S) == Nil;
}
/* Mengirim true jika DrafStack kosong: lihat definisi di atas */
boolean IsFullDrafStack(DrafStack S){
    return Top(S) == MaxEL -1;
}
/* Mengirim true jika tabel penampung nilai elemen DrafStack penuh */

/* ************ Menambahkan sebuah elemen ke DrafStack ************ */
void PushDrafStack(DrafStack * S, ElDraftype X){
    Top(*S)++;
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen DrafStack S. */
/* I.S. S mungkin kosong, tabel penampung elemen DrafStack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen DrafStack ************ */
void PopDrafStack(DrafStack * S, ElDraftype* X){
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

void CreateDraf(Draf *D,char * tweet,DATETIME waktu){
    strCpy(tweet,DrafTweet(*D));
    DateTime(*D) = waktu;

}

void printDraf(Draf D){
    printf("| ");
    TulisDATETIME(DateTime(D));
    printf("\n");
    printf("| ");
    printf("%s\n",DrafTweet(D));
}

// boolean findDraf(DrafStack S, int id){
//     Draf temp;
//     while (!IsEmptyDrafStack(S)){
//         PopDrafStack(&S,&temp);
//         if(Id(temp) == id){
//             return true;
//         }
//     }
//     return false;
// }

Draf printLastDraf(DrafStack S){
    Draf temp;
    PopDrafStack(&S,&temp);
    printDraf(temp);

    return temp;
    
}

void DeleteLastDraf(DrafStack *S){
    Draf temp;
    PopDrafStack(S,&temp);
}

void EditLastDraf(DrafStack *S , char *tweet){
    Draf temp;
    PopDrafStack(S,&temp);
    strCpy(tweet,DrafTweet(temp));
    PushDrafStack(S,temp);
}

void copyReverse(DrafStack S1 , DrafStack *S2){
    Draf temp;
    CreateEmptyDrafStack(S2);
    while (!IsEmptyDrafStack(S1))
    {
        PopDrafStack(&S1,&temp);
        PushDrafStack(S2,temp);
    }
    
}