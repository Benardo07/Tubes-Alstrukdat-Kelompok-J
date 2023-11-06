#ifndef TREE_H
#define TREE_H

#include "../listdin/listdin.h"
#include "../datetime/datetime.h"
#include <stdlib.h>
#include "../../primitif/primitif.h"



typedef struct
{
    int id;
    char tweet[280];
    char writer[20];
    DATETIME d;
} Balasan;

#define IDBalasan(b) (b).id
#define TweetBalasan(b) (b).tweet
#define WriterBalasan(b) (b).writer
#define WaktuBalasan(b) (b).d

typedef struct nodet *AddressTree;
typedef struct nodet
{
    Balasan B;
    ListDinTree children;

} Nodet;

typedef AddressTree Tree;

#define BALASAN(t) (t)->B
#define CHILDREN(t) (t)->children

Tree newTree(Balasan B,int childCapacity);

Balasan CreateBalasan(Balasan *B, int id, char *tweet ,char *writer , DATETIME d);

Balasan CreateRootBalasan();

AddressTree findBalasanInTree(Tree T,int id);

void printBalasan(Balasan B);

#endif