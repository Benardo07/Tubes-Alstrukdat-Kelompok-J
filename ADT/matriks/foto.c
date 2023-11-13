#include "foto.h"
#include <stdio.h>


void CreatePhotoMatrix(foto *F) {
    ROW_EFF(*F) = CAP;
    COL_EFF(*F) =  2*CAP;
    
    for (int i = 0; i < CAP; ++i) {
        for (int j = 0; j < 10; ++j) {
            Element(*F, i, j) = (j % 2 == 0) ? 'B' : '*';
        }
    }
}

void ChangePhotoMatrix(foto *F, int i, int j, char newVal) {
    if (i < ROW_EFF(*F) && j < COL_EFF(*F)) {
        Element(*F,i,j) = newVal;
    }
}

void PrintPhotoMatrix(foto F) {
    char temp ;
    for (int i = 0; i < ROW_EFF(F); ++i) {
        for (int j = 0; j < COL_EFF(F); ++j) {
            if (j % 2 == 0){
                temp = Element(F,i,j);
            }else{
                if(temp == 'R'){
                    print_red(Element(F,i,j));
                }else if(temp == 'G'){
                    print_green(Element(F,i,j));
                }else if(temp == 'B'){
                    print_blue(Element(F,i,j));
                }
            }
        }
        printf("\n");
    }
}
