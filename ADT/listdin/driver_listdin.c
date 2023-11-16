#include <stdio.h>
#include "listdin.h"
#include "../tree/tree.h"

int main(){
    ListDinTree l;
    CreateListDinTree(&l, 10); // Assuming capacity 10
    printf("List created. IsEmpty: %s, IsFull: %s\n", 
           isEmptyDinTree(l) ? "Yes" : "No", 
           isFullDinTree(l) ? "Yes" : "No");

    DATETIME d;
    CreateDATETIME(&d,20,10,2023,10,12,49);
    Balasan b1 = CreateBalasan(&b1,1,"Haloo gess","ben",d);
    Balasan b2 = CreateBalasan(&b2,2,"Haloo semua","ben",d);
    Balasan b3 = CreateBalasan(&b3,3,"Haloo semua","ben",d);
    ElDinType val1 = newTree(b1,100); // Initialize val1 appropriately
    ElDinType val2 = newTree(b2,100);
    insertLastDinTree(&l, val1);
    insertLastDinTree(&l,val2);
    printf("\nAfter insertion: \n");
    int i;
    for(i = 0; i < NEFFDINTREE(l) ; i++){
        printBalasan(ELMTDINTREE(l,i)->B);
    }

    ElDinType deletedVal;
    deleteLastDinTree(&l, &deletedVal);
    printf("\nAfter deletion: \n");
    for(i = 0; i < NEFFDINTREE(l) ; i++){
        printBalasan(ELMTDINTREE(l,i)->B);
    }

    expandListDinTree(&l, 5); // Expanding by 5
    printf("After expanding: Capacity = %d\n", CAPACITYDINTREE(l));
    shrinkListDinTree(&l, 3); // Shrinking by 3
    printf("After shrinking: Capacity = %d\n", CAPACITYDINTREE(l));

    compressListDinTree(&l);
    printf("After compression: Capacity = %d\n", CAPACITYDINTREE(l));

    ListDinTree lCopy;
    copyListDinTree(l, &lCopy);
    printf("\nCopied List: \n");
    for(i = 0; i < NEFFDINTREE(lCopy) ; i++){
        printBalasan(ELMTDINTREE(lCopy,i)->B);
    }

    dealocateListDinTree(&l);
    dealocateListDinTree(&lCopy);
    return 0;



}