#include <stdio.h>
#include <stdlib.h>
#include "../ADT/listlinier/listlinier.h"
#include "../ADT/mesinkarakter/charmachine.h"
#include "../ADT/mesinkata/wordmachine.h"
#include "../ADT/liststatik/listpengguna.h"

void CreateKicau(Kicau *k,int id, int like, Word text, char *aut, DATETIME waktu);

void insertKicau(List *l, char *val, int *id);

void editKicau(List *l, int id, char *auth);

void sukaKicau(List *l, ListPengguna l2, int id);

void printKicau(List l,int id);

void kicauan(List l,ListPengguna l2);