#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "adt/mesinkarakter/charmachine.h"
#include "adt/mesinkata/wordmachine.h"
#include "adt/liststatik/listpengguna.h"
#include "adt/listlinier/listlinier.h"
#include "kicauan/kicauan.h"
// #include "ADT\graf\graf.h"
#include "adt/boolean.h"
#include "main.h"
#include "adt/stack/drafStack.h"

//inisialisasi variabel di luar supaya bisa langsung diakses semua function (gk usah oper parameter), tapi! lokalisasi buruk
// extern ListPengguna LPengguna;
// extern ListPengguna users[20];
// // extern Graf Teman;
// extern List LKicau;
// extern DrafStack sDraf;
// extern Pengguna currentUser;
// extern int JumlahId = 1;

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
    // printf("\n");
    // DisplayDraf(InfoTop(sDraf));

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
// boolean isDirectoryExist(char *nama){
//     struct stat s;

//     if (stat(nama, &s)==0 && S_ISDIR(s.st_mode)) {
//         return true;
//     } else {
//         return false;
//     }
// }

// void strCat(char *str1, char *str2, char *dest){
//     char temp[100]; //batasan maks length
//     int i=0,j=0;
//     while(str1[i]!='\0') {
//         temp[i]=str1[i];
//         i++;
//     }
//     while (str2[j]!='\0') {
//         temp[i]=str2[j];
//         i++;
//         j++;
//     }
//     temp[i]='\0';

//     for(j=0;j<=i;j++){
//         dest[j]=temp[j];
//     }
// }

// void strCpy(char *str1, char *dest){
//     int i = 0;
//     while(str1[i]!='\0'&&str1[i]!='\n') {
//         dest[i]=str1[i];
//         i++;
//     }
//     dest[i] = '\0';
// }

// int strlength(char *str1){
//     int i = 0;
//     while(str1[i]!='\0'&&str1[i]!='\n') {
//         i++;
//     }
//     return i;
// }

// char *strLower(char *str){
//     static char str2[1000];
//     int i;

//     i = 0;
//     while (str[i] != '\0'){
//         if (str[i]>='A' && str[i]<='Z') {
//             str2[i] = str[i] + 32;
//         } else {
//             str2[i] = str[i];
//         }
//         i++;
//     }
//     str2[i] = '\0';

//     return str2;
// }

// boolean strIsInt(char *str){
//     int i,n, s;
//     boolean sukses = true;

//     i = 0; n = 0;
//     while (str[i] != '\0' && sukses) {
//         s = str[i] - '0';
//         if (s<0 || s>9) {
//             sukses = false;
//             printf("char bukan int\n");
//         } else {
//             i++;
//             n++;
//         }

//         if (n>31) {
//             sukses = false;
//             printf("int overflow\n");
//         }
//     }

//     return sukses;
// }

// boolean isStrEqual(char *str1, char *str2){
//     boolean equal = true;
//     int i=0;

//     while ((str1[i] != '\0' || str2[i] != '\0') && equal) {
//         if (str1[i] != str2[i]) {
//             equal = false;
//         } else {
//             i++;
//         }
//     }

//     if((str1[i]!='\0' && str2[i]=='\0') || (str1[i]=='\0' && str2[i]!='\0')) equal = false;

//     return equal;
// }

// //****************************************KEBUTUHAN PROGRAM***************************************************//
// boolean Muat(){
//     char namafolder[100];
//     boolean sukses = true;

//     printf("\nSilahkan masukan folder konfigurasi untuk dimuat: ");
//     STARTWORD();
//     strCat("./",currentWord.TabWord,namafolder); //menggunakan relative path
//     //printf("%s\n", namafolder);

//     if (!isDirectoryExist(namafolder)) {
//         sukses = false;
//         printf("\nFolder tidak ditemukan\n");
//     } else printf("\nFolder ditemukan\n");
//         sukses = MuatPengguna(namafolder);
//         sukses = MuatKicauan(namafolder);
//         sukses = MuatDraf(namafolder);
//         //dilanjutkan sukses = MuatTeman, etc

//     return sukses;
// }

// boolean MuatPengguna(char *namafolder){
//     FILE *fPengguna;
//     boolean sukses = true;
//     char namafile[100]; //asumsi batasan strlength

//     strCat(namafolder,"/pengguna.config", namafile);
//     //printf("%s\n",namafile);
//     fPengguna = fopen(namafile,"r");

