#include <stdio.h>
#include <stdlib.h>
#include "kicau.h"
#include "../datetime/datetime.h"

Address newNode(Kicau val){
    Address new = (Address) malloc (sizeof(Node));
    INFO(new) = val;
    NEXT(new) = NULL;
    return new;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */


/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

void CreateKicau(Kicau *k,int id, int like, Word text, Word aut, DATETIME waktu){
    (*k).id = id;
    (*k).like = like;
    (*k).text = text;
    (*k).author = aut;
    (*k).waktu = waktu;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmptyList(List l){
    return (FIRST(l)==NULL);
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
Kicau getElmt(List l, int idx){
    int ctr = 0;
    Address p = l;
    while (ctr<idx){
        ctr= ctr+1;
        p = NEXT(p);
    }
    return(INFO(p));
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, Kicau val){
    int ctr = 0;
    Address p = *l;
    while (ctr < idx){
        ctr = ctr +1;
        p = NEXT(p);
    }
    INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */


int indexOf(List l, int id){
    int idx = 0;
    Address p = l;
    boolean found = false;
    while (p!=NULL && !found){
        if (id(p)==id){
            found = true;
        }
        else{
            idx +=1;
            p = NEXT(p);
        }
    }
    if (found){
        return(idx);
    }
    else{
        return(IDX_UNDEFINE);
    }
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEFINE jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstKicau(List *l, Kicau val){
    Address p = newNode(val);
    if (p!=NULL){
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLastKicau(List *l, Kicau val){
    Address p,loc;
    if(isEmptyList(*l)){
        insertFirstKicau(l,val);
    }
    else{
        p=newNode(val);
        loc = *l;
        while (NEXT(loc)!=NULL){
            loc = NEXT(loc);
        }
        NEXT(loc) = p;
    }
}


// nambah kicauan inputnya author
void insertKicau(List *l, Word val, int *id){ //val ini buat authornya terus idnya jadi disimpen di main.
    boolean space = true;
    Word text;
    printf("Masukkan kicauan:\n");
    readKicau(&text);
    printf("\n");
    if (!allSpace(text)){
        space = false;
    }

    while(space){ // cek apakah cuma berisi space atau tidak
    printf("Kicauan tidak boleh hanya berisi spasi!\n");
    printf("Masukkan kicauan:\n");
    readKicau(&text);
    printf("\n");
    if (!allSpace(text)){
        space = false;
    }
    }

    // ambil waktu lokal
    time_t currentTime;
    struct tm *localTime;

    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1; 
    int year = localTime->tm_year + 1900;
    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;
    int second = localTime->tm_sec;
    DATETIME d;
    CreateDATETIME(&d,day,month,year,hour,minute,second);

    Kicau k;
    CreateKicau(&k,*id,0,text,val,d);
    insertLastKicau(l,k);

    // print hasil kicau
    printf("Selamat! kicauan telah diterbitkan!\n");
    printKicau(*l,*id);
    *id+=1; //id next tambah 1
}

void editKicau(List *l, int id, Word auth){
    if (indexOf(*l,id)==IDX_UNDEFINE){
        printf("Tidak ditemukan kicauan dengan ID = %d!\n",id);
        printf("\n");
    }
    else{
        Kicau el;
        el = getElmt(*l,id-1);
        if(!isEqual(el.author,auth)){
            printf("Kicauan dengan ID = %d bukan milikmu!\n",id);
            printf("\n");
        }
        else{
            boolean space = true;
            Word text;
            printf("Masukkan kicauan:\n");
            readKicau(&text);
            printf("\n");
            if (!allSpace(text)){
                space = false;
            }

            while(space){ // cek apakah cuma berisi space atau tidak
            printf("Kicauan tidak boleh hanya berisi spasi!\n");
            printf("Masukkan kicauan:\n");
            readKicau(&text);
            printf("\n");
            if (!allSpace(text)){
                space = false;
            }
            }

            el.text = text;
            setElmt(l,id-1,el); // set element dengan text baru

            printf("Selamat! kicauan telah diterbitkan!\n");
            printKicau(*l,id);
        }
    }
}

void sukaKicau(List *l, int id, Word auth){
    if (indexOf(*l,id)==IDX_UNDEFINE){
        printf("Tidak ditemukan kicauan dengan ID = %d!\n",id);
        printf("\n");
    }
    else{
        Kicau el;
        el = getElmt(*l,id-1);

        el.like += 1;
        setElmt(l,id-1,el); // set element dengan text baru

        printf("Selamat! kicauan telah disukai!\n");
        printKicau(*l,id);
    }
}

void printKicau(List l,int id){ // print kicau satuan
    Kicau el;
    el = getElmt(l,id-1);
    printf("Detil kicauan:\n");
    printf("| ID = %d\n",el.id);
    printf("| ");
    printWord(el.author);
    printf("\n");
    printf("| ");
    TulisDATETIME(el.waktu);
    printf("\n");
    printf("| ");
    printWord(el.text);
    printf("\n");
    printf("| Disukai: %d\n",el.like);
    printf("\n");
}
/****************** PROSES SEMUA ELEMEN LIST ******************/

// print semua kicauan (ini belum cek temenan apa ngga)
void kicauan(List l){ 
    inverseList(&l); // di invers dulu biar ngeprint yang terbaru
    Address p = l;
    while (p!=NULL){
        printf("| ID = %d\n",id(p));
        printf("| ");
        printWord(author(p));
        printf("\n");
        printf("| ");
        TulisDATETIME(waktu(p));
        printf("\n");
        printf("| ");
        printWord(text(p));
        printf("\n");
        printf("| Disukai: %d\n",like(p));
        printf("\n");
        p = NEXT(p);
    }
   inverseList(&l); // balikin jadi list awal lagi
}

void inverseList(List *l){
    Address p = *l;
    Kicau temp;
    for(int i = 0; i<length(*l)/2;i++){
        temp = getElmt(*l,i);
        setElmt(l,i,getElmt(*l,length(*l)-1-i));
        setElmt(l,length(*l)-1-i,temp);
    }
}

int length(List l){
    int ctr = 0;
    Address p = l;
    if (isEmptyList(l)){
        return 0;
    }
    while (p!=NULL){
        ctr+=1;
        p = NEXT(p);
    }
    return(ctr);
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
