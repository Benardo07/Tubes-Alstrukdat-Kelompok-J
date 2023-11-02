#include <stdio.h>
#include "wordmachine.h"
#include "kicauan.h"
#include "../ADT/listlinier/listlinier.h"
#include "../utas/utas.h"

List l;
List LUtas;
int JumlahId = 1;
int IdUtas = 1;

boolean MuatKicauan(char *namafolder);
boolean MuatUtas(char *namafolder);
// gcc -o q kicauan/driver.c adt/datetime/datetime.c kicauan/kicauan.c adt/datetime/time.c kicauan/wordmachine.c kicauan/charmachine.c adt/listlinier/listlinier.c utas/utas.c

int main() {
    boolean loop = true;
    while (loop) {
        loop = !MuatKicauan("configs");
        loop = !MuatUtas("configs");
    }
    kicauan(l);
    perutasan(getElmt(LUtas,0));
    perutasan(getElmt(LUtas,1));
    printf("\nFile konfigurasi berhasil dimuat! Selamat berkicau!\n");
    // Create a Word to store the author's name
    Word aut,aut2;
    printf("masukkan author: ");
    readWord(&aut);
    
    insertKicau(&l, aut,&JumlahId);
    insertKicau(&l, aut,&JumlahId);

    // Print semua kicauan
    kicauan(l);

    int idx;
    printf("edit id berapa: ");
    scanf("%d",&idx);
    editKicau(&l,idx,aut2);
    printf("edit id berapa: ");
    scanf("%d",&idx);
    editKicau(&l,idx,aut2);

    kicauan(l);

    printf("suka id berapa: ");
    scanf("%d",&idx);
    sukaKicau(&l,idx,aut2);

    kicauan(l);

    // try utas
    printf("mau buat utas id berapa: ");
    scanf("%d",&idx);
    Kicau k1 = getElmt(l,idx-1);
    buatUtas(&LUtas,&k1,&IdUtas,idx,aut);
    
    printf("mau buat utas id berapa: ");
    scanf("%d",&idx);
    k1 = getElmt(l,idx-1);
    buatUtas(&LUtas,&k1,&IdUtas,idx,aut);

    printf("mau cetak utas id berapa: ");
    scanf("%d",&idx);
    perutasan(getElmt(LUtas,idx-1));

    printf("mau SAMBUNG utas idx berapa: ");
    scanf("%d",&idx);
    k1 = getElmt(LUtas,0);
    sambungUtas(&k1,idx,1,&LUtas,aut);
    perutasan(getElmt(LUtas,0));

    printf("mau hapus utas idx berapa: ");
    scanf("%d",&idx);
    k1 = getElmt(LUtas,0);
    hapusUtas(&k1,idx,IdUtas,LUtas,aut);
    perutasan(getElmt(LUtas,0));

    printf("done");
    return 0;
}

void strCat(char *str1, char *str2, char *dest){
    char temp[100]; //batasan maks length
    int i=0,j=0;
    while(str1[i]!='\0') {
        temp[i]=str1[i];
        i++;
    }
    while (str2[j]!='\0') {
        temp[i]=str2[j];
        i++;
        j++;
    }
    temp[i]='\0';

    for(j=0;j<=i;j++){
        dest[j]=temp[j];
    }
}

void strCpy(char *str1, char *dest){
    int i = 0;
    while(str1[i]!='\0'&&str1[i]!='\n') {
        dest[i]=str1[i];
        i++;
    }
    dest[i] = '\0';
}

int strlen(char *str1){
    int i = 0;
    while(str1[i]!='\0'&&str1[i]!='\n') {
        i++;
    }
    return i;
}

boolean MuatKicauan(char *namafolder){
    FILE *fKicauan;
    boolean sukses = true;
    char namafile[100]; //asumsi batasan strlen

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
            p.text.Length = strlen(p.text.TabWord);

            fscanf(fKicauan,"%d",&like);
            fgets(line,280,fKicauan);
            p.like = like;

            fgets(p.author.TabWord, sizeof(p.author.TabWord), fKicauan);
            p.author.Length = strlen(p.text.TabWord);
            p.author.TabWord[strlen(p.author.TabWord)] = '\0';

            int h,m,s,d,b,y;
            fscanf(fKicauan, "%d/%d/%d %d:%d:%d", &d, &b, &y, &h, &m, &s);
            fgets(line,280,fKicauan);
            CreateDATETIME(&date,d,b,y,h,m,s);
            p.waktu = date;

            insertLastKicau(&l,p);
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
        printf("Tidak ada file konfigurasi kicauan.\n");
        sukses = false;
    } else {
        printf("File kicauan ditemukan\n");

        char line[280];
        int n, m, i, j;
        DATETIME date;

        fscanf(fUtas,"%d",&n);
        fgets(line,280,fUtas);

        for (i=0;i<n;i++){
            int id;
            fscanf(fUtas,"%d",&id);
            fgets(line,280,fUtas);
            insertLastKicau(&LUtas,getElmt(l,id-1));

            fscanf(fUtas,"%d",&m);
            fgets(line,280,fUtas);
            Kicau p;
            for (j=0;j<m;j++){
                int idx,like;
                fscanf(fUtas,"%d",&id);
                fgets(line,280,fUtas);
                p.id = id;

                fgets(p.text.TabWord, sizeof(p.text.TabWord), fUtas);
                p.text.Length = strlen(p.text.TabWord);

                fgets(p.author.TabWord, sizeof(p.author.TabWord), fUtas);
                p.author.Length = strlen(p.text.TabWord);
                p.author.TabWord[strlen(p.author.TabWord)] = '\0';

                int h,m,s,d,b,y;
                fscanf(fUtas, "%d/%d/%d %d:%d:%d", &d, &b, &y, &h, &m, &s);
                fgets(line,280,fUtas);
                CreateDATETIME(&date,d,b,y,h,m,s);
                p.waktu = date;
                Kicau k;
                k= getElmt(LUtas,i);
                insertLastKicau(&(k.Utas),p);
            }
            setElmt(&LUtas,IdUtas,p);
            IdUtas+=1;
        }
    }

    fclose(fUtas);
    return sukses;
}
