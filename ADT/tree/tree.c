#include <stdio.h>
#include "tree.h"

Tree newTree(Balasan B,int childCapacity){
    Tree a = (Tree) malloc(sizeof(Nodet));

    if(a == NULL){
        printf("Memory alokasi gagal !!!");

    }else{
        BALASAN(a) = B;
        CreateListDinTree(&CHILDREN(a), childCapacity);
    }
    return a;
}

Balasan CreateBalasan(Balasan *B, int id, char *tweet ,char *writer , DATETIME d){
    IDBalasan(*B) = id;
    strCpy(tweet,TweetBalasan(*B));
    strCpy(writer,WriterBalasan(*B));
    WaktuBalasan(*B) = d;
}

Balasan CreateRootBalasan(){
    Balasan B;
    IDBalasan(B) = -1;
    B.tweet[0] = '\0';
    B.writer[0] = '\0';
}

AddressTree findBalasanInTree(Tree T,int id){
    if(T == NULL){
        return NULL;
    }
    if(IDBalasan(BALASAN(T)) == id){
        return T;
    }
    AddressTree temp;
    int i;
    for(i = getFirstIdxDinTree(CHILDREN(T)); i <= getLastIdxDinTree(CHILDREN(T)); i++){
        temp = findBalasanInTree(ELMTDINTREE(CHILDREN(T),i),id);

        if(temp != NULL){
            return temp;
        }
    }
    return NULL;
}

void printBalasan(Balasan B){
    printf("| ID = %d\n",IDBalasan(B));
    printf("| %s\n",WriterBalasan(B));
    printf("| ");
    TulisDATETIME(WaktuBalasan(B));
    printf("\n");
    printf("| %s\n",TweetBalasan(B));
}