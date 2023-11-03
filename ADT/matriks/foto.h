#ifndef FOTO_H
#define FOTO_H

# include "../boolean.h"
#include "../pcolor/pcolor.h"

#define CAP 5

typedef struct{
    char matriks[CAP][2*CAP];
    int row;
    int col;
} foto;

#define ROW_EFF(M) (M).row
#define COL_EFF(M) (M).col
#define ELMT(M,i,j) (M).matriks[(i)][(j)]

void CreatePhotoMatrix(foto *F);

void ChangePhotoMatrix(foto *F, int i, int j, int newVal);

void PrintPhotoMatrix(foto F);

#endif