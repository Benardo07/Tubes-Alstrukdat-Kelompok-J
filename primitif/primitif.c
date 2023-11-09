
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

    while ((i<strlength(str2)) && equal) {
        if (str1[i] != str2[i]) {
            equal = false;
        } else {
            i++;
        }
    }
    if(str1[i]!=' '){
        if((str1[i]!='\0' && str2[i]=='\0') || (str1[i]=='\0' && str2[i]!='\0')){ 
                equal = false;}
    }

    return equal;
}


int ambilangka(char *str1){
    int id=0;
    int i = 0;
    while (str1[i] != ' ' ) {
            i++;
    }
    i++;
    while (str1[i] != '\0' && str1[i] != ' ' ) {
        id = id * 10 + (str1[i] - '0');
        i++;
    }
    return id;
}

int ambilangka2(char *str1){
    int id=0;
    int i = 0;
    while (str1[i] != ' ' ) {
            i++;
    }
    i++;
    while (str1[i] != '\0' && str1[i] != ' ' ) {
        i++;
    }
    i++;
    while (str1[i] != '\0') {
        id = id * 10 + (str1[i] - '0');
        i++;
    }
    return id;
}


boolean isWeton(char *weton){
    boolean sukses=false;
    char* temp = strLower(weton);

    if (isStrEqual("pahing",temp) || isStrEqual("kliwon",temp) || isStrEqual("wage",temp) || isStrEqual("pon",temp) || isStrEqual("legi",temp)){
        sukses = true;
    }

    return sukses;
}

void strCpyTwoElmt(char *str1,char *dest1 , int *dest2){
    int i = strlength(str1) - 1;
    int z = 0;
    *dest2 = 0;
    int multiplier = 1;
    while (i >= 0 && str1[i] != ' '){
        *dest2 += ((str1[i]-'0') * multiplier);
        multiplier *= 10;
        i--;
    }
    z = 0;
    while(z < i){
        dest1[z] = str1[z];
        z++;
    }
    dest1[z] = '\0';
}

void takeTwovalue(char *str1 , int* yangDiBalas, int* yangBalas){
    int i =0;
    while (str1[i] != ' ')
    {
        i++;
    }
    i++;
    int z = 10;
    boolean negatif = false;
    while (str1[i] != ' ')
    {
        if(str1[i] == '-'){
            negatif = true;
        }else{
            *yangDiBalas = (*yangDiBalas)*z +  (str1[i] - '0');
        }
        i++;
    }
    if(negatif){
        *yangDiBalas = -1* (*yangDiBalas);
        negatif = false;
    }
    i++;
    while (str1[i] != '\0')
    {
        if(str1[i] == '-'){
            negatif = true;
        }else{
            *yangBalas = (*yangBalas)*z +  (str1[i] - '0');
        }
        i++;
    }
    if(negatif){
        *yangBalas = (*yangBalas) * -1;
        negatif = false;
    }

}