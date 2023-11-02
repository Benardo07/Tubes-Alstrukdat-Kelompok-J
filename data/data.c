#include <stdio.h>
#include "data.h"

ListPengguna LPengguna;
ListPengguna users[20];
// extern Graf Teman;
List LKicau;
DrafStack sDraf;
Pengguna currentUser;
int JumlahId ;



boolean Muat(){
    char namafolder[100];
    boolean sukses = true;

    printf("\nSilahkan masukan folder konfigurasi untuk dimuat: ");
    STARTWORD();
    strCat("./",currentWord.TabWord,namafolder); //menggunakan relative path
    //printf("%s\n", namafolder);

    if (!isDirectoryExist(namafolder)) {
        sukses = false;
        printf("\nFolder tidak ditemukan\n");
    } else printf("\nFolder ditemukan\n");
        sukses = MuatPengguna(namafolder);
        sukses = MuatKicauan(namafolder);
        sukses = MuatDraf(namafolder);
        //dilanjutkan sukses = MuatTeman, etc

    return sukses;
}

boolean MuatPengguna(char *namafolder){
    FILE *fPengguna;
    boolean sukses = true;
    char namafile[100]; //asumsi batasan strlength

    strCat(namafolder,"/pengguna.config", namafile);
    //printf("%s\n",namafile);
    fPengguna = fopen(namafile,"r");

    if (fPengguna == NULL) {
        printf("Tidak ada file konfigurasi pengguna.\n");
        sukses = false;
    } else {
        printf("File pengguna ditemukan\n");

        char line[135];
        int n, i, j;

        fscanf(fPengguna,"%d",&n);
        fgets(line,135,fPengguna);

        for (i=0;i<n;i++){
            Pengguna p;
            fgets(line,135,fPengguna);
            strCpy(line,NAMA(p));

            fgets(line,135,fPengguna);
            strCpy(line,PASSWORD(p));

            fgets(line,135,fPengguna);
            strCpy(line,BIO(p));

            fgets(line,135,fPengguna);
            strCpy(line,HP(p));

            fgets(line,135,fPengguna);
            strCpy(line,WETON(p));

            fgets(line,135,fPengguna);
            strCpy(line,JENIS(p));

            for (j=0;j<5;j++) {
                fgets(line,135,fPengguna);
                strCpy(line,FOTO(p)[j]);
            }

            insertLast(&LPengguna,p);
        }
    }

    fclose(fPengguna);
    return sukses;
}

boolean MuatKicauan(char *namafolder){
    FILE *fKicauan;
    boolean sukses = true;
    char namafile[100]; //asumsi batasan strlength

    strCat(namafolder,"/kicauan.config", namafile);
    fKicauan = fopen(namafile,"r");

    if (fKicauan == NULL) {
        printf("Tidak ada file konfigurasi kicauan.\n");
        sukses = false;
    } else {
        printf("File kicauan ditemukan\n");

        char line[280];
        int n, i, j;
        DATETIME date;

        fscanf(fKicauan,"%d",&n);
        fgets(line,280,fKicauan);

        for (i=0;i<n;i++){
            Kicau p;
            int id,like;

            fscanf(fKicauan,"%d",&id);
            fgets(line,280,fKicauan);
            p.id = id;

            fgets(p.text.TabWord, sizeof(p.text.TabWord), fKicauan);
            p.text.Length = strlength(p.text.TabWord);

            fscanf(fKicauan,"%d",&like);
            fgets(line,280,fKicauan);
            p.like = like;

            fgets(p.author.TabWord, sizeof(p.author.TabWord), fKicauan);
            p.author.Length = strlength(p.text.TabWord);
            p.author.TabWord[strlength(p.author.TabWord)] = '\0';

            int h,m,s,d,b,y;
            fscanf(fKicauan, "%d/%d/%d %d:%d:%d", &d, &b, &y, &h, &m, &s);
            fgets(line,280,fKicauan);
            CreateDATETIME(&date,d,b,y,h,m,s);
            p.waktu = date;

            insertLastKicau(&LKicau,p);
            JumlahId+=1;
        }
    }

    fclose(fKicauan);
    return sukses;
}

boolean MuatDraf (char *namafolder){
    FILE *fDraf;
    boolean sukses = true;
    char namafile[100]; //asumsi batasan strlength

    strCat(namafolder,"/draf.config", namafile);
    fDraf = fopen(namafile,"r");

    if(fDraf == NULL){
        printf("Tidak ada file konfigurasi draf.\n");
        sukses = false;
    }else{
        printf("File draf ditemukan.\n");
        char line[280];
        int n, j;

        fscanf(fDraf,"%d\n",&n);
        int i ;
        for(i = 0 ; i < n ; i++){
            Draf d;
            fscanf(fDraf,"%d\n",&Id(d));

            fgets(line,280,fDraf);
            strCpy(line,DrafTweet(d));

            fgets(line,280,fDraf);
            strCpy(line,Author(d));

            fgets(line,280,fDraf);
            int temp = sscanf(line, "%d/%d/%d %d:%d:%d", &Day(DateTime(d)), &Month(DateTime(d)), &Year(DateTime(d)), &Hour(Time(DateTime(d))) ,&Minute(Time(DateTime(d))) , &Second(Time(DateTime(d))));
            Push(&sDraf,d);
        }
        
    }
    fclose(fDraf);
    return sukses;
}