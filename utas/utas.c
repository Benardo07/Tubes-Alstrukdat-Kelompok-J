#include <stdio.h>
#include <stdlib.h>
#include "../ADT/listlinier/listlinier.h"
#include "../kicauan/kicauan.h"
#include "utas.h"
#include "../kicauan/charmachine.h"
#include "../kicauan/wordmachine.h" // ini masih pake punyaku dulu

void buatUtas(List *l,Kicau *k, int *IdUtas,int IdKicau, Word author){
    if(!isEqual((*k).author,author)){
        printf("Utas ini bukan milik anda!\n");
    }
    else{
        if(indexOf(*l,IdKicau)!=IDX_UNDEF){
            printf("Kicau ini sudah berupa utas!\n");
        }
        else{
            insertLastKicau(l,*k);
            printf("Utas berhasil dibuat!\n");
            List lUtas = (*k).Utas;
            insertUtas(k,*IdUtas);
            setElmt(l,*IdUtas-1,*k);
            *IdUtas+=1;
        }
    }
}


void insertUtas(Kicau *k,int idUtas){
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
        len = length((*k).Utas);
        if (len==IDX_UNDEF){
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
        readWord(&input);
        printf("\n");

        char yes[2] = "YA";

        if (!isCharSame(yes,input.TabWord)){
            lanjut = false;
        }
    }

    printf("Utas selesai!\n");
}

boolean isCharSame(char *s1,char *s2){
    boolean sama = true;
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            sama = false;
        }
    }
    return sama; 
}

void utas(List l){ 
    Address p = l;
    int i = 1;
    while (p!=NULL){
        printf("     | INDEKS = %d\n",i);
        printf("     | ");
        printWord(author(p));
        printf("\n");
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
    printWord(k.author);
    printf("\n");
    printf("| ");
    TulisDATETIME(k.waktu);
    printf("\n");
    printf("| ");
    printWord(k.text);
    printf("\n");
    printf("\n");
    utas(k.Utas);
}

void sambungUtas(Kicau *k,int idx,int IdUtas,List *ListUtas, Word aut){
    Word input,text;
    int id,len;
    time_t currentTime;
    struct tm *localTime;

    len = length((*k).Utas);
    if (idx<=len){
        if(isEqual((*k).author,aut)){
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
            insertAt(&((*k).Utas),k2,idx-1);

            utas((*k).Utas);
            setElmt(ListUtas, IdUtas-1,*k);
            
        }
        else{
            printf("Anda tidak bisa menyambung utas ini!\n");
        }
    }
    else{
        printf("Indeks Terlalu Tinggi!\n");
    }
}

void hapusUtas(Kicau *k,int idx,int IdUtas,List ListUtas, Word aut){
    Word input,text;
    int id,len;
    time_t currentTime;
    struct tm *localTime;

    len = length((*k).Utas);
    if (idx<=len || indexOf((*k).Utas,idx)!=IDX_UNDEF){
        if(isEqual((*k).author,aut)){
            if(idx==0){
                printf("Anda tidak bisa menghapus kicauan utama!\n");
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