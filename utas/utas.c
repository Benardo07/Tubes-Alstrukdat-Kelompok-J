#include <stdio.h>
#include <stdlib.h>
#include "../ADT/listlinier/listlinier.h"
#include "../kicauan/kicauan.h"
#include "utas.h"
#include "../ADT/mesinkata/wordmachine.h"
#include "../ADT/mesinkarakter/charmachine.h"
#include "../primitif/primitif.h"
#include "../teman/teman.h"
#include "../ADT/liststatik/listpengguna.h"

void buatUtas(List *l,Kicau *k, int *IdUtas,int IdKicau, char *author){
    if(!isStrEqual((*k).author, author)){
        printf("Utas ini bukan milik anda!\n");
    }
    else{
        if((*k).idutas != -999){
            printf("Kicau ini sudah berupa utas!\n");
        }
        else{
            printf("Utas berhasil dibuat!\n");
            insertUtas(k);
            k->idutas = *IdUtas;
            setElmt(l,IdKicau,*k); 
            *IdUtas+=1;
        }
    }
}


void insertUtas(Kicau *k){
    Word input,text;
    int id,len;
    boolean lanjut = true;
    time_t currentTime;
    struct tm *localTime;

    while(lanjut){
        boolean space = true;
        Word text;
        printf("Masukkan kicauan:\n");
        readKicau(&text);
        printf("\n");
        len = length((*k).Utas);
        if (len==IDXUNDEF){
            id = 1;
        } else{
            id = len+1;
        }

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

        Kicau k2;
        CreateKicau(&k2,id,0,text,(*k).author,d);
        insertLastKicau(&((*k).Utas),k2);
        
        printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
        char *operasi;
        StartSentence();
        operasi = currentSentence.TabWord;
        printf("\n");


        while (!(isStrEqual(operasi,"YA")) && !(isStrEqual(operasi,"TIDAK")) ){
            printf("Perintah Tidak Dikenali\n");
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
            StartSentence();
            operasi = currentSentence.TabWord;
            printf("\n");
        }
        if (isStrEqual(operasi,"TIDAK")){
            lanjut = false;
        }
    }
    printf("Utas selesai!\n");
}


void utas(List l){ 
    Address p = l;
    int i = 1;
    while (p!=NULL){
        printf("     | INDEKS = %d\n",i);
        printf("     | ");
        printf("%s\n",author(p));
        printf("     | ");
        TulisDATETIME(waktu(p));
        printf("\n");
        printf("     | ");
        printWord(text(p));
        printf("\n");
        printf("\n");
        p = NEXT(p);
        i+=1;
    }
}

void perutasan(Kicau k){ 
    printf("| ID = %d\n",k.id);
    printf("| ");
    printf("%s\n",k.author);
    printf("| ");
    TulisDATETIME(k.waktu);
    printf("\n");
    printf("| ");
    printWord(k.text);
    printf("\n");
    printf("\n");
    utas(k.Utas);
}

void sambungUtas(Kicau *k,int idx,int IdUtas,List *ListUtas, char *aut){
    Word input,text;
    int id,len;
    time_t currentTime;
    struct tm *localTime;

    len = length((*k).Utas);
    if (idx<=len+1){
        if(isStrEqual((*k).author,aut)){
            boolean space = true;
            Word text;
            printf("Masukkan kicauan:\n");
            readKicau(&text);
            printf("\n");
        
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

            Kicau k2;
            CreateKicau(&k2,id,0,text,(*k).author,d);
            if(idx==1){
                insertFirst(&((*k).Utas),k2);
            }
            else{
                insertAt(&((*k).Utas),k2,idx-1);
            }
            int kic = cekutas(*ListUtas,IdUtas);
            setElmt(ListUtas,kic,*k);
            printf("Utas berhasil disambung!\n");
        }
        else{
            printf("Anda tidak bisa menyambung utas ini!\n");
        }
        // ELMTDIN(*ListUtas,IdUtas-1) = *k;
        // utas(ELMTDIN(*ListUtas,IdUtas-1).Utas);
    }
    else{
        printf("Indeks Terlalu Tinggi!\n");
    }
}

void hapusUtas(Kicau *k,int idx, char *aut){
    Word input,text;
    int id,len;
    time_t currentTime;
    struct tm *localTime;

    len = length((*k).Utas);
    if (idx<=len){
        if(isStrEqual((*k).author,aut)){
            if(idx==0){
                printf("Anda tidak bisa menghapus kicauan utama!\n");
            }
            else if(idx==1){
                Kicau val;
                deleteFirst(&((*k).Utas),&val);
                printf("Kicauan sambungan berhasil dihapus!\n");
            }
            else{
                deleteAt(&((*k).Utas),idx-1,k);
                printf("Kicauan sambungan berhasil dihapus!\n");
            }
        }
        else{
            printf("Anda tidak bisa menghapus kicauan dalam utas ini!!\n");
        }
    }
    else{
        printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n",idx);
    }
}