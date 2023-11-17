#include <stdio.h>
#include "datetime.h"

int main(){
    DATETIME d1, d2;
    long int detik;

    printf("Masukkan d1: \n");
    BacaDATETIME(&d1);
    printf("Jam d1: ");
    TulisDATETIME(d1); 
    printf("\n");

    printf("Masukkan d2: \n");
    BacaDATETIME(&d2);
    printf("Jam t2: ");
    TulisDATETIME(d2); 
    printf("\n");
    
    if (DEQ(d1, d2)){
        printf("D1 sama dengan D2\n");
    }
    if (DNEQ(d1, d2)){
        printf("D1 tidak sama dengan D2\n");
        if (DLT(d1, d2)){
            printf("D1 lebih kecil dari D2\n");
        }
        if (DGT(d1, d2)){
            printf("D1 lebih besar dari D2\n");
        }
    };

    printf("d1 ditambah 2 detik: ");TulisDATETIME(DATETIMENextNDetik(d1,2));
    printf("\nd1 dikurang 2 detik: ");TulisDATETIME(DATETIMEPrevNDetik(d1,2));

    printf("\nDurasi antara d1 dan d2: %ld detik", DATETIMEDurasi(d1, d2)); 
    
    return 0;
}