//     if (fPengguna == NULL) {
//         printf("Tidak ada file konfigurasi pengguna.\n");
//         sukses = false;
//     } else {
//         printf("File pengguna ditemukan\n");

//         char line[135];
//         int n, i, j;

//         fscanf(fPengguna,"%d",&n);
//         fgets(line,135,fPengguna);

//         for (i=0;i<n;i++){
//             Pengguna p;
//             fgets(line,135,fPengguna);
//             strCpy(line,NAMA(p));

//             fgets(line,135,fPengguna);
//             strCpy(line,PASSWORD(p));

//             fgets(line,135,fPengguna);
//             strCpy(line,BIO(p));

//             fgets(line,135,fPengguna);
//             strCpy(line,HP(p));

//             fgets(line,135,fPengguna);
//             strCpy(line,WETON(p));

//             fgets(line,135,fPengguna);
//             strCpy(line,JENIS(p));

//             for (j=0;j<5;j++) {
//                 fgets(line,135,fPengguna);
//                 strCpy(line,FOTO(p)[j]);
//             }

//             insertLast(&LPengguna,p);
//         }
//     }

//     fclose(fPengguna);
//     return sukses;
// }

// boolean MuatKicauan(char *namafolder){
//     FILE *fKicauan;
//     boolean sukses = true;
//     char namafile[100]; //asumsi batasan strlength

//     strCat(namafolder,"/kicauan.config", namafile);
//     fKicauan = fopen(namafile,"r");

//     if (fKicauan == NULL) {
//         printf("Tidak ada file konfigurasi kicauan.\n");
//         sukses = false;
//     } else {
//         printf("File kicauan ditemukan\n");

//         char line[280];
//         int n, i, j;
//         DATETIME date;

//         fscanf(fKicauan,"%d",&n);
//         fgets(line,280,fKicauan);

//         for (i=0;i<n;i++){
//             Kicau p;
//             int id,like;

//             fscanf(fKicauan,"%d",&id);
//             fgets(line,280,fKicauan);
//             p.id = id;

//             fgets(p.text.TabWord, sizeof(p.text.TabWord), fKicauan);
//             p.text.Length = strlength(p.text.TabWord);

//             fscanf(fKicauan,"%d",&like);
//             fgets(line,280,fKicauan);
//             p.like = like;

//             fgets(p.author.TabWord, sizeof(p.author.TabWord), fKicauan);
//             p.author.Length = strlength(p.text.TabWord);
//             p.author.TabWord[strlength(p.author.TabWord)] = '\0';

//             int h,m,s,d,b,y;
//             fscanf(fKicauan, "%d/%d/%d %d:%d:%d", &d, &b, &y, &h, &m, &s);
//             fgets(line,280,fKicauan);
//             CreateDATETIME(&date,d,b,y,h,m,s);
//             p.waktu = date;

//             insertLastKicau(&LKicau,p);
//             JumlahId+=1;
//         }
//     }

//     fclose(fKicauan);
//     return sukses;
// }

// boolean MuatDraf (char *namafolder){
//     FILE *fDraf;
//     boolean sukses = true;
//     char namafile[100]; //asumsi batasan strlength

//     strCat(namafolder,"/draf.config", namafile);
//     fDraf = fopen(namafile,"r");

//     if(fDraf == NULL){
//         printf("Tidak ada file konfigurasi draf.\n");
//         sukses = false;
//     }else{
//         printf("File draf ditemukan.\n");
//         char line[280];
//         int n, j;

//         fscanf(fDraf,"%d\n",&n);
//         int i ;
//         for(i = 0 ; i < n ; i++){
//             Draf d;
//             fscanf(fDraf,"%d\n",&Id(d));

//             fgets(line,280,fDraf);
//             strCpy(line,DrafTweet(d));

//             fgets(line,280,fDraf);
//             strCpy(line,Author(d));

//             fgets(line,280,fDraf);
//             int temp = sscanf(line, "%d/%d/%d %d:%d:%d", &Day(DateTime(d)), &Month(DateTime(d)), &Year(DateTime(d)), &Hour(Time(DateTime(d))) ,&Minute(Time(DateTime(d))) , &Second(Time(DateTime(d))));
//             Push(&sDraf,d);
//         }
        
//     }
//     fclose(fDraf);
//     return sukses;
// }

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
