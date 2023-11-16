#include <stdio.h>
#include "tree.h"

int main(){
    // Create Balasan
    DATETIME d;
    CreateDATETIME(&d,20,10,2023,10,12,49);
    Balasan b1 = CreateBalasan(&b1,1,"Haloo gess","ben",d);
    Balasan b2 = CreateBalasan(&b2,2,"Haloo semua","ben",d);
    Balasan b3 = CreateBalasan(&b3,3,"Haloo semua kwkwkw","ben",d);
    // ... create more Balasan instances as needed ...

    // Create Tree
    Balasan b0 = CreateRootBalasan();
    Tree T = newTree(b0,100);
    Tree T1 = newTree(b1,100);
    Tree T2 = newTree(b2,100);
    Tree T3 = newTree(b3,100);

    insertLastDinTree(&T->children,T1);
    insertLastDinTree(&T->children,T2);

    insertLastDinTree(&T2->children,T3);


    // Test nbElmt
    printf("Number of elements in the tree: %d\n", nbElmt(T));

    // Find Balasan in Tree
    AddressTree found = findBalasanInTree(T, 3);
    if (found != NULL) {
        printBalasan(BALASAN(found));
    } else {
        printf("Balasan not found.\n");
    }

    // Find Balasan Parent in Tree
    AddressTree parent = findBalasanParentInTree(T, 3, NULL);
    if (parent != NULL) {
        printBalasan(BALASAN(parent));
    } else {
        printf("Parent Balasan not found.\n");
    }

    // Additional tests for other functions as needed
    // ...

    return 0;

}