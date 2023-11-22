#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "ADT/mesinkarakter/charmachine.h"
#include "ADT/mesinkata/wordmachine.h"
#include "ADT/mesinkata/mesinkalimat.h"
#include "ADT/liststatik/listpengguna.h"
#include "ADT/listlinier/listlinier.h"
#include "kicauan/kicauan.h"
#include "utas/utas.h"
#include "teman/teman.h"
#include "ADT/graf/graf.h"
#include "ADT/boolean.h"
#include "main.h"
#include "ADT/stack/drafStack.h"

//gcc -o p main.c adt/mesinkata/mesinkalimat.c data/data.c primitif/primitif.c adt/pcolor/pcolor.c adt/matriks/foto.c adt/mesinkarakter/charmachine.c adt/queue/prioqueue.c adt/graf/graf.c adt/mesinkata/wordmachine.c adt/liststatik/listpengguna.c adt/listlinier/listlinier.c kicauan/kicauan.c teman/teman.c adt/stack/drafstack.c adt/datetime/datetime.c adt/datetime/time.c utas/utas.c adt/listdin/listdin.c adt/tree/tree.c permintaan/requests.c draf/draf.c balasan/balasan.c profil/profil.c

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
    // printListP(LPengguna);
    // printListP(LPengguna);
    // printf("%d",NEFF(LPengguna));
    // printf("\n");
    // DisplayDraf(InfoTop(sDraf));

    //*********************************START MENU LOOP******************************************//
    loop = true;
    while (loop) {
        printf("\n>> ");
        char *operasi;

        STARTWORD();
        operasi = currentWord.TabWord;
        if (isStrEqual(operasi, "DAFTAR")){
            DAFTAR();
        } else if (isStrEqual(operasi, "MASUK")){
            if (MASUK()) {
                loop = false;
            }
        } else if (isStrEqual(operasi, "KELUAR")){
            printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        } else if (isStrEqual(operasi, "TUTUP_PROGRAM")){
            printf("\nAnda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
            loop = false;
        } else if (isStrEqual(operasi, "MUAT")){
            if (Muat()) printf("\nPemuatan berhasil!\n");
        } else if (isStrEqual(operasi, "SIMPAN")) {
            Simpan();
        } else {
            printf("\nPerintah invalid.\n");
        }
    }
    return 0;
}