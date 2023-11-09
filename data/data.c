#include <stdio.h>
#include "data.h"
#include "../ADT/mesinkata/wordmachine.h"
#include "../ADT/mesinkarakter/charmachine.h"
#include "../ADT/listlinier/listlinier.h"
#include "../ADT/graf/graf.h"

ListPengguna LPengguna;
ListPengguna users[20];
Graf Teman;
List LKicau;
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
        sukses = MuatUtas(namafolder);
        // sukses = MuatDraf(namafolder);
        // sukses = MuatBalasan(namafolder);
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
            createPengguna(&p);
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
                strCpy(line,FOTO(p).matriks[j]);
            }

            insertLastP(&LPengguna,p);
        }

        int edge = 0;
        for(i=0; i<n; ++i) {
            for(j=0; j<n; ++j) {
                fscanf(fPengguna, "%d", &edge);
                ELMT_GRAPH(Teman, i, j) = edge;
            }
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

            fgets(line,280,fKicauan);
            strCpy(line,p.author);


            int h,m,s,d,b,y;
            fscanf(fKicauan, "%d/%d/%d %d:%d:%d", &d, &b, &y, &h, &m, &s);
            fgets(line,280,fKicauan);
            CreateDATETIME(&date,d,b,y,h,m,s);
            p.waktu = date;
            p.idutas = -999;
            p.Utas = NULL;
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
            DrafStack tempStack;
            CreateEmptyDrafStack(&tempStack);
            fgets(line,280,fDraf);
            char username[20];
            int tempJumlah;
            strCpyTwoElmt(line,username,&tempJumlah);
            int index = searchNama(LPengguna,username);
            JMLHDRAF(ELMT(LPengguna,index)) = tempJumlah;
            // setJumlahDraf(&LPengguna,username,tempJumlah);
            int k;
            for (k = 0; k < tempJumlah;k++){
                Draf d;
                fgets(line, 280, fDraf);
                strCpy(line,DrafTweet(d));

                fscanf(fDraf, "%d/%d/%d %d:%d:%d", &Day(DateTime(d)), &Month(DateTime(d)), &Year(DateTime(d)), &Hour(Time(DateTime(d))) ,&Minute(Time(DateTime(d))) , &Second(Time(DateTime(d))));
                fgets(line,280,fDraf);

                PushDrafStack(&tempStack,d);
            }

            copyReverse(tempStack,&DRAF(ELMT(LPengguna,searchNama(LPengguna,username))));          
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
            fgets(line,50,fUtas);

            fscanf(fUtas,"%d",&m);
            fgets(line,280,fUtas);
            Kicau utas = getElmt(LKicau,id-1);
            utas.idutas = IdUtas;
            utas.Utas = NULL;
            for (j=0;j<m;j++){
                Kicau p;
                fgets(p.text.TabWord, sizeof(p.text.TabWord), fUtas);
                p.text.Length = strlength(p.text.TabWord);

                fgets(line,280,fUtas);
                strCpy(line,p.author);

                int h,m,s,d,b,y;
                fscanf(fUtas, "%d/%d/%d %d:%d:%d", &d, &b, &y, &h, &m, &s);
                fgets(line,280,fUtas);
                CreateDATETIME(&date,d,b,y,h,m,s);
                p.waktu = date;
                insertLastKicau(&(utas.Utas),p);
                

            }
            setElmt(&LKicau,id-1,utas);
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
        } else if (isStrEqual(operasi, "KICAU")) { 
            insertKicau(&LKicau,currentUser.nama,&IdKicau);
        }
        else if (isStrEqual(operasi, "KICAUAN")) { 
            kicauan(LKicau,LPengguna);
        }
        else if (isStrEqual(operasi, "SUKA_KICAUAN")) { 
            int id; 
            id = ambilangka(operasi);
            sukaKicau(&LKicau,LPengguna,id);
        }
        else if (isStrEqual(operasi, "UBAH_KICAUAN")) { 
            int id;
            id = ambilangka(operasi);
            editKicau(&LKicau,id,currentUser.nama);
        }
        else if (isStrEqual(operasi, "UTAS")) { 
            int id;
            Kicau k1;
            id = ambilangka(operasi);            
            if(id>IdKicau-1){
                printf("Kicauan Tidak Ditemukan!\n");
            }
            else{
                k1 = getElmt(LKicau,id-1);
                buatUtas(&LKicau,&k1,&IdUtas,id-1,currentUser.nama);
            }
        }
        else if (isStrEqual(operasi, "SAMBUNG_UTAS")) { 
            int id,id2;
            Kicau k1;
            id = ambilangka(operasi);
            id2 = ambilangka2(operasi);
            if(id>IdUtas-1){
                printf("Utas Tidak Ditemukan!\n");
            }
            else{
                int idkic = cekutas(LKicau,id);
                k1 = getElmt(LKicau,idkic);
                sambungUtas(&k1,id2,id,&LKicau,currentUser.nama);
                setElmt(&LKicau,idkic,k1);
            }
        }
        else if (isStrEqual(operasi, "HAPUS_UTAS")) { 
            int id,id2;
            Kicau k1;
            id = ambilangka(operasi);
            id2 = ambilangka2(operasi);
            if(id>IdUtas-1){
                printf("Utas Tidak Ditemukan!\n");
            }
            else{
                int idkic = cekutas(LKicau,id);
                k1 = getElmt(LKicau,idkic);
                hapusUtas(&k1,id2,currentUser.nama);
                setElmt(&LKicau,idkic,k1);
            }
        }
        else if (isStrEqual(operasi, "CETAK_UTAS")) { 
            int id;
            id = ambilangka(operasi);
            if(id>IdUtas-1){
                printf("Utas Tidak Ditemukan!\n");
            }
            else{
                Kicau k1;
                int idkic = cekutas(LKicau,id);
                k1 = getElmt(LKicau,idkic);
                perutasan(k1);
            }
        }
        //else if (isStrEqual(operasi, "_____")) { } <--- dilanjutkan
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

boolean MuatBalasan (char *namafolder){
    FILE *fBalas;
    boolean sukses = true;
    char namafile[100]; //asumsi batasan strlength

    strCat(namafolder,"/balasan.config", namafile);
    fBalas = fopen(namafile,"r");

    if(fBalas == NULL){
        printf("Tidak ada file konfigurasi balasan.\n");
        sukses = false;
    }else{
        printf("File konfigurasi balasan berhasil ditemukan.\n");
    }

    char line[280];
    int n;

    fscanf(fBalas,"%d\n",&n);

    int i;
    for (i = 0; i < n ; i++){
        int idkic;
        fscanf(fBalas,"%d\n",&idkic);
        int z,j;
        fscanf(fBalas,"%d\n",&z);
        for(j = 0; j < z; j++){
            int yangDiBalas , yangBalas; 
            fscanf(fBalas,"%d %d\n",&yangDiBalas,&yangBalas);
            char tweetBalasan[280];
            fgets(line,280,fBalas);
            strCpy(line,tweetBalasan);
            char penulis[20];
            fgets(line,280,fBalas);
            strCpy(line,penulis);
            int h,m,s,d,b,y;
            fscanf(fBalas, "%d/%d/%d %d:%d:%d", &d, &b, &y, &h, &m, &s);
            fgets(line,280,fBalas);
            DATETIME date;
            CreateDATETIME(&date,d,b,y,h,m,s);
            Balasan B;
            CreateBalasan(&B,yangBalas,tweetBalasan,penulis,date);
            Tree T = newTree(B,1000);
            if(yangDiBalas == -1){
                AddBalasanKicauAt(&LKicau,idkic,T);
            }else{
                Kicau tempKicau = getElmt(LKicau,indexOf(LKicau,idkic));
                insertLastDinTree(&CHILDREN(findBalasanInTree(tempKicau.Balas,yangDiBalas)),T);
            }
        }
    }
    return sukses;
}