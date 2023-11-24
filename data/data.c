#include <stdio.h>
#include "data.h"
#include "../ADT/mesinkata/wordmachine.h"
#include "../ADT/mesinkata/mesinkalimat.h"
#include "../ADT/mesinkarakter/charmachine.h"
#include "../ADT/listlinier/listlinier.h"
#include "../ADT/matriks/foto.h"
#include "../ADT/graf/graf.h"
#include "../kicauan/kicauan.h"
#include "../ADT/datetime/datetime.h"
#include "../ADT/datetime/time.h"
#include "../teman/teman.h"
#include "../draf/draf.h"
#include "../balasan/balasan.h"
#include "../profil/profil.h"
#include "../permintaan/requests.h"

Sentence test;
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
    strCat("./",currentSentence.TabWord,namafolder); //menggunakan relative path

    if (!isDirectoryExist(namafolder)) {
        sukses = false;
        printf("\nFolder tidak ditemukan\n");
    } else {
        printf("\nFolder ditemukan\n");
        
        deleteAll(&LKicau);
        CreateListPengguna(&LPengguna);
        createGraph(&Teman);

        sukses = MuatPengguna(namafolder);
        sukses = MuatDraf(namafolder);
        sukses = MuatKicauan(namafolder);
        sukses = MuatUtas(namafolder);
        sukses = MuatBalasan(namafolder);

        printf("Data berhasil dimuat.\n");
    }

    return sukses;
}

boolean MuatPengguna(char *namafolder){
    FILE *fPengguna;
    boolean sukses = true;
    char namafile[100]; //asumsi batasan strlength

    strCat(namafolder,"/pengguna.config", namafile);

    fPengguna = fopen(namafile,"r");

    if (fPengguna == NULL) {
        printf("Tidak ada file konfigurasi pengguna.\n");
        sukses = false;
    } else {
        printf("File pengguna ditemukan\n");

        STARTFILE(fPengguna);
        int n, i, j, k;

        readLineFile();
        n = strToInt(currentSentence.TabWord);
        for (i=0;i<n;i++){
            Pengguna p;
            createPengguna(&p);
            ID(p) = i+1;

            readLineFile();
            strCpy(currentSentence.TabWord,NAMA(p));

            readLineFile();
            strCpy(currentSentence.TabWord,PASSWORD(p));

            readLineFile();
            strCpy(currentSentence.TabWord,BIO(p));

            readLineFile();
            strCpy(currentSentence.TabWord,HP(p));

            readLineFile();
            strCpy(currentSentence.TabWord,WETON(p));

            readLineFile();
            strCpy(currentSentence.TabWord,JENIS(p));

            for (j=0;j<5;j++) {
                for (k=0; k<10; k++) {
                    FOTO(p).matriks[j][k] = currentChar;
                    ADVFILE();
                    if(k == 9){
                        while (currentChar == ' ')
                        {
                            ADVFILE();
                        }
                        
                    }
                    ADVFILE();
                }
            }

            ROW_EFF(FOTO(p)) = CAP;
            COL_EFF(FOTO(p)) = 2*CAP;

            insertLastP(&LPengguna,p);
        }

        createGraph(&Teman);
        Teman.nodes = n;
        int edge, temanUser;
        for(i=0; i<n; ++i) {
            temanUser = 0;
            for(j=0; j<n; ++j) {
                edge = currentChar - '0';
                ELMT_GRAPH(Teman, i, j) = edge;
                if (edge == 1) {
                    Teman.edges++;
                    if (i != j) temanUser++;
                }
                ADVFILE();
                ADVFILE();
            }
            TOTALFRIENDS(ELMT(LPengguna, i)) = temanUser;
        }

        readLineFile();
        n = strToInt(currentSentence.TabWord);
        while(n--) {
            int id_1, id_2, teman;
            id_1 = currentChar - '0'; ADVFILE(); ADVFILE();
            id_2 = currentChar - '0'; ADVFILE(); ADVFILE();
            teman = currentChar - '0'; ADVFILE(); ADVFILE();
            infotype request = newPrioElmt(id_1, teman);
            EnqueuePrio(&FREQ(ELMT(LPengguna, id_2-1)), request);
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

        int n, i;
        DATETIME date;
    
        STARTFILE(fKicauan);
        readLineFile();
        n = strToInt(currentSentence.TabWord);
        for (i=0;i<n;i++){
            Kicau p;
            int like;

            readLineFile();
            p.id = i+1;

            readLineFile();
            strCpy(currentSentence.TabWord,p.text.TabWord);
            p.text.Length = strlength(p.text.TabWord);

            readLineFile();
            like = strToInt(currentSentence.TabWord);
            p.like = like;

            readLineFile();
            strCpy(currentSentence.TabWord,p.author);

            int h,m,s,d,b,y;
            readLineFile();
            sscanf(currentSentence.TabWord, "%d/%d/%d %d:%d:%d", &d, &b, &y, &h, &m, &s);
            CreateDATETIME(&date,d,b,y,h,m,s);
            p.waktu = date;
            p.idutas = -999;
            p.Utas = NULL;
            p.Balas = newTree(CreateRootBalasan(),1000);
            p.lastIDBalas = 0;
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
        int n, i;
        DATETIME date;
        STARTFILE(fDraf);
        readLineFile();
        n = strToInt(currentSentence.TabWord);
        for(i = 0 ; i < n ; i++){
            DrafStack tempStack;
            CreateEmptyDrafStack(&tempStack);
            readLineFile();
            char username[20];
            int tempJumlah;
            strCpyTwoElmt(currentSentence.TabWord,username,&tempJumlah);
            int index = searchNama(LPengguna,username);
            JMLHDRAF(ELMT(LPengguna,index)) = tempJumlah;
            int k;
            for (k = 0; k < tempJumlah;k++){
                Draf dtemp;
                readLineFile();
                strCpy(currentSentence.TabWord,DrafTweet(dtemp));

                int h,m,s,d,b,y;
                readLineFile();
                sscanf(currentSentence.TabWord, "%d/%d/%d %d:%d:%d", &d, &b, &y, &h, &m, &s);
                CreateDATETIME(&date,d,b,y,h,m,s);

                DateTime(dtemp) = date;
                // fscanf(fDraf, "%d/%d/%d %d:%d:%d", &Day(DateTime(d)), &Month(DateTime(d)), &Year(DateTime(d)), &Hour(Time(DateTime(d))) ,&Minute(Time(DateTime(d))) , &Second(Time(DateTime(d))));
                // fgets(line,280,fDraf);

                PushDrafStack(&tempStack,dtemp);
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

   
        int n, m, i, j;
        DATETIME date;

        STARTFILE(fUtas);
        readLineFile();
        n = strToInt(currentSentence.TabWord);
        for (i=0;i<n;i++){
            int id;

            readLineFile();
            id = strToInt(currentSentence.TabWord);

            readLineFile();
            m = strToInt(currentSentence.TabWord);

            Kicau utas = getElmt(LKicau,id-1);
            utas.idutas = IdUtas;
            utas.Utas = NULL;
            for (j=0;j<m;j++){
                Kicau p;
               
                readLineFile();
                strCpy(currentSentence.TabWord,p.text.TabWord);
                p.text.Length = strlength(p.text.TabWord);
                
                readLineFile();
                strCpy(currentSentence.TabWord,p.author);
    
                readLineFile();
                int h,m,s,d,b,y;
                sscanf(currentSentence.TabWord, "%d/%d/%d %d:%d:%d", &d, &b, &y, &h, &m, &s);

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

boolean MuatBalasan(char* namafolder) {
    FILE *fBalasan;
    boolean sukses = true;
    char namafile[100]; //asumsi batasan strlength

    strCat(namafolder,"/balasan.config", namafile);
    fBalasan = fopen(namafile,"r");

    if (fBalasan == NULL) {
        printf("Tidak ada file konfigurasi balasan.\n");
        sukses = false;
    } else {
        printf("File balasan ditemukan\n");

        DATETIME date;
        int n, m, i, j;
        STARTFILE(fBalasan);
        readLineFile();
        n = strToInt(currentSentence.TabWord);

        for (i=0;i<n;i++){
            int idKicau; 
            readLineFile();
            idKicau = strToInt(currentSentence.TabWord);

            readLineFile();
            m = strToInt(currentSentence.TabWord);
            int idParent, idBalasan;
            int idTemp = 0;
            for(j=0; j<m; ++j) {
                 
                // readLineFile();
                // ambilDuaNum(currentSentence.TabWord,&idParent,&idBalasan);
                readTwoValuesLine(&idParent,&idBalasan);
                Balasan B;
                char text[280]; 
                readLineFile();
                strCpy(currentSentence.TabWord,text);

                char author[20];
                readLineFile();
                strCpy(currentSentence.TabWord,author);

                int h,m,s,d,b,y;
                readLineFile();
                sscanf(currentSentence.TabWord, "%d/%d/%d %d:%d:%d", &d, &b, &y, &h, &m, &s);
                CreateDATETIME(&date,d,b,y,h,m,s);

                CreateBalasan(&B, idBalasan, text, author, date);
                Tree T = newTree(B, 1000);

                if(idParent == -1) AddBalasanKicauAt(&LKicau,idKicau,T);
                else insertLastDinTree(&CHILDREN(findBalasanInTree(getElmt(LKicau, idKicau-1).Balas,idParent)),T);

                if(idTemp < idBalasan){
                    idTemp = idBalasan;
                }
            }

            setLastId(&LKicau,idKicau,idTemp);
        }
    }

    fclose(fBalasan);
    return sukses;
}

void SimpanPengguna(char* namaFolder) {
    FILE *fPengguna;
    char pathPengguna[100];
    strCat(namaFolder, "/pengguna.config", pathPengguna);

    fPengguna = fopen(pathPengguna, "w");
    fprintf(fPengguna, "%d\n", listLengthP(LPengguna));

    int i, j, k, requestCount = 0;

    PrioQueue q; CreatePrioQueue(&q);
    for(i=0; i<listLengthP(LPengguna); ++i) {
        Pengguna p = ELMT(LPengguna, i);
        fprintf(fPengguna, "%s\n", NAMA(p));
        fprintf(fPengguna, "%s\n", PASSWORD(p));
        fprintf(fPengguna, "%s\n", BIO(p));
        fprintf(fPengguna, "%s\n", HP(p));
        fprintf(fPengguna, "%s\n", WETON(p));
        fprintf(fPengguna, "%s\n", JENIS(p));
        for(j=0; j<5; ++j) {
            for(k=0; k<9; ++k) fprintf(fPengguna, "%c ", FOTO(p).matriks[j][k]);
            fprintf(fPengguna, "%c\n", FOTO(p).matriks[j][9]);
        }
        if (!IsPrioQueueEmpty(FREQ(p))) {
            infotype temp = newPrioElmt(i, 1);
            requestCount += lengthPrioQueue(FREQ(p));
            EnqueuePrio(&q, temp);
        }
    }

    for(i=0; i<SIMPUL(Teman); ++i) {
        for(j=0; j<SIMPUL(Teman)-1; ++j) {
            fprintf(fPengguna, "%d ", ELMT_GRAPH(Teman, i, j));
        }
        fprintf(fPengguna, "%d\n", ELMT_GRAPH(Teman, i, SIMPUL(Teman)-1));
    }

    fprintf(fPengguna, "%d\n", requestCount);
    while (!IsPrioQueueEmpty(q)) {
        infotype idx; DequeuePrio(&q, &idx);
        Pengguna p = ELMT(LPengguna, idx.userId);

        PrioQueue friendRequests = FREQ(p);
        while(!IsPrioQueueEmpty(friendRequests)) {
            infotype temp; DequeuePrio(&friendRequests, &temp);
            fprintf(fPengguna, "%d %d %d\n", temp.userId, ID(p), temp.prio);
        }
    }

    fclose(fPengguna);
}

void SimpanKicauan(char* namaFolder) {
    FILE *fKicauan;
    char pathKicauan[100];
    strCat(namaFolder, "/kicauan.config", pathKicauan);

    fKicauan = fopen(pathKicauan, "w");
    fprintf(fKicauan, "%d\n", length(LKicau));

    for(int i=0; i<length(LKicau); ++i) {
        Kicau k = getElmt(LKicau, i);
        fprintf(fKicauan, "%d\n", k.id);
        fprintf(fKicauan, "%s\n", k.text.TabWord);
        fprintf(fKicauan, "%d\n", k.like);
        fprintf(fKicauan, "%s\n", k.author);
        SimpanDATETIME(fKicauan, k.waktu);
    }

    fclose(fKicauan);
}

void SimpanDraf(char* namaFolder) {
    FILE* fDraf;
    char pathDraf[100];
    strCat(namaFolder, "/draf.config", pathDraf);

    fDraf = fopen(pathDraf, "w");

    PrioQueue q; CreatePrioQueue(&q);
    int n = 0, i;
    for(i=0; i<listLengthP(LPengguna); ++i) {
        if (JMLHDRAF(ELMT(LPengguna,i)) > 0) {
            infotype temp = newPrioElmt(i, 1);
            EnqueuePrio(&q, temp);
            n++;
        }
    }
    fprintf(fDraf, "%d\n", n);

    while(!IsPrioQueueEmpty(q)) {
        infotype index; DequeuePrio(&q, &index);
        Pengguna p = ELMT(LPengguna, index.userId);
        fprintf(fDraf, "%s %d\n", NAMA(p), JMLHDRAF(p));

        DrafStack temp; CreateEmptyDrafStack(&temp);
        copyReverse(DRAF(p),&temp);
        DrafStack s; CreateEmptyDrafStack(&s);
        while(!IsEmptyDrafStack(temp)) {
            Draf d; PopDrafStack(&temp, &d);
            PushDrafStack(&s, d);
        }

        while(!IsEmptyDrafStack(s)) {
            Draf d; PopDrafStack(&s, &d);
            fprintf(fDraf, "%s\n", DrafTweet(d));
            SimpanDATETIME(fDraf, DateTime(d));
        }
    }

    fclose(fDraf);
}

void SimpanUtas(char* namaFolder) {
    FILE *fUtas;
    char pathUtas[100];
    strCat(namaFolder, "/utas.config", pathUtas);

    fUtas = fopen(pathUtas, "w");
    Address p = LKicau;
    PrioQueue q; CreatePrioQueue(&q);

    while(p != NULL) {
        if (FirstUtas(p) != NULL) {
            int cnt = 0;
            Address loc = FirstUtas(p);
            while(loc != NULL) {cnt++; loc = NEXT(loc);}

            infotype jumlahUtas = newPrioElmt(cnt, 1);
            EnqueuePrio(&q, jumlahUtas);
        }
        p = NEXT(p);
    }

    fprintf(fUtas, "%d\n", lengthPrioQueue(q));
    p = LKicau;
    while(p != NULL) {
        if (FirstUtas(p) != NULL) {
            infotype temp; DequeuePrio(&q, &temp);
            fprintf(fUtas, "%d\n", id(p));
            fprintf(fUtas, "%d\n", temp.userId);

            Address loc = FirstUtas(p);
            while(loc != NULL) {
                Kicau k = INFO(loc);
                fprintf(fUtas, "%s\n", k.text.TabWord);
                fprintf(fUtas, "%s\n", k.author);
                SimpanDATETIME(fUtas, k.waktu);

                loc = NEXT(loc);
            }
        }
        p = NEXT(p);
    }

    fclose(fUtas);
}

void SimpanBalasanRekursif(FILE *fBalasan, Tree T, int id) {
    if (T == NULL) return;

    for(int i=getFirstIdxDinTree(CHILDREN(T)); i<=getLastIdxDinTree(CHILDREN(T)); ++i) {
        Balasan B = BALASAN(ELMTDINTREE(CHILDREN(T), i));
        fprintf(fBalasan, "%d %d\n", id, B.id);
        fprintf(fBalasan, "%s\n", B.tweet);
        fprintf(fBalasan, "%s\n", B.writer);
        SimpanDATETIME(fBalasan, B.d);
        SimpanBalasanRekursif(fBalasan, ELMTDINTREE(CHILDREN(T), i), B.id);
    }
}

void SimpanBalasan(char* namaFolder) {
    FILE *fBalasan;
    char pathBalasan[100];
    strCat(namaFolder, "/balasan.config", pathBalasan);

    fBalasan = fopen(pathBalasan, "w");
    inverseList(&LKicau);
    PrioQueue q; CreatePrioQueue(&q);

    int i;
    for(i=0; i<length(LKicau); ++i){
        Kicau k = getElmt(LKicau, i);
        if (NEFFDINTREE(CHILDREN(k.Balas)) > 0) {
            infotype temp = newPrioElmt(k.id, 1);
            EnqueuePrio(&q, temp);
        }
    }

    fprintf(fBalasan, "%d\n", lengthPrioQueue(q));
    inverseList(&LKicau);
    while(!IsPrioQueueEmpty(q)) {
        infotype temp; DequeuePrio(&q, &temp);
        fprintf(fBalasan, "%d\n", temp.userId);
        Tree T = getElmt(LKicau, temp.userId-1).Balas;
        
        fprintf(fBalasan, "%d\n", nbElmt(T));
        SimpanBalasanRekursif(fBalasan, T, -1);
    }
    inverseList(&LKicau);
    fclose(fBalasan);
}

boolean Simpan() {
    boolean sukses = true;

    char namaFolder[100];
    printf("\nMasukkan nama folder penyimpanan: ");
    StartSentence();
    strCat("./", currentSentence.TabWord, namaFolder);

    if (isDirectoryExist(namaFolder)) {
        printf("Anda akan melakukan penyimpanan di %s.\n", namaFolder);
    }
    else {
        printf("Tidak ditemukan folder %s. Membuat folder baru bernama %s...\n", namaFolder, namaFolder);
        printf("Mohon tunggu...\n");
        printf("1...\n2...\n3...\n");
        int check;
        #ifdef _WIN32
        check = mkdir(namaFolder);  // Windows version of mkdir
        #else
        check = mkdir(namaFolder, 0777);  // Unix/Linux version of mkdir
        #endif
        if (check == 0) printf("Folder berhasil dibuat!\n");
        else {
            printf("Folder gagal dibuat.\n");
            sukses = false;
        }
    }

    if (sukses) {
        SimpanPengguna(namaFolder);
        SimpanKicauan(namaFolder);
        SimpanBalasan(namaFolder);
        SimpanDraf(namaFolder);
        SimpanUtas(namaFolder);

        printf("File config berhasil disimpan.\n");
    }

    return sukses;
}

boolean MASUK() {
    //return true jika tutup program
    char nama[21];
    boolean loop = true;
    int idx;

    if (isEmptyP(LPengguna)) {
        printf("\nBelum ada pengguna yang terdaftar.\n");
        return false;
    }

    while (loop) {
        printf("\nMasukkan nama:\n");
        StartSentence();
        strCpy(currentSentence.TabWord,nama);
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
        strCpy(currentSentence.TabWord,sandi);
        if (!checkSandi(LPengguna,idx,sandi)) {
            printf("\nWah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
        } else {
            loop = false;
            currentUser = ELMT(LPengguna,idx);
            IdCurrentUser = idx + 1;
            printf("\nAnda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", NAMA(currentUser));
        }
    }

    //*************************************MAIN-LOOP******************************************//
    boolean keluar = false;
    loop = true;
    while (loop) {
        printf("\n>> ");
        char *operasi;

        StartSentence(); 
        operasi = currentSentence.TabWord;

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
        } else if (isStrEqual(operasi, "DAFTAR_TEMAN")) {
            daftarTeman(IdCurrentUser);
        } else if (isStrEqual(operasi, "HAPUS_TEMAN")) {
            hapusTeman(IdCurrentUser);
        }else if(isStrEqual(operasi,"GANTI_PROFIL")){
            gantiProfil();
        }else if (isStrEqual(operasi, "LIHAT_PROFIL")){
            char output[30];
            getString(operasi,output,sizeof(output));
            LihatProfil(output);
        }else if(isStrEqual(operasi, "ATUR_JENIS_AKUN")){
            aturjenisakun();
        }else if(isStrEqual(operasi, "UBAH_FOTO_PROFIL")){
            UbahfotoProfil();
        }else if(isStrEqual(operasi, "TAMBAH_TEMAN")){
            TambahTeman(&LPengguna);
        }else if(isStrEqual(operasi, "DAFTAR_PERMINTAAN_PERTEMANAN")){
            DaftarPermintaanTeman();
        }else if(isStrEqual(operasi, "SETUJUI_PERTEMANAN")){
            SetujuiTeman();
        }else if (isStrEqual(operasi, "KICAU")) {
            insertKicau(&LKicau,currentUser.nama,&IdKicau);
        }
        else if (isStrEqual(operasi, "KICAUAN")) {
            kicauan(LKicau,LPengguna,currentUser.nama);
        }
        else if (isStrEqual(operasi, "SUKA_KICAUAN")) {
            int id;
            id = ambilangka(operasi);
            sukaKicau(&LKicau,LPengguna,id,currentUser.nama);
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
                if(!isPenggunaPrivate(&LPengguna,k1.author)||(isTeman(findIDPenggunaByName(&LPengguna,k1.author),IdCurrentUser))){
                    perutasan(k1);
                }
                else{
                    printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
                }
            }
        }
        else if(isStrEqual(operasi,"BUAT_DRAF")){
            makingDraf(&LPengguna);
        }
        else if(isStrEqual(operasi,"LIHAT_DRAF")){
            seeDraf();
        }
        else if(isStrEqual(operasi,"BALAS")){
            int yangDibalas = 0,yangBalas = 0;
            takeTwovalue(operasi,&yangDibalas,&yangBalas);
            balasKicauan(yangDibalas,yangBalas,&LKicau);
        }
        else if(isStrEqual(operasi,"BALASAN")){
            int idK = ambilangka(operasi);
            printSemuaBalasan(idK);
        }
        else if(isStrEqual(operasi,"HAPUS_BALASAN")){
            int kic = 0,bal = 0;
            takeTwovalue(operasi,&kic,&bal);
            hapusBalasan(kic,bal);
        }
        else if (isStrEqual(operasi, "SIMPAN")) {
            Simpan();
        }
        else if (isStrEqual(operasi, "MUAT")) {
            Muat();
            loop = false;
        }
        //else if (isStrEqual(operasi, "_____")) { } <--- dilanjutkan
        else {
            printf("\nPerintah invalid.\n");
        }
    }
    return keluar;
}

void DAFTAR(){
    if (!isFullP(LPengguna)){
        boolean loop = true;

        // terima nama
        char nama[21];
        while (loop) {
            printf("\nMasukkan nama:\n");
            StartSentence();
            strCpy(currentSentence.TabWord,nama);

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
        strCpy(currentSentence.TabWord,sandi);

        Pengguna p;
        newPengguna(&p, nama, sandi);
        ID(p) = listLengthP(LPengguna)+1;
        addNode(&Teman);

        insertLastP(&LPengguna,p);

        printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
    } else {
        printf("\nJumlah pengguna sudah penuh.\n");
    }

}
