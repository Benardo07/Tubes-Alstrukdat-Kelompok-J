#include <stdio.h>
#include "time.h"

int main(){
    TIME t1, t2;
    int detik;

    printf("Masukkan t1: \n");
    BacaTIME(&t1);
    printf("Jam t1: ");
    TulisTIME(t1); 
    printf("\n");

    printf("Masukkan t2: \n");
    BacaTIME(&t2);
    printf("Jam t2: ");
    TulisTIME(t2); 
    printf("\n");
    
    printf("Waktu t1 ke detik: %d\n", TIMEToDetik(t1));
    printf("Waktu t2 ke detik: %d\n", TIMEToDetik(t2));

    printf("Masukkan detik: ");
    scanf("%d", &detik);
    printf("\n%d detik ke TIME: ", detik);
    TulisTIME(DetikToTIME(detik));
    printf("\n\n");

    if (TEQ(t1, t2)){
        printf("T1 sama dengan T2\n");
    }
    if (TNEQ(t1, t2)){
        printf("T1 tidak sama dengan T2\n");
        if (TLT(t1, t2)){
            printf("T1 lebih kecil dari T2\n");
        }
        if (TGT(t1, t2)){
            printf("T1 lebih besar dari T2\n");
        }
    };

    printf("t1 ditambah 1 detik: ");TulisTIME(NextDetik(t1));
    printf("\nt1 dikurang 1 detik: ");TulisTIME(PrevDetik(t1));
    printf("\nt1 ditambah 2 detik: ");TulisTIME(NextNDetik(t1, 2));
    printf("\nt1 dikurang 2 detik: ");TulisTIME(PrevNDetik(t1, 2));

    printf("\nDurasi antara t1 dan t2: %ld detik", Durasi(t1, t2)); 
    
    return 0;
}
