#include "foto.h"
#include <stdio.h>


void CreatePhotoMatrix(foto *F) {
    ROW_EFF(*F) = CAP;
    COL_EFF(*F) =  2*CAP; // We are doubling the number of columns to account for the '*' characters
    
    for (int i = 0; i < CAP; ++i) {
        for (int j = 0; j < 10; ++j) {
            Element(*F, i, j) = (j % 2 == 0) ? 'R' : '*';
        }
    }
}

void ChangePhotoMatrix(foto *F, int i, int j, int newVal) {
    if (i < ROW_EFF(*F) && j < COL_EFF(*F)) {
        Element(*F,i,j) = newVal;
    }
}

void PrintPhotoMatrix(foto F) {
    char temp ;
    for (int i = 0; i < ROW_EFF(F); ++i) {
        for (int j = 0; j < COL_EFF(F); ++j) {
            // Print 'R' if the element is 1, '*' if 0
            if (j % 2 == 0){
                temp = Element(F,i,j);
            }else{
                if(temp == 'R'){
                    print_red(Element(F,i,j));
                }else if(temp == 'G'){
                    print_green(Element(F,i,j));
                }else{
                    print_blue(Element(F,i,j));
                }
            }
            
        }
        printf("\n");
    }
}

// Example usage in your main.c
// int main() {
//     foto myFoto;
//     CreatePhotoMatrix(&myFoto);
//     PrintPhotoMatrix(myFoto);
    
//     // // Example of changing a value
//     // ChangePhotoMatrix(&myFoto, 2, 2, 0); // This would change the central 'R' to '*'
//     // PrintPhotoMatrix(&myFoto);

//     return 0;
// }
