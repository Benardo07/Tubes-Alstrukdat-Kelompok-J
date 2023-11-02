
#include <stdio.h>
#include "primitif.h"

boolean isDirectoryExist(char *nama){
    struct stat s;

    if (stat(nama, &s)==0 && S_ISDIR(s.st_mode)) {
        return true;
    } else {
        return false;
    }
}

void strCat(char *str1, char *str2, char *dest){
    char temp[100]; //batasan maks length
    int i=0,j=0;
    while(str1[i]!='\0') {
        temp[i]=str1[i];
        i++;
    }
    while (str2[j]!='\0') {
        temp[i]=str2[j];
        i++;
        j++;
    }
    temp[i]='\0';

    for(j=0;j<=i;j++){
        dest[j]=temp[j];
    }
}

void strCpy(char *str1, char *dest){
    int i = 0;
    while(str1[i]!='\0'&&str1[i]!='\n') {
        dest[i]=str1[i];
        i++;
    }
    dest[i] = '\0';
}

int strlength(char *str1){
    int i = 0;
    while(str1[i]!='\0'&&str1[i]!='\n') {
        i++;
    }
    return i;
}

char *strLower(char *str){
    static char str2[1000];
    int i;

    i = 0;
    while (str[i] != '\0'){
        if (str[i]>='A' && str[i]<='Z') {
            str2[i] = str[i] + 32;
        } else {
            str2[i] = str[i];
        }
        i++;
    }
    str2[i] = '\0';

    return str2;
}

boolean strIsInt(char *str){
    int i,n, s;
    boolean sukses = true;

    i = 0; n = 0;
    while (str[i] != '\0' && sukses) {
        s = str[i] - '0';
        if (s<0 || s>9) {
            sukses = false;
            printf("char bukan int\n");
        } else {
            i++;
            n++;
        }

        if (n>31) {
            sukses = false;
            printf("int overflow\n");
        }
    }

    return sukses;
}

boolean isStrEqual(char *str1, char *str2){
    boolean equal = true;
    int i=0;

    while ((str1[i] != '\0' || str2[i] != '\0') && equal) {
        if (str1[i] != str2[i]) {
            equal = false;
        } else {
            i++;
        }
    }

    if((str1[i]!='\0' && str2[i]=='\0') || (str1[i]=='\0' && str2[i]!='\0')) equal = false;

    return equal;
}