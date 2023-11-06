
#include <stdio.h>
#include <stdlib.h>
#include "../ADT/mesinkata/wordmachine.h"
#include "kicauan.h"
#include "../utas/utas.h"
#include "../ADT/listlinier/listlinier.h"
#include "../ADT/listdin/listdinutas.h"

List l;
ListDin LUtas;

int JumlahId = 1;
int IdUtas = 1;

boolean MuatKicauan(char *namafolder);
boolean MuatUtas(char *namafolder);
// gcc -o q kicauan/driver.c adt/datetime/datetime.c kicauan/kicauan.c adt/datetime/time.c adt/mesinkata/wordmachine.c adt/mesinkarakter/charmachine.c adt/listlinier/listlinier.c primitif/primitif.c utas/utas.c adt/listdin/listdinutas.c

int main() {
    CreateListDinUtas(&LUtas,3);
    boolean loop = true;
    while (loop) {
        loop = !MuatKicauan("configs");
        loop = !MuatUtas("configs");
    }
    kicauan(l);
    perutasan(ELMTDIN(LUtas,0));
    perutasan(ELMTDIN(LUtas,1));
    printf("\nFile konfigurasi berhasil dimuat! Selamat berkicau!\n");
    // Create a Word to store the author's name
    printf("masukkan author: ");
    char *tes,*aut;
    STARTWORD();
    tes = currentWord.TabWord;
    aut = tes;
    insertKicau(&l,aut,&JumlahId);
    insertKicau(&l,aut,&JumlahId);

    // Print semua kicauan
    kicauan(l);

    int idx;
    printf("edit id berapa: ");
    scanf("%d",&idx);
    editKicau(&l,idx,aut);
    printf("edit id berapa: ");
    scanf("%d",&idx);
    editKicau(&l,idx,aut);

    kicauan(l);

    printf("suka id berapa: ");
    scanf("%d",&idx);
    sukaKicau(&l,idx);

    kicauan(l);

    // try utas
    printf("mau buat utas id berapa: ");
    scanf("%d",&idx);
    Kicau k1 = getElmt(l,idx-1);
    buatUtas(&LUtas,&k1,&IdUtas,idx,aut);
    
    printf("mau buat utas id berapa: ");
    scanf("%d",&idx);
    k1 = getElmt(l,idx-1);
    buatUtas(&LUtas,&k1,&IdUtas,idx,k1.author);

    printf("mau cetak utas id berapa: ");
    scanf("%d",&idx);
    perutasan(ELMTDIN(LUtas,idx-1));

    k1 = ELMTDIN(LUtas,2);
    printf("mau SAMBUNG utas idx berapa: ");
    scanf("%d",&idx);
    sambungUtas(&k1,idx,1,&LUtas,k1.author);
    utas(ELMTDIN(LUtas,2).Utas);
    perutasan(ELMTDIN(LUtas,2));

    printf("mau hapus utas idx berapa: ");
    scanf("%d",&idx);
    hapusUtas(&k1,idx,k1.author);
    utas(ELMTDIN(LUtas,2).Utas);
    perutasan(ELMTDIN(LUtas,2));

    printf("done");
    return 0;
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

            insertLastKicau(&l,p);
            p.Utas = NULL;
            JumlahId+=1;
        }
    }
    fclose(fKicauan);
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
            insertLastDin(&LUtas,getElmt(l,id-1));

            fscanf(fUtas,"%d",&m);
            fgets(line,280,fUtas);
            Kicau utas = getElmt(l,id-1);
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
            ELMTDIN(LUtas,i) = utas;
            IdUtas+=1;
        }
    }

    fclose(fUtas);
    return sukses;
}
