#include "../ADT/boolean.h"
#include <sys/stat.h>

boolean isDirectoryExist(char *nama);

void strCat(char *str1, char *str2, char *dest);

void strCpy(const char *str1, char *dest);

int strlength(char *str1);

char *strLower(char *str);

boolean strIsInt(char *str);

int strToInt(const char *str);

boolean isStrEqual(char *str1, char *str2);

boolean strictIsStrEqual(char *str1, char *str2);

int ambilangka(char *str1);

int ambilangka2(char *str1);

void getString(const char *str1, char *hasil, int maxLen);

boolean isWeton(char *weton);

void strCpyTwoElmt(char *str1,char *dest1 , int *dest2);

void takeTwovalue(char *str1 , int* yangDiBalas, int* yangBalas);

void makeUpper(char *str);

void ambilDuaNum(char *str1 , int *num1 , int *num2);
