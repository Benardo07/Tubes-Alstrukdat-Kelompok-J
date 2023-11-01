#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "adt\mesinkarakter\charmachine.h"
#include "adt\mesinkata\wordmachine.h"
#include "adt\liststatik\listpengguna.h"
#include "boolean.h"
#include <stdio.h>

extern char currentChar;
extern boolean EOP;

extern char currentChar;
extern boolean EOP;

boolean isDirectoryExist(char *nama);

void strCat(char *str1, char *str2, char *dest);

void strCpy(char *str1, char *dest);

char *strLower(char *str);

boolean strIsInt(char *string);

boolean isStrEqual(char *str1, char *str2);

boolean Muat();

boolean MuatPengguna(char *namafolder);

boolean isWeton(char *weton);

void DAFTAR();

#endif // MAIN_H_INCLUDED
