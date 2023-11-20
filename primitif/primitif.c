#include <stdio.h>
#include <math.h>
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

void strCpy(const char *str1, char *dest){
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

// int strToInt(char *str) {
// //     int i=0, s=0;

// //     while (str[i] != '\0' && str[i] != ' ' && i<31) {
// //         if (i > 0) {
// //             s *= 10;
// //         }
// //         s += str[i] - '0';
// //         i++;
// //     }

// //     return s;
// // }

int strToInt(const char *str) {
    int i = 0, s = 0, sign = 1;

    // Check for negative numbers
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }

    while (str[i] != '\0' && str[i] != ' ' && i < 31) {
        if (i > 0) {
            s *= 10;
        }
        s += str[i] - '0';
        i++;
    }

    return sign * s;
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

boolean strictIsStrEqual(char *str1, char *str2){
    boolean equal = true;
    int i=0;

    if (strlength(str1) != strlength(str2)){
        equal = false;
    } else {
        while ((i<strlength(str2)) && equal) {
            if (str1[i] != str2[i]) {
                equal = false;
            } else {
                i++;
            }
        }
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

    if (strictIsStrEqual("pahing",temp) || strictIsStrEqual("kliwon",temp) || strictIsStrEqual("wage",temp) ||
        strictIsStrEqual("pon",temp) || strictIsStrEqual("legi",temp) || strictIsStrEqual("",temp)){
        sukses = true;
    }

    return sukses;
}

void getString(const char *str1, char *hasil, int maxLen) {
    int i = 0, j = 0;
    while (str1[i] != ' ' && str1[i] != '\0') {
        i++;
    }

    if (str1[i] == '\0') {
        hasil[0] = '\0';
        return;
    }
    i++;

    while (str1[i] != '\0' && j < maxLen - 1) {
        hasil[j++] = str1[i++];
    }

    hasil[j] = '\0';
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

void makeUpper(char *str){
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 'a' + 'A';
    }
};

void ambilDuaNum(char *str1, int *num1, int *num2) {
    int i = 0, sign = 1;

    *num1 = 0;  // Initialize num1
    *num2 = 0;  // Initialize num2

    // Handling the sign for the first number
    if (str1[i] == '-') {
        sign = -1;
        i++;
    }

    // Extracting the first number
    while (str1[i] != ' ' && str1[i] != '\0') {
        *num1 = (*num1 * 10) + (str1[i] - '0');
        
        i++;
    }
    *num1 *= sign;

    // Skip the space
    while (str1[i] == ' ') {
        i++;
    }

    // Handling the sign for the second number
    if (str1[i] == '-') {
        sign = -1;
        i++;
    } else {
        sign = 1;
    }

    // Extracting the second number
    while (str1[i] != '\0') {
        *num2 = (*num2 * 10) + (str1[i] - '0');
        
        i++;
    }
    *num2 *= sign;
}