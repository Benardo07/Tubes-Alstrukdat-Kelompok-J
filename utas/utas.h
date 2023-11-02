#include <stdio.h>
#include <stdlib.h>
#include "../ADT/listlinier/listlinier.h"
#include "../kicauan/kicauan.h"
#include "../kicauan/charmachine.h"
#include "../kicauan/wordmachine.h"

void buatUtas(List *l,Kicau *k, int *IdUtas, int IdKicau, Word author);

void insertUtas(Kicau *k,int idUtas);

boolean isCharSame(char *s1,char *s2);

void utas(List l);

void perutasan(Kicau k); // cetak utas

void sambungUtas(Kicau *k,int idx,int IdUtas,List *ListUtas, Word aut);

void hapusUtas(Kicau *k,int idx,int IdUtas,List ListUtas, Word aut);