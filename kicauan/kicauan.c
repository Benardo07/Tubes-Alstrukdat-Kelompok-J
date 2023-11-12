#include <stdio.h>
#include <stdlib.h>
#include "../ADT/listlinier/listlinier.h"
#include "kicauan.h"
#include "../teman/teman.h"
#include "../ADT/mesinkarakter/charmachine.h"
#include "../ADT/mesinkata/wordmachine.h" 
#include "../primitif/primitif.h"
#include "../ADT/liststatik/listpengguna.h"

void CreateKicau(Kicau *k,int id, int like, Word text, char *aut, DATETIME waktu){
    (*k).id = id;
    (*k).like = like;
    (*k).text = text;
    (*k).idutas = -999;
    strCpy(aut,(*k).author);
    (*k).waktu = waktu;
    CreateList(&(*k).Utas);
    (*k).Balas = newTree(CreateRootBalasan(),1000);
    (*k).lastIDBalas = 0;
}

// nambah kicauan inputnya author
void insertKicau(List *l, char *val, int *id){ //val ini buat authornya terus idnya jadi disimpen di main.
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

void editKicau(List *l, int id, char *auth){
    if (indexOf(*l,id)==IDXUNDEF){
        printf("Tidak ditemukan kicauan dengan ID = %d!\n",id);
        printf("\n");
    }
    else{
        Kicau el;
        el = getElmt(*l,id-1);
        if(!isStrEqual( el.author, auth)){
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

void sukaKicau(List *l, ListPengguna l2, int id,char *auth){
    if (indexOf(*l,id)==IDXUNDEF){
        printf("Tidak ditemukan kicauan dengan ID = %d!\n",id);
        printf("\n");
    }
    else{
        Kicau el;
        el = getElmt(*l,id-1);
        if(!isPenggunaPrivate(&l2,el.author)){
            el.like += 1;
            setElmt(l,id-1,el); // set element dengan text baru
            printf("Selamat! kicauan telah disukai!\n");
            printKicau(*l,id);
        }
        else{
            if(isTeman(findIDPenggunaByName(l2,el.author),findIDPenggunaByName(l2,auth))){
                el.like += 1;
                setElmt(l,id-1,el); // set element dengan text baru
                printf("Selamat! kicauan telah disukai!\n");
                printKicau(*l,id);
            }
            else{
                printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
            }
        }
    }
}

void printKicau(List l,int id){ // print kicau satuan
    Kicau el;
    el = getElmt(l,id-1);
    printf("Detil kicauan:\n");
    printf("| ID = %d\n",el.id);
    printf("| ");
    printf("%s\n",el.author);
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
void kicauan(List l, ListPengguna l2, char *auth){ 
    inverseList(&l); // di invers dulu biar ngeprint yang terbaru
    Address p = l;
    while (p!=NULL){
        if(!isPenggunaPrivate(&l2,p->info.author)){
            printf("| ID = %d\n",id(p));
            printf("| ");
            printf("%s\n",p->info.author);
            printf("| ");
            TulisDATETIME(waktu(p));
            printf("\n");
            printf("| ");
            printWord(text(p));
            printf("\n");
            printf("| Disukai: %d\n",like(p));
            printf("\n");
        }
        else if(isPenggunaPrivate(&l2,p->info.author)){
            if(isTeman(findIDPenggunaByName(l2,p->info.author),findIDPenggunaByName(l2,auth))){
                printf("| ID = %d\n",id(p));
                printf("| ");
                printf("%s\n",p->info.author);
                printf("| ");
                TulisDATETIME(waktu(p));
                printf("\n");
                printf("| ");
                printWord(text(p));
                printf("\n");
                printf("| Disukai: %d\n",like(p));
                printf("\n");
            }
        }
        p = NEXT(p);
    }
   inverseList(&l); // balikin jadi list awal lagi
}

