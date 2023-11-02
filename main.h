#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "adt/mesinkarakter/charmachine.h"
#include "adt/mesinkata/wordmachine.h"
#include "adt/liststatik/listpengguna.h"
#include "adt/listlinier/kicau.h"
#include "adt/boolean.h"
#include <stdio.h>

extern ListPengguna LPengguna;
extern ListPengguna users[20];
extern Graf Teman;
extern List LKicau;
extern DrafStack sDraf;
extern Pengguna currentUser;

extern char currentChar;
extern boolean EOP;

extern char currentChar;
extern boolean EOP;

boolean isDirectoryExist(char *nama);

void strCat(char *str1, char *str2, char *dest);

void strCpy(char *str1, char *dest);

int strlength(char *str1);

char *strLower(char *str);

boolean strIsInt(char *string);

boolean isStrEqual(char *str1, char *str2);

boolean Muat();

boolean MuatPengguna(char *namafolder);

boolean MuatDraf (char *namafolder);

boolean MuatKicauan(char *namafolder);

boolean isWeton(char *weton);

void DAFTAR();

#endif // MAIN_H_INCLUDED
