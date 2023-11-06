#include <stdio.h>
#include <stdlib.h>
#include "../ADT/listlinier/listlinier.h"
#include "../kicauan/kicauan.h"
#include "../primitif/primitif.h"
#include "../ADT/listdin/listdinutas.h"

void buatUtas(ListDin *l,Kicau *k, int *IdUtas, int IdKicau, char *author);

void insertUtas(Kicau *k);

boolean isCharSame(char *s1,char *s2);

void utas(List l);

void perutasan(Kicau k); // cetak utas

void sambungUtas(Kicau *k,int idx,int IdUtas,ListDin *ListUtas, char *aut);

void hapusUtas(Kicau *k,int idx,char *aut);