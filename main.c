#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "adt\mesinkarakter\charmachine.h"
#include "adt\mesinkata\wordmachine.h"
#include "adt\liststatik\listpengguna.h"
#include "boolean.h"
#include "main.h"

//inisialisasi variabel di luar supaya bisa langsung diakses semua function (gk usah oper parameter), tapi! lokalisasi buruk
ListPengguna LPengguna;

int main()
{
    //*********************************INISIALISASI******************************************//
    printf(".______    __    __  .______      .______    __  .______\n"
           "|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\\n"
           "|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |\n"
           "|   _  <  |  |  |  | |      /     |   _  <  |  | |      /\n"
           "|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n"
           "|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n"
           "Selamat datang di BurBir.\n"
           "Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n"
           );

    boolean loop = true;
    while (loop) {
        loop = !Muat();
    }

    printf("\nFile konfigurasi berhasil dimuat! Selamat berkicau!\n");
    printList(LPengguna);

    //*********************************MAIN-LOOP******************************************//
    loop = true;
    while (loop) {
        printf("\n>> ");
        char *operasi;

        STARTWORD();
        operasi = currentWord.TabWord;

        if (isStrEqual(operasi, "DAFTAR")){
            //DAFTAR();
        } else if (isStrEqual(operasi, "MASUK")){
            //MASUK();
        } else if (isStrEqual(operasi, "KELUAR")){
            printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        } else if (isStrEqual(operasi, "TUTUP_PROGRAM")){
            printf("\nAnda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
            loop = false;
        }
        else {
            printf("\nPerintah invalid.\n");
        }
    }
    return 0;
}

//****************************************PRIMITIF***************************************************//
boolean isDirectoryExist(char *nama){
    struct stat s;

    if (stat(nama, &s)==0 && S_ISDIR(s.st_mode)) {
        return true;
    } else {
        return false;
    }
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

char *strLower(char *str){
    static char str2[1000];
    int i;

    i = 0;
    while (str[i] != '\0'){
        if (str[i]>='A' && str[i]<='Z') {
            str2[i] = str[i] + 32;
        } else {
            str2[i] = str[i];
        }
        i++;
    }
    str2[i] = '\0';

    return str2;
}

boolean strIsInt(char *str){
    int i,n, s;
    boolean sukses = true;

    i = 0; n = 0;
    while (str[i] != '\0' && sukses) {
        s = str[i] - '0';
        if (s<0 || s>9) {
            sukses = false;
            printf("char bukan int\n");
        } else {
            i++;
            n++;
        }

        if (n>31) {
            sukses = false;
            printf("int overflow\n");
        }
    }

    return sukses;
}

boolean isStrEqual(char *str1, char *str2){
    boolean equal = true;
    int i=0;

    while ((str1[i] != '\0' || str2[i] != '\0') && equal) {
        if (str1[i] != str2[i]) {
            equal = false;
        } else {
            i++;
        }
    }

    if((str1[i]!='\0' && str2[i]=='\0') || (str1[i]=='\0' && str2[i]!='\0')) equal = false;

    return equal;
}

//****************************************KEBUTUHAN PROGRAM***************************************************//
boolean Muat(){
    char namafolder[100];
    boolean sukses = true;

    printf("\nSilahkan masukan folder konfigurasi untuk dimuat: ");
    STARTWORD();
    strCat("./",currentWord.TabWord,namafolder); //menggunakan relative path
    //printf("%s\n", namafolder);

    if (!isDirectoryExist(namafolder)) {
        sukses = false;
        printf("\nFile tidak ditemukan\n");
    } else printf("\nFolder ditemukan\n");
        sukses = MuatPengguna(namafolder);
        //dilanjutkan sukses = MuatTeman, etc

    return sukses;
}

boolean MuatPengguna(char *namafolder){
    FILE *fPengguna;
    boolean sukses = true;
    char namafile[100]; //asumsi batasan strlen

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

boolean isWeton(char *weton){
    boolean sukses=false;
    char* temp = strLower(weton);

    if (isStrEqual("pahing",temp) || isStrEqual("kliwon",temp) || isStrEqual("wage",temp) || isStrEqual("pon",temp) || isStrEqual("legi",temp)){
        sukses = true;
    }

    return sukses;
}

void DAFTAR(){ //WIP
    boolean loop = true;

    // terima nama
    Word nama;
    while (loop) {
        printf("\nMasukkan nama:\n");
        StartSentence();
        nama = currentWord;
        printf("%s\n", nama);

        // if (unik) {
            loop = false;
        //} else {
            printf("\nWah, sayang sekali nama tersebut telah diambil. \n");
        //}
    }

    // terima sandi
    Word sandi;
    printf("\nMasukkan kata sandi:\n");
    StartSentence();
    sandi = currentWord;
    printf("%s\n", sandi);

    // masukkan data

    printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
}
