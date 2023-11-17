#include <stdio.h>
#include "../../kicauan/kicauan.h"
#include "listlinier.h"

int main(){
    List l;
    CreateList(&l);
    printf("List created. IsEmpty: %s\n", 
           isEmptyListLinier(l) ? "Yes" : "No");

    DATETIME d;
    CreateDATETIME(&d,20,10,2023,10,12,49);

    Word text,text2,text3;
    readKicau(&text);
    readKicau(&text2);
    readKicau(&text3);

    Kicau k1,k2,k3;
    CreateKicau(&k1,1,0,text,"user",d);
    CreateKicau(&k2,2,0,text2,"user2",d);
    CreateKicau(&k3,3,0,text3,"user3",d);
    
    insertFirst(&l,k1);
    printf("\nAfter First insertion: \n");
    int i;
    for(i = 1; i <= length(l) ; i++){
        printKicau(l,i);
    }

    insertLastKicau(&l,k2);
    printf("\nAfter Second insertion: \n");
    for(i = 1; i <= length(l) ; i++){
        printKicau(l,i);
    }

    insertAt(&l,k3,1);
    printf("\nAfter Third insertion: \n");
    for(i = 1; i <= length(l) ; i++){
        printKicau(l,i);
    }

    Kicau deletedVal;
    deleteFirst(&l, &deletedVal);
    deleteLast(&l,&deletedVal);
    printf("\nAfter deletion: \n");
    for(i = 1; i <= length(l) ; i++){
        printKicau(l,i);
    }

    List lCopy;
    copyList(&l, &lCopy);
    printf("\nCopied List: \n");
    for(i = 1; i <= length(lCopy) ; i++){
        printKicau(lCopy,i);
    }

    List l2,l3;
    CreateList(&l2);
    insertFirst(&l2,k1);
    l3 = concat(l,l2);
    printf("\nConcat List: \n");
    for(i = 1; i <= length(l3) ; i++){
        printKicau(l3,i);
    }

    inverseList(&l3);
    printf("\nInverse List: \n");
    for(i = 1; i <= length(l3) ; i++){
        printKicau(l3,i);
    }
    
    return 0;

}