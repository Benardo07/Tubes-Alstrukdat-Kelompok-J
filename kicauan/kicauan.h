#include <stdio.h>
#include <stdlib.h>
#include "../ADT/listlinier/listlinier.h"
#include "charmachine.h"
#include "wordmachine.h" // ini masih pake punyaku dulu

void CreateKicau(Kicau *k,int id, int like, Word text, Word aut, DATETIME waktu);

void insertKicau(List *l, Word val, int *id);

void editKicau(List *l, int id, Word auth);

void sukaKicau(List *l, int id, Word auth);

void printKicau(List l,int id);

void kicauan(List l);