# include "foto.h"
# include <stdio.h>

int main(){
    foto F;
    CreatePhotoMatrix(&F);
    printf("Initial Photo : \n");
    PrintPhotoMatrix(F);
    printf("\n");

    ChangePhotoMatrix(&F, 1, 2, 'G');
    ChangePhotoMatrix(&F, 2, 6, 'B');

    printf("Setelah ubah elementnya : \n");
    PrintPhotoMatrix(F);

    return 0;
}

