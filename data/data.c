#include <stdio.h>
#include "data.h"

ListPengguna LPengguna;
ListPengguna users[20];
// extern Graf Teman;
List LKicau;
List LUtas;
DrafStack sDraf;
Pengguna currentUser;
int IdCurrentUser;
int IdKicau=1;
int IdUtas=1;

boolean Muat(){
    char namafolder[100];
    boolean sukses = true;

    printf("\nSilahkan masukan folder konfigurasi untuk dimuat: ");
    StartSentence();
    strCat("./",currentWord.TabWord,namafolder); //menggunakan relative path
    //printf("%s\n", namafolder);

    if (!isDirectoryExist(namafolder)) {
        sukses = false;
        printf("\nFolder tidak ditemukan\n");
    } else {
        printf("\nFolder ditemukan\n");
        sukses = MuatPengguna(namafolder);
        sukses = MuatKicauan(namafolder);
        sukses = MuatDraf(namafolder);
        //dilanjutkan sukses = MuatTeman, etc
    }

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

            insertLastP(&LPengguna,p);
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
            IdKicau+=1;
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

boolean MuatUtas(char *namafolder){
    FILE *fUtas;
    boolean sukses = true;
    char namafile[100]; //asumsi batasan strlength

    strCat(namafolder,"/utas.config", namafile);
    fUtas = fopen(namafile,"r");

    if (fUtas == NULL) {
        printf("Tidak ada file konfigurasi utas.\n");
        sukses = false;
    } else {
        printf("File utas ditemukan\n");

        char line[280];
        int n, m, i, j;
        DATETIME date;

        fscanf(fUtas,"%d",&n);
        fgets(line,280,fUtas);

        for (i=0;i<n;i++){
            int id;
            fscanf(fUtas,"%d",&id);
            fgets(line,280,fUtas);
            insertLastKicau(&LUtas,getElmt(LKicau,id-1));

            fscanf(fUtas,"%d",&m);
            fgets(line,280,fUtas);
            Kicau p;
            for (j=0;j<m;j++){
                int idx,like;
                fscanf(fUtas,"%d",&idx);
                fgets(line,280,fUtas);
                p.id = idx;

                fgets(p.text.TabWord, sizeof(p.text.TabWord), fUtas);
                p.text.Length = strlength(p.text.TabWord);

                fgets(p.author.TabWord, sizeof(p.author.TabWord), fUtas);
                p.author.Length = strlength(p.text.TabWord);
                p.author.TabWord[strlength(p.author.TabWord)] = '\0';

                int h,m,s,d,b,y;
                fscanf(fUtas, "%d/%d/%d %d:%d:%d", &d, &b, &y, &h, &m, &s);
                fgets(line,280,fUtas);
                CreateDATETIME(&date,d,b,y,h,m,s);
                p.waktu = date;
                Kicau k;
                k= getElmt(LUtas,i);
                insertLastKicau(&(k.Utas),p);
            }
            setElmt(&LUtas,IdUtas-1,p);
            IdUtas+=1;
        }
    }

    fclose(fUtas);
    return sukses;
}

boolean MASUK() {
    //return true jika tutup program
    char nama[21];
    boolean loop = true;
    int idx;
    while (loop) {
        printf("\nMasukkan nama:\n");
        StartSentence();
        strCpy(currentWord.TabWord,nama);

        idx = searchNama(LPengguna,nama);
        if (idx == IDX_UNDEF){
            printf("\nWah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        } else {
            loop = false;
        }
    }

    char sandi[21];
    loop = true;
    while(loop){
        printf("\nMasukkan kata sandi:\n");
        StartSentence();
        strCpy(currentWord.TabWord,sandi);

        if (!checkSandi(LPengguna,idx,sandi)) {
            printf("\nWah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
        } else {
            loop = false;
            currentUser = ELMT(LPengguna,idx);
            IdCurrentUser = idx + 1;
            printf("\nAnda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", NAMA(currentUser));
        }
    }

    //printPengguna(currentUser);
    //printf("%d\n", IdCurrentUser);

    //*************************************MAIN-LOOP******************************************//
    boolean keluar = false;
    loop = true;
    while (loop) {
        printf("\n>> ");
        char *operasi;

        STARTWORD(); //Operasi hanya 1 kata (jika beberapa huruf, dipisah simbol '_')
        operasi = currentWord.TabWord;

        if (isStrEqual(operasi, "MASUK")){
            printf("\nWah Anda sudah masuk. Keluar dulu yuk!\n");
        } else if (isStrEqual(operasi, "KELUAR")){
            printf("\nAnda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
            loop = false;
        } else if (isStrEqual(operasi, "DAFTAR")){
            printf("\nAnda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
        } else if (isStrEqual(operasi, "TUTUP_PROGRAM")){
            printf("\nAnda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
            loop = false;
            keluar = true;
        } //else if (isStrEqual(operasi, "_____")) { } <--- dilanjutkan
        else {
            printf("\nPerintah invalid.\n");
        }
    }
    return keluar;
}

void DAFTAR(){
    boolean loop = true;

    // terima nama
    char nama[21];
    while (loop) {
        printf("\nMasukkan nama:\n");
        StartSentence();
        strCpy(currentWord.TabWord,nama);

        if (searchNama(LPengguna, nama) != IDX_UNDEF) {
            printf("\nWah, sayang sekali nama tersebut telah diambil. \n");
        } else {
            loop = false;
        }
    }

    // terima sandi
    char sandi[21];
    printf("\nMasukkan kata sandi:\n");
    StartSentence();
    strCpy(currentWord.TabWord,sandi);

    Pengguna p;
    newPengguna(&p, nama, sandi);

    insertLastP(&LPengguna,p);

    printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
}
