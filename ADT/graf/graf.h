# ifndef graf_H
# define graf_H

# include "../boolean.h"

# define CAP 20

typedef struct
{
    int matriks[CAP][CAP];
    int row;
    int col;
} graf;

#define ROW_EFF(M) (M).row
#define COL_EFF(M) (M).col
#define ELMT(M,i,j) (M).matriks[(i)][(j)]

void CreateGraphMatrix(graf *G, int row, int col);

void DisplayGraph(graf G);

void MatriksTeman(graf *G, int row, int col);

void DelMatriksTeman(graf *G, int row, int col);

# endif