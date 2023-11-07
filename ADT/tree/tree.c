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

// AddressTree findBalasanParentInTree(Tree T,int id){
//     if(T == NULL){
//         return NULL;
//     }
//     if(IDBalasan(BALASAN(T)) == id){
//         return T;
//     }
//     AddressTree tempParent;
//     AddressTree temp;
//     int i;
//     for(i = getFirstIdxDinTree(CHILDREN(T)); i <= getLastIdxDinTree(CHILDREN(T)); i++){
//         tempParent = T;
//         temp = findBalasanInTree(ELMTDINTREE(CHILDREN(T),i),id);

//         if(temp != NULL){
//             return tempParent;
//         }
//     }
//     return NULL;
// }

AddressTree findBalasanParentInTree(Tree T, int id, AddressTree parent) {
    if (T == NULL) {
        return NULL;
    }
    if (IDBalasan(BALASAN(T)) == id) {
        // If the current node is the one we're looking for, return the parent
        return parent;
    }
    AddressTree temp;
    for (int i = getFirstIdxDinTree(CHILDREN(T)); i <= getLastIdxDinTree(CHILDREN(T)); i++) {
        // Pass the current node T as the parent for the next level of recursion
        temp = findBalasanParentInTree(ELMTDINTREE(CHILDREN(T), i), id, T);
        if (temp != NULL) {
            return temp;  // Found the parent of the node with the specified id
        }
    }
    return NULL;  // Not found in this subtree
}

void printBalasan(Balasan B){
    printf("| ID = %d\n",IDBalasan(B));
    printf("| %s\n",WriterBalasan(B));
    printf("| ");
    TulisDATETIME(WaktuBalasan(B));
    printf("\n");
    printf("| %s\n",TweetBalasan(B));
}

// void printAllBalasanWithIndent(Tree T, int depth) {
//     if(T == NULL){
//         return;
//     }

//     // Print the current node's Balasan with indentation
//     if(depth != 0){
//         printBalasanWithIndent(BALASAN(T), depth);
//     }
    
//     // Recursively call the function on all children with increased depth
//     int i;
//     for(i = getFirstIdxDinTree(CHILDREN(T)); i <= getLastIdxDinTree(CHILDREN(T)); i++){
//         printAllBalasanWithIndent(ELMTDINTREE(CHILDREN(T), i), depth + 1);
//     }
// }

// void printBalasanWithIndent(Balasan B, int depth){
//     printf("\n");
//     for(int i = 0; i < depth -1; i++) {
//         printf("    "); // 4 spaces for each level of indent
//     }
//     printf("| ID = %d\n", IDBalasan(B));
    
//     for(int i = 0; i < depth -1; i++) {
//         printf("    ");
//     }
//     printf("| %s\n", WriterBalasan(B));
    
//     for(int i = 0; i < depth - 1; i++) {
//         printf("    ");
//     }
//     printf("| ");
//     TulisDATETIME(WaktuBalasan(B));
//     printf("\n");
    
//     for(int i = 0; i < depth-1; i++) {
//         printf("    ");
//     }
//     printf("| %s\n", TweetBalasan(B));
// }
