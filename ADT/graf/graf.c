# include "graf.h"
# include <stdio.h>

void CreateGraphMatrix(graf *G, int row, int col){
    ROW_EFF(*G) = row;
    COL_EFF(*G) = col;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            ELMT(*G,i,j) = 0;
        }
    }
};

void DisplayGraph(graf G){
    int i,j;
    for(i=0;i<G.row;i++){
        for(j=0;j<G.col;j++){
            if(j != G.col){
                printf("%d ", ELMT(G,i,j));
            }else{
                printf("%d",ELMT(G,i,j));
            }
        }
        printf("\n");
    }
};

// 
void MatriksTeman(graf *G, int row, int col){
    ELMT(*G,row,col) = 1;
    ELMT(*G,col,row) = 1; 
};

void DelMatriksTeman(graf *G, int row, int col){
    if(ELMT(*G,row,col) == 1){
        ELMT(*G,row,col) = 0;
        ELMT(*G,col,row) = 0;
    }
};